/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 03:06:58 by asimoes           #+#    #+#             */
/*   Updated: 2021/04/21 23:23:11 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_s(char *value, t_conf *conf)
{
	char	*sub;
	char	*trim;

	sub = ft_substr(value, 2, ft_strlen(value) - 2);
	if (!sub)
		exit_error("Missing S texture path.", conf);
	trim = ft_strtrim(sub, " \t");
	free(sub);
	if (!trim || ft_strlen(trim) == 0)
		exit_error("Missing S texture path.", conf);
	conf->s_path = trim;
}
