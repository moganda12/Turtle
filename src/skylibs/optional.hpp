#pragma once

#include <iostream>

namespace sky
{
    template <class T>

    class optional {
    public:
    	optional() {
    		bool isdef = false;
        	}
    	optional(T contenti) {
    		isdef = true;
    		content = contenti;
    	}
    	bool has_value() {
    		return isdef;
    	}
		[[nodiscard]] T value() {
			if(this->has_value()) {
				return content;
			} else {
				std::cout << "yu bad coder yu big dumdum yu deserve err";
				exit(734678);
			}
		}
    private:
	    bool isdef;
	    T content;
    };
} // namespace sky
