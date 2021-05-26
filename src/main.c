/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 23:37:18 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/26 14:29:17 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_conf	conf;

	ft_bzero(&conf, sizeof(t_conf));
	conf.fd = -1;
	check_args(argc, argv, &conf);
	check_config(argv[1], &conf);
	init_game(&conf);
	conf.window = mlx_new_window(conf.mlx, conf.resx, conf.resy, "Cub3D");
	if (conf.window == NULL)
		exit_error("mlx_new_window failed", &conf);
	render(&conf);
	mlx_hook(conf.window, 33, (1L << 17), exit_hook, &conf);
	mlx_hook(conf.window, 2, (1L << 0), key_pressed_hook, &conf);
	mlx_hook(conf.window, 3, (1L << 1), key_released_hook, &conf);
	mlx_hook(conf.window, 15, (1L << 16), visibility_hook, &conf);
	mlx_loop_hook(conf.mlx, loop_hook, &conf);
	mlx_loop(conf.mlx);
	return (0);
}
