#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	if (argc < 4)
		return 1;

	std::ifstream	input(argv[1]);
	if (!input) {
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}

	std::ofstream	output(std::string(argv[1]).append(".replace").c_str());
	if (!output) {
		std::cerr << "Unable to create file" << std::endl;
		input.close();
		return (1);
	}

	bool		trigger = false;
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	line;
	while (std::getline(input, line)) {
		size_t		cursor = 0;
		std::string	tmp;
		while (!s1.empty() && (cursor = line.find(s1, cursor)) != std::string::npos) {
			tmp = line.substr(cursor + s1.size());
			line = line.substr(0, cursor).append(s2).append(tmp);
			cursor += s2.length();
		}
		if (trigger)
				output << "\n";
			trigger = true;
		output << line;
	}
	input.close();
	output.close();
} 