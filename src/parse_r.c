/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 02:30:23 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/26 14:16:26 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	res_error(char *err, t_res_data *res, t_conf *conf)
{
	free(res->value);
	free(res->sub);
	free(res->trim);
	ft_freetab(res->split, 1);
	exit_error(err, conf);
}

void	check_values(char *x, char *y, t_res_data *res, t_conf *conf)
{
	if (!is_numeric(x) || !is_numeric(y))
		res_error("Resolution values are not numeric.", res, conf);
	conf->resx = ft_atoi_pos(x);
	conf->resy = ft_atoi_pos(y);
	if (conf->resx < 0 || conf->resy < 0)
	{
		conf->resx = 2147483647;
		conf->resy = 2147483647;
	}
	if (conf->resx == 0 || conf->resy == 0)
		res_error("Resolution values can not be zeros.", res, conf);
}

void	parse_r(char *value, t_conf *conf)
{
	t_res_data	res;
	int			count;

	res.value = value;
	res.sub = ft_substr(value, 2, ft_strlen(value) - 2);
	if (!res.sub)
		res_error("Resolution values are missing.", &res, conf);
	res.trim = ft_strtrim(res.sub, " \t");
	free(res.sub);
	if (!res.trim)
		res_error("Resolution values are missing.", &res, conf);
	res.split = ft_split(res.trim, ' ');
	free(res.trim);
	if (!res.split)
		res_error("Resolution values are not separated by space.", &res, conf);
	count = 0;
	while (res.split[count] != NULL)
		count++;
	if (count != 2)
		res_error("Wrong number of values for resolution.", &res, conf);
	check_values(res.split[0], res.split[1], &res, conf);
	ft_freetab(res.split, 1);
}
