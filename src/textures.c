/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:49:54 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/22 21:26:03 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_conf *conf)
{
	conf->no.img = mlx_xpm_file_to_image(conf->mlx, conf->no_path,
			&conf->no.h, &conf->no.w);
	if (!conf->no.img)
		exit_error("Failed to load NO texture.", conf);
	conf->so.img = mlx_xpm_file_to_image(conf->mlx, conf->so_path,
			&conf->so.h, &conf->so.w);
	if (!conf->so.img)
		exit_error("Failed to load SO texture.", conf);
	conf->ea.img = mlx_xpm_file_to_image(conf->mlx, conf->ea_path,
			&conf->ea.w, &conf->ea.h);
	if (!conf->ea.img)
		exit_error("Failed to load EA texture.", conf);
	conf->we.img = mlx_xpm_file_to_image(conf->mlx, conf->we_path,
			&conf->we.h, &conf->we.w);
	if (!conf->we.img)
		exit_error("Failed to load WE texture.", conf);
	conf->s.img = mlx_xpm_file_to_image(conf->mlx, conf->s_path,
			&conf->s.h, &conf->s.w);
	if (!conf->s.img)
		exit_error("Failed to load S texture.", conf);
}

void	get_textures_addr(t_conf *conf)
{
	conf->no.data = (int *)mlx_get_data_addr(conf->no.img, &conf->no.bpp,
			&conf->no.sl, &conf->no.endian);
	conf->so.data = (int *)mlx_get_data_addr(conf->so.img, &conf->so.bpp,
			&conf->so.sl, &conf->so.endian);
	conf->ea.data = (int *)mlx_get_data_addr(conf->ea.img, &conf->ea.bpp,
			&conf->ea.sl, &conf->ea.endian);
	conf->we.data = (int *)mlx_get_data_addr(conf->we.img, &conf->we.bpp,
			&conf->we.sl, &conf->we.endian);
	conf->s.data = (int *)mlx_get_data_addr(conf->s.img, &conf->s.bpp,
			&conf->s.sl, &conf->s.endian);
}
