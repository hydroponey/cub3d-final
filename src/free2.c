/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 04:58:00 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/26 15:41:59 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef LINUX

void	free_config(t_conf *conf)
{
	int	i;

	free_paths(conf);
	free_textures(conf);
	if (conf->mlx != NULL && conf->window != NULL)
		mlx_destroy_window(conf->mlx, conf->window);
	i = 0;
	while (i < conf->map_height)
	{
		if (conf->map != NULL && i < conf->map_alloc_lines)
			free(conf->map[i]);
		if (conf->text_map != NULL)
			free(conf->text_map[i]);
		i++;
	}
	free(conf->sprites);
	free(conf->z_buffer);
	free(conf->map);
	free(conf->text_map);
	if (conf->mlx != NULL)
	{
		mlx_destroy_display(conf->mlx);
		free(conf->mlx);
	}
}

#else

void	free_config(t_conf *conf)
{
	int	i;

	free_paths(conf);
	free_textures(conf);
	if (conf->mlx != NULL && conf->window != NULL)
		mlx_destroy_window(conf->mlx, conf->window);
	i = 0;
	while (i < conf->map_height)
	{
		if (conf->map != NULL && i < conf->map_alloc_lines)
			free(conf->map[i]);
		if (conf->text_map != NULL)
			free(conf->text_map[i]);
		i++;
	}
	free(conf->sprites);
	free(conf->z_buffer);
	free(conf->map);
	free(conf->text_map);
	if (conf->mlx != NULL)
	{
		free(conf->mlx);
	}
}

#endif
