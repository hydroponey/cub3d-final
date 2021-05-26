/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 07:42:57 by asimoes           #+#    #+#             */
/*   Updated: 2021/04/21 23:23:24 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_conf *conf)
{
	draw_walls(conf);
	draw_sprites(conf);
	mlx_put_image_to_window(conf->mlx, conf->window, conf->img, 0, 0);
}
