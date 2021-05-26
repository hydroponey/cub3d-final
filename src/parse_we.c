/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_we.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 03:07:33 by asimoes           #+#    #+#             */
/*   Updated: 2021/04/21 23:23:19 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_we(char *value, t_conf *conf)
{
	char	*sub;
	char	*trim;

	sub = ft_substr(value, 3, ft_strlen(value) - 3);
	if (!sub)
		exit_error("Missing WE texture path.", conf);
	trim = ft_strtrim(sub, " \t");
	free(sub);
	if (!trim || ft_strlen(trim) == 0)
		exit_error("Missing WE texture path.", conf);
	conf->we_path = trim;
}
