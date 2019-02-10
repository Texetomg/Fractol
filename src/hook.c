/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:15:35 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/10 16:34:52 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_close(t_fractal *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	hook(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, 2, 0, key_press, fractal);
	mlx_hook(fractal->win_ptr, 4, 0, mouse_hook, fractal);
	mlx_hook(fractal->win_ptr, 6, 0, mouse_move, fractal);
	mlx_hook(fractal->win_ptr, 17, 0, ft_close, fractal);
}
