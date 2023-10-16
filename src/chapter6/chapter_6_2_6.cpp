/*
 * ==========================================================================
 *
 *       Filename:  chapter_6_2_6.cpp
 *
 *    Description:  header for chapter_6_2_6.cpp
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
#include <initializer_list>
#include <string>

namespace exercise::chapter6 {
    void error_msg(int errCode, std::initializer_list<std::string> i1) {
        std::cout << errCode << ": ";
        for (const auto& elem : i1) { // 实际类型是 const string& const
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main() {

    using exercise::chapter6::error_msg;

    const std::string expected = "hello";
    const std::string actual = "world";

    if (expected != actual) {
        error_msg(42, {"function", expected, actual});
    }
    else {
        error_msg(0, {"function", "okay"});
    }

    return 0;
}
