#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include<vector>

#include "Entity/User/User.hpp"
#include "Service/User/UserService.hpp"
#include "Request/Request.hpp"
#include "View/Page/User/UserView.hpp"

using namespace std;

int main() {
    Request request;
    
    vector<User> users = UserService::readUsers();
    UserView::ListUser(users);  
    return 0;
}
