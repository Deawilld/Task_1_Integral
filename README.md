<h2># Task_1_Integral</h2>
<p>
  The function "double integral(double (*f)(double), double dLeft, double dRight, double dStep)" computes a numeric integral from the given function "f" on the interval [dLeft, dRight] with the given steps (dStep) by calculation values of the function in a loop.
</p>
<p>
  The total number of steps (dRight - dLeft)/dSteps must not exceed MAX_ULLONG, otherwise NaN is returned. But note that the larger the number of steps is, the longer it takes to compute. E.g. for about 10^9 steps it takes several seconds. By the way, the precision doesn't always get better when increasing the number of steps.
</p>
