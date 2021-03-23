#ifndef _TagStruct_h
#define _TagStruct_h
#include <string>
#include <vector>
#include <fstream>

struct Tag_Information{
	std::string tag_name;
	int num_pairs;
	std::string tag_text;
};

std::vector<Tag_Information> Tag_Collection;
std::string fileHolder;
int counter;
char* fileName;
ifstream infile;
ofstream outfile;

void fileread(char* file);
void Tag_Clear();
void Tag_Add(std::string line);
