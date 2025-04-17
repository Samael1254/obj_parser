#include "obj_parser.h"
#include <stdio.h>
#include <stdlib.h>

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

void	exit_program(t_mesh *mesh, int status)
{
	free_mesh(mesh);
	exit(status);
}

void	error(const char *type, const char *msg, int line_nb)
{
	printf("\e[31;1mError\e[0;1m: ");
	if (type)
		printf("%s\e[0m: ", type);
	printf("%s", msg);
	if (line_nb >= 0)
		printf(" (line %d)", line_nb);
	printf("\n");
}

void	warning(const char *type, const char *msg, int line_nb)
{
	printf("\e[33;1mWarning\e[0;1m: ");
	if (type)
		printf("%s\e[0m: ", type);
	printf("%s", msg);
	if (line_nb >= 0)
		printf(" (line %d)", line_nb);
	printf("\n");
}

void	info(const char *type, const char *msg)
{
	printf("\e[34;1mInfo\e[0;1m: ");
	if (type)
		printf("%s\e[0m: ", type);
	printf("%s\n", msg);
}
