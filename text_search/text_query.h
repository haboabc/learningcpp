#ifndef TEXT_QUERY_H_
#define TEXT_QUERY_H_

#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

class Query_result;

class Text_query {
public:
	using line_no = std::vector<std::string>::size_type;

	Text_query() = default;
	Text_query(std::ifstream &file);
	Query_result query(std::string s) const;
	
private:
	std::shared_ptr<std::vector<std::string>> file;	
	std::map<std::string,
			std::shared_ptr<std::set<line_no>>> wm;

};

#endif /* TEXT_QUERY_H_ */
