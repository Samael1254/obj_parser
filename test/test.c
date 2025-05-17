#include "obj_parser.h"
#include <stdio.h>
#include <stdlib.h>

static void	check_argument_count(int argc)
{
	if (argc == 2)
		return ;
	dprintf(2, "\e[31;1mError\e[0;1m: ");
	if (argc < 2)
		dprintf(2, "no .obj file was given as argument\n");
	if (argc > 2)
		dprintf(2, "too many arguments, only one needed\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_mesh	*mesh;

	check_argument_count(argc);
	mesh = parse_obj_file(argv[1]);
	if (!mesh)
		return (EXIT_FAILURE);
	print_mesh(*mesh);
	save_obj_file("filetest", *mesh);
	print_mesh_info(*mesh);
	free_mesh(mesh);
	return (EXIT_SUCCESS);
}
