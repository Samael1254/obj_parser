#include "ft_memory.h"
#include "ft_strings.h"
#include "get_next_line.h"
#include "obj_parser.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static void	parse_line(char *line, int line_nb, int count[4], t_mesh *mesh)
{
	if (is_element(line, "v"))
		mesh->vertices[count[0]++] = parse_vertex(line, line_nb, mesh);
	else if (is_element(line, "vn"))
		mesh->normals[count[1]++] = parse_vertex(line, line_nb, mesh);
	else if (is_element(line, "vt"))
		mesh->uvs[count[2]++] = parse_vertex(line, line_nb, mesh);
	else if (is_element(line, "f"))
		mesh->faces[count[3]++] = parse_face(line, line_nb, mesh);
}

void	parse_obj_file(char *filename, t_mesh *mesh)
{
	int		fd;
	int		line_nb;
	char	*line;
	char	*newline;
	int		count[4];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("could not open file", filename, -1, mesh);
	line_nb = 1;
	ft_bzero(count, 4 * sizeof(int));
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		newline = ft_strchr(line, '\n');
		if (newline)
			*newline = '\0';
		parse_line(line, line_nb, count, mesh);
		free(line);
		line_nb++;
	}
	close(fd);
}
