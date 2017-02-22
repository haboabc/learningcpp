#include <iostream>
#include "query_result.h"

static std::string make_plural(std::vector<std::string>::size_type num, const std::string s1, const std::string &s2)
{
	return num > 1? s1+s2: s1;
}
std::ostream &print(std::ostream &stream, const Query_result &result) 
{
	stream << result.word << " occurs " << result.set->size() << " " 
			<< make_plural(result.set->size(), "time", "s") << std::endl;

	for (auto const &num : *result.set) {
		stream << "\t(line " << num + 1 << ")" << *(result.file->begin() + num) << std::endl;	
	}

	return stream;
} 
