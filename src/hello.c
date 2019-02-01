/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:49:05 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/01 18:04:45 by bfalmer-         ###   ########.fr       */
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
	kernel->ret_num_devices;
	kernel->ret_num_platforms;
	kernel->ret;
}

void	finalization_kernel(t_kernel *kernel)
{
	kernel->ret = clFlush(kernel->command_queue);
	kernel->ret = clFinish(kernel->command_queue);
	kernel->ret = clReleaseKernel(kernel->kernel);
	kernel->ret = clReleaseProgram(kernel->program);
	kernel->ret = clReleaseMemObject(kernel->memobj);
	kernel->ret = clReleaseCommandQueue(kernel->command_queue);
	kernel->ret = clReleaseContext(kernel->context);
}

int     main()
{
	t_kernel    *kernel;
	char		string[MEM_SIZE];
	FILE		*fp;
	char		*fileName;
	char		*source_str;
	size_t		source_size;

	fileName = "./hello.cl";
	kernel = (t_kernel*)malloc(sizeof(t_kernel));
	init_kernel(kernel);
	/* Load the source code containing the kernel*/
	fp = fopen(fileName, "r");
	if (!fp)
	{
		ft_putstr("Failed to load kernel.\n");
		exit(0);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);
	
	/* Get Platform and Device Info */
	kernel->ret = clGetPlatformIDs(1, &kernel->platform_id, &kernel->ret_num_platforms);
	kernel->ret = clGetDeviceIDs(kernel->platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &kernel->device_id, &kernel->ret_num_devices);
	
	/* Create OpenCL context */
	kernel->context = clCreateContext(NULL, 1, &kernel->device_id, NULL, NULL, &kernel->ret);
	
	/* Create Command Queue */
	kernel->command_queue = clCreateCommandQueue(kernel->context, kernel->device_id, 0, &kernel->ret);
	
	/* Create Memory Buffer */
	kernel->memobj = clCreateBuffer(kernel->context, CL_MEM_READ_WRITE,MEM_SIZE * sizeof(char), NULL, &kernel->ret);
	
	/* Create Kernel Program from the source */
	kernel->program = clCreateProgramWithSource(kernel->context, 1, (const char **)&source_str,
	(const size_t *)&source_size, &kernel->ret);
	
	/* Build Kernel Program */
	kernel->ret = clBuildProgram(kernel->program, 1, &kernel->device_id, NULL, NULL, NULL);
	
	/* Create OpenCL Kernel */
	kernel->kernel = clCreateKernel(kernel->program, "hello", &kernel->ret);
	
	/* Set OpenCL Kernel Parameters */
	kernel->ret = clSetKernelArg(kernel->kernel, 0, sizeof(cl_mem), (void *)&kernel->memobj);
	
	/* Execute OpenCL Kernel */
	kernel->ret = clEnqueueTask(kernel->command_queue, kernel->kernel, 0, NULL,NULL);
	
	/* Copy results from the memory buffer */
	kernel->ret = clEnqueueReadBuffer(kernel->command_queue, kernel->memobj, CL_TRUE, 0,
				MEM_SIZE * sizeof(char),string, 0, NULL, NULL);

	finalization_kernel(kernel);
	free(source_str);
	
	return 0;
}