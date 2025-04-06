#include "FileReader.hpp"
#include <iostream>

FileReader* FileReader::sharedInstance = nullptr;

FileReader* FileReader::getInstance() {
    if (sharedInstance == nullptr) {
        sharedInstance = new FileReader();
    }
    return sharedInstance;
}

void FileReader::loadFrames(std::string name, std::string path) {
	std::cout << name << std::endl;
	FILE* file = fopen(path.c_str(), "rb");
	assert(file != 0);

	char readBuffer[65536];
	rapidjson::FileReadStream is(file, readBuffer, sizeof(readBuffer));
	rapidjson::Document doc;

	doc.ParseStream(is);
	fclose(file);

	for (auto it = doc["frames"].MemberBegin(); it != doc["frames"].MemberEnd(); ++it) {
		rapidjson::Value& frame = it->value["frame"];
		std::vector<int> temp;
		temp.push_back(frame["x"].GetInt());
		temp.push_back(frame["y"].GetInt());
		temp.push_back(frame["w"].GetInt());
		temp.push_back(frame["h"].GetInt());
		this->frames[name].push_back(temp);
	}
}

Frame FileReader::getFrame(std::string name, int index) {
    return this->frames[name][index];
}
