/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:49:05 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/04 17:21:56 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    init_kernel(t_kernel *kernel)
{
	kernel->device_id = NULL;
	kernel->context = NULL;
	kernel->command_queue = NULL;
	kernel->memobj = NULL;
	kernel->program = NULL;
	kernel->kernel = NULL;
	kernel->platform_id = NULL;
}

void	finalization_kernel(t_kernel *kernel)
{
	kernel->ret = clFlush(kernel->command_queue);
	if (kernel->ret != 0)
		ft_putstr("clFlush fail\n");
	kernel->ret = clFinish(kernel->command_queue);
	if (kernel->ret != 0)
		ft_putstr("clFinish fail\n");
	kernel->ret = clReleaseKernel(kernel->kernel);
	if (kernel->ret != 0)
		ft_putstr("clReleaseKernel fail\n");
	kernel->ret = clReleaseProgram(kernel->program);
	if (kernel->ret != 0)
		ft_putstr("clReleaseProgram fail\n");
	kernel->ret = clReleaseMemObject(kernel->memobj);
	if (kernel->ret != 0)
		ft_putstr("clReleaseMemObject fail\n");
	kernel->ret = clReleaseCommandQueue(kernel->command_queue);
	if (kernel->ret != 0)
		ft_putstr("clReleaseMemObject fail\n");
	kernel->ret = clReleaseContext(kernel->context);
	if (kernel->ret != 0)
		ft_putstr("clReleaseContext fail\n");
}

void	set_kernel_args(t_kernel *kernel, t_fractal *fractal)
{
	kernel->ret = clSetKernelArg(kernel->kernel, 0, sizeof(cl_mem), (void *)&kernel->memobj);
	kernel->ret = clSetKernelArg(kernel->kernel, 1, sizeof(int), &fractal->color);
	kernel->ret = clSetKernelArg(kernel->kernel, 2, sizeof(double), &fractal->real);
	kernel->ret = clSetKernelArg(kernel->kernel, 3, sizeof(double), &fractal->imag);
}

void     start_kernel(t_fractal *fractal)
{
	t_kernel    *kernel;
	char		string[MEM_SIZE];
	FILE		*fp;
	char		*fileName;
	char		*source_str;
	size_t		source_size;
	size_t		*global_work_size;

	fileName = "src/hello.cl";
	kernel = (t_kernel*)malloc(sizeof(t_kernel));
	global_work_size = (size_t*)malloc(sizeof(size_t));
	global_work_size[0] = 1000 * 1000 * 4;
	init_kernel(kernel);
	fp = fopen(fileName, "r");
	if (!fp)
	{
		fprintf(stderr, "Failed to load kernel.\n");
		exit(0);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);
	kernel->ret = clGetPlatformIDs(1, &kernel->platform_id, &kernel->ret_num_platforms);
	if (kernel->ret != 0)
		ft_putstr("clGetPlatformId fail\n");
	kernel->ret = clGetDeviceIDs(kernel->platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &kernel->device_id, &kernel->ret_num_devices);
	if (kernel->ret != 0)
		ft_putstr("clGetDeviceIDs fail\n");
	kernel->context = clCreateContext(NULL, 1, &kernel->device_id, NULL, NULL, &kernel->ret);
	if (kernel->ret != 0)
		ft_putstr("clCreateContext fail\n");
	kernel->command_queue = clCreateCommandQueue(kernel->context, kernel->device_id, 0, &kernel->ret);
	if (kernel->ret != 0)
		ft_putstr("clCreateCommandQueue\n");
	kernel->memobj = clCreateBuffer(kernel->context, CL_MEM_READ_WRITE,MEM_SIZE * sizeof(char), NULL, &kernel->ret);
	if (kernel->ret != 0)
		ft_putstr("clCreateBuffer\n");
	kernel->program = clCreateProgramWithSource(kernel->context, 1, (const char **)&source_str,
	(const size_t *)&source_size, &kernel->ret);
	if (kernel->ret != 0)
		ft_putstr("clCreateProgramWithSource\n");
	kernel->ret = clBuildProgram(kernel->program, 1, &kernel->device_id, NULL, NULL, NULL);
	if (kernel->ret != 0)
		ft_putstr("clBuildProgram fail\n");
	kernel->kernel = clCreateKernel(kernel->program, "hello", &kernel->ret);
	if (kernel->ret != 0)
		ft_putstr("clCreateKernel fail\n");
	set_kernel_args(kernel, fractal);	
	kernel->ret = clEnqueueNDRangeKernel(kernel->command_queue, kernel->kernel,
					1, NULL, global_work_size, NULL, 0, NULL, NULL);
	if (kernel->ret != 0)
		ft_putstr("clEnqueueNDRangeKernel fail\n");
	kernel->ret = clEnqueueReadBuffer(kernel->command_queue, kernel->memobj, CL_TRUE, 0,
				MEM_SIZE * sizeof(char),string, 0, NULL, NULL);
	if (kernel->ret != 0)
		ft_putstr("clEnqueueReadBuffer fail\n");
	puts(string);
	finalization_kernel(kernel);
	free(source_str);
}