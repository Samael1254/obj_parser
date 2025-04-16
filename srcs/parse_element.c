#include "ft_algebra.h"
#include "ft_conversion.h"
#include "ft_strings.h"
#include "obj_parser.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

// bool	check_line_data(char **line_data)
// {
// }

t_vec3	parse_vertex(char *line, int line_nb, t_mesh *mesh)
{
	t_vec3	new_vertex;
	char	**line_data;
	int		arg_count;

	line_data = ft_split(line, ' ');
	arg_count = ft_strtab_size(line_data) - 1;
	if (arg_count < 3 || arg_count > 4)
	{
		ft_free_strtab(line_data);
		error("v", "wrong number of parameters (must be 3 or 4)", line_nb,
			mesh);
	}
	if (arg_count == 4)
		warning("Unhandled parameter", "vertex weigth", line_nb);
	new_vertex.x = ft_atod(line_data[1]);
	new_vertex.y = ft_atod(line_data[2]);
	new_vertex.z = ft_atod(line_data[3]);
	ft_free_strtab(line_data);
	return (new_vertex);
}

t_vec3	parse_normal(char *line, int line_nb, t_mesh *mesh)
{
	t_vec3	new_vertex;
	char	**line_data;
	int		arg_count;

	line_data = ft_split(line, ' ');
	arg_count = ft_strtab_size(line_data) - 1;
	if (arg_count != 3)
	{
		ft_free_strtab(line_data);
		error("vn", "wrong number of parameters (must be 3)", line_nb, mesh);
	}
	new_vertex.x = ft_atod(line_data[1]);
	new_vertex.y = ft_atod(line_data[2]);
	new_vertex.z = ft_atod(line_data[3]);
	ft_free_strtab(line_data);
	return (new_vertex);
}

t_vec2	parse_uv(char *line, int line_nb, t_mesh *mesh)
{
	t_vec2	new_vertex;
	char	**line_data;
	int		arg_count;

	line_data = ft_split(line, ' ');
	arg_count = ft_strtab_size(line_data) - 1;
	if (arg_count < 1 || arg_count > 2)
	{
		ft_free_strtab(line_data);
		error("vt", "wrong number of parameters (must be 1 or 2)", line_nb,
			mesh);
	}
	new_vertex.x = ft_atod(line_data[1]);
	new_vertex.y = 0;
	if (arg_count == 2)
		new_vertex.y = ft_atod(line_data[2]);
	ft_free_strtab(line_data);
	return (new_vertex);
}

static t_vertex	parse_face_vertex(char *vertex_data)
{
	t_vertex	new_vertex;
	int			nb_len;
	int			data_len;

	new_vertex.text_id = -1;
	new_vertex.norm_id = -1;
	nb_len = ft_strcspn(vertex_data, "/");
	data_len = (int)ft_strlen(vertex_data);
	vertex_data[nb_len] = '\0';
	new_vertex.geo_id = ft_atoi(vertex_data);
	if (nb_len == data_len)
		return (new_vertex);
	vertex_data += nb_len + 1;
	nb_len = ft_strcspn(vertex_data, "/");
	data_len = (int)ft_strlen(vertex_data);
	vertex_data[nb_len] = '\0';
	if (nb_len > 0)
		new_vertex.text_id = ft_atoi(vertex_data);
	if (nb_len == data_len)
		return (new_vertex);
	vertex_data += nb_len + 1;
	new_vertex.norm_id = ft_atoi(vertex_data);
	return (new_vertex);
}

t_vertex	*parse_face(char *line, int line_nb, t_mesh *mesh)
{
	t_vertex	*new_face;
	char		**line_data;
	int			i;
	int			arg_count;

	line_data = ft_split(line, ' ');
	arg_count = ft_strtab_size(line_data) - 1;
	if (arg_count < 3)
	{
		ft_free_strtab(line_data);
		error("face", "wrong number of parameters (must be 3)", line_nb, mesh);
	}
	if (arg_count == 4)
		warning("more than 3 vertices in face",
			"this parser only handles triangle faces", line_nb);
	new_face = malloc(3 * sizeof(t_vertex));
	if (!new_face)
	{
		ft_free_strtab(line_data);
		error("malloc failed", "parse_face", line_nb, mesh);
	}
	i = 0;
	while (i < 3)
	{
		new_face[i] = parse_face_vertex(line_data[i + 1]);
		i++;
	}
	ft_free_strtab(line_data);
	return (new_face);
}
