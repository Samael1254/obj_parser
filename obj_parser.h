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

typedef struct s_mesh
{
	t_vector3d	*vertices;
	int			n_vertices;
	t_vector3d	*normals;
	int			n_normals;
	t_vector2d	*uvs;
	int			n_uvs;
	t_vertex	**faces;
	int			n_faces;
}				t_mesh;

t_mesh			*init_mesh(char *filename);
bool			is_element(char *line, const char *elem);
void			check_argument(int argc, char **argv);

t_mesh			*parse_obj_file(char *filename);
t_vertex		*parse_face(char *line, int line_nb, t_mesh *mesh);
t_vector3d		parse_vertex(char *line, int line_nb, t_mesh *mesh);
t_vector3d		parse_normal(char *line, int line_nb, t_mesh *mesh);
t_vector2d		parse_uv(char *line, int line_nb, t_mesh *mesh);

void			print_mesh(t_mesh *mesh);

void			error(const char *type, const char *msg, int line_nb,
					t_mesh *mesh);
void			warning(const char *type, const char *msg, int line_nb);
void			info(const char *type, const char *msg);
void			exit_program(t_mesh *mesh, int status);

#endif
