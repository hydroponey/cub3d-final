/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:46:50 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/22 23:26:26 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_left(t_conf *conf)
{
	double	old_dirx;
	double	old_planex;

	if (conf->key_left)
	{
		old_dirx = conf->dirx;
		conf->dirx = conf->dirx * cos(conf->rot_speed)
			- conf->diry * sin(conf->rot_speed);
		conf->diry = old_dirx * sin(conf->rot_speed)
			+ conf->diry * cos(conf->rot_speed);
		old_planex = conf->planex;
		conf->planex = conf->planex * cos(conf->rot_speed)
			- conf->planey * sin(conf->rot_speed);
		conf->planey = old_planex * sin(conf->rot_speed)
			+ conf->planey * cos(conf->rot_speed);
		return (1);
	}
	return (0);
}

int	rotate_right(t_conf *conf)
{
	double	old_dirx;
	double	old_planex;

	if (conf->key_right)
	{
		old_dirx = conf->dirx;
		conf->dirx = conf->dirx * cos(-conf->rot_speed)
			- conf->diry * sin(-conf->rot_speed);
		conf->diry = old_dirx * sin(-conf->rot_speed) + conf->diry
			* cos(-conf->rot_speed);
		old_planex = conf->planex;
		conf->planex = conf->planex * cos(-conf->rot_speed)
			- conf->planey * sin(-conf->rot_speed);
		conf->planey = old_planex * sin(-conf->rot_speed)
			+ conf->planey * cos(-conf->rot_speed);
		return (1);
	}
	return (0);
}
