/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:38:33 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/30 20:04:52 by bfalmer-         ###   ########.fr       */
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

void	drow_mandelbrot(t_mlx_win mlx_win, t_img img)
{
	t_fractal	*frac;

	if (!(frac = (t_fractal*)malloc(sizeof(t_fractal))))
		malloc_error();
		//
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
	draw_mandelbrot(mlx_win, img);
	mlx_loop(mlx_win->mlx_ptr);
}

int     main(int ac, char **av)
{
	check_ac_av(ac, av[1]);
	window_init(av[1]);
	return(0);
}