/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:55:39 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/10 21:36:36 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x0 = -2;
	fractal->y0 = 2;
	fractal->x1 = 2;
	fractal->y1 = -2;
	fractal->x_coord = 0;
	fractal->y_coord = 0;
	fractal->flag = 0;
	fractal->color = 16;
	fractal->iteration = 150;
	fractal->count_scroll = 0;
}

void	which_fractal(t_fractal *fractal, char *av)
{
	init_fractal(fractal);
	if (ft_strcmp(av, "mandelbrot") == 0)
		fractal->name = 'm';
	if (ft_strcmp(av, "julia") == 0)
		fractal->name = 'j';
	if (ft_strcmp(av, "burningship") == 0)
		fractal->name = 'b';
	if (ft_strcmp(av, "newton") == 0)
		fractal->name = 'n';
	if (ft_strcmp(av, "spider") == 0)
		fractal->name = 's';
}

void	init_kernel(t_kernel *kernel)
{
	kernel->device_id = NULL;
	kernel->context = NULL;
	kernel->command_queue = NULL;
	kernel->memobj = NULL;
	kernel->program = NULL;
	kernel->kernel = NULL;
	kernel->platform_id = NULL;
}
