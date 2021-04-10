#pragma once

#include <filesystem>
#include <vector>

#ifdef MEDIAPARSERLIB_EXPORTS
#define MEDIAPARSERLIB_API __declspec(dllexport)
#else
#define MEDIAPARSERLIB_API __declspec(dllimport)
#endif

namespace MediaParserLib
{
	typedef struct 
	{
		std::filesystem::path mediaPath;
		std::vector<std::filesystem::path> metaFiles;
	} MediaInfo;

	MEDIAPARSERLIB_API 
		std::vector<MediaInfo> parseForMedia(std::filesystem::path directoryToParse);
}
