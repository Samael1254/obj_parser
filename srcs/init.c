#include "ft_memory.h"
#include "get_next_line.h"
#include "obj_parser.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static bool	count_elements(char *filename, t_mesh *mesh)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error("could not open file", filename, -1);
		return (false);
	}
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
	return (true);
}

t_mesh	*init_mesh(char *filename)
{
	t_mesh	*mesh;

	mesh = ft_calloc(1, sizeof(t_mesh));
	if (!mesh)
		return (error("malloc failed", "in init_mesh", -1), NULL);
	if (!count_elements(filename, mesh))
		return (free(mesh), NULL);
	mesh->vertices = NULL;
	mesh->normals = NULL;
	mesh->uvs = NULL;
	mesh->faces = NULL;
	mesh->vertices = malloc(mesh->n_vertices * sizeof(t_vec3));
	mesh->normals = malloc(mesh->n_normals * sizeof(t_vec3));
	mesh->uvs = malloc(mesh->n_uvs * sizeof(t_vec2));
	mesh->faces = ft_calloc(mesh->n_faces, sizeof(t_vertex *));
	if (!mesh->vertices || !mesh->normals || !mesh->uvs || !mesh->faces)
		return (free_mesh(mesh), error("malloc failed", "in init_mesh", -1),
			NULL);
	return (mesh);
}
