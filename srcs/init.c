#include "ft_memory.h"
#include "get_next_line.h"
#include "obj_parser.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static void	count_elements(char *filename, t_mesh *mesh)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("could not open file", filename, -1, mesh);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_element(line, "v"))
			mesh->n_vertices++;
		else if (is_element(line, "vn"))
			mesh->n_normals++;
		else if (is_element(line, "vt"))
			mesh->n_uvs++;
		else if (is_element(line, "f"))
			mesh->n_faces++;
		free(line);
	}
	close(fd);
}

t_mesh	*init_mesh(char *filename)
{
	t_mesh	*mesh;

	mesh = ft_calloc(1, sizeof(t_mesh));
	if (!mesh)
		error("malloc failed", "in init_mesh", -1, mesh);
	count_elements(filename, mesh);
	mesh->vertices = malloc(mesh->n_vertices * sizeof(t_vec3));
	mesh->normals = malloc(mesh->n_normals * sizeof(t_vec3));
	mesh->uvs = malloc(mesh->n_uvs * sizeof(t_vec2));
	mesh->faces = ft_calloc(mesh->n_faces, sizeof(t_vertex *));
	if (!mesh->vertices || !mesh->normals || !mesh->uvs || !mesh->faces)
		error("malloc failed", "in init_mesh", -1, mesh);
	return (mesh);
}
