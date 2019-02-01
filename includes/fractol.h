/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:24:42 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/01 15:52:26 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# define WDTH	1600
# define HGHT	1200

typedef struct  s_img
{
	void		*img_ptr;
	void		*addr_ptr;
	int			size_line;
	int			endian;
	int			bpp;
}               t_img;

typedef	struct 	s_mlx_win
{
	void    	*mlx_ptr;
	void    	*win_ptr;	
}				t_mlx_win;

typedef	struct 	s_fractal
{
	int			color;
	int			x0;
	int			y0;
	double		real;
	double		imag;
	double		c_real;
	double		c_imag;
	double		ex_real;
	double		ex_imag;
}				t_fractal;

void            arg_error(void);
void            malloc_error(void);
void            mlx_win_error(void);
int				mandelbrot(t_fractal *fractal, int x, int y);
void			drow_img(t_mlx_win *mlx_win, t_img *img);

#endif