/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:49:05 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/05 18:52:01 by bfalmer-         ###   ########.fr       */
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
		error("clFlush fail\n");
	kernel->ret = clFinish(kernel->command_queue);
	if (kernel->ret != 0)
		error("clFinish fail\n");
	kernel->ret = clReleaseKernel(kernel->kernel);
	if (kernel->ret != 0)
		error("clReleaseKernel fail\n");
	kernel->ret = clReleaseProgram(kernel->program);
	if (kernel->ret != 0)
		error("clReleaseProgram fail\n");
	kernel->ret = clReleaseMemObject(kernel->memobj);
	if (kernel->ret != 0)
		error("clReleaseMemObject fail\n");
	kernel->ret = clReleaseCommandQueue(kernel->command_queue);
	if (kernel->ret != 0)
		error("clReleaseMemObject fail\n");
	kernel->ret = clReleaseContext(kernel->context);
	if (kernel->ret != 0)
		error("clReleaseContext fail\n");
}

void	set_kernel_args(t_kernel *kernel)
{
	kernel->ret = clSetKernelArg(kernel->kernel, 0, sizeof(cl_mem), &(kernel->memobj));
}

void	start_kernel(t_img *img)
{
	t_kernel    *kernel;
	char		*string;
	int			fd;
	char		*source_str;
	size_t		source_size;
	size_t		global_work_size;

	string = ft_strnew(WDTH * HGHT * sizeof(int));
	kernel = (t_kernel*)malloc(sizeof(t_kernel));
	global_work_size = WDTH * HGHT;
	init_kernel(kernel);
	fd = open("src/kernel.cl", O_RDONLY);
	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = read(fd, source_str, MAX_SOURCE_SIZE);
	close(fd);
	if ((kernel->ret = clGetPlatformIDs(1, &(kernel->platform_id), &(kernel->ret_num_platforms))) != 0)
		error("clGetPlatformId fail");
	if ((kernel->ret = clGetDeviceIDs(kernel->platform_id, CL_DEVICE_TYPE_GPU, 1,&(kernel->device_id), &(kernel->ret_num_devices))) != 0)
		error("clGetDeviceIDs fail");
	if ((kernel->context = clCreateContext(NULL, 1, &(kernel->device_id), NULL, NULL, &(kernel->ret))) != 0)
		error("clCreateContext fail");
	if ((kernel->command_queue = clCreateCommandQueue(kernel->context, kernel->device_id, 0, &(kernel->ret))) != 0)
		error("clCreateCommandQueue fail");
	if ((kernel->memobj = clCreateBuffer(kernel->context, CL_MEM_READ_WRITE, WDTH * HGHT * sizeof(int), NULL, &(kernel->ret))) != 0)
		error("clCreateBuffer");
	if ((kernel->program = clCreateProgramWithSource(kernel->context, 1, (const char **)&source_str,(const size_t *)&source_size, &(kernel->ret))) != 0)
		error("clCreateProgramWithSource");
	if ((kernel->ret = clBuildProgram(kernel->program, 1, &(kernel->device_id), NULL, NULL, NULL)) != 0)
		error("clBuildProgram fail");
	if ((kernel->kernel = clCreateKernel(kernel->program, "fractals", &(kernel->ret))) != 0)
		error("clCreateKernel fail");
	set_kernel_args(kernel);	
	if ((kernel->ret = clEnqueueNDRangeKernel(kernel->command_queue, kernel->kernel, 1, NULL, &global_work_size, NULL, 0, NULL, NULL)) != 0)
		error("clEnqueueNDRangeKernel fail");
	if ((kernel->ret = clEnqueueReadBuffer(kernel->command_queue, kernel->memobj, CL_TRUE, 0, WDTH * HGHT * sizeof(int),string, 0, NULL, NULL)) !=0)
		error("clEnqueueReadBuffer fail");
	ft_memcpy(img->addr_ptr, string, WDTH * HGHT * sizeof(int));
	finalization_kernel(kernel);
	
	free(source_str);
}