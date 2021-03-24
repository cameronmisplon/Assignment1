#include "TagStruct.h"

namespace MSPCAM001
{

struct tag_Information
{
	std::string tag_name;
	int num_pairs;
	std::string tag_text;
}tag;
std::vector<tag_Information> tag_Collection;
std::vector<std::string> edgeCases;
size_t found;

void fileread(std::string file)
{
	std::ifstream infile(file);
	std::string fileHolder;
	while (getline (infile,fileHolder)){
		tag_Add(fileHolder);
	}
	infile.close();
}

void tag_Add(std::string line)
{
	if (line.substr(0,1)=="<")
	{
		found = line.find('>');
		if (line.find("/")==1){
			edgeCases.pop_back();
		}
		else{
			tag.tag_name=line.substr(1,found-1);
			tag.num_pairs=1;
			if (line.find('<',1)==std::string::npos)
			{
				edgeCases.push_back(tag.tag_name);
				tag.tag_text = line.substr(found+1);
			}
			else{
			        tag.tag_text = line.substr(found+1,line.find('/')-found-2); 
			}
			bool temp = true;
			for (int i=0;i<tag_Collection.size();++i)
			{
				if (tag_Collection[i].tag_name==tag.tag_name)
				{
					tag_Collection[i].num_pairs++;
					tag_Collection[i].tag_text += ":" + tag.tag_text;
					temp = false;
					break;
				}
			}
			if (temp) 
			{
				tag_Collection.push_back(tag);
			}
                }
	}
	else
	{
		found = line.find('<');
		if (found == std::string::npos)
		{
			tag_Collection[tag_Collection.size()-1].tag_text+=":"+line;
		}
		else{
			tag_Collection[tag_Collection.size()-1].tag_text+=":"+line.substr(0,found);
			edgeCases.pop_back();
		
		}
	}
}

void tag_Clear()
{
	tag_Collection.clear();
	edgeCases.clear();
}

void print_Tags()
{
	for (int j=0;j<tag_Collection.size();++j)
	{
		std::cout << tag_Collection[j].tag_name << std::endl;
	}
}

void write_Tags()
{
	std::ofstream outfile("tag.txt");
	for (int k=0;k<tag_Collection.size();++k)
	{
		outfile << tag_Collection[k].tag_name;
		outfile << " ";
		outfile << tag_Collection[k].num_pairs;
		outfile << " ";
		outfile << tag_Collection[k].tag_text << std::endl;
	}
	outfile.close();
}

void single_Tag(std::string given_tag)
{
	for (int l=0; l<tag_Collection.size();++l)
	{
		if (given_tag == tag_Collection[l].tag_name)
		{
			std::cout << tag_Collection[l].tag_name;
			std::cout << " ";
			std::cout << tag_Collection[l].num_pairs;
			std::cout << " ";
			std::cout << tag_Collection[l].tag_text << std::endl;
			break;
		}
	}
}
void message_Clear()
{
	system("clear");
}
}
