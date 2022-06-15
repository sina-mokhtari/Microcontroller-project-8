/*
 * mathStuff.c
 *
 *  Created on: Jun 11, 2022
 *      Author: Sina
 */

#include "requisite.h"
#include "mathStuff.h"

double xRadian = 0;
void xChange() {
	if (mode == ASCENDING) {
		x++;
		if (x == 720)
			mode = DESCENDING;
	} else {
		x--;
		if (x == -720)
			mode = ASCENDING;
	}

	xRadian = degreeToRadian(x);
	xSin = sin(xRadian);
	xCos = cos(xRadian);
	xCubeRoot = power(x, (double) 1 / 3);
}

double degreeToRadian(double n) {
	return n * M_PI / 180;
}

double power(double n, double p) {
	if (n >= 0)
		return pow(n, p);
	else
		return -pow(-n, p);
}
