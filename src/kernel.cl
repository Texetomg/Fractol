__kernel void fractals(__global char* string,
								double x0,
								double y0,
								double x1,
								double y1)
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
	i = 0;
	color = 0xFFFFFF;
	c_real = x0 + ((double)(x)) / 1000 * (x1 - x0);
	c_imag = y1 + ((double)(y)) / 1000 * (y0 - y1);
	real = 0;
	imag = 0;
	while (i < 250 && (real * real + imag * imag) <= 4)
	{
		ex_real = real * real - imag * imag + c_real;
		ex_imag = 2 * real * imag + c_imag;
		real = ex_real;
		imag = ex_imag;
		i++;
		color = color - 470 * 470;
	}
	((__global unsigned int*)(string))[gid] = color;
}