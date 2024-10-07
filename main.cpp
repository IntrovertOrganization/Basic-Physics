#include "function.h"

int main() {
	std::vector <std::string> list = {
		"\n",
		"[option] | [title]",
		"------------------",
		"[1]      | Calculate Coloumb's law",
		"[0]      | Quit",
		"\n"
	};
	for (std::string item : list) {
		std::cout << item << std::endl;
	}

	int option;

	while (option != 0) {
		std::cout << "[input] Enter your option: ";
		std::cin >> option;
	}
}