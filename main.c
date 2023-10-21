#include "integral.h"
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

double f(double x) { //test function
	return x;
}

void testIntegral(const char* label, double (*f)(double), double left_edge, double right_edge, double step, double expected_result) {
	time_t start, end;
	time(&start);
	double res = integral(f, left_edge, right_edge, step);
	time(&end);
	printf("Integral of %s | [%lf, %lf, step=%.1le]:\n", label, left_edge, right_edge, step);
	printf("Result: %.16lf\n", res);
	printf("Error: %le\n", res - expected_result);
	printf("Time taken: %lf s\n", difftime(end, start));
	printf("\n");

}

int main()
{
	testIntegral("y=x", f, 0, 5, 0.01, 12.5);
	testIntegral("y=sin(x)", sin, 0, M_PI, 0.00000001, 2);

	return 0;
}
