#pragma once

#include <string>
#include <vector>
#include <optional>

#include "screwup.hpp"

using str = std::string;

enum class TokenType {
	exit,
	int_lit,
	semicolon
};

struct Token {
	TokenType type;
	std::optional<str> content = {};
};

class Lexative {
public:
	inline Lexative(const str& src):
		m_src(src)
	{}

	inline std::vector<Token> lex() {
		std::vector<Token> tokens;
		str buffer;
		while(peek(1) != {}) {
			char ch = m_src.at(c);
			if(std::isalpha(ch)) {
				buffer.push_back(ch);
				c++;
				while(std::isalnum(m_src.at(c))) {
					buffer.push_back(m_src.at(c));
					c++;
					if(c >= m_src.length()) {
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
				while(std::isdigit(m_src.at(c))) {
					buffer.push_back(m_src.at(c));
					c++;
					if(c >= m_src.length()) {
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
private:

	[[nodiscard]] std::optional<char> peek(int ahead) const {
		if(index + ahead >= m_src.length()) {
			return {};
		} else {
			return m_src.at(index + ahead);
		};
	}

	char consume() {
		return m_src.at(index++);
	}

	const str m_src;
	int index = 0;
};
