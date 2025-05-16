#include "obj_parser.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_mesh	*mesh;

	check_argument(argc, argv);
	mesh = parse_obj_file(argv[1]);
	print_mesh(mesh);
	exit_program(mesh, EXIT_SUCCESS);
}
