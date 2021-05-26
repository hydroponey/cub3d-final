/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:41:09 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/23 17:28:20 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "cub3d.h"

void	error_double_param(int param, char *line, t_conf *conf)
{
	free(line);
	if (param == PARAM_R)
		exit_error("Multiple resolution lines in configuration file.", conf);
	if (param == PARAM_C)
		exit_error("Multiple ceil color lines in configuration file", conf);
	if (param == PARAM_EA)
		exit_error("Multiple east texture lines in configuration file", conf);
	if (param == PARAM_F)
		exit_error("Multiple floor color lines in configuration file", conf);
	if (param == PARAM_NO)
		exit_error("Multiple north texture lines in configuration file", conf);
	if (param == PARAM_S)
		exit_error("Multiple sprite texture lines in configuration file", conf);
	if (param == PARAM_SO)
		exit_error("Multiple south texture lines in configuration file", conf);
	if (param == PARAM_WE)
		exit_error("Multiple west texture lines in configuration file", conf);
}

void	check_param(int param, char *value, t_conf *conf)
{
	if (param == PARAM_R)
		parse_r(value, conf);
	if (param == PARAM_C)
		parse_c(value, conf);
	if (param == PARAM_EA)
		parse_ea(value, conf);
	if (param == PARAM_F)
		parse_f(value, conf);
	if (param == PARAM_NO)
		parse_no(value, conf);
	if (param == PARAM_S)
		parse_s(value, conf);
	if (param == PARAM_SO)
		parse_so(value, conf);
	if (param == PARAM_WE)
		parse_we(value, conf);
}

int	is_param(char **params, char *line, int *check, t_conf *conf)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (ft_strncmp(params[i], line, ft_strlen(params[i])) == 0)
		{
			if (check[i] != 0)
				error_double_param(i, line, conf);
			check_param(i, line, conf);
			check[i] = 1;
			return (1);
		}
		i++;
	}
	if (ft_strlen(line) > 0)
	{
		free(line);
		exit_error("Unknown parameter or no value.", conf);
	}
	return (0);
}

int	check_params(int fd, char **params, t_conf *conf)
{
	int		ret;
	char	*line;
	char	*trimmed;
	int		params_double_check[8];
	int		params_read;

	params_read = 0;
	ft_bzero(&params_double_check, sizeof(int) * 8);
	ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		trimmed = trim_helper(line, " \t", conf);
		free(line);
		map_check(trimmed, conf);
		params_read += is_param(params, trimmed, params_double_check, conf);
		free(trimmed);
		if (params_read == 8 || ret == 0)
			break ;
		ret = get_next_line(fd, &line);
	}
	if (params_read != 8)
		return (1);
	return (0);
}

void	set_params_headers(char **params)
{
	params[0] = "R ";
	params[1] = "NO ";
	params[2] = "SO ";
	params[3] = "WE ";
	params[4] = "EA ";
	params[5] = "S ";
	params[6] = "F ";
	params[7] = "C ";
}
