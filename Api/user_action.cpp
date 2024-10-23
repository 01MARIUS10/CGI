#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include<vector>

#include "../Entity/User/User.hpp"
#include "../Service/User/UserService.hpp"
#include "../Request/Request.hpp"
#include "../View/Page/User/UserView.hpp"

using namespace std;


int main() {
    string action;
    Request request;
    bool success(false);
    action     = request.getParams("action=");

    if(action =="delete"){
        int id = stoi(request.getParams("id="));
        success = UserService::deleteLine(id); 

        if (success) {
            cout << "Status: 302 Found\n";
            cout << "Location: /userLists.cgi\n\n";
        }
        else{
            cout << "Status: 302 Found\n";
            cout << "Location: /index.cgi\n\n";
        }
    }
    else if(action =="saveEdit" && request.isPost()){
        int id         = stoi(request.getParams("id="));
        string nom     = (request.getParams("nom="));
        string prenom  = (request.getParams("prenom="));
        string date    = (request.getParams("date_naissance="));
        string sexe    = (request.getParams("sexe="));
        User user(nom,prenom,date,sexe);
        
        bool U = UserService::updateLine(user,id); 
        if (success) {
            cout << "Status: 302 Found\n";
            cout << "Location: /userLists.cgi\n\n";
        }
        else{
            cout << "Status: 302 Found\n";
            cout << "Location: /index.cgi\n\n";
        }
    }    
    return 0;
}
