/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:49:05 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/11 15:43:26 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	finalization_kernel(t_kernel *kernel, char *string)
{
	free(string);
	kernel->ret |= clFlush(kernel->command_queue);
	kernel->ret |= clFinish(kernel->command_queue);
	kernel->ret |= clReleaseKernel(kernel->kernel);
	kernel->ret |= clReleaseProgram(kernel->program);
	kernel->ret |= clReleaseMemObject(kernel->memobj);
	kernel->ret |= clReleaseCommandQueue(kernel->command_queue);
	kernel->ret |= clReleaseContext(kernel->context);
	if (kernel->ret != 0)
		error("finalization_kernel error");
}

void	set_kernel_args(t_kernel *kernel, t_fractal *fractal)
{
	kernel->ret |= clSetKernelArg(kernel->kernel, 0,
		sizeof(cl_mem), &(kernel->memobj));
	kernel->ret |= clSetKernelArg(kernel->kernel, 1,
		sizeof(double), &(fractal->x0));
	kernel->ret |= clSetKernelArg(kernel->kernel, 2,
		sizeof(double), &(fractal->y0));
	kernel->ret |= clSetKernelArg(kernel->kernel, 3,
		sizeof(double), &(fractal->x1));
	kernel->ret |= clSetKernelArg(kernel->kernel, 4,
		sizeof(double), &(fractal->y1));
	kernel->ret |= clSetKernelArg(kernel->kernel, 5,
		sizeof(char), &(fractal->name));
	kernel->ret |= clSetKernelArg(kernel->kernel, 6,
		sizeof(double), &(fractal->x_coord));
	kernel->ret |= clSetKernelArg(kernel->kernel, 7,
		sizeof(double), &(fractal->y_coord));
	kernel->ret |= clSetKernelArg(kernel->kernel, 8,
		sizeof(double), &(fractal->iteration));
	kernel->ret |= clSetKernelArg(kernel->kernel, 9,
		sizeof(double), &(fractal->color));
	if (kernel->ret != 0)
		error("set_kernel_args error");
}

void	set_components_kernel2(t_kernel *kernel, char *source_str,
	size_t source_size)
{
	kernel->program = clCreateProgramWithSource(kernel->context, 1,
		(const char **)&source_str,
		(const size_t *)&source_size, &(kernel->ret));
	if (kernel->ret != 0)
		error("set_components_kernel2 error");
	kernel->ret |= clBuildProgram(kernel->program,
		1, &(kernel->device_id), NULL, NULL, NULL);
	kernel->kernel = clCreateKernel(kernel->program,
		"fractals", &(kernel->ret));
	if (kernel->ret != 0)
		error("set_components_kernel2 error");
}

void	set_components_kernel(t_kernel *kernel, char *source_str,
	size_t source_size)
{
	kernel->ret |= clGetPlatformIDs(1,
		&(kernel->platform_id), &(kernel->ret_num_platforms));
	kernel->ret |= clGetDeviceIDs(kernel->platform_id, CL_DEVICE_TYPE_GPU,
		1, &(kernel->device_id), &(kernel->ret_num_devices));
	kernel->context = clCreateContext(NULL,
		1, &(kernel->device_id), NULL, NULL, &(kernel->ret));
	if (kernel->ret != 0)
		error("set_components_kernel error");
	kernel->command_queue = clCreateCommandQueue(kernel->context,
		kernel->device_id, 0, &(kernel->ret));
	if (kernel->ret != 0)
		error("set_components_kernel error");
	kernel->memobj = clCreateBuffer(kernel->context,
		CL_MEM_READ_WRITE, SIZE, NULL, &(kernel->ret));
	if (kernel->ret != 0)
		error("set_components_kernel error");
	set_components_kernel2(kernel, source_str, source_size);
}

void	start_kernel(t_kernel *kernel, t_fractal *fractal)
{
	char		*string;
	int			fd;
	char		*source_str;
	size_t		source_size;
	size_t		global_work_size;

	string = ft_strnew(SIZE);
	global_work_size = WDTH * HGHT;
	init_kernel(kernel);
	fd = open("src/kernel.cl", O_RDONLY);
	if (!(source_str = (char*)malloc(MAX_SOURCE_SIZE)))
		error("malloc error");
	source_size = read(fd, source_str, MAX_SOURCE_SIZE);
	close(fd);
	set_components_kernel(kernel, source_str, source_size);
	set_kernel_args(kernel, fractal);
	kernel->ret |= clEnqueueNDRangeKernel(kernel->command_queue,
		kernel->kernel, 1, NULL, &global_work_size, NULL, 0, NULL, NULL);
	kernel->ret |= clEnqueueReadBuffer(kernel->command_queue,
		kernel->memobj, CL_TRUE, 0, SIZE, string, 0, NULL, NULL);
	if (kernel->ret != 0)
		error("NDRange or ReadBuffer error");
	ft_memcpy(fractal->addr_ptr, string, SIZE);
	finalization_kernel(kernel, string);
	free(source_str);
}
