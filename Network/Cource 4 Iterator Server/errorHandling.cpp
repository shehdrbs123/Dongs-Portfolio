#include <iostream>

void error_handling(const char* message)
{
    std::cout << message << std::endl;
    exit(1);
}
