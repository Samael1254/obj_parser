#include "obj_parser.h"
#include <stdio.h>
#include <stdlib.h>

void	exit_program(t_mesh *mesh, int status)
{
	int	i;

	if (!mesh)
		exit(status);
	if (mesh->vertices)
		free(mesh->vertices);
	if (mesh->normals)
		free(mesh->normals);
	if (mesh->uvs)
		free(mesh->uvs);
	i = 0;
	while (i < mesh->n_faces)
		free(mesh->faces[i++]);
	if (mesh->faces)
		free(mesh->faces);
	exit(status);
}

void	error(char *type, char *msg, int line_nb, t_mesh *mesh)
{
	printf("\e[31;1mError\e[0;1m: ");
	if (type)
		printf("%s\e[0m: ", type);
	printf("%s", msg);
	if (line_nb >= 0)
		printf(" (line %d)", line_nb);
	printf("\n");
	exit_program(mesh, EXIT_FAILURE);
}

void	warning(char *type, char *msg, int line_nb)
{
	printf("\e[33;1mWarning\e[0;1m: ");
	if (type)
		printf("%s\e[0m: ", type);
	printf("%s", msg);
	if (line_nb >= 0)
		printf(" (line %d)", line_nb);
	printf("\n");
}

void	info(char *type, char *msg)
{
	printf("\e[34;1mInfo\e[0;1m: ");
	if (type)
		printf("%s\e[0m: ", type);
	printf("%s\n", msg);
}
