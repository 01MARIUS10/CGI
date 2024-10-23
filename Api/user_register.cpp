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
    string nom, prenom,dateNaissance,sexe;
    Request request;

    nom           = request.getParams("nom=");
    prenom        = request.getParams("prenom=");
    dateNaissance = request.getParams("date_naissance=");
    sexe          = request.getParams("sexe=");

    User user(nom,prenom,dateNaissance,sexe);
    if(user.isValidate()){
        int isRegister= UserService::registerUser(user);
        if(isRegister){
            cout << "Status: 302 Found\n";
            cout << "Location: /userLists.cgi\n\n";
        }
        else{
            cout << "Status: 302 Found\n";
            cout << "Location: /index.cgi\n\n";
        }
    }
    else{
        cout << "Status: 302 Found\n";
        cout << "Location: /index.cgi\n\n";
    }

    return 0;
}
