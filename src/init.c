/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:49:15 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/22 23:32:28 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_sprites(t_conf *conf)
{
	conf->sprites_count = count_sprites(conf);
	conf->sprites = (t_sprite *)malloc(sizeof(t_sprite) * conf->sprites_count);
	if (!conf->sprites)
		exit_error("Sprites array malloc failed.", conf);
	conf->z_buffer = (double *)malloc(sizeof(double) * conf->resx);
	if (!conf->z_buffer)
		exit_error("Failed to malloc z_buffer.", conf);
	save_sprites(conf);
}

void	init_game(t_conf *conf)
{
	int		h;
	int		w;

	conf->mlx = mlx_init();
	if (conf->mlx == NULL)
		exit_error("mlx_init failed", conf);
	mlx_get_screen_size(conf->mlx, &w, &h);
	if (conf->resx > w || conf->resy > h)
	{
		conf->resx = w;
		conf->resy = h;
	}
	conf->move_speed = 0.003 * (conf->resx * conf->resy) / (640 * 480);
	conf->rot_speed = 0.003 * (conf->resx * conf->resy) / (640 * 480);
	load_textures(conf);
	get_textures_addr(conf);
	create_image(conf);
	init_sprites(conf);
	if (conf->save)
	{
		draw_walls(conf);
		draw_sprites(conf);
		exit_screenshot(conf);
	}
}
