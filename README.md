# MediaParserLib
Library for parsing media content on local disks.

	typedef struct 
	{
		std::filesystem::path mediaPath;
		std::vector<std::filesystem::path> metaFiles;
	} MediaInfo;

	MEDIAPARSERLIB_API 
		std::vector<MediaInfo> parseForMedia(std::filesystem::path directoryToParse);
