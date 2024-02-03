#pragma once

#include <string>
#include <vector>
#include <optional>

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
	inline Lexative(const str& src):
		m_src(src)
	{}

	inline std::vector<Token> lex() {
		std::vector<Token> tokens;
		str buffer;
		while(this->peek(1).has_value()) {};
		return tokens;
	}
private:

	[[nodiscard]] sky::optional<char> peek(int ahead) const {
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
