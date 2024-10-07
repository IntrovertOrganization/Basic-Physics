#pragma once

#include <iostream>
#include <cmath>
#include <vector>

const double k = 8.9875e9; // Coulomb's constant (N·m^2/C^2)

double calculateColoumbsLaw(int q1, int q2, int r) {
	return k * (q1 * q2) / pow(r, 2);
}