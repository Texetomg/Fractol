/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:24:42 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/06 19:51:28 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# ifdef __APPLE__
# include <OpenCL/opencl.h>
# else
# include <CL/cl.h>
# endif
# define WDTH	1000
# define HGHT	1000
# define SIZE	WDTH*HGHT*sizeof(int)
# define MAX_SOURCE_SIZE (0x100000)

typedef	struct			s_fractal
{
	void    			*mlx_ptr;
	void    			*win_ptr;
	void				*img_ptr;
	void				*addr_ptr;
	int					size_line;
	int					endian;
	int					bpp;
	double				x0;
	double				y0;
	double				x1;
	double				y1;
	double				x_coord;
	double				y_coord;
	int					iteration;
	char				name;
	int					flag;
}						t_fractal;

typedef struct			s_kernel
{
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_mem				memobj;
	cl_program 			program;
	cl_kernel			kernel;
	cl_platform_id		platform_id;
	cl_uint				ret_num_devices;
	cl_uint				ret_num_platforms;
	cl_int				ret;
}						t_kernel;

void            		error(char *text);
int						mandelbrot(t_fractal *fractal, int x, int y);
void					drow_img(t_fractal *fractal);
void     				start_kernel(t_kernel *kernel, t_fractal *fractal);
void					hook(t_fractal *fractal);
int						key_press(int key);
int						mouse_hook(int key, int x, int y, t_fractal *fractal);
int						mouse_move(int x, int y, t_fractal *fractal);
#endif