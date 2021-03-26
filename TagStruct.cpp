#include "TagStruct.h"

namespace MSPCAM001
{

struct tag_Information
{
	std::string tag_name;
	int num_pairs;
	std::string tag_text;
}tag; // The data structure which is used to store the information relating to each tag
std::vector<tag_Information> tag_Collection;
std::vector<std::string> edgeCases;  //Adds the name of a nested tag as it appears, this is useful as any line not starting with a '<' will be added to the last tag stored in edgeCases
size_t found; //Used to store the length of the tag for that line
int edgeTag; // Used in the cases of nested tags to store which element we need to add the nested text to.
std::string fileHolder; //used to read in text file input line by line
std::string innerLine;

void fileread(std::string file)
{
	std::ifstream infile(file);
	while (getline (infile,fileHolder)){
		tag_Add(fileHolder);
	}
	infile.close();
}

void tag_Add(std::string line)
{
	if (line.substr(0,1)=="<") //otherwise the line must be added to a nested tag
	{
		found = line.find('>');
		if (line.find("/")==1){ //Doesn't have any text, just closes a previously nested tag.
			edgeCases.pop_back();
		}
		else{
			tag.tag_name=line.substr(1,found-1);
			tag.num_pairs=1;
			if (line.find('<',1)==std::string::npos){
			}
			else if (line.substr(line.find('<',1)+1,1)!="/")
			{
				size_t foundTemp = line.find('>',found+1);
				size_t found2 =line.find('>',foundTemp+1);
				innerLine = line.substr(line.find('<',1),found2-line.find('<',1)+1);
				line = line.substr(0,line.find('<',1))+line.substr(found2+1);
				tag_Add(innerLine);
			} 
			if (line.find('<',1)==std::string::npos) //tag isn't closed on the same line - must be a nested tag
			{
				edgeCases.push_back(tag.tag_name);
				tag.tag_text = line.substr(found+1);
			}
			else{
			        tag.tag_text = line.substr(found+1,line.find('<')-found-1); // The length of the substr is equal to the position of the start of the closing tag minus the length of the opening tag.
			}
			bool temp = true;
			if (tag.tag_text.find('<')!=std::string::npos)
			{
				tag.tag_text = tag.tag_text.substr(0,tag.tag_text.find('<'));
			}
			for (int i=0;i<tag_Collection.size();++i) //checks whether this tag has been seen before
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
		found = line.find('<'); //checks whether line has closing tag
		for (int o=0;o<tag_Collection.size();++o)
		{
			if (tag_Collection[o].tag_name==edgeCases[edgeCases.size()-1])
			{
				edgeTag=o;
				break;
			}
		}
		if (found == std::string::npos) //line doesn't have a closing tag
		{
		        if (tag_Collection[edgeTag].tag_text!="")
		        {
				tag_Collection[edgeTag].tag_text+=":"+line;
			}
			else{
				tag_Collection[edgeTag].tag_text = line;
			}
				
		}
		else{
			tag_Collection[edgeTag].tag_text+=":"+line.substr(0,found);
			edgeCases.pop_back(); //The presence of a closing tag means that the tag is no longer a nested tag
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
