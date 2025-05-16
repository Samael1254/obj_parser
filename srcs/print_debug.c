#include "ft_algebra.h"
#include "obj_parser.h"
#include "obj_parser_internal.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
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

void	dprint_mesh(int fd, t_mesh mesh)
{
	int	i;

	i = 0;
	while (i < mesh.n_vertices)
		print_vertex(fd, mesh.vertices[i++], "v");
	if (mesh.n_vertices > 0)
		dprintf(fd, "\n");
	i = 0;
	while (i < mesh.n_normals)
		print_vertex(fd, mesh.normals[i++], "vn");
	if (mesh.n_normals > 0)
		dprintf(fd, "\n");
	i = 0;
	while (i < mesh.n_uvs)
		print_uv(fd, mesh.uvs[i++], "vt");
	if (mesh.n_uvs > 0)
		dprintf(fd, "\n");
	i = 0;
	while (i < mesh.n_faces)
		print_face(fd, mesh.faces[i++]);
}

void	print_mesh(t_mesh mesh)
{
	dprint_mesh(STDOUT_FILENO, mesh);
}

int	save_obj_file(const char *filename, t_mesh mesh)
{
	int	fd;

	fd = open(filename, O_WRONLY);
	if (fd == -1)
		return (error("unable to open file for saving", filename, -1), -1);
	dprint_mesh(fd, mesh);
	return (0);
}
