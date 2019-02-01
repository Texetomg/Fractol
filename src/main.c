/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:38:33 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/01 15:38:24 by bfalmer-         ###   ########.fr       */
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

void	drow_img(t_mlx_win *mlx_win, t_img *img)
{
	int			x;
	int			y;
	t_fractal	*fractal;

	y = 0;
	if (!(fractal = (t_fractal*)malloc(sizeof(t_fractal))))
		malloc_error();
	fractal->x0 = WDTH / 2;
	fractal->y0 = HGHT / 2;
	while(y < HGHT)
	{
		x = 0;
		while(x < WDTH)
		{
			*((int*)(img->addr_ptr) + x + y * WDTH) = mandelbrot(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_win->mlx_ptr, mlx_win->win_ptr, img->img_ptr, 0, 0);
}

void    window_init(char *av)
{
	t_img   	*img;
	t_mlx_win	*mlx_win;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		malloc_error();
	if (!(mlx_win = (t_mlx_win*)malloc(sizeof(t_mlx_win))))
		malloc_error();
	if (!(mlx_win->mlx_ptr = mlx_init()))
		mlx_win_error();
	if (!(mlx_win->win_ptr = mlx_new_window(mlx_win->mlx_ptr, WDTH, HGHT, av)))
		mlx_win_error();
	img->img_ptr = mlx_new_image(mlx_win->mlx_ptr, WDTH, HGHT);
	img->addr_ptr = mlx_get_data_addr(img->img_ptr,
					&(img->bpp), &(img->size_line), &(img->endian));
	img->bpp = img->bpp / 8;
	drow_img(mlx_win, img);
	mlx_loop(mlx_win->mlx_ptr);
}

int     main(int ac, char **av)
{
	check_ac_av(ac, av[1]);
	window_init(av[1]);
	return(0);
}