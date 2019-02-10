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
	double	dx;
	double	dy;
	int		gid;
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
			color = color + ft_color;
		}
		if (i == iteration)
			color = 0x000000;
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
			color = color + ft_color;
        }
		if (i == iteration)
			color = 0x000000;
	}
	else if (name == 'n')
	{
		real = x0 + ((double)(x)) / 1000 * (x1 - x0);
        imag = y1 + ((double)(y)) / 1200 * (y0 - y1);
		dx = real;
		dy = imag;
        i = 0;
        while (i < iteration && (real * real + imag * imag) < 1000000 && (dx * dx + dy * dy) > 0.0000001)
        {
			c_real = real * real * real * real + 2 * real * real * imag * imag + imag * imag * imag * imag;
			ex_real = real * 2 / 3 + (real * real - imag * imag) / 3 / c_real;
			ex_imag = imag * 2 / 3 * (1 - real / c_real);
			if (ex_real > real)
				dx = ex_real - real;
			else
				dx = real - ex_real;
			if (ex_imag > imag)
				dy = ex_imag - imag;
			else
				dy = imag - ex_imag;
            real = ex_real;
            imag = ex_imag;
            i++;
			color = color + ft_color;
        }
		if (i == iteration)
			color = 0x000000;
	}
	else if (name == 's')
	{
		i= 0;
		c_real = x0 + ((double)(x)) / 1000 * (x1 - x0);
		c_imag = y1 + ((double)(y)) / 1000 * (y0 - y1);
		real = c_real;
		imag = c_imag;
		while (i < iteration && (real * real + imag * imag) <= 16)
		{
			ex_real = real * real - imag * imag + c_real;
			ex_imag = 2 * real * imag + c_imag;
			c_real = c_real / 2 + ex_real;
			c_imag = c_imag / 2 + ex_imag;
			real = ex_real;
			imag = ex_imag;
			i++;
			color = color + ft_color;
		}
		if (i == iteration)
			color = 0x000000;
	}	
	((__global unsigned int*)(string))[gid] = color;
}