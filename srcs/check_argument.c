#include "ft_strings.h"
#include "obj_parser.h"
#include <stddef.h>

static void	check_obj_filename(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strcmp(extension, ".obj") != 0)
	{
		error("wrong file name", "mesh file must have .obj extension", -1);
		exit_program(NULL, 1);
	}
	if (filename == extension)
	{
		error("wrong file name", "name must be provided before extension", -1);
		exit_program(NULL, 1);
	}
}

void	check_argument(int argc, char **argv)
{
	if (argc < 2)
	{
		error("argument error", "no .obj file name given", -1);
		exit_program(NULL, 1);
	}
	if (argc > 2)
	{
		error("argument error", "too many arguments, only one needed", -1);
		exit_program(NULL, 1);
	}
	check_obj_filename(argv[1]);
}
