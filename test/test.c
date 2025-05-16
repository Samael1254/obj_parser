#include "obj_parser.h"
#include <stdlib.h>

static void	check_argument_count(int argc)
{
	if (argc == 1)
		return ;
	if (argc < 2)
		error("argument error", "no .obj file name given", -1);
	if (argc > 2)
		error("argument error", "too many arguments, only one needed", -1);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_mesh	*mesh;

	check_argument_count(argc);
	mesh = parse_obj_file(argv[1]);
	print_mesh(mesh);
	free_mesh(mesh);
	return (EXIT_SUCCESS);
}
