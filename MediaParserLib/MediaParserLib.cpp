#include "pch.h"
#include "MediaParserLib.h"

#include <iostream>
#include <filesystem>
#include <vector>
#include <set>

namespace MediaParserLib
{
	namespace fs = std::filesystem;
	using std::cout, std::cerr, std::endl, std::vector, std::string;

	enum class MediaFileType
	{
		NONE,
		UNKNOWN,
		IMAGE,
		VIDEO
	};

	static MediaFileType getMediaFileType(fs::path filePath);

	MediaSummary parseForMedia(fs::path pathToParse)
	{
		MediaSummary summary;

		// confirm if directory to parse is a directory
		if (!fs::is_directory(pathToParse))
		{
			cerr << "Invalid directory to parse: " << pathToParse << endl;
			return summary;
		}

		for (auto& p : std::filesystem::recursive_directory_iterator(pathToParse))
		{
			summary.parsedFileCount++;
			summary.fileExtensionsCountMap[p.path().extension().string()]++;

			switch (getMediaFileType(p))
			{
			case MediaFileType::IMAGE:
				summary.imageMediaMap[p.path().string()] = {p};
				break;
			case MediaFileType::VIDEO:
				summary.videoMediaMap[p.path().string()] = {p};
				break;
			}
		}

		return summary;
	}

	static MediaFileType getMediaFileType(fs::path filePath)
	{
		std::set<string> imageMediaExtensions = { ".jpg", ".jpeg", ".png", ".svg"};
		std::set<string> videoMediaExtensions = { ".mp4" };

		if (imageMediaExtensions.find(filePath.extension().string()) != imageMediaExtensions.end())
		{
			return MediaFileType::IMAGE;
		}
		if (videoMediaExtensions.find(filePath.extension().string()) != videoMediaExtensions.end())
		{
			return MediaFileType::VIDEO;
		}

		return MediaFileType::UNKNOWN;
	}
}
