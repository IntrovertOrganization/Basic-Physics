﻿#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream> 

const std::string blue = "\033[34m", yellow = "\033[33m", green = "\033[32m", red = "\033[31m", reset = "\033[0m";

void finish() {
	std::cout << "\n" << red << "Exit..." << reset << "\n\n";
	exit(0);
}

const double k = 8.9875e9;

double calculateCoulombsLaw(double& q1, double& q2, double& r) {
	return k * (q1 * q2 / pow(r, 2));
}

std::string formatScientific(double value) {
	if (value == 0.0) return "0";

	int exponent = static_cast<int>(std::floor(std::log10(std::fabs(value))));
	double base = value / std::pow(10, exponent);

	std::ostringstream oss;

	oss << base << "x10^" << exponent;

	return oss.str();
}