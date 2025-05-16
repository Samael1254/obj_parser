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
	char		*texture;
	char		*bump;
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

// PARSING

t_mesh			*parse_obj_file(const char *filename);

// PRINT

void			print_mesh(t_mesh mesh);

void			dprint_mesh(int fd, t_mesh mesh);

int				save_obj_file(const char *filename, t_mesh mesh);

// OUTPUT AND EXIT

void			free_mesh(t_mesh *mesh);

bool			is_obj_filename_valid(const char *filename);

#endif
