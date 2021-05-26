/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 00:10:19 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/22 21:32:37 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_sprites(t_conf *conf)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	while (x < conf->map_height)
	{
		y = 0;
		while (y < conf->map_width)
		{
			if (conf->map[x][y] == 2)
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

void	save_sprites(t_conf *conf)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	i = 0;
	while (x < conf->map_height)
	{
		y = 0;
		while (y < conf->map_width)
		{
			if (conf->map[x][y] == 2)
			{
				conf->sprites[i].x = x + 0.5;
				conf->sprites[i].y = y + 0.5;
				i++;
			}
			y++;
		}
		x++;
	}
}

void	setup_sprites(t_sprite_data *sd, t_conf *conf)
{
	int				i;

	sd->order = (int *)malloc(sizeof(int) * conf->sprites_count);
	if (!sd->order)
		exit_error("Malloc error in setup_sprites.", conf);
	ft_memset(sd->order, 0, sizeof(int) * conf->sprites_count);
	sd->distance = (int *)malloc(sizeof(int) * conf->sprites_count);
	if (!sd->distance)
		exit_error("Malloc error in setup_sprites.", conf);
	ft_memset(sd->distance, 0, sizeof(int) * conf->sprites_count);
	i = 0;
	while (i < conf->sprites_count)
	{
		sd->order[i] = i;
		sd->distance[i] = ((conf->posx - conf->sprites[i].x) * (conf->posx
					- conf->sprites[i].x) + (conf->posy - conf->sprites[i].y)
				* (conf->posy - conf->sprites[i].y));
		i++;
	}
}

void	draw_sprites(t_conf *conf)
{
	int				i;
	int				j;
	t_sprite_data	sd;

	setup_sprites(&sd, conf);
	sort_sprites(sd.order, sd.distance, conf->sprites_count);
	i = 0;
	while (i < conf->sprites_count)
	{
		set_cur_sprite(&sd, conf, i);
		j = sd.draw_start_x;
		while (j < sd.draw_end_x)
			draw_sprite(&sd, conf, j++);
		i++;
	}
	free(sd.order);
	free(sd.distance);
}
