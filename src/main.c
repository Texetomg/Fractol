/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:38:33 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/30 12:57:48 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    check_ac_av(int ac, char *av)
{
	if (ac != 2)
		arg_error();
	if (ft_strcmp(av, "mandelbrot") != 0 && ft_strcmp(av, "julia") !=0)
		arg_error();
}

void    window_init(char *av)
{
	t_mlx_win   *mlx_win;

	if (!(mlx_win = (t_mlx_win*)malloc(sizeof(t_mlx_win))))
		malloc_error();
	if (!(mlx_win->mlx = mlx_init()))
		 mlx_win_error();
	if (!(mlx_win->win = mlx_new_window(mlx_win->mlx, 1200, 900, av)))
		 mlx_win_error();
	mlx_loop(mlx_win->mlx);
}

int     main(int ac, char **av)
{
	check_ac_av(ac, av[1]);
	window_init(av[1]);
	return(0);
}