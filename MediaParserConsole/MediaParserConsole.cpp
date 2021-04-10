#include <iostream>
#include <filesystem>
#include "MediaParserLib.h"

int main()
{
    using namespace MediaParserLib;

    std::cout << "Hello World!\n";

    parseForMedia(R"(c:\temp\hello.jpg)");
}
