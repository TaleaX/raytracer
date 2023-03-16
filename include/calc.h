/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:05:43 by tdehne            #+#    #+#             */
/*   Updated: 2023/03/15 03:56:19 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H
# include "room.h"
# include "vector.h"
# include <stdbool.h>

double	hit_sphere(t_sphere sphere, t_vec3 ray_origin, t_vec3 ray_direction);
double	hit_plane(t_plane plane, t_vec3 ray_origin, t_vec3 ray_direction);
double	calc_light(t_vec3 light_ray, t_vec3 normal, double intensity);
t_color	color_room(t_ray ray, t_room room, int depth);
t_vec3	get_lightRay(t_light light, t_vec3 hit_pos);
double	random_double(void);
double	random_min_max(double min, double max);
t_vec3	random_in_usphere(void);
t_vec3	random_in_hemisphere(t_vec3 normal);
t_vec3	reflected_direction(t_vec3 lightRay, t_vec3 normal);

#endif