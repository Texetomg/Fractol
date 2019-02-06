/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:38:33 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/06 16:04:36 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    check_ac_av(int ac, char *av)
{
	if (ac != 2)
		error("Usage: <name> [mandelbrot/julia/]");
	if (ft_strcmp(av, "mandelbrot") != 0 && ft_strcmp(av, "julia") !=0)
		error("Usage: <name> [mandelbrot/julia/]");
}

void	init_fractal(t_fractal *fractal)
{
	fractal->x0 = -1;
	fractal->y0 = 1;
	fractal->x1 = 1;
	fractal->y1 = -1;
}

void    window_init(char *av)
{
	t_fractal	*fractal;

	if (!(fractal = (t_fractal*)malloc(sizeof(t_fractal))))
		error("malloc error");
	if (!(fractal->mlx_ptr = mlx_init()))
		error("mlx init error");
	if (!(fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WDTH, HGHT, av)))
		error("win init error");
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WDTH, HGHT);
	fractal->addr_ptr = mlx_get_data_addr(fractal->img_ptr,
					&(fractal->bpp), &(fractal->size_line), &(fractal->endian));
	fractal->bpp = fractal->bpp / 8;
	init_fractal(fractal);
	drow_img(fractal);
	hook(fractal);
	mlx_loop(fractal->mlx_ptr);
}

int     main(int ac, char **av)
{
	check_ac_av(ac, av[1]);
	window_init(av[1]);
	return(0);
}