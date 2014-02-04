/*
 * CSVRecord.cpp
 *
 *  Created on: Jan 31, 2014
 *      Author: Team2481
 */

#include "CSVRecord.h"

CSVRecord::CSVRecord() : csvFile("HeadingData.csv", ofstream::app){

}

CSVRecord::CSVRecord(CSVRecord& other) {
	
}

CSVRecord::~CSVRecord() {
}

CSVRecord& CSVRecord::getInstance() {
	static CSVRecord instance;
	return instance;
}

void CSVRecord::Write(string value){
//	printf("%s", value.c_str());
//	csvFile << value;
//	csvFile << "\n";
//	csvFile.flush();
//	printf("Hi");
//	
//	ofstream csvFileA("HeadingDataA.csv", ofstream::app);
//	csvFileA << " Hi ";
//	csvFileA << value;
//	csvFileA << "\n";
//	csvFileA.flush();
//	csvFileA.close();

}
void CSVRecord::CloseFile(){
	//csvFile.close();
}
