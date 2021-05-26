/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 01:30:26 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/26 14:21:30 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	exit_hook(t_conf *conf)
{
	free_config(conf);
	exit(0);
	return (0);
}

int	key_pressed_hook(int code, t_conf *conf)
{
	if (code == KEY_ESCAPE)
	{
		free_config(conf);
		exit(0);
	}
	if (code == KEY_A)
		conf->key_a = 1;
	if (code == KEY_D)
		conf->key_d = 1;
	if (code == KEY_S)
		conf->key_s = 1;
	if (code == KEY_W)
		conf->key_w = 1;
	if (code == KEY_LEFT)
		conf->key_left = 1;
	if (code == KEY_RIGHT)
		conf->key_right = 1;
	return (0);
}

int	key_released_hook(int code, t_conf *conf)
{
	if (code == KEY_A)
		conf->key_a = 0;
	if (code == KEY_D)
		conf->key_d = 0;
	if (code == KEY_S)
		conf->key_s = 0;
	if (code == KEY_W)
		conf->key_w = 0;
	if (code == KEY_LEFT)
		conf->key_left = 0;
	if (code == KEY_RIGHT)
		conf->key_right = 0;
	return (0);
}

int	loop_hook(t_conf *conf)
{
	int	change;

	change = move_forward(conf);
	change += move_backwards(conf);
	change += move_left(conf);
	change += move_right(conf);
	change += rotate_left(conf);
	change += rotate_right(conf);
	if (change)
		render(conf);
	return (0);
}

int	visibility_hook(t_conf *conf)
{
	mlx_put_image_to_window(conf->mlx, conf->window, conf->img, 0, 0);
	return (0);
}
