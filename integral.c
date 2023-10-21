#include "integral.h"
#include <math.h>
#include <limits.h>


double integral(double (*f)(double), double dLeft, double dRight, double dStep) {
	double dRange = dRight - dLeft;
	double dNumSteps = dRange / dStep;
	if (!isfinite(dNumSteps) || dNumSteps < 0 || dNumSteps > ULLONG_MAX) {
		return NAN;
	}

	//a special case for very small intervals
	if (abs(dRange) < abs(dStep)) return (f(dLeft) + f(dRight)) * 0.5;

	unsigned long long int iNumSteps = floorl(dNumSteps);
	
	//Double double sum accumulator
	double ddSumU = 0, ddSumL = 0;

	{//working with the edges
		double dStepRem = dRange - iNumSteps * dStep; //the part of the interval which was not counted in iNumSteps
		ddSumU += (f(dRight) * dStepRem + f(dRight - dStepRem)*(dStepRem+dStep))*0.5; //right edge
		DekkerAccumulate(&ddSumU, &ddSumL, f(dLeft) * dStep * 0.5); //left edge

		iNumSteps -= 1;
	}

	for (unsigned long long int i = 1; i <= iNumSteps; i++) {
		DekkerAccumulate(&ddSumU, &ddSumL, f(dLeft + i * dStep) * dStep);
	}

	return ddSumU;
}

//See Double Double Arithmetics (https://csclub.uwaterloo.ca/~pbarfuss/dekker1971.pdf)
void DekkerAccumulate(double *s_upper, double *s_lower, const double a) {
	double R = *s_upper + a;
	double r = *s_upper - R + a;
	r = *s_lower + r;
	*s_upper = R + r;
	*s_lower = R - *s_upper + r;
}