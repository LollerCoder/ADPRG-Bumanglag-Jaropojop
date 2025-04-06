#pragma once
#include "../rapidjson-1.1.0/rapidjson-1.1.0/include/rapidjson/filereadstream.h"
#include "../rapidjson-1.1.0/rapidjson-1.1.0/include/rapidjson/document.h"
#include "../rapidjson-1.1.0/rapidjson-1.1.0/include/rapidjson/rapidjson.h"
#include <vector>
#include <unordered_map>
#include "string"

// the file reader class

typedef std::vector<int> Frame; // a vector of frames 

class FileReader {
public:
	static FileReader* getInstance();
private:
	FileReader() {};

	FileReader(FileReader const&) {};

	FileReader& operator=(FileReader const&) {};

	static FileReader* sharedInstance;
public:
	void loadFrames(std::string name, std::string path); // loads the file and gets the frame info from the json
	Frame getFrame(std::string name, int index); // returns the specific frame
private:
	std::unordered_map<std::string, std::vector<Frame>> frames; // stores a vector of frames with their names as key
};

