#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "Func.h"

using namespace std;

double calculateFunction(double x, double precision) {
	double term = x;
	int n = 1;
	double result = 0.0;
	double previousResult = 0.0;

	while (abs(term) >= precision) {
		double numerator = pow(-1, n - 1) * pow(2, 2 * n - 1);
		double denominator = 1.0;

		for (int j = 1; j <= 2 * n; ++j) {
			denominator *= j;
		}

		term = numerator / denominator * pow(x, 2 * n);
		result = previousResult + term;
		previousResult = result;
		n++;
	}

	return result;
}
