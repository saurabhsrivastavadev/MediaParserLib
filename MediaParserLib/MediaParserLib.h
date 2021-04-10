#pragma once

#include <filesystem>
#include <vector>
#include <unordered_map>

#ifdef MEDIAPARSERLIB_EXPORTS
#define MEDIAPARSERLIB_API __declspec(dllexport)
#else
#define MEDIAPARSERLIB_API __declspec(dllimport)
#endif

namespace MediaParserLib
{
	struct MediaInfo
	{
		std::filesystem::path mediaFile;
		std::vector<std::filesystem::path> metaFiles;
	};

	using MediaId = std::string;
	using FileExtension = std::string;
	using MediaMap = std::unordered_map<MediaId, MediaInfo>;
	using ExtensionCountMap = std::unordered_map<FileExtension, int>;

	struct MediaSummary
	{
		std::filesystem::path parsedPath;
		uint32_t parsedFileCount;

		// Map of all image files found with each media info
		MediaMap imageMediaMap;

		// Map of all video files found with each media info
		MediaMap videoMediaMap;

		// Count of various file extensions seen
		ExtensionCountMap fileExtensionsCountMap;

		// ctor
		MediaSummary() : 
			parsedPath(), parsedFileCount(0), imageMediaMap(), videoMediaMap(),
			fileExtensionsCountMap() {}
	};

	MEDIAPARSERLIB_API 
		MediaSummary parseForMedia(std::filesystem::path pathToParse);
}
