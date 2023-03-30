/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dns <dns@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:15:13 by tdehne            #+#    #+#             */
/*   Updated: 2023/03/30 16:07:00 by dns              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "../MLX42/include/MLX42/MLX42.h"
# define ASPECT_RATIO (double)(21.0 / 9.0)
# define HEIGHT 800
# define WIDTH ((int)(HEIGHT * ASPECT_RATIO))
# define VH 1.0
# define VW ((double)(VH * ASPECT_RATIO))
# define VIEWPORT_DIST 1.0

//enums
typedef enum e_light_type		t_light_type;
typedef enum e_material_type	t_material_type;
typedef enum e_obj_type			t_obj_type;

typedef struct s_hit_rec		t_hit_rec;

//room structs
// typedef struct s_window			t_window;
typedef struct s_pixel			t_pixel;
typedef struct s_data			t_data;
typedef struct s_viewport		t_viewport;
typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_camera			t_camera;
typedef struct s_room			t_room;
typedef struct s_light			t_light;
typedef struct s_ray			t_ray;
typedef struct s_obj			t_obj;

//vector structs
typedef struct s_v2		t_vec2;
typedef struct s_v3		t_vec3;
typedef struct s_color	t_color;
typedef	t_vec3					t_v3;

enum e_obj_type {
	SPHERE,
	PLANE,
	CYLINDER
};

enum e_light_type
{
	POINT,
	SUN,
	AMBIENT
};

enum e_material_type
{
	MATTE,
	SHINY,
	MIRROR,
	GLAS,
	METAL
};

//vector + color structs
struct s_v2 {
	int		x;
	int		y;
};

struct s_v3 {
	double	x;
	double	y;
	double	z;
};

struct s_color {
	double	r;
	double	g;
	double	b;
	double	a;
};

struct s_ray {
	t_vec3	origin;
	t_vec3	direction;
};

struct s_light {
	t_light_type	type;
	t_ray			ray;
	double			intensity;
};


struct	s_obj
{
	t_vec3			center;
	t_vec3			point;
	t_vec3			point2;
	t_vec3			normal;
	double			radius;
	t_obj_type		obj_type;
	t_color			color;
	t_material_type material;
	double			fuzz;
	double			specular;
};

t_data	*data(void);

struct s_pixel
{
	// double		v_x;
	// double		v_y;

	// bool        hit_anything;
	int         hits_num;
	t_color		color;
	double		t;
	t_vec3		hitpoint;
	int			obj_id;
	t_vec3      normal;
	t_obj_type	type;
	t_material_type material;
	double			fuzz;
	double			specular;
	// int			sphere_id;
};

struct s_camera {
	// t_ray	ray;
	t_vec3	origin;
	t_vec3	lookat;
	double	viewport_height;
	double	viewport_width;
	double	vfov;
	t_vec3	lower_left_corner;
};

struct s_data
{
	mlx_image_t	*g_img;
	t_pixel     px[HEIGHT][WIDTH];
	t_vec2		coord;
	double		cam_dist;
	t_camera	camera;
	t_obj		objects[1000];
	t_ray		ray;
	t_light		light;
	t_vec3		viewport_px;
	t_vec3		cam_origin;
	t_vec3		horizontal;
	t_vec3      vertical;
	t_vec3		lower_left_corner;
	int			samples;
	int			obj_len;
	double		scale; 
};

struct s_sphere {
	t_vec3			center;
	double			radius;
	t_color			color;
	t_material_type material;

};

struct s_plane {
	t_vec3	p;
	t_vec3	normal;
	t_vec3	c;
	t_color	color;
};




// struct s_room {
// 	t_camera	camera;
// 	t_light		light;
// 	t_plane		planes[4];
// 	t_sphere	spheres[4];
// 	size_t		num_spheres;
// 	size_t		num_lights;
// 	size_t		num_planes;
// };



// struct s_window {
// 	mlx_image_t	*g_img;
// 	int			x;
// 	int			y;
// 	int			WIN_WIDTH;
// 	int			WIN_HEIGHT;
// };


struct	s_hit_rec
{
	t_vec3			hitpos;
	t_vec3			normal;
	t_material_type material;
	t_color			color;
	double			radius;
	t_vec3			center;
	double	t;
};


#endif