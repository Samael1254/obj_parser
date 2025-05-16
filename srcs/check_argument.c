#include "obj_parser_internal.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

bool	is_obj_filename_valid(const char *filename)
{
	const char	*extension;

	extension = strrchr(filename, '.');
	if (!extension || strcmp(extension, ".obj") != 0)
	{
		error("wrong file name", "mesh file must have .obj extension", -1);
		return (false);
	}
	if (filename == extension)
	{
		error("wrong file name", "name must be provided before extension", -1);
		return (false);
	}
	return (true);
}
