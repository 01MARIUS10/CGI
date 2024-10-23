#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include "../../Entity/User/User.hpp" 
using namespace std;

class UserService {
    public:
        static vector<User> readUsers() ;
        static User getUser(int i) ;
        static int  registerUser(User U);
        static bool loginUser(string login,string password);
        static bool deleteLine(int lineNumber);
        static bool updateLine(User U, int lineNumber);
};