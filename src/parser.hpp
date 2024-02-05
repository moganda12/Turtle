#pragma once

#include <string>
#include <vector>

#include "./screwup.hpp"
#include "./lexative.hpp"


namespace node {
    struct Int_lit {
        Token int_lit;
    };
    struct Expr {
        Int_lit int_lit;
    };

    struct Exit {
        Expr expr;
    };

    struct Mult {
    };
    
    struct Add {
    };
    
} // namespace node



class Parser {
public:
    explicit inline Parser(std::vector<Token>& tks):
        tokens(std::move(tks))
    {}

    node::Expr parseExpr() {
        if(peek(0).has_value()) {
            Token token = consume();
            if(token.type == TokenType::int_lit) {
                return {.int_lit = {.int_lit = token}};
            } else {
                screwup(4);
            };
        };
    }

    node::Exit parse() {
        node::Exit base;
        while(peek(0).has_value()) {
            Token T = consume();

            if(T.type == TokenType::exit && peek().has_value()) {
                node::Expr exixp = parseExpr();
                base = {.expr = exixp};
                goto end;
            };
        };
        end:
        index = 0;
        return base;
    }

private:

    [[nodiscard]] inline sky::optional<Token> peek(int ahead = 1) const {
		if(index + ahead >= tokens.size()) {
			return {};
		} else {
			return tokens.at(index + ahead);
		};
	}

	inline Token consume() {
		return tokens.at(index++);
	}

    const std::vector<Token> tokens;
    size_t index = 0;
};
