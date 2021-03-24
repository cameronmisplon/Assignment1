#ifndef _TagStruct_h
#define _TagStruct_h
#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>

namespace MSPCAM001
{
	void fileread(std::string file);
	void tag_Add(std::string line);
	void tag_Clear();
	void print_Tags();
	void write_Tags();
	void single_Tag(std::string given_tag);
	void message_Clear();
}
#endif
