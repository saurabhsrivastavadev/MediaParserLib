#include "pch.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include "MediaParserLib.h"

namespace MediaParserLib
{
	std::vector<MediaInfo> parseForMedia(std::filesystem::path directoryToParse)
	{
		// confirm if directory to parse is a directory
		// todo

		for (auto& p : std::filesystem::recursive_directory_iterator(directoryToParse))
		{
			std::cout << p.path() << std::endl;
		}

		return std::vector<MediaInfo>();
	}
}
