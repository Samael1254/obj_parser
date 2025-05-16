#include "get_next_line.h"
#include "obj_parser_internal.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static bool	count_elements(const char *filename, t_mesh *mesh)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error("could not open file", filename, -1), true);
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
	return (false);
}

t_mesh	*init_mesh(const char *filename)
{
	t_mesh	*mesh;

	mesh = calloc(1, sizeof(t_mesh));
	if (!mesh)
		return (error("malloc failed", "in init_mesh", -1), NULL);
	if (count_elements(filename, mesh))
		return (free(mesh), NULL);
	mesh->vertices = malloc(mesh->n_vertices * sizeof(t_vec3));
	mesh->normals = malloc(mesh->n_normals * sizeof(t_vec3));
	mesh->uvs = malloc(mesh->n_uvs * sizeof(t_vec2));
	mesh->faces = calloc(mesh->n_faces, sizeof(t_vertex *));
	if (!mesh->vertices || !mesh->normals || !mesh->uvs || !mesh->faces)
		return (free_mesh(mesh), error("malloc failed", "in init_mesh", -1),
			NULL);
	return (mesh);
}
