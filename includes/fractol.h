/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:24:42 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/30 18:46:20 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# define WDTH	1200
# define HGHT	900

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
	int		c;
	int		z0;
	int		z1;
	int		x;
	int		y;	
}				t_fractal;


void            arg_error(void);
void            malloc_error(void);
void            mlx_win_error(void);

#endif