#include "function.h"

int main() {
	int option;
	double q1, q2, r;

	std::vector<std::string> explanation = {
		"\n"+bold+blue+"The Coulomb's Law"+reset+"\n",
		"          |q1| x |q2|  ",
		blue+"|F|"+reset+" = ke ------------- ",
		"             r^2    \n",
		blue+"ke"+reset+"  = Coulomb's constant, the value is: 8.9875 x 10^9, N . m^2/C^2",
		blue+"q1 & q2"+reset+" = Electric charge (C)",
		blue+"r"+reset+"  = Distance between the charges (m^2)\n"
	};

	for (std::string item : explanation) {
		std::cout << item << std::endl;
	}

	std::vector<std::string> list = {
		"\n[option] | [title]",
		"------------------",
		"[1]      | Calculate Coloumb's law",
		"[2]      | Source",
		"[0]      | Quit\n",
	};
	for (std::string item : list) {
		std::cout << item << std::endl;
	}

	std::vector<std::string> sources = {
		"\n[source]               | [url]",
		"------------------------------",
		"Wikipedia              | https://en.wikipedia.org/wiki/Coulomb%27s_law",
		"The Physics Classroom  | https://www.physicsclassroom.com/class/estatics/lesson-3/coulomb-s-law",
		"PhET                   | https://phet.colorado.edu/sims/html/coulombs-law/latest/coulombs-law_en.html",
		"Britannica             | https://www.britannica.com/science/Coulombs-law"
	};

	std::cout << input << " Enter your option: ";
	std::cin >> option;

	while (option != 0) {
		if (option == 1) {
			std::cout << input << " Enter q1 value: ";
			std::cin >> q1;

			if (q1 != 0) {
				std::cout << input << " Enter q2 value: ";
				std::cin >> q2;

				if (q2 != 0) {
					std::cout << input << " Enter r value: ";
					std::cin >> r;

					if (r != 0) {
						std::cout << output << " Result: ";
						std::cout << calculateCoulombsLaw(q1, q2, r) << " N" << std::endl;
						exit(0);
					}
					else if (r == 0) {
						exit(0);
					}
				}
				else if (q2 == 0) {
					exit(0);
				}
			}
			else if (q1 == 0) {
				exit(0);
			}
		}
		else if (option == 2) {
			for (std::string item : sources) {
				std::cout << item << std::endl;
			}

			for (std::string item : list) {
				std::cout << item << std::endl;
			}

			std::cout << input << " Enter your option: ";
			std::cin >> option;
		}
		else {
			std::cout << error << " Invalid option" << std::endl;
			std::cout << input << " Enter your option: ";
			std::cin >> option;
		}
	}

	if (option == 0) {
		exit(0);
	}
	
	return 0;
}