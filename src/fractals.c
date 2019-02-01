/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:43:24 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/01 15:43:54 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_fractal *fractal, int x, int y)
{
	int			i;

	i = 0;
	fractal->color = 0xFFFFFF;
	fractal->c_real = ((double)(x - fractal->x0)) / (WDTH / 5);
	fractal->c_imag = ((double)(fractal->y0 - y)) / (HGHT / 5);
	fractal->real = 0;
	fractal->imag = 0;
	while (i < 250 && (fractal->real * fractal->real + fractal->imag * fractal->imag) <= 4)
	{
		fractal->ex_real = fractal->real * fractal->real - fractal->imag * fractal->imag + fractal->c_real;
		fractal->ex_imag = 2 * fractal->real * fractal->imag + fractal->c_imag;
		fractal->real = fractal->ex_real;
		fractal->imag = fractal->ex_imag;
		i++;
		fractal->color = fractal->color - 470 * 470;
	}
	return (fractal->color);
}
