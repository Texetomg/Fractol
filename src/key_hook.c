/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:43:29 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/06 20:18:51 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_press(int key, t_fractal *fractal)
{
    if (key == 91)
        fractal->recolor = fractal->recolor + 10000;
	if (key == 53)
		exit(1);
    mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	drow_img(fractal);
	return(0);
}