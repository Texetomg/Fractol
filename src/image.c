/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:45:08 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/06 16:03:46 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	drow_img(t_fractal *fractal)
{
	t_kernel	*kernel;

	kernel = (t_kernel*)malloc(sizeof(t_kernel));
	/*free*/
	start_kernel(kernel, fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img_ptr, 0, 0);
}
