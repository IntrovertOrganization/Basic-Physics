#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

const std::string blue = "\033[34m", yellow = "\033[33m", green = "\033[32m", red = "\033[31m", reset = "\033[0m";

void finish() {
	std::cout << "\n" << red << "Exit..." << reset << "\n\n";
	exit(0);
}

void nl() {
	std::cout << "\n";
}

double calculateCoulombsLaw(double& q1, double& q2, double& r) {
	return 8.9875e9 * (q1 * q2 / pow(r, 2));
}

std::string formatQ(double value) {
	std::stringstream ss;
	
	ss << std::scientific << std::setprecision(1) << value;

	std::string scientfc = ss.str();

	size_t pos = scientfc.find('e');

	std::string base = scientfc.substr(0, pos);
	int exponent = std::stoi(scientfc.substr(pos + 1));

	if (base.find(".0") != std::string::npos) {
		base = base.substr(0, base.find(".0"));
	}

	return base + "x10^-" + std::to_string(exponent) + " C";
}

std::string formatR(double value) {
	std::ostringstream oss;
	oss << value << " m^2";
	return oss.str();
}

std::string formatResult(double value) {
	int exponent = static_cast<int>(std::floor(std::log10(std::abs(value))));
	double base = value / std::pow(10, exponent);

	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << base << " N";

	return ss.str();
}

