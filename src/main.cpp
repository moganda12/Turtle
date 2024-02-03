#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>

#include "./lexative.hpp"
#include "./screwup.hpp"

using str = std::string;

//lexes file
std::vector<Token> lexative(const str& code) {
	std::vector<Token> tokens;
	str buffer;
	for(int c; c < code.length(); c++) {
		char ch = code.at(c);
		if(std::isalpha(ch)) {
			buffer.push_back(ch);
			c++;
			while(std::isalnum(code.at(c))) {
				buffer.push_back(code.at(c));
				c++;
				if(c >= code.length()) {
					break;
				};
			};
			c--;
			if(buffer == "exit") {
				tokens.push_back({TokenType::exit});
				buffer.clear();
				continue;
			} else {
				screwup(2);
			};
		} else if(std::isdigit(ch)) {
			buffer.push_back(ch);
			c++;
			while(std::isdigit(code.at(c))) {
				buffer.push_back(code.at(c));
				c++;
				if(c >= code.length()) {
					break;
				};
			};
			c--;
			tokens.push_back({.type = TokenType::int_lit,.content = buffer});
		} else if(ch == ';') {
			tokens.push_back({.type = TokenType::semicolon});
			continue;
		} else if(std::isspace(ch)) {
			continue;
		} else {
			screwup(3);
		};
	};
	return tokens;
}

int main(int argc, char* argv[]) {
	if(argc >= 2) {
    	std::cout << "Attempting to compile " << argv[1] << "\n";

		str contents;

		//reads provided file
		std::fstream file(argv[1], std::ios::in);
		std::stringstream contents_stream;
		contents_stream << file.rdbuf();
		file.close();

		//outputs to string
		contents = contents_stream.str();

		//lexes file
		std::vector<Token> tokens = lexative(contents);

		//nofifies user that compile has succeded
		std::cout << "Compilation succeded\n";
		
		return 0;
	} else {
		std::cerr << "Not enough arguments provided.\n";
		return 1;
	}
}