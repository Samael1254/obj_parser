#ifndef OBJ_PARSER_INTERNAL_H
# define OBJ_PARSER_INTERNAL_H

# include "obj_parser.h"
# include <stdbool.h>

t_mesh		*init_mesh(const char *filename);

// UTILS

bool		is_element(char *str, const char *elem);
bool		is_int(char *str);
bool		is_float(char *str);
bool		is_vertex(char *str);

// PARSING

t_vec3		parse_vertex(char **line_data, int line_nb, bool *failed);
t_vec3		parse_normal(char **line_data, int line_nb, bool *failed);
t_vec2		parse_uv(char **line_data, int line_nb, bool *failed);
t_vertex	*parse_face(char **line_data, int line_nb, bool *failed);

// OUTPUT AND EXIT

void		free_mesh(t_mesh *mesh);
void		error(const char *type, const char *msg, int line_nb);
void		warning(const char *type, const char *msg, int line_nb);
void		info(const char *type, const char *msg);

#endif
