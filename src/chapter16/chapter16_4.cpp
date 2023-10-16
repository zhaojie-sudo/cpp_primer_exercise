/*
 * ==========================================================================
 *
 *       Filename:  chapter16_4.cpp
 *
 *    Description:  header for chapter16_4.cpp
 *
 *        Version:  ${VERSION}
 *        Created:  2023/10/16
 *       Revision:  2023/10/16
 *       Compiler:  g++
 *
 *         Author:  zhaojie, jie.zhao@baltamatica.com
 *
 * ==========================================================================
 */

#include <iostream>

namespace exercise::chapter16 {
    template<typename T, typename... Args>
    void foo(const T& t, const Args&... rest) {
        std::cout << sizeof...(Args) << std::endl;
        std::cout << sizeof...(rest) << std::endl;
    }

    template<typename T>
    std::ostream& print(std::ostream& os, const T& t) {
        return os << t << std::endl;
    }

    template<typename T, typename... Args>
    std::ostream& print(std::ostream& os, const T& t, const Args&... rest) {
        os << t << ", ";
        return print(os, rest...);
    }
}

int main() {

    using exercise::chapter16::foo;
    using exercise::chapter16::print;

    int i = 0;
    double d = 3.14;
    std::string s = "hello world";

    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");

    print(std::cout, i);
    print(std::cout, i, s);
    print(std::cout, d, s, 42, "hi");
}