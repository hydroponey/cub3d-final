/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 01:25:28 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/24 07:20:58 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define FOV 0.6

int	get_max_width(t_conf *conf)
{
	int		i;
	int		max_width;
	int		len;

	max_width = -1;
	i = 0;
	while (i < conf->map_lines)
	{
		len = ft_strlen(conf->text_map[i]);
		if (max_width < len)
			max_width = len;
		i++;
	}
	return (max_width);
}

void	add_map_line(t_conf *conf, char *line)
{
	int		old_size;
	int		new_size;

	old_size = sizeof(char *) * conf->map_lines;
	new_size = sizeof(char *) * (conf->map_lines + 1);
	conf->text_map = cube_realloc(conf->text_map, new_size, old_size);
	if (!conf->text_map)
	{
		free(line);
		exit_error("realloc error.", conf);
	}
	conf->text_map[conf->map_lines] = ft_strdup(line);
	if (!conf->text_map[conf->map_lines])
	{
		free(line);
		exit_error("strdup error.", conf);
	}
	conf->map_lines++;
}

void	set_start_dir(t_conf *conf, int x, int y, char c)
{
	if (x == 0 || y == 0)
		exit_error("Starting position can not be on a border.", conf);
	conf->map[x][y] = 0;
	conf->posy = y + 0.5;
	conf->posx = x + 0.5;
	if (c == 'N')
	{
		conf->dirx = -1;
		conf->planey = 0.66;
	}
	if (c == 'S')
	{
		conf->dirx = 1;
		conf->planey = -0.66;
	}
	if (c == 'E')
	{
		conf->diry = 1;
		conf->planex = 0.66;
	}
	if (c == 'W')
	{
		conf->diry = -1;
		conf->planex = -0.66;
	}
}

void	transform_line(t_conf *conf, int x)
{
	int		y;
	int		len;
	char	c;

	y = 0;
	ft_memset(conf->map[x], -1, sizeof(int) * conf->map_width);
	len = ft_strlen(conf->text_map[x]);
	while (y < len)
	{
		c = conf->text_map[x][y];
		if (c == ' ')
			conf->map[x][y] = -1;
		else if (c >= '0' && c <= '2')
			conf->map[x][y] = c - 48;
		else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			if (conf->start)
				exit_error("Multiple starting positions in map.", conf);
			set_start_dir(conf, x, y, c);
			conf->start = 1;
		}
		else
			exit_error("Unsupported character found in map.", conf);
		y++;
	}
}

void	transform_map(t_conf *conf)
{
	int	width;
	int	x;

	width = get_max_width(conf);
	conf->map_alloc_lines = 0;
	conf->map_width = width;
	conf->map_height = conf->map_lines;
	conf->map = (int **)malloc(sizeof(int *) * conf->map_lines);
	if (!conf->map)
		exit_error("Malloc error.", conf);
	x = 0;
	while (x < conf->map_lines)
	{
		conf->map[x] = malloc(sizeof(int) * width);
		if (!conf->map[x])
			exit_error("Malloc error.", conf);
		conf->map_alloc_lines++;
		transform_line(conf, x);
		x++;
	}
	if (conf->start == 0)
		exit_error("No starting position found.", conf);
}
