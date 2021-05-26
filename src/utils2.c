/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 03:52:39 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/23 17:24:48 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_commas(char *value)
{
	int	count;
	int	i;
	int	len;

	len = ft_strlen(value);
	count = 0;
	i = 0;
	while (i < len)
	{
		if (value[i] == ',')
			count++;
		i++;
	}
	return (count);
}

void	trim_values(char **data, t_conf *conf)
{
	int		i;
	char	*old;

	i = 0;
	while (data[i] != NULL)
	{
		old = data[i];
		data[i] = ft_strtrim(data[i], " \t");
		if (data[i] == NULL)
		{
			ft_freetab(data, 1);
			exit_error("Malloc error.", conf);
		}
		free(old);
		i++;
	}
}

void	*cube_realloc(void *ptr, size_t size, size_t ptrsize)
{
	void	*new;

	new = malloc(size);
	if (!new)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new, ptr, ptrsize);
		free(ptr);
	}
	return (new);
}

void	create_image(t_conf *conf)
{
	int		bpp;
	int		sl;
	int		endian;

	conf->img = mlx_new_image(conf->mlx, conf->resx, conf->resy);
	if (!conf->img)
		exit_error("mlx_new_image failed.", conf);
	conf->img_data = (int *)mlx_get_data_addr(conf->img, &bpp, &sl, &endian);
	if (!conf->img_data)
		exit_error("mlx_get_data_addr failed.", conf);
	conf->img_bpp = bpp;
}

void	map_check(char *trimmed, t_conf *conf)
{
	if (trimmed != NULL && trimmed[0] >= '0' && trimmed[0] <= '2')
	{
		free(trimmed);
		exit_error("Missing parameters before map.", conf);
	}
}
