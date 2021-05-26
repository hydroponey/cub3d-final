/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 07:13:53 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/22 23:29:04 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line(t_conf *conf, char *line)
{
	char	*trimmed;
	int		len;

	trimmed = ft_strtrim(line, " \t");
	if (!trimmed)
	{
		free(line);
		exit_error("Malloc error in check_line.", conf);
	}
	len = ft_strlen(trimmed);
	free(trimmed);
	if (len > 0)
		add_map_line(conf, line);
}

void	parse_map(int fd, t_conf *conf)
{
	int		ret;
	char	*line;

	ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		check_line(conf, line);
		free(line);
		if (ret == 0 || ret == -1)
			break ;
		ret = get_next_line(fd, &line);
	}
	transform_map(conf);
	check_map(conf);
}
