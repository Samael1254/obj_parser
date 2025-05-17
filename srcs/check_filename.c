#include "obj_parser_internal.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/**
 * @brief Checks if a file name or path corresponds to a .obj file
 *
 * @param filename : Path of the file to evaluate
 * @return Return true or false depending on the result
 */
bool	is_obj_filename_valid(const char *filename)
{
	const char	*extension;

	if (strchr(filename, '/'))
		filename = strrchr(filename, '/') + 1;
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
