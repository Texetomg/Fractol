/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:35:40 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/30 12:54:35 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void    arg_error(void)
{
	ft_putstr("Usage: <name> [mandelbrot/julia/]\n");
	exit(0);
}

void    malloc_error(void)
{
	ft_putstr("malloc error\n");
	exit(0);
}

void    mlx_win_error(void)
{
	ft_putstr("mlx/win error\n");
	exit(0);
}
