/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:46:43 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/22 21:00:36 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_maplist(t_pos *list)
{
	t_pos	*cur;
	t_pos	*tmp;

	cur = list;
	while (cur != NULL)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}

void	add_last(t_pos *list, t_pos *item)
{
	t_pos	*cur;

	cur = list;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = item;
}

t_pos	*create_mapitem(int x, int y, t_conf *conf)
{
	t_pos	*new;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (!new)
	{
		free_maplist(conf->maplist_start);
		free_map(conf->map_copy, conf->map_lines);
		exit_error("Failed to malloc new in create_mapitem.", conf);
	}
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

void	check_p(t_pos *cur, int **map, t_pos *start, t_conf *conf)
{
	if (cur->x == 0 || cur->y == 0 || cur->x == conf->map_lines - 1
		|| cur->y == conf->map_width - 1)
	{
		free_maplist(start);
		free_map(map, conf->map_lines);
		exit_error("Map is not closed.", conf);
	}
	if (map[cur->x - 1][cur->y] == -1 || map[cur->x + 1][cur->y] == -1
	|| map[cur->x][cur->y + 1] == -1 || map[cur->x][cur->y - 1] == -1)
	{
		free_maplist(start);
		free_map(map, conf->map_lines);
		exit_error("Map is not closed.", conf);
	}
	map[cur->x][cur->y] = TILE_CHECKED;
	conf->map_copy = map;
	conf->maplist_start = start;
	add_last(start, create_mapitem(cur->x - 1, cur->y - 1, conf));
	add_last(start, create_mapitem(cur->x - 1, cur->y + 1, conf));
	add_last(start, create_mapitem(cur->x + 1, cur->y - 1, conf));
	add_last(start, create_mapitem(cur->x + 1, cur->y + 1, conf));
	add_last(start, create_mapitem(cur->x - 1, cur->y, conf));
	add_last(start, create_mapitem(cur->x + 1, cur->y, conf));
	add_last(start, create_mapitem(cur->x, cur->y - 1, conf));
	add_last(start, create_mapitem(cur->x, cur->y + 1, conf));
}
