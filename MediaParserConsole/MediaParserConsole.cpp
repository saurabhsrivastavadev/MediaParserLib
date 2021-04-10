#include "MediaParserLib.h"

#include <iostream>
#include <filesystem>
#include <vector>
#include <chrono>

int main()
{
    using namespace MediaParserLib;
    using std::cout, std::cerr, std::endl;
    using std::chrono::system_clock, std::chrono::duration_cast, std::chrono::milliseconds;

    cout << "--------------------------" << endl;
    cout << "<< Media Parser Console >>" << endl;
    cout << "--------------------------" << endl << endl;

    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    auto mediaSummary = parseForMedia(R"(D:\GooglePhotosTakeout\sobu86@gmail.com)");
    auto end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    printf("Parsed %d files\n", mediaSummary.parsedFileCount);
    printf("Image files = %d\n", mediaSummary.imageMediaMap.size());
    printf("Video files = %d\n", mediaSummary.videoMediaMap.size());

    for (auto const& pair : mediaSummary.fileExtensionsCountMap)
    {
        printf("Extension = [%s] Count = [%d]\n", pair.first.c_str(), pair.second);
    }

    printf("Parsing Time = %llu milliseconds\n", end - start);
}
