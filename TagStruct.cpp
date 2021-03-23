#include "TagStruct.h"

void MSPCAM001::fileread(char* file)
{
	std::ifstream infile(file);
	while (getline (infile,MSPCAM001::fileHolder)){
		MSPCAM001::tag_Add(MSPCAM001::fileHolder);
	}
	infile.close();
}

void MSPCAM001::tag_Add(std::string line)
{
	if (line.substr(0,1)=="<")
	{
		MSPCAM001::found = line.find('>');
		if (line.find(1)=='/'){
			MSPCAM001::edgeCases.pop_back();
		}
		else{
			MSPCAM001::tag.tag_name=line.substr(1,found);
			MSPCAM001::tag.num_pairs=1;
			MSPCAM001::found = line.find('<',1);
			if (MSPCAM001::found==std::string::npos)
			{
				MSPCAM001::edgeCases.push_back(MSPCAM001::tag.tag_name);
				MSPCAM001::tag.tag_text = line.substr(line.find('>')+1);
			}
			else{
				MSPCAM001::tag.tag_text = line.substr(line.find('>')+1,MSPCAM001::found);
			}
			bool temp = true;
			for (int i=0;i<MSPCAM001::tag_Collection.size();++i)
			{
				if (tag_Collection[i].tag_name==MSPCAM001::tag.tag_name)
				{
					tag_Collection[i].num_pairs++;
					tag_Collection[i].tag_text += "." + MSPCAM001::tag.tag_text;
					temp = false;
					break;
				}
			}
			if (temp) 
			{
				MSPCAM001::tag_Collection.push_back(MSPCAM001::tag);
			}
                }
	}
	else
	{
		MSPCAM001::found = line.find('<');
		if (MSPCAM001::found == std::string::npos)
		{
			tag_Collection[tag_Collection.size()-1].tag_text+=":"+line;
		}
		else{
			tag_Collection[tag_Collection.size()-1].tag_text+=":"+line.substr(0,MSPCAM001::found);
			MSPCAM001::edgeCases.pop_back();
		
		}
	}
}

void tag_Clear()
{
	MSPCAM001::tag_Collection.clear();
	MSPCAM001::edgeCases.clear();
}

void print_Tags()
{
	for (int j=0;j<MSPCAM001::tag_Collection.size();++j)
	{
		std::cout << MSPCAM001::tag_Collection[j].tag_name << std::endl;
	}
}

void write_Tags()
{
	std::ofstream outfile("tag.txt");
	for (int k=0;k<MSPCAM001::tag_Collection.size();++k)
	{
		outfile << MSPCAM001::tag_Collection[k].tag_name;
		outfile << " ";
		outfile << MSPCAM001::tag_Collection[k].num_pairs;
		outfile << " ";
		outfile << MSPCAM001:: tag_Collection[k].tag_text << std::endl;
	}
}

void single_Tag(std::string given_tag)
{
	for (int l=0; l<MSPCAM001::tag_Collection.size();++l)
	{
		if (given_tag == MSPCAM001::tag_Collection[l].tag_name)
		{
			std::cout << MSPCAM001::tag_Collection[l].tag_name;
			std::cout << " ";
			std::cout << MSPCAM001:: tag_Collection[l].num_pairs;
			std::cout << " ";
			std::cout << MSPCAM001:: tag_Collection[l].tag_text << std::endl;
			break;
		}
	}
}