int main() {
	int option;
	double q1, q2, r;

	std::vector<std::string> explanation = {
		"\n-------------------------" + blue + "The Coulomb's Law" + reset + "--------------------------\n",
		"Coulomb's law, is an experimental law of physics that calculates the\namount of force between two electrically charged particles at rest.",
		"\n+--------" + blue + "Formula" + reset + "--------+",
		"|                       |",
		"|          |q1| x |q2|  |",
		"| |F| = ke -----------  |",
		"|              r^2      |",
		"+-----------------------+\n",
		blue + "ke" + reset + "      = Coulomb's constant, the value is: 8.9875 x 10^9 Nm^2/C^2",
		blue + "q1 & q2" + reset + " = Electric charge (C)",
		blue + "r" + reset + "       = Distance between the charges (m^2)"
	};

	for (std::string item : explanation) {
		std::cout << item << std::endl;
	}

	std::vector<std::string> list = {
		"\n+----------+-------------+",
		"| [option] |  [details]  |",
		"|----------+-------------|",
		"|   ["+blue+"1"+reset+"]    | Calculator  |",
		"|   ["+blue+"2"+reset+"]    | Source      |",
		"|   ["+blue+"0"+reset+"]    | Quit        |",
		"+----------+-------------+\n"
	};
	for (std::string item : list) {
		std::cout << item << std::endl;
	}

	std::vector<std::string> sources = {
		"\n+-----------------------+---------------------------------------------------------------------------------+",
		"|       [source]        |                                     [url]                                       |",
		"|-----------------------+---------------------------------------------------------------------------------|",
		"| Wikipedia             | https://en.wikipedia.org/wiki/Coulomb%27s_law                                   |",
		"| The Physics Classroom | https://www.physicsclassroom.com/class/estatics/lesson-3/coulomb-s-law          |",
		"| PhET                  | https://phet.colorado.edu/sims/html/coulombs-law/latest/coulombs-law_en.html    |",
		"| Britannica            | https://www.britannica.com/science/Coulombs-law                                 |",
		"+-----------------------+---------------------------------------------------------------------------------+"
	};

	std::cout << "Enter your option> ";
	std::cin >> option;
	nl();

	while (option != 0) {
		if (option == 1) {
			std::vector<std::string> valueOfK = {
				"+----------"+blue+"Given"+reset+"-"+blue+"Value"+reset+"---------+",
				"|                              |",
				"|             |q1| x |q2|      |",
				"|    |F| = ke -----------      |",
				"|                 r^2          |",
				"+---------------------------------~",
				"|"+blue + " ke" + reset + " = 8.9875 x 10^9 Nm^2/C^2",
				"|"+blue + " q1" + reset + " = " + green + "[entering...]" + reset,
				"|"+blue + " q2" + reset + " = " + yellow + "[waiting...]" + reset,
				"|"+blue + " r" + reset + "  = " + yellow + "[waiting...]" + reset,
				"+---------------------------------~\n"
			};

			for (std::string item : valueOfK) {
				std::cout << item << std::endl;
			}

			std::cout << "Enter q1 value> ";
			std::cin >> q1;
			nl();
			
			std::vector<std::string> valueOfQ1 = {
				"+----------" + blue + "Given" + reset + "-" + blue + "Value" + reset + "---------+",
				"|                              |",
				"|             |q1| x |q2|      |",
				"|    |F| = ke -----------      |",
				"|                 r^2          |",
				"+---------------------------------~",
				"|" + blue + " ke" + reset + " = 8.9875 x 10^9 Nm^2/C^2",
				"|" + blue + " q1" + reset + " = "+formatQ(q1),
				"|" + blue + " q2" + reset + " = " + green + "[entering...]" + reset,
				"|" + blue + " r" + reset + "  = " + yellow + "[waiting...]" + reset,
				"+---------------------------------~\n"
			};

			for (std::string item : valueOfQ1) {
				std::cout << item << std::endl;
			}

			if (q1 != 0) {
				std::cout << "Enter q2 value> ";
				std::cin >> q2;
				nl();

				std::vector<std::string> valueOfQ2 = {
					"+----------" + blue + "Given" + reset + "-" + blue + "Value" + reset + "---------+",
					"|                              |",
					"|             |q1| x |q2|      |",
					"|    |F| = ke -----------      |",
					"|                 r^2          |",
					"+---------------------------------~",
					"|" + blue + " ke" + reset + " = 8.9875 x 10^9 Nm^2/C^2",
					"|" + blue + " q1" + reset + " = " + formatQ(q1),
					"|" + blue + " q2" + reset + " = " + formatQ(q2),
					"|" + blue + " r" + reset + "  = " + green + "[entering...]" + reset,
					"+---------------------------------~\n"
				};

				for (std::string item : valueOfQ2) {
					std::cout << item << std::endl;
				}

				if (q2 != 0) {
					std::cout << "Enter r value> ";
					std::cin >> r;
					nl();

					std::vector<std::string> valueOfR = {
						"+----------" + blue + "Given" + reset + "-" + blue + "Value" + reset + "---------+",
						"|                              |",
						"|             |q1| x |q2|      |",
						"|    |F| = ke -----------      |",
						"|                 r^2          |",
						"+---------------------------------~",
						"|" + blue + " ke" + reset + " = 8.9875 x 10^9 Nm^2/C^2",
						"|" + blue + " q1" + reset + " = " + formatQ(q1),
						"|" + blue + " q2" + reset + " = " + formatQ(q2),
						"|" + blue + " r" + reset + "  = " + formatR(r),
						"+---------------------------------~\n"
					};

					for (std::string item : valueOfR) {
						std::cout << item << std::endl;
					}

					if (r != 0) {
						std::cout << "Result> ";
						std::cout << formatResult(calculateCoulombsLaw(q1, q2, r)) << std::endl;

						for (std::string item : list) {
							std::cout << item << std::endl;
						}

						std::cout << "Enter your option> ";
						std::cin >> option;
					}
					else if (r == 0) {
						finish();
					}
				}
				else if (q2 == 0) {
					finish();
				}
			}
			else if (q1 == 0) {
				finish();
			}
		}
		else if (option == 2) {
			for (std::string item : sources) {
				std::cout << item << std::endl;
			}

			for (std::string item : list) {
				std::cout << item << std::endl;
			}

			std::cout << "Enter your option> ";
			std::cin >> option;
		}
		else {
			std::cout << "Invalid option, please enter a valid value!" << std::endl;
			std::cout << "Enter your option> ";
			std::cin >> option;
		}
	}

	if (option == 0) {
		finish();
	}
	
	return 0;
}