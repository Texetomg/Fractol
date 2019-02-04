__kernel void hello(__global int* string, int color, double real, double imag)
{  
    int 	gid;
    int 	x;
    int 	y;
    int		i;
	double	c_real;
	double	c_imag;
	double	ex_real;
	double	ex_imag;

    gid = get_global_id(0);
    x = gid % 1000;
    y = gid / 1000;
	i = 0;
	color = 0xFFFFFF;
	c_real = ((double)(x - (1000 / 2))) / (1000 / 5);
	c_imag = ((double)((1000 / 2) - y)) / (1000 / 5);
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
	*((int*)(string) + x + y * 1000) = color;
}