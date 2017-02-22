#include <iostream>
#include <fstream>
#include <string>

#include "text_query.h"
#include "query_result.h"

static void run_query(std::ifstream &file)
{
	Text_query tq(file);

	while (true) {
		std::cout << "Enter word to look for, or  q to quit: ";	

		std::string s;
		if (!(std::cin >> s) || s == "q") { break; };

		print(std::cout, tq.query(s)) << std::endl;
	}

}

int main()
{

	std::ifstream file("./input.txt");	

	run_query(file);

	file.close();

	return 0;
}
