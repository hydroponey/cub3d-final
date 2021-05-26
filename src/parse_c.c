/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 03:02:58 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/22 23:29:36 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ceil_error(char *message, t_ceil *data, t_conf *conf)
{
	free(data->value);
	free(data->sub);
	free(data->trim);
	if (data->rgb != NULL)
		ft_freetab(data->rgb, 1);
	exit_error(message, conf);
}

void	transform_c(t_ceil *data, t_conf *conf)
{
	int		count;
	int		rgb[3];

	count = 0;
	while (data->rgb[count] != NULL)
		count++;
	if (count != 3)
		ceil_error("Missing an RGB value for Ceil color.", data, conf);
	trim_values(data->rgb, conf);
	if (!is_numeric(data->rgb[0]) || !is_numeric(data->rgb[1])
		|| !is_numeric(data->rgb[2]))
		ceil_error("Ceil RGB values are not numeric.", data, conf);
	rgb[0] = ft_atoi_pos(data->rgb[0]);
	rgb[1] = ft_atoi_pos(data->rgb[1]);
	rgb[2] = ft_atoi_pos(data->rgb[2]);
	ft_freetab(data->rgb, 1);
	data->rgb = NULL;
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		ceil_error("Ceil RGB values are not between 0 and 255.", data, conf);
	conf->ceil = rgb[2] + (rgb[1] << 8) + (rgb[0] << 16);
}

void	parse_c(char *value, t_conf *conf)
{
	t_ceil	data;

	ft_bzero(&data, sizeof(t_ceil));
	data.value = value;
	if (count_commas(value) != 2)
		ceil_error("Ceil RGB value has a bad format.", &data, conf);
	data.sub = ft_substr(value, 2, ft_strlen(value) - 2);
	if (!data.sub)
		ceil_error("Ceil value is missing.", &data, conf);
	data.trim = ft_strtrim(data.sub, " \t");
	free(data.sub);
	data.sub = NULL;
	if (!data.trim)
		ceil_error("Ceil value is missing.", &data, conf);
	data.rgb = ft_split(data.trim, ',');
	free(data.trim);
	data.trim = NULL;
	if (!data.rgb)
		ceil_error("Malloc failed on ft_split for Ceil value.", &data, conf);
	transform_c(&data, conf);
}
