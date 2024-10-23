#ifndef USERVIEW_HPP
#define USERVIEW_HPP

#include <iostream>
#include <vector>
#include "../../../Entity/User/User.hpp"

using namespace std;

class UserView {
public:
    static void ListUser(vector<User> users);
    static void ShowUser(User user);
    static void editUser(User user,int index);
};

#endif 
