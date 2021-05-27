/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:10:27 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/27 04:10:57 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_texture(t_ray *ray, t_conf *conf)
{
	t_texture	*tex;

	if (ray->side == 0 && ray->dirx < 0)
		tex = &conf->no;
	if (ray->side == 0 && ray->dirx >= 0)
		tex = &conf->so;
	if (ray->side == 1 && ray->diry < 0)
		tex = &conf->we;
	if (ray->side == 1 && ray->diry >= 0)
		tex = &conf->ea;
	return (tex);
}

void	set_wall_info(t_conf *conf, t_ray *ray, t_wall *wall)
{
	wall->line_height = (int)(conf->resy / ray->perp_wall_dist);
	wall->draw.y_start = conf->resy / 2 - wall->line_height / 2;
	if (wall->draw.y_start < 0)
		wall->draw.y_start = 0;
	wall->draw.y_end = wall->line_height / 2 + conf->resy / 2;
	if (wall->draw.y_end >= conf->resy)
		wall->draw.y_end = conf->resy - 1;
	if (ray->side == 0)
		wall->wall_x = conf->posy + ray->perp_wall_dist * ray->diry;
	else
		wall->wall_x = conf->posx + ray->perp_wall_dist * ray->dirx;
	wall->wall_x -= floor(wall->wall_x);
	wall->tex = get_texture(ray, conf);
	wall->tex_x = (int)(wall->wall_x * (double)wall->tex->w);
	wall->step = (double)wall->tex->h / wall->line_height;
	wall->tex_pos = (wall->draw.y_start - conf->resy / 2
			+ wall->line_height / 2) * wall->step;
}
