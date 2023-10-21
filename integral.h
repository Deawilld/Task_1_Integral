#pragma once

double integral(double (*f)(double), double dLeft, double dRight, double dStep);

void DekkerAccumulate(double *s_upper, double *s_lower, double a);