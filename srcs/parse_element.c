#include "ft_algebra.h"
#include "ft_conversion.h"
#include "ft_strings.h"
#include "obj_parser_internal.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool	is_line_valid(char **line_data, bool (*check)(char *), int min_params,
		int max_params, int line_nb)
{
	int	i;

	i = 1;
	while (line_data[i])
	{
		if (!check(line_data[i]))
			return (error("wrong parameter type", line_data[i], line_nb),
				false);
		i++;
	}
	i -= 1;
	if (i < min_params || i > max_params)
		error(line_data[0], "wrong number of parameters", line_nb);
	return (true);
}

t_vec3	parse_vertex(char **line_data, int line_nb, bool *failed)
{
	t_vec3	new_vertex;

	if (!is_line_valid(line_data, &is_float, 3, 4, line_nb))
	{
		ft_free_strtab(line_data);
		*failed = true;
		return (ft_init_vec3(0));
	}
	new_vertex.x = ft_atod(line_data[1]);
	new_vertex.y = ft_atod(line_data[2]);
	new_vertex.z = ft_atod(line_data[3]);
	ft_free_strtab(line_data);
	return (new_vertex);
}

t_vec3	parse_normal(char **line_data, int line_nb, bool *failed)
{
	t_vec3	new_vertex;

	if (!is_line_valid(line_data, &is_float, 3, 3, line_nb))
	{
		ft_free_strtab(line_data);
		*failed = true;
		return (ft_init_vec3(0));
	}
	new_vertex.x = ft_atod(line_data[1]);
	new_vertex.y = ft_atod(line_data[2]);
	new_vertex.z = ft_atod(line_data[3]);
	ft_free_strtab(line_data);
	return (new_vertex);
}

t_vec2	parse_uv(char **line_data, int line_nb, bool *failed)
{
	t_vec2	new_vertex;

	if (!is_line_valid(line_data, &is_float, 1, 2, line_nb))
	{
		ft_free_strtab(line_data);
		*failed = true;
		return (ft_init_vec2(0));
	}
	new_vertex.x = ft_atod(line_data[1]);
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
	nb_len = strcspn(vertex_data, "/");
	data_len = (int)strlen(vertex_data);
	vertex_data[nb_len] = '\0';
	new_vertex.geo_id = atoi(vertex_data);
	if (nb_len == data_len)
		return (new_vertex);
	vertex_data += nb_len + 1;
	nb_len = strcspn(vertex_data, "/");
	data_len = (int)strlen(vertex_data);
	vertex_data[nb_len] = '\0';
	if (nb_len > 0)
		new_vertex.text_id = ft_atoi(vertex_data);
	if (nb_len == data_len)
		return (new_vertex);
	vertex_data += nb_len + 1;
	new_vertex.norm_id = ft_atoi(vertex_data);
	return (new_vertex);
}

t_vertex	*parse_face(char **line_data, int line_nb, bool *failed)
{
	t_vertex	*new_face;
	int			i;

	if (!is_line_valid(line_data, &is_vertex, 3, 3, line_nb))
	{
		ft_free_strtab(line_data);
		*failed = true;
		return (NULL);
	}
	new_face = malloc(3 * sizeof(t_vertex));
	if (!new_face)
	{
		ft_free_strtab(line_data);
		error("malloc failed", "parse_face", line_nb);
		*failed = true;
		return (NULL);
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
