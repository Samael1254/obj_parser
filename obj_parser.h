#ifndef OBJ_PARSER_H
# define OBJ_PARSER_H

# include "ft_algebra.h"
# include <stdbool.h>

typedef struct vertex
{
	int			geo_id;
	int			text_id;
	int			norm_id;
}				t_vertex;

typedef struct s_material
{
	t_vec3		ka;
	t_vec3		kd;
	t_vec3		ks;
	double		specularity;
}				t_material;

typedef struct s_mesh
{
	t_vec3		*vertices;
	int			n_vertices;
	t_vec3		*normals;
	int			n_normals;
	t_vec2		*uvs;
	int			n_uvs;
	t_vertex	**faces;
	int			n_faces;
}				t_mesh;

t_mesh			*init_mesh(char *filename);
void			check_argument(int argc, char **argv);

// UTILS

bool			is_element(char *line, const char *elem);
bool			is_int(char *str);
bool			is_float(char *str);

// PARSING

t_mesh			*parse_obj_file(char *filename);
t_vertex		*parse_face(char *line, int line_nb, t_mesh *mesh);
t_vec3			parse_vertex(char *line, int line_nb, t_mesh *mesh);
t_vec3			parse_normal(char *line, int line_nb, t_mesh *mesh);
t_vec2			parse_uv(char *line, int line_nb, t_mesh *mesh);

// PRINT

void			print_mesh(t_mesh *mesh);

// OUTPUT AND EXIT

void			error(const char *type, const char *msg, int line_nb,
					t_mesh *mesh);
void			warning(const char *type, const char *msg, int line_nb);
void			info(const char *type, const char *msg);
void			exit_program(t_mesh *mesh, int status);

#endif
