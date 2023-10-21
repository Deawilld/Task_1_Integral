#include "integral.h"
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double f(double x) { //test function
	return x;
}

int main()
{
	double res = integral(f, 0, 5, 0.000000001);
	printf("Integral of y=x | [-2, 2, step=1e-9]: %.16lf\n", res);
	printf("Error: %le\n", res - 12.5);

	res = integral(sin, 0, M_PI, 0.00000001);
	printf("Integral of y=sin(x) | [0, PI, step=1e-8]: %.16lf\n", res);
	printf("Error: %le\n", res - 2);

	return 0;
}
