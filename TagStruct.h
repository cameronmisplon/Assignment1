#ifndef _TagStruct_h
#define _TagStruct_h
#include <string.h> //neccessary for string manipulation in identifying nested tags
#include <vector>
#include <fstream> 
#include <iostream>
#include <cstdlib> //clears the terminal after every option to redisplay menu

namespace MSPCAM001
{
	void fileread(std::string file);
	void tag_Add(std::string line);
	void tag_Clear(); //ensures that multiple text file entries won't result in overlapping of tags
	void print_Tags();
	void write_Tags();
	void single_Tag(std::string given_tag);
	void message_Clear(); 
}
#endif
