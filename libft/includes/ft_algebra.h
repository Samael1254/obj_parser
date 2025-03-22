/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algebra.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfulconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:27:40 by gfulconi          #+#    #+#             */
/*   Updated: 2025/03/07 13:45:24 by gfulconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGEBRA_H
# define FT_ALGEBRA_H

typedef enum e_axis
{
	X_AXIS = 0,
	Y_AXIS = 1,
	Z_AXIS = 2,
}			t_axis;

// 2d integer vector
typedef struct s_ivector2d
{
	int		x;
	int		y;
}			t_ivector2d;

// 2d double vector
typedef struct s_vector2d
{
	double	x;
	double	y;
}			t_vector2d;

// 3d double vector
typedef struct s_vector3d
{
	double	x;
	double	y;
	double	z;
}			t_vector3d;

// 4d double vector
typedef struct s_vector4d
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_vector4d;

// ADD

// Computes the sum of two 2d vectors
t_vector2d	ft_add_vectors2d(t_vector2d a, t_vector2d b);
// Computes the sum of two 3d vectors
t_vector3d	ft_add_vectors3d(t_vector3d a, t_vector3d b);
// Computes the sum of two 4d vectors
t_vector4d	ft_add_vectors4d(t_vector4d a, t_vector4d b);

// SUB

// Computes the difference of two 2d vectors
t_vector2d	ft_sub_vectors2d(t_vector2d a, t_vector2d b);
// Computes the difference of two 3d vectors
t_vector3d	ft_sub_vectors3d(t_vector3d a, t_vector3d b);
// Computes the difference of two 4d vectors
t_vector4d	ft_sub_vectors4d(t_vector4d a, t_vector4d b);

// SCALE

// Computes the scaling of a 2d vector by lambda
t_vector2d	ft_scale_vector2d(double lambda, t_vector2d a);
// Computes the scaling of a 3d vector by lambda
t_vector3d	ft_scale_vector3d(double lambda, t_vector3d a);
// Computes the scaling of a 4d vector by lambda
t_vector4d	ft_scale_vector4d(double lambda, t_vector4d a);

// NORM

// Computes the norm of a 2d vector
double		ft_vector2d_norm(t_vector2d a);
// Computes the norm of a 3d vector
double		ft_vector3d_norm(t_vector3d a);

// Computes the square norm of a 2d vector
double		ft_vector2d_square_norm(t_vector2d a);
// Computes the square norm of a 3d vector
double		ft_vector3d_square_norm(t_vector3d a);

// NORMALIZE

// Returns a normalized version (of norm 1) of a 2d vector
t_vector2d	ft_normalize_vector2d(t_vector2d a);
// Returns a normalized version (of norm 1) of a 3d vector
t_vector3d	ft_normalize_vector3d(t_vector3d a);

// DOT PRODUCT

// Computes the dot product of two 2d vectors
double		ft_dot_vectors2d(t_vector2d a, t_vector2d b);
// Computes the dot product of two 3d vectors
double		ft_dot_vectors3d(t_vector3d a, t_vector3d b);

// CROSS PRODUCT

// Computes the cross product of two 3d vectors
t_vector3d	ft_cross_vectors3d(t_vector3d a, t_vector3d b);

// DISTANCE BETWEEN TWO POINTS

// Computes the distance between two 2d vectors
double		ft_distance2d(t_vector2d a, t_vector2d b);
// Computes the distance between two 3d vectors
double		ft_distance3d(t_vector3d a, t_vector3d b);

// MIDDLE OF TWO POINTS

// Returns the middle between two 2d vectors
t_vector2d	ft_middle2d(t_vector2d a, t_vector2d b);
// Returns the middle between two 3d vectors
t_vector3d	ft_middle3d(t_vector3d a, t_vector3d b);

// LINEAR INTERPOLATION

// Returns a linear interpolation between two 2d vectors
t_vector2d	ft_lerp2d(t_vector2d a, t_vector2d b, double lambda);
// Returns a linear interpolation between two 3d vectors
t_vector3d	ft_lerp3d(t_vector3d a, t_vector3d b, double lambda);

// ANGLES BETWEEN VECTORS

// Computes the angle formed by two 2d vectors
double		ft_vectors2d_angle(t_vector2d a, t_vector2d b);
// Computes the angle formed by two 3d vectors
double		ft_vectors3d_angle(t_vector3d a, t_vector3d b);

// ANGLE CONVERSION

// Converts an angle from radians to degrees
double		ft_rad_to_deg(double rad);
// Converts an angle from degress to radians
double		ft_deg_to_rad(double deg);

// CHECK ORTHOGONALITY

// Checks whether two 2d vectors are orthogonal
int			ft_are_vectors2d_ortho(t_vector2d a, t_vector2d b);
// Checks whether two 3d vectors are orthogonal
int			ft_are_vectors3d_ortho(t_vector3d a, t_vector3d b);

// CHECK COLINEARITY

// Checks whether two 2d vectors are colinear
int			ft_are_vectors2d_col(t_vector2d a, t_vector2d b);
// Checks whether two 3d vectors are colinear
int			ft_are_vectors3d_col(t_vector3d a, t_vector3d b);

// 2d LINE EQUATION

// Returns the equation of a 2d line passing through two points in the form
// of a 3d vector
t_vector3d	ft_line2d_equation(t_vector2d a, t_vector2d b);

// 2d LINE DIRECTION VECTOR

// Returns the direction vector of a 2d line
t_vector2d	ft_direction_vector2d(t_vector3d line);

// 2d LINES INTERSECTION

// Returns the intersection point between two 2d lines
t_vector2d	ft_lines2d_intersection(t_vector3d l1, t_vector3d l2);

// VECTOR CONVERSION

// Converts a 3d vector to 2d
t_vector2d	ft_3dto2d_vector(t_vector3d v3);
// Converts a 4d vector to 3d
t_vector3d	ft_4dto3d_vector(t_vector4d v4);
// Converts a 3d vector to 4d
t_vector4d	ft_3dto4d_vector(t_vector3d v3);
// Converts a 2d vector to 3d
t_vector3d	ft_2dto3d_vector(t_vector2d v2);
// Converts a 2d integer vector to double
t_vector2d	ft_i2dto2d_vector(t_ivector2d vi2);

// SET VECTOR

// Returns a 2d integer vector with the given coordinates
t_ivector2d	ft_set_ivector2d(int x, int y);
// Returns a 2d vector with the given coordinates
t_vector2d	ft_set_vector2d(double x, double y);
// Returns a 3d vector with the given coordinates
t_vector3d	ft_set_vector3d(double x, double y, double z);
// Returns a 4d vector with the given coordinates
t_vector4d	ft_set_vector4d(double x, double y, double z, double w);

// INIT VECTOR

// Returns a 2d vector with all coordinates set to the given value
t_vector2d	ft_init_vector2d(double value);
// Returns a 3d vector with all coordinates set to the given value
t_vector3d	ft_init_vector3d(double value);
// Returns a 4d vector with all coordinates set to the given value
t_vector4d	ft_init_vector4d(double value);

// ROTATE VECTOR

// Returns the given 3d vector (2d homogeneous vector) rotated by the given
// rotator (containing the rotation angles along each two axes)
t_vector3d	ft_rotate_vector3d(t_vector3d v, t_vector2d rotator);
// Returns the given 4d vector (3d homogeneous vector) rotated by the given
// rotator (containing the rotation angles along all axes)
t_vector4d	ft_rotate_vector4d(t_vector4d v, t_vector3d rotator);

// TRANSLATE VECTOR

// Returns the given translated 3d vector (2d homogeneous vector) along each
// two axes by the coordinates of the given translator
t_vector3d	ft_translate_vector3d(t_vector3d v, t_vector2d translator);
// Returns the given translated 4d vector (3d homogeneous vector) along each
// two axes by the coordinates of the given translator
t_vector4d	ft_translate_vector4d(t_vector4d v, t_vector3d translator);

// GET BASE VECTOR

// Returns the 2d base vector corresponding to the given axis
t_vector2d	ft_get_base_vector2d(t_axis axis);
// Returns the 3d base vector corresponding to the given axis
t_vector3d	ft_get_base_vector3d(t_axis axis);
// Returns the 4d base vector corresponding to the given axis
t_vector4d	ft_get_base_vector4d(t_axis axis);

// SET NULL MATRIX

// Sets all the elements of a given 2d matrix to zero
void		ft_set_null_matrix2d(double m[2][2]);
// Sets all the elements of a given 3d matrix to zero
void		ft_set_null_matrix3d(double m[3][3]);
// Sets all the elements of a given 4d matrix to zero
void		ft_set_null_matrix4d(double m[4][4]);

// ADD MATRIXES

// Stores the sum of two given 3d matrixes in a third matrix
void		ft_add_matrixes3d(double a[3][3], double b[3][3], double sum[3][3]);
// Stores the sum of two given 4d matrixes in a third matrix
void		ft_add_matrixes4d(double a[4][4], double b[4][4], double sum[4][4]);

// SCALE MATRIXES

// Scales the given 3d matrix by a factor lambda
void		ft_scale_matrix3d(double m[3][3], double lambda);
// Scales the given 4d matrix by a factor lambda
void		ft_scale_matrix4d(double m[4][4], double lambda);

// MATRIX PRODUCT

// Stores the product of two given 3d matrixes in a third matrix
void		ft_matrix3d_product(double a[3][3], double b[3][3],
				double prod[3][3]);
// Stores the product of two given 4d matrixes in a third matrix
void		ft_matrix4d_product(double a[4][4], double b[4][4],
				double prod[4][4]);

// MATRIX VECTOR PRODUCT

// Returns the result of a 3d matrix-vector product in a 3d vector
t_vector3d	ft_matrix_vector_product3d(double m[3][3], t_vector3d v);
// Returns the result of a 4d matrix-vector product in a 4d vector
t_vector4d	ft_matrix_vector_product4d(double m[4][4], t_vector4d v);

// MATRIX CONVERSION

// Converts a 3d matrix to 4d and sets the new coefficients to 0
void		ft_3dto4d_matrix(double m3[3][3], double m4[4][4]);
// Converts a 4d matrix to 3d
void		ft_4dto3d_matrix(double m4[4][4], double m3[3][3]);

// TRANSLATION MATRIX

// Stores a 3d translation matrix from the given translator
void		ft_set_translation_matrix3d(double m[3][3], t_vector2d t);
// Stores a 4d translation matrix from the given translator
void		ft_set_translation_matrix4d(double m[4][4], t_vector3d t);

// ROTATION MATRIX

void		ft_set_base_rotation_matrix3d(double m[3][3], double angle,
				t_axis axis);
void		ft_set_base_rotation_matrix4d(double m[4][4], double angle,
				t_axis axis);
void		ft_set_rotation_matrix3d(double m[3][3], double angle,
				t_vector3d axis);
void		ft_set_rotation_matrix4d(double m[4][4], double angle,
				t_vector3d axis);

// STRETCHING MATRIX

void		ft_set_stretching_matrix3d(double m[3][3], t_vector3d s);
void		ft_set_stretching_matrix4d(double m[4][4], t_vector4d s);

// SCALING MATRIX

void		ft_set_scaling_matrix3d(double m[3][3], double s);
void		ft_set_scaling_matrix4d(double m[4][4], double s);

// ORTHOGRAPHIC PROJECTION

t_vector3d	ft_orthographic_projection(t_vector4d v);

// AXONOMETRIC PROJECTIONS

t_vector3d	ft_axonometric_projection(t_vector4d v, double ang1, double ang2);
t_vector3d	ft_dimetric_projection(t_vector4d v, double ang1);
t_vector3d	ft_isometric_projection(t_vector4d v);

// OBLIQUE PROJECTION

t_vector3d	ft_oblique_projection(t_vector4d v, double depth, double angle);
t_vector3d	ft_cavalier_projection(t_vector4d v);
t_vector3d	ft_cabinet_projection(t_vector4d v);

// PLANE PROJECTION

t_vector3d	ft_plane_projection(t_vector4d v, t_axis normal);

// 1-POINT PERSPECTIVE PROJECTION

t_vector3d	ft_perspective_projection(t_vector4d v, t_vector4d cam_pos,
				t_vector3d cam_rot, t_ivector2d display_size);

// MATRIX DETERMINANT

// Compute the determinant of a 2d matrix
int			ft_determinant2d(double m[2][2]);

// REFLEXION MATRIX

// SHEERING MATRIX

// 3d LINE EQUATION

// PLANE EQUATION

// 3d LINE / PLANE INTERSECTION

// PLANE / PLANE INTERSECTION

// CIRCLE EQUATION

// SPHERE EQUATION

// MATRIX TRACE

// EIGENVALUES AND EIGENVECTORS

// TRANSPOSED MATRIX

// INVERSE MATRIX

// PRINT VECTOR

void		ft_print_vector2d(t_vector2d v, int precision);
void		ft_print_vector3d(t_vector3d v, int precision);
void		ft_print_vector4d(t_vector4d v, int precision);

// PRINT MATRIX

void		ft_print_matrix3d(double m[3][3], int precision);
void		ft_print_matrix4d(double m[4][4], int precision);

#endif
