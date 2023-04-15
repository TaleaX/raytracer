/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dns <dns@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:19:27 by dns               #+#    #+#             */
/*   Updated: 2023/04/13 20:42:17 by dns              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_light(char **line)
{
	(*line)++;
	parse_skip_three(line, &data()->lights[data()->n_lights].ray.origin);
	
	parse_skip_one(line, &data()->lights[data()->n_lights].intensity);
	parse_skip_color(line, &data()->lights[data()->n_lights].color);
	data()->lights[data()->n_lights].type = POINT;
	data()->n_lights++;
	return (0);
}

int	get_ambientlight(char **line)
{
	(*line) += 2;
	parse_skip_one(line, &data()->lights[data()->n_lights].intensity);
	parse_skip_color(line, &data()->lights[data()->n_lights].color);
	data()->lights[data()->n_lights].type = AMBIENT;
	data()->n_lights++;
	return (0);
}

int	get_camera(char **line)
{
	(*line)++;
	parse_skip_three(line, &data()->camera.origin);
	parse_skip_three(line, &data()->camera.lookat);
	parse_skip_one(line, &data()->camera.hfov);
	return (0);
}

int get_sun(char **line)
{
	(*line)++;
	parse_skip_three(line, &data()->lights[data()->n_lights].ray.direction);
	parse_skip_one(line, &data()->lights[data()->n_lights].intensity);
	data()->lights[data()->n_lights].type = SUN;
	data()->n_lights++;
	return (0);
}