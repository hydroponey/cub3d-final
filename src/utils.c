/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:43:25 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/23 17:25:57 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *message, t_conf *conf)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	if (conf != NULL)
		free_config(conf);
	exit(EXIT_FAILURE);
}

int	ft_atoi_pos(const char *str)
{
	unsigned int	i;
	int				number;
	int				check;

	i = 0;
	number = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = number * 10 + str[i] - '0';
		if (check < 0)
			return (-1);
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number);
}

int	is_numeric(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (!ft_isdigit(str[i--]))
			return (0);
	}
	return (1);
}

char	*trim_helper(char *str, char *charset, t_conf *conf)
{
	char	*trimmed;

	trimmed = ft_strtrim(str, charset);
	if (!trimmed)
	{
		free(str);
		exit_error("Malloc error.", conf);
	}
	return (trimmed);
}
