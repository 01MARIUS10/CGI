#ifndef ERRORVIEW_HPP
#define ERRORVIEW_HPP

#include <iostream>
#include <vector>
#include "../../../Entity/User/User.hpp"

using namespace std;

class ErrorView {
public:
    static void ShowError(vector<string> errors);
};

#endif 
