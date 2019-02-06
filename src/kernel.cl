
__kernel void fractals(__global char* string,
								double x0,
								double y0,
								double x1,
								double y1,
								char name,
								double x_coord,
								double y_coord,
								int recolor,
								int iteration)
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
	int		color;
	int		gid;

	gid = get_global_id(0);
	x = gid % 1000;
	y = gid / 1000;
	color = 0xFFFFFF;
	if (name == 'm')
	{
		i = 0;
		c_real = x0 + ((double)(x)) / 1000 * (x1 - x0);
		c_imag = y1 + ((double)(y)) / 1000 * (y0 - y1);
		real = 0;
		imag = 0;
		while (i < iteration && (real * real + imag * imag) <= 4)
		{
			ex_real = real * real - imag * imag + c_real;
			ex_imag = 2 * real * imag + c_imag;
			real = ex_real;
			imag = ex_imag;
			i++;
						color = color - recolor;
		}
	}
	else if (name == 'j')
	{	
		i = 0;
		real = x0 + ((double)(x)) / 1000 * (x1 - x0);
        imag = y1 + ((double)(y)) / 1000 * (y0 - y1);
        c_real = x_coord;
		c_imag = y_coord;
        while (i < iteration && (real * real + imag * imag) <= 4)
        {
            ex_real = real * real - imag * imag + c_real;
            ex_imag = 2 * real * imag + c_imag;
            real = ex_real;
			imag = ex_imag;
			i++;
		}
	}
	else if (name == 'b')
	{
		i = 0;
		c_real = x0 + ((double)(x)) / 1000 * (x1 - x0);
        c_imag = y1 + ((double)(y)) / 1000 * (y0 - y1);
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

        }
	}
	((__global unsigned int*)(string))[gid] = color;
}