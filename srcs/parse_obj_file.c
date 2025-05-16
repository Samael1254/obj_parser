#include "ft_strings.h"
#include "get_next_line.h"
#include "obj_parser.h"
#include "obj_parser_internal.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

static bool	parse_line(char *line, int line_nb, int count[4], t_mesh *mesh)
{
	bool	failed;
	char	**line_data;

	failed = false;
	line_data = ft_split(line, ' ');
	if (!line_data)
		return (error("malloc failed", "in parse_line", -1), true);
	if (is_element(line_data[0], "v"))
		mesh->vertices[count[0]++] = parse_vertex(line_data, line_nb, &failed);
	else if (is_element(line_data[0], "vn"))
		mesh->normals[count[1]++] = parse_normal(line_data, line_nb, &failed);
	else if (is_element(line_data[0], "vt"))
		mesh->uvs[count[2]++] = parse_uv(line_data, line_nb, &failed);
	else if (is_element(line_data[0], "f"))
		mesh->faces[count[3]++] = parse_face(line_data, line_nb, &failed);
	if (failed)
		return (true);
	return (false);
}

t_mesh	*parse_obj_file(const char *filename)
{
	int		fd;
	int		line_nb;
	char	*line;
	char	*newline;
	int		count[4] = {0, 0, 0, 0};
	t_mesh	*mesh;

	if (!is_obj_filename_valid(filename))
		return (NULL);
	mesh = init_mesh(filename);
	if (!mesh)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (free_mesh(mesh), error("could not open file", filename, -1),
			NULL);
	line_nb = 1;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		newline = strchr(line, '\n');
		if (newline)
			*newline = '\0';
		if (parse_line(line, line_nb, count, mesh))
			return (free(line), free(mesh), NULL);
		free(line);
		line_nb++;
	}
	close(fd);
	return (mesh);
}
