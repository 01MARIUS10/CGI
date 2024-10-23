#include "User.hpp"
#include <regex>
using namespace std;

string User::delimiter = "||+||";

string User::filename ="/var/www/SITE/site3/Data/users.txt";

User::User(string nom, string prenom, string dateNaissance, string sexe)
{
    nom = nom;
    prenom = prenom;
    dateNaissance = dateNaissance ;
    sexe = sexe;
}
User::User(string str) {
    int pos(0); 
    string delimiter = User::delimiter;

    pos = str.find(delimiter);
    nom = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());

    pos = str.find(delimiter);
    prenom = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());

    pos = str.find(delimiter);
    dateNaissance = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());
    sexe = str; 
}

string User::getNom() const { return nom; }
string User::getPrenom() const { return prenom; }
string User::getDateNaissance() const { return dateNaissance; }
string User::getSexe() const { return sexe; }

void User::setNom(const string nom) { this->nom = nom; }
void User::setPrenom(const string prenom) { this->prenom = prenom; }
void User::setDateNaissance(const string dateNaissance) { this->dateNaissance = dateNaissance; }
void User::setSexe(const string sexe) { this->sexe = sexe; }
void User::setByLine(const string line){
    int pos(0); 
    string str = line;
    string delimiter = User::delimiter;

    pos = str.find(delimiter);
    nom = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());

    pos = str.find(delimiter);
    prenom = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());

    pos = str.find(delimiter);
    dateNaissance = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());
    sexe = str; 
}


string User::toString() {
    return nom + " " + prenom + " " + dateNaissance + " " + sexe;
}

bool User::isValidate()
{
    bool validate = true;

    if (nom.empty()) {
        validate = false;
    }

    if (prenom.empty()) {
        validate = false;
    }

    regex dateRegex(R"(\d{4}-\d{2}-\d{2})");
    
    if (dateNaissance.empty() || !regex_match(dateNaissance, dateRegex)) {
        validate = false;
    }

    if (sexe != "homme" && sexe != "femme" && sexe != "autre") {
        validate = false;
    }

    return validate;
}
vector<string> User::validationError()
{
    vector<string> mssgs ;

    if (nom.empty()) {
        mssgs.push_back("le nom est vide");
    }

    if (prenom.empty()) {
        mssgs.push_back("le prenom est vide");
    }

    regex dateRegex(R"(\d{4}-\d{2}-\d{2})");
    
    if (dateNaissance.empty()){
        mssgs.push_back("la date de naissance est vide");
    } 
    if(!regex_match(dateNaissance, dateRegex)) {
        mssgs.push_back("la date de naissance est invalide");
    }

    if (sexe != "homme" && sexe != "femme" && sexe != "autre") {
        mssgs.push_back("le sexe est invalide");
    }

    return mssgs;
}





