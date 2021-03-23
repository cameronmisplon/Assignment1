#ifndef _TagStruct_h
#define _TagStruct_h
#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>

namespace MSPCAM001
{
	struct tag_Information{
		std::string tag_name;
		int num_pairs;
		std::string tag_text;
	}tag;

	std::vector<tag_Information> tag_Collection;
	std::vector<std::string> edgeCases;
	std::string fileHolder;
	size_t found;
	void fileread(char* file);
	void tag_Add(std::string line);
	void tag_Clear();
	void print_Tags();
	void write_Tags();
	void single_Tag(std::string given_tag);
}
#endif
