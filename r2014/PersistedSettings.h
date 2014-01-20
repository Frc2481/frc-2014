/*
 * PersistedSettings.h
 *
 *  Created on: Jan 18, 2014
 *      Author: Team2481
 */

#ifndef PERSISTEDSETTINGS_H_
#define PERSISTEDSETTINGS_H_

#include <iostream.h>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

class PersistedSettings {
private:
	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
	std::vector<std::string> split(const std::string &s, char delim);
	
public:
	PersistedSettings();
	virtual ~PersistedSettings();
	void WriteToFile(std::string filename);
	void LoadFromFile(std::string filename);
	std::map<std::string, double>  data;
};

#endif /* PERSISTEDSETTINGS_H_ */
