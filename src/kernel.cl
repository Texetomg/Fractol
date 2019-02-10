__kernel void fractals(__global char* string,
								double x0,
								double y0,
								double x1,
								double y1,
								char name,
								double x_coord,
								double y_coord,
								int iteration,
								int ft_color)
{  
    int 	x;
    int 	y;
    int		i;
	double	c_real;
	double	c_imag;
	double	ex_real;
	double	ex_imag;
	double	real;
	double	imag;
	int		gid;
	int		n;
	int		color;

	color = 0;
	gid = get_global_id(0);
	x = gid % 1200;
	y = gid / 1000;
	if (name == 'm')
	{
		i = 0;
		c_real = x0 + ((double)(x)) / 1000 * (x1 - x0);
		c_imag = y1 + ((double)(y)) / 1200 * (y0 - y1);
		real = 0;
		imag = 0;
		while (i < iteration && (real * real + imag * imag) <= 4)
		{
			ex_real = real * real - imag * imag + c_real;
			ex_imag = 2 * real * imag + c_imag;
			real = ex_real;
			imag = ex_imag;
			i++;
			color = color + ft_color;
		}
		if (i == iteration)
			color = 0x000000;
		n = 50;
	}
	else if (name == 'j')
	{	
		i = 0;
		real = x0 + ((double)(x)) / 1000 * (x1 - x0);
        imag = y1 + ((double)(y)) / 1200 * (y0 - y1);
        c_real = x_coord;
		c_imag = y_coord;
        while (i < iteration && (real * real + imag * imag) <= 4)
        {
            ex_real = real * real - imag * imag + c_real;
            ex_imag = 2 * real * imag + c_imag;
            real = ex_real;
			imag = ex_imag;
			i++;
			color = color;
		}
		if (i == iteration)
			color = 0x000000;
		n = 9;
	}
	else if (name == 'b')
	{
		i = 0;
		c_real = x0 + ((double)(x)) / 1000 * (x1 - x0);
        c_imag = y1 + ((double)(y)) / 1200 * (y0 - y1);
        real = 0;
        imag = 0;
        while (i < iteration && (real * real + imag * imag) <= 4)
        {
            ex_real = real * real - imag * imag + c_real;
			if (real * imag > 0)
            	ex_imag = 2 * real * imag + c_imag;
			else
				ex_imag = (-1) * 2 * real * imag + c_imag;
            real = ex_real;
            imag = ex_imag;
            i++;
			color = color;
        }
		if (i == iteration)
			color = 0x000000;
		n = 30;
	}
	((__global unsigned int*)(string))[gid] = color;
}