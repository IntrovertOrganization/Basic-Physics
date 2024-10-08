#include "function.h"

int main() {
	int option;
	double q1, q2, r;

	std::vector<std::string> explanation = {
		"\n-------------------------"+blue+"The Coulomb's Law"+reset+"--------------------------\n",
		"Coulomb's law, is an experimental law of physics that calculates the\namount of force between two electrically charged particles at rest.",
		"\n+--------"+blue+"Formula"+reset+"--------+",
		"|                       |",
		"|          |q1| x |q2|  |",
		"| |F| = ke -----------  |",
		"|              r^2      |",
		"+-----------------------+\n",
		blue+"ke"+reset+"      = Coulomb's constant, the value is: 8.9875 x 10^9 Nm^2/C^2",
		blue+"q1 & q2"+reset+" = Electric charge (C)",
		blue+"r"+reset+"       = Distance between the charges (m^2)"
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

	while (option != 0) {
		if (option == 1) {

			std::vector<std::string> inputQ1 = {
				"\n                             " + blue + "|q1|" + reset + " x |q2|",
				"|F| = 8.9875 x 10^9 Nm^2/C^2 -----------",
				"                                r^2\n"
			};

			for (std::string item : inputQ1) {
				std::cout << item << std::endl;
			}
			
			std::cout << "Enter q1 value> ";
			std::cin >> q1;

			if (q1 != 0) {
				std::cout << "Enter q2 value> ";
				std::cin >> q2;

				if (q2 != 0) {
					std::cout << "Enter r value> ";
					std::cin >> r;

					if (r != 0) {
						std::cout << "Result> ";
						std::cout << calculateCoulombsLaw(q1, q2, r) << " N" << std::endl;
						finish();
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