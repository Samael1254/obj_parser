#include "ft_strings.h"
#include "obj_parser_internal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	print_vertex(int fd, t_vec3 vertex, const char *type)
{
	dprintf(fd, "%s %f %f %f\n", type, vertex.x, vertex.y, vertex.z);
}

static void	print_uv(int fd, t_vec2 uv, const char *type)
{
	dprintf(fd, "%s %f %f\n", type, uv.x, uv.y);
}

static void	print_face(int fd, const t_vertex *face)
{
	int	i;

	dprintf(fd, "f ");
	i = 0;
	while (i < 3)
	{
		dprintf(fd, "%d", face[i].geo_id);
		if (face[i].text_id != -1 || face[i].norm_id != -1)
			dprintf(fd, "/");
		if (face[i].text_id != -1)
			dprintf(fd, "%d", face[i].text_id);
		if (face[i].norm_id != -1)
			dprintf(fd, "/%d", face[i].norm_id);
		if (i != 2)
			dprintf(fd, " ");
		i++;
	}
	dprintf(fd, "\n");
}

/**
 * @brief Print the OBJ content of a mesh on the standard output
 *
 * @param mesh: Mesh to print
 */
void	dprint_mesh(int fd, t_mesh mesh)
{
	for (int i = 0; i < mesh.n_vertices; i++)
		print_vertex(fd, mesh.vertices[i], "v");
	if (mesh.n_vertices > 0)
		dprintf(fd, "\n");
	for (int i = 0; i < mesh.n_normals; i++)
		print_vertex(fd, mesh.normals[i], "vn");
	if (mesh.n_normals > 0)
		dprintf(fd, "\n");
	for (int i = 0; i < mesh.n_uvs; i++)
		print_uv(fd, mesh.uvs[i], "vt");
	if (mesh.n_uvs > 0)
		dprintf(fd, "\n");
	for (int i = 0; i < mesh.n_faces; i++)
		print_face(fd, mesh.faces[i]);
}

/**
 * @brief Print the OBJ content of a mesh on the standard output
 *
 * @param mesh: Mesh to print
 */
void	print_mesh(t_mesh mesh)
{
	dprint_mesh(STDOUT_FILENO, mesh);
}

/**
 * @brief Save a mesh as a .obj file
 *
 * @param filename: Name of the file to write in (without the .obj extension)
 * @param mesh: Mesh to save
 * @return Returns 0 on success and -1 on failure
 */
int	save_obj_file(const char *filename, t_mesh mesh)
{
	int		fd;
	char	*obj_filename;

	if (!filename)
		return (-1);
	obj_filename = ft_strjoin(filename, ".obj");
	if (!filename)
		return (-1);
	fd = open(obj_filename, O_WRONLY | O_CREAT, 00666);
	if (fd == -1)
		return (error("unable to open file for saving", obj_filename, -1),
			free(obj_filename), -1);
	free(obj_filename);
	dprint_mesh(fd, mesh);
	close(fd);
	return (0);
}

/**
 * @brief Print information about a mesh on the given file descriptor
 *
 * @param fd: File descriptor to print in
 * @param mesh: Mesh to print the info about
 */
void	dprint_mesh_info(int fd, t_mesh mesh)
{
	dprintf(fd, "Mesh info:\n");
	dprintf(fd, "Vertices count:       %d\n", mesh.n_vertices);
	dprintf(fd, "Vertex normals count: %d\n", mesh.n_normals);
	dprintf(fd, "Vertex UVs count:     %d\n", mesh.n_uvs);
	dprintf(fd, "Faces count:          %d\n", mesh.n_faces);
}

/**
 * @brief Print information about a mesh on the standard output
 *
 * @param mesh: Mesh to print info about
 */
void	print_mesh_info(t_mesh mesh)
{
	dprint_mesh_info(STDOUT_FILENO, mesh);
}
