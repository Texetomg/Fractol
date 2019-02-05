/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:38:33 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/05 18:37:21 by bfalmer-         ###   ########.fr       */
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

void    window_init(char *av)
{
	t_img   	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		error("malloc error");
	if (!(img->mlx_ptr = mlx_init()))
		error("mlx init error");
	if (!(img->win_ptr = mlx_new_window(img->mlx_ptr, WDTH, HGHT, av)))
		error("win init error");
	img->img_ptr = mlx_new_image(img->mlx_ptr, WDTH, HGHT);
	img->addr_ptr = mlx_get_data_addr(img->img_ptr,
					&(img->bpp), &(img->size_line), &(img->endian));
	img->bpp = img->bpp / 8;
	drow_img(img);
	mlx_loop(img->mlx_ptr);
}

int     main(int ac, char **av)
{
	check_ac_av(ac, av[1]);
	window_init(av[1]);
	return(0);
}