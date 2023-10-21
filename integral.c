#include "integral.h"
#include <math.h>
#include <limits.h>

double integral(double (*f)(double), double dLeft, double dRight, double dStep) {
	double dRange = dRight - dLeft;
	double dNumSteps = dRange / dStep;
	if (!isfinite(dNumSteps) || dNumSteps < 0 || dNumSteps > UINT_MAX) {
		return NAN;
	}

	//a special case for very small intervals
	if (abs(dRange) < abs(dStep)) return (f(dLeft) + f(dRight)) * 0.5;

	unsigned int iNumSteps = floor(dNumSteps);
	
	double dSum = 0.;

	{//working with the edges
		dSum += f(dLeft) * dStep * 0.5; //left edge
		double dStepRem = dRange - iNumSteps * dStep; //the part of the interval which was not counted in iNumSteps
		dSum += (f(dRight) * dStepRem + f(dRight - dStepRem)*(dStepRem+dStep))*0.5; //right edge

		iNumSteps -= 1;
	}

	for (unsigned int i = 1; i <= iNumSteps; i++) {
		dSum += f(dLeft + i * dStep) * dStep;
	}

	return dSum;
}