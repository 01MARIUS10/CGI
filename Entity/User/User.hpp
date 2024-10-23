#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class User {
    public:
        User(string nom, string prenom, string dateNaissance, string sexe);
        User(string str);
        string toString() ;
        
        string getNom() const;
        string getPrenom() const;
        string getDateNaissance() const;
        string getSexe() const;

        void setNom(const string nom);
        void setPrenom(const string prenom);
        void setDateNaissance(const string dateNaissance);
        void setSexe(const string sexe);
        void setByLine(const string line);
        bool isValidate();

        static string delimiter;
        static string filename;
        vector<string> validationError();

    private:
        string nom;
        string prenom;
        string dateNaissance;
        string sexe;
};

#endif 
