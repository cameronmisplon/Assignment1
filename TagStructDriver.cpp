#include "TagStruct.h"
#include <string>
#include <iostream>

int main(int argc, char** argv) //Takes in user input and branches based on which option the user chooses. Loops endlessly until the user chooses the q option
{
	std::string option;
	std::string fileName;
        std::string chosenTag;
	std::string returnKey;
	std::string message = "r: Read and process tag file \np:Print all tags \nd:Write data to tag.txt \nl: Print tag data for a tag you enter \nq: Quit \nEnter an option (r,p,d,l) or q to quit, and press return.";
	for(;;)
	{
		std::cout << message << std::endl;
		std::cin >> option;
		if (option=="q")
		{
			MSPCAM001::message_Clear();
			break;
		}
		else if (option=="r")
		{
			std::cout << "Enter text file name (with .txt), and press return" << std::endl;
			MSPCAM001::tag_Clear();
			std::cin >> fileName;
			MSPCAM001::fileread(fileName);
		}
		else if (option=="p")
		{
			MSPCAM001::print_Tags();
		}
		else if (option=="d")
		{
			MSPCAM001::write_Tags();
		}
		else if (option=="l")
		{
			std::cout << "Please enter your desired tag:" << std::endl;
			std::cin >> chosenTag;
			MSPCAM001::single_Tag(chosenTag);
		}
		std::cout << "Enter 'next' to re-display menu:" << std::endl;
		std::cin >> returnKey;
		MSPCAM001::message_Clear();
	}
	return 0;
}

