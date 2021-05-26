/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 07:23:21 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/22 23:25:27 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

void	sort_sprites(int *order, int *distance, int count)
{
	int	i;
	int	tmp;
	int	change;

	i = 0;
	change = 0;
	while (i < (count - 1))
	{
		if (distance[order[i]] < distance[order[i + 1]])
		{
			tmp = order[i];
			order[i] = order[i + 1];
			order[i + 1] = tmp;
			change = 1;
		}
		i++;
	}
	if (change)
		sort_sprites(order, distance, count);
}

void	set_cur_sprite(t_sprite_data *sd, t_conf *conf, int i)
{
	sd->sprite_x = conf->sprites[sd->order[i]].x - conf->posx;
	sd->sprite_y = conf->sprites[sd->order[i]].y - conf->posy;
	sd->inv_det = 1.0 / (conf->planex * conf->diry - conf->dirx * conf->planey);
	sd->transform_x = sd->inv_det
		* (conf->diry * sd->sprite_x - conf->dirx * sd->sprite_y);
	sd->transform_y = sd->inv_det
		* (-conf->planey * sd->sprite_x + conf->planex * sd->sprite_y);
	sd->sprite_screen_x = (int)((conf->resx / 2)
			* (1 + sd->transform_x / sd->transform_y));
	sd->sprite_height = abs((int)(conf->resy / (sd->transform_y)));
	sd->draw_start_y = -sd->sprite_height / 2 + conf->resy / 2;
	if (sd->draw_start_y < 0)
		sd->draw_start_y = 0;
	sd->draw_end_y = sd->sprite_height / 2 + conf->resy / 2;
	if (sd->draw_end_y >= conf->resy)
		sd->draw_end_y = conf->resy - 1;
	sd->sprite_width = abs((int)(conf->resy / (sd->transform_y)));
	sd->draw_start_x = -sd->sprite_width / 2 + sd->sprite_screen_x;
	if (sd->draw_start_x < 0)
		sd->draw_start_x = 0;
	sd->draw_end_x = sd->sprite_width / 2 + sd->sprite_screen_x;
	if (sd->draw_end_x >= conf->resx)
		sd->draw_end_x = conf->resx - 1;
}

void	draw_sprite(t_sprite_data *sd, t_conf *conf, int j)
{
	int	k;

	if (sd->transform_y > 0 && j < conf->resx
		&& sd->transform_y < conf->z_buffer[j])
	{
		sd->tex_x = (j - (-sd->sprite_width / 2 + sd->sprite_screen_x))
			* conf->s.w / sd->sprite_width;
		k = sd->draw_start_y;
		while (k < sd->draw_end_y)
		{
			sd->d = k * 256 - conf->resy * 128 + sd->sprite_height * 128;
			sd->tex_y = ((sd->d * conf->s.h) / sd->sprite_height) / 256;
			if ((conf->s.w * sd->tex_y + sd->tex_x) < (conf->s.w * conf->s.h))
			{
				sd->color = conf->s.data[conf->s.w * sd->tex_y + sd->tex_x];
				if (sd->color != 0x000000 && sd->color != -16777216)
					conf->img_data[k * conf->resx + j] = sd->color;
			}
			k++;
		}
	}
}
