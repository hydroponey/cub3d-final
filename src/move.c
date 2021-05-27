/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 04:54:04 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/27 16:59:52 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_conf *conf)
{
	if (conf->key_w)
	{
		if (conf->map[(int)(conf->posx + conf->dirx
				* conf->move_speed)][(int)conf->posy] == 0)
			conf->posx += conf->dirx * conf->move_speed;
		if (conf->map[(int)conf->posx][(int)(conf->posy
			+ conf->diry * conf->move_speed)] == 0)
			conf->posy += conf->diry * conf->move_speed;
		return (1);
	}
	return (0);
}

int	move_backwards(t_conf *conf)
{
	if (conf->key_s)
	{
		if (conf->map[(int)(conf->posx - conf->dirx
				* conf->move_speed)][(int)conf->posy] == 0)
			conf->posx -= conf->dirx * conf->move_speed;
		if (conf->map[(int)conf->posx][(int)(conf->posy
			- conf->diry * conf->move_speed)] == 0)
			conf->posy -= conf->diry * conf->move_speed;
		return (1);
	}
	return (0);
}

int	move_left(t_conf *conf)
{
	if (conf->key_a)
	{
		if (conf->map[(int)(conf->posx - conf->diry
				* conf->move_speed)][(int)conf->posy] == 0)
			conf->posx -= conf->diry * conf->move_speed;
		if (conf->map[(int)conf->posx][(int)(conf->posy
			+ conf->dirx * conf->move_speed * 2)] == 0)
			conf->posy += conf->dirx * conf->move_speed;
		return (1);
	}
	return (0);
}

int	move_right(t_conf *conf)
{
	if (conf->key_d)
	{
		if (conf->map[(int)(conf->posx + conf->diry
				* conf->move_speed)][(int)conf->posy] == 0)
			conf->posx += conf->diry * conf->move_speed;
		if (conf->map[(int)conf->posx][(int)(conf->posy
			- conf->dirx * conf->move_speed)] == 0)
			conf->posy -= conf->dirx * conf->move_speed;
		return (1);
	}
	return (0);
}
