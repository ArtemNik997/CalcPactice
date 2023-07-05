// Task ¹10
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <conio.h>
#include "Func.h"

using namespace std;

const double epsilon = 1e-10;

int main() {
	double x_beg = -1.0;
	double x_end = 1.0;
	double prec = 0.001;
	double result = 0.0;

	for (double x = x_beg; x <= x_end;) {
		result = calculateFunction(x, prec);
		cout << "f(" << x << ") = " << result << "\n";
		if (abs(x + 0.1) < epsilon) {
			x = 0.0;
		}
		else {
			x += 0.1;
		}
	}

	_getch();
	return 0;
}

