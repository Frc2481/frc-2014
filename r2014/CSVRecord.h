/*
 * CSVRecord.h
 *
 *  Created on: Jan 31, 2014
 *      Author: Team2481
 */

#ifndef CSVRECORD_H_
#define CSVRECORD_H_
#include <WPILib.h>
#include <fstream>
#include <sstream>

class CSVRecord {
private:
	ofstream csvFile;
	CSVRecord();
	CSVRecord(CSVRecord& other);
public:
	static CSVRecord& getInstance();
	virtual ~CSVRecord();
	void Write(string value);
	void CloseFile();
};

#endif /* CSVRECORD_H_ */
