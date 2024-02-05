#pragma once

#include <string>
#include <vector>

#include "./screwup.hpp"
#include "./skylibs/optional.hpp"

using str = std::string;

enum class TokenType {
	exit,
	int_lit,
	semicolon
};

struct Token {
	TokenType type;
	sky::optional<str> content = {};
};

class Lexative {
public:
	inline explicit Lexative(const str& src):
		m_src(src)
	{}

	std::vector<Token> lex() {
		std::vector<Token> tokens;
		str buffer;
		while(this->peek(0).has_value()) {
			char c = this->consume();
			if(std::isalpha(c)) {
				buffer.push_back(c);

				//repeats until it can't get anymore alphanumeric charachters or it reaches the end of file
				while(this->peek(0).has_value() && std::isalnum(this->peek(0).value())) {
					buffer.push_back(this->consume());
				};
				
				//checks for valid tokens
				if(buffer == "exit") {
					tokens.push_back({.type = TokenType::exit});
					buffer.clear();
					continue;
				} else {
					screwup(3);
				};
			} else if(std::isdigit(c)) {
				//checks for numbers
				buffer.push_back(c);

				while(this->peek(0).has_value() && std::isdigit(this->peek(0).value())) {
					buffer.push_back(this->consume());
				};

				tokens.push_back({.type = TokenType::int_lit, .content = buffer});
				buffer.clear();
				continue;
			} else if(std::isspace(c)) {
				continue;
			} else if(c == ';') {
				tokens.push_back({.type = TokenType::semicolon});
				continue;
			} else {
				screwup(2);
			};
		};

		index  = 0;
		return tokens;
	}
private:

	[[nodiscard]] inline sky::optional<char> peek(int ahead = 1) const {
		if(index + ahead >= m_src.length()) {
			return {};
		} else {
			return m_src.at(index + ahead);
		};
	}

	inline char consume() {
		return m_src.at(index++);
	}

	const str m_src;
	size_t index = 0;
};
