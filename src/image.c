/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:45:08 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/04 17:17:29 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	drow_img(t_img *img)
{
	t_fractal	*fractal;
	if (!(fractal = (t_fractal*)malloc(sizeof(t_fractal))))
		malloc_error();
	start_kernel(fractal);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
}
