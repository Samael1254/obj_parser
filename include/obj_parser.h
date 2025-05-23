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

/**
 * @typedef s_material
 * @brief Struct containing .mtl material information
 *
 */
typedef struct s_material
{
	t_vec3		ka;
	t_vec3		kd;
	t_vec3		ks;
	double		specularity;
	char		*texture;
	char		*bump;
}				t_material;

/**
 * @typedef s_mesh
 * @brief Struct containing .obj mesh information
 *
 */
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

t_mesh			*parse_obj_file(const char *filename);

void			print_mesh(t_mesh mesh);

void			dprint_mesh(int fd, t_mesh mesh);

int				save_obj_file(const char *filename, t_mesh mesh);

void			dprint_mesh_info(int fd, t_mesh mesh);

void			print_mesh_info(t_mesh mesh);

void			free_mesh(t_mesh *mesh);

bool			is_obj_filename_valid(const char *filename);

#endif
