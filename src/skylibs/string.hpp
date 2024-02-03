#pragma once

#include <string>

using str = std::string;

namespace sky
{
    class string {
    public:
        string(str value) {
            addr = new str(value);
        }
        void set(str value) {
            delete addr;
            addr = new str(value);
        }
    private:
        str* addr;
    };
} // namespace sky
