#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

class Request {
    public : 
        Request();
        string method;
        string getParams(string str);
        static void urlDecode(const string& src, string& dest) ;
        bool isPost();
        bool isGet();
    private:
        string decodedData;

};