/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 00:45:23 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/24 08:10:34 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_screenshot(void *data, int size, t_conf *conf)
{
	int		fd;
	int		written;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		free(data);
		exit_error("Failed to create screenshot.bmp", conf);
	}
	written = write(fd, data, size);
	if (written < 0)
	{
		free(data);
		exit_error("Failed to write screenshot.bmp", conf);
	}
	free(data);
	close(fd);
}

void	exit_screenshot(t_conf *conf)
{
	char		*bmp;
	int			fd;
	int			size;

	size = conf->resx * conf->resy * conf->img_bpp / 8 + 54;
	bmp = (char *)malloc(sizeof(char) * size);
	if (!bmp)
		exit_error("Malloc error.", conf);
	ft_bzero(bmp, size);
	ft_memcpy(&bmp[0], "BM", 2);
	fd = 54;
	ft_memcpy(&bmp[10], &fd, 4);
	fd = 40;
	ft_memcpy(&bmp[14], &fd, 4);
	ft_memcpy(&bmp[18], &conf->resx, 4);
	fd = -conf->resy;
	ft_memcpy(&bmp[22], &fd, 4);
	fd = 1;
	ft_memcpy(&bmp[26], &fd, 2);
	ft_memcpy(&bmp[28], &conf->img_bpp, 2);
	ft_memcpy(&bmp[54], conf->img_data, size - 54);
	write_screenshot(bmp, size, conf);
	free_config(conf);
	exit(0);
}
