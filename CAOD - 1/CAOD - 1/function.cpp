#include "pch.h"
#include "function.h"
#include <iomanip> // setprecision

void function(double a, double b, double c, double xBegin, double xEnd, double dX) {
	int aC, bC, cC;
	double result;
	aC = a;
	bC = b;
	cC = c;
	for (double x = xBegin; x <= xEnd; x += dX) {
		if (x < 0 && b != 0) {
			result = a * pow(x, 2) + b;
		} else
		if (x > 0 && b == 0) {
			result = (x - a) / (x - c);
		}
		else {
			result = x / c;
		}
		if (((aC || bC) && (aC || cC))!=0) {
			cout << setprecision(3);
			cout << x << " | " << result << endl;
		}
		else {
			cout << setprecision(3);
			cout << x << " | " << int(result) << endl;
		}
	}
}
