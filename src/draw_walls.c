/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:05:17 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/27 04:03:26 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting_1(int x, t_ray *ray, t_conf *conf)
{
	ray->camera_x = 2 * x / (double)conf->resx - 1;
	ray->dirx = conf->dirx + conf->planex * ray->camera_x;
	ray->diry = conf->diry + conf->planey * ray->camera_x;
	ray->mapx = (int)conf->posx;
	ray->mapy = (int)conf->posy;
	ray->delta_distx = sqrt(1 + (ray->diry * ray->diry)
			/ (ray->dirx * ray->dirx));
	ray->delta_disty = sqrt(1 + (ray->dirx * ray->dirx)
			/ (ray->diry * ray->diry));
	ray->hit = 0;
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->side_distx = (conf->posx - ray->mapx) * ray->delta_distx;
	}
	else
	{
		ray->stepx = 1;
		ray->side_distx = (ray->mapx + 1.0 - conf->posx) * ray->delta_distx;
	}
}

void	raycasting_2(t_ray *ray, t_conf *conf)
{
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->side_disty = (conf->posy - ray->mapy) * ray->delta_disty;
	}
	else
	{
		ray->stepy = 1;
		ray->side_disty = (ray->mapy + 1.0 - conf->posy) * ray->delta_disty;
	}
}

void	raycasting_3(t_ray *ray, t_conf *conf)
{
	while (ray->hit == 0)
	{
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx += ray->delta_distx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->side_disty += ray->delta_disty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (conf->map[ray->mapx][ray->mapy] == 1)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->mapx - conf->posx + (1 - ray->stepx) / 2)
			/ ray->dirx;
	else
		ray->perp_wall_dist = (ray->mapy - conf->posy + (1 - ray->stepy) / 2)
			/ ray->diry;
	if (ray->perp_wall_dist == 0)
		ray->perp_wall_dist = 1;
}

void	draw_texture(t_conf *conf, t_ray *ray, int x)
{
	t_wall	wall;
	int		i;
	int		tex_offset;

	set_wall_info(conf, ray, &wall);
	i = 0;
	while (i < conf->resy)
	{
		if (i < wall.draw.y_start)
			conf->img_data[i * conf->resx + x] = conf->ceil;
		else if (i > wall.draw.y_end)
			conf->img_data[i * conf->resx + x] = conf->floor;
		else
		{
			wall.tex_y = (int)wall.tex_pos;
			wall.tex_pos += wall.step;
			tex_offset = wall.tex->h * wall.tex_y + wall.tex_x;
			if (tex_offset > wall.tex->h * wall.tex->w)
				wall.color = 0x000000;
			else
				wall.color = (int)wall.tex->data[tex_offset];
			conf->img_data[i * conf->resx + x] = wall.color;
		}
		i++;
	}
}

void	draw_walls(t_conf *conf)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < conf->resx)
	{
		ft_memset(&ray, -1, sizeof(t_ray));
		raycasting_1(x, &ray, conf);
		raycasting_2(&ray, conf);
		raycasting_3(&ray, conf);
		conf->z_buffer[x] = ray.perp_wall_dist;
		draw_texture(conf, &ray, x);
		x++;
	}
}
