/*
 * PersistedSettings.cpp
 *
 *  Created on: Jan 18, 2014
 *      Author: Team2481
 */

#include "PersistedSettings.h"
#include "RobotParameters.h"

PersistedSettings::PersistedSettings() {
	// TODO Auto-generated constructor stub
	LoadFromFile(ENCODER_OFFSET_FILENAME);
}

PersistedSettings::~PersistedSettings() {
	// TODO Auto-generated destructor stub
}

void PersistedSettings::LoadFromFile(std::string filename) {
	ifstream settingsFile(filename.c_str());
	if(!settingsFile.good())
	{
		return;
	}
	std::string line;
	while(!settingsFile.eof())
	{
		getline(settingsFile, line);
		std::vector<std::string> vec = split(line, '=');
		data.insert(std::pair<std::string,double>(vec[0],atof(vec[1].c_str())));
	}
	settingsFile.close();
}

void PersistedSettings::WriteToFile(std::string filename) {
	printf("pre write to file \n ");
	ofstream settingsFile(filename.c_str());
	
	typedef std::map<std::string, double >::iterator it_type;
	for(it_type iterator = data.begin(); iterator != data.end(); iterator++) {
		settingsFile << iterator->first;
		settingsFile << "=";
		settingsFile << iterator->second;
		settingsFile << "\r\n";
	}
	settingsFile.close();
	printf("post write to file \n ");
	
}

std::vector<std::string> &PersistedSettings::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> PersistedSettings::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
PersistedSettings& PersistedSettings::GetInstance(){
	static PersistedSettings instance;
	return instance;
}
double PersistedSettings::Get(string name){
	return data[name];
}

void PersistedSettings::Set(string name, double value){
	printf("pre Set \n");
	data[name] = value;
	WriteToFile(ENCODER_OFFSET_FILENAME);
	printf("post Set \n");
}

