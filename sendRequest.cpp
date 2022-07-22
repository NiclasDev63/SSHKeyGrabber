#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#pragma comment (lib, "cpr.lib")
#pragma comment (lib, "libcurl.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "Crypt32.lib")

using json = nlohmann::json;
using std::cout;
using std::endl;


int sendRequest(std::string& url, std::string& message)
{
    json test;
    test["content"] = message;
    cpr::Response r = cpr::Post(cpr::Url{ url },
        cpr::Body{ test.dump() },
        cpr::Header{ {"Content-Type", "application/json"}, {"User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11"} });
    //if (r.status_code == 204)
    //{
    //    cout << "Content send succesfully" << endl;
    //}
    return 0;
}