#include <iostream>
#include <string>
#include <sstream>

int main()
{
    int four = 4, five = 5;

    // no output
    char foo = four;
    std::cout << foo << std::endl;

    // doesn't show anything
    char bar = static_cast<char>(five);
    std::cout << bar << std::endl;

    // not equal
    std::cout << (bar == '5') << std::endl;  // 0

    // this works though
    std::string s = std::to_string(four);
    std::cout << s << std::endl;

    // this works too
    std::stringstream ss;
    ss << five;
    std::string fiveStr = ss.str();
    std::cout << fiveStr << std::endl;

    return 0;
}
