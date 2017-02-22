#ifndef QUERY_RESULT_H_
#define QUERY_RESULT_H_

#include <vector>
#include <string>
#include <memory>
#include <set>
#include <map>

class Query_result {
friend std::ostream &print(std::ostream &stream, const Query_result &result);

public:
	Query_result() = default;
	Query_result(std::string word,
				std::shared_ptr<std::set<std::vector<std::string>::size_type>> set,
				std::shared_ptr<std::vector<std::string>> file):word(word), set(set), file(file) {}
private:
	std::string word;
	std::shared_ptr<std::set<std::vector<std::string>::size_type>> set;
	std::shared_ptr<std::vector<std::string>> file;

};

#endif /* QUERY_RESULT_H_ */
