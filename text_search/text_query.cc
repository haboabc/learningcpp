#include "text_query.h"
#include "query_result.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

Text_query::Text_query(std::ifstream &infile): file(new(std::vector<std::string>))
{
	std::string text;
	
	while (getline(infile, text)) {
		file->push_back(text);	
		line_no n = file->size() - 1; // for the first one in vector is 0 element

		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto & tmp = wm[word];
			if (!tmp) {
				tmp.reset(new std::set<line_no>);	
			}

			tmp->insert(n);
		
		}
	}

}

Query_result Text_query::query(std::string s) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

	auto loc = wm.find(s);
	if (loc == wm.end()) {
		return Query_result(s, nodata, file);
	} else {
		return Query_result(s, loc->second, file);	
	}
}
