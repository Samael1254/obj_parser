#include "obj_parser_internal.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Frees all the mesh information
 *
 * @param mesh: Pointer to the mesh to free
 */
void	free_mesh(t_mesh *mesh)
{
	int	i;

	if (!mesh)
		return ;
	if (mesh->vertices)
		free(mesh->vertices);
	if (mesh->normals)
		free(mesh->normals);
	if (mesh->uvs)
		free(mesh->uvs);
	i = 0;
	while (i < mesh->n_faces)
		if (mesh->faces[i++])
			free(mesh->faces[i - 1]);
	if (mesh->faces)
		free(mesh->faces);
	free(mesh);
}

void	error(const char *type, const char *msg, int line_nb)
{
	dprintf(2, "\e[31;1mError\e[0;1m: ");
	if (type)
		dprintf(2, "%s\e[0m: ", type);
	dprintf(2, "%s", msg);
	if (line_nb >= 0)
		dprintf(2, " (line %d)", line_nb);
	dprintf(2, "\n");
}

void	warning(const char *type, const char *msg, int line_nb)
{
	dprintf(2, "\e[33;1mWarning\e[0;1m: ");
	if (type)
		dprintf(2, "%s\e[0m: ", type);
	dprintf(2, "%s", msg);
	if (line_nb >= 0)
		dprintf(2, " (line %d)", line_nb);
	dprintf(2, "\n");
}

void	info(const char *type, const char *msg)
{
	dprintf(2, "\e[34;1mInfo\e[0;1m: ");
	if (type)
		dprintf(2, "%s\e[0m: ", type);
	dprintf(2, "%s\n", msg);
}
