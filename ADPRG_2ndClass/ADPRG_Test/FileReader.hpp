#pragma once
#include "../rapidjson-1.1.0/rapidjson-1.1.0/include/rapidjson/filereadstream.h"
#include "../rapidjson-1.1.0/rapidjson-1.1.0/include/rapidjson/document.h"
#include "../rapidjson-1.1.0/rapidjson-1.1.0/include/rapidjson/rapidjson.h"
#include <vector>
#include <unordered_map>
#include "string"

typedef std::vector<int> Frame;

class FileReader {
public:
	static FileReader* getInstance();
private:
	FileReader() {};

	FileReader(FileReader const&) {};

	FileReader& operator=(FileReader const&) {};

	static FileReader* sharedInstance;
public:
	void loadFrames(std::string name, std::string path);
	Frame getFrame(std::string name, int index);
private:
	std::unordered_map<std::string, std::vector<Frame>> frames;
};

