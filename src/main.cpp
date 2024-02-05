#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "./lexative.hpp"
#include "./parser.hpp"
#include "./screwup.hpp"
#include "./skylibs/optional.hpp"
#include "./skylibs/string.hpp"

using str = std::string;

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
		Lexative lexer = Lexative(contents);

		std::vector<Token> tokens = lexer.lex();

		//parses tokens
		Parser parser = Parser(tokens);

		node::Exit exit = parser.parse();

		//notifies user that compile has succeded
		std::cout << "Compilation succeded\n";
		
		return 0;
	} else {
		std::cerr << "Not enough arguments provided.\n";
		return 1;
	}
}