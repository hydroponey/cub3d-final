/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:13:24 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/22 21:00:18 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(t_conf *conf, int **map, t_pos *start)
{
	t_pos	*cur;

	cur = start;
	while (cur != NULL)
	{
		if (cur->x < 0 || cur->y < 0 || cur->x >= conf->map_lines
			|| cur->y >= conf->map_width)
		{
			cur = cur->next;
			continue ;
		}
		if (map[cur->x][cur->y] == 0 || map[cur->x][cur->y] == 2)
			check_p(cur, map, start, conf);
		cur = cur->next;
	}
}

void	free_map(int **map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	**copy_map(t_conf *conf)
{
	int	**map_copy;
	int	i;
	int	j;

	map_copy = (int **)malloc(sizeof(int *) * conf->map_lines);
	if (!map_copy)
		exit_error("Failed to malloc map copy.", conf);
	i = 0;
	while (i < conf->map_lines)
	{
		map_copy[i] = (int *)malloc(sizeof(int) * conf->map_width);
		if (!map_copy[i])
			exit_error("Map copy malloc failed.", conf);
		j = 0;
		while (j < conf->map_width)
		{
			map_copy[i][j] = conf->map[i][j];
			j++;
		}
		i++;
	}
	return (map_copy);
}

void	check_map(t_conf *conf)
{
	t_pos	*start;
	int		**map_copy;

	start = (t_pos *)malloc(sizeof(t_pos));
	if (!start)
		exit_error("Failed to malloc t_pos in check_map.", conf);
	start->x = (int)conf->posx;
	start->y = (int)conf->posy;
	start->next = NULL;
	map_copy = copy_map(conf);
	flood_fill(conf, map_copy, start);
	free_maplist(start);
	free_map(map_copy, conf->map_lines);
}
