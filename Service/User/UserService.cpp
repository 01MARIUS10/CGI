#include "UserService.hpp"

vector<User> UserService::readUsers() {
    ifstream file(User::filename);
    vector<User> users;
    string line;
    
    if (!file) {
        cerr << "Erreur lors de l'ouverture du fichier pour lecture." << endl;
        return users;
    }

    while (getline(file, line)) {
        User user(line); 
        users.push_back(user);
    }

    file.close();
    return users;
}
User UserService::getUser(int i){
    ifstream file(User::filename);
    User user("");
    int compt(1);
    string line;
    
    if (!file) {
        cerr << "Erreur lors de l'ouverture du fichier pour lecture." << endl;
        return user;
    }

    while (getline(file, line)) {
        if(compt==i){
            user.setByLine(line); 
        }
        compt++;
    }

    file.close();
    return user;
}


int UserService::registerUser(User U) {
    ofstream file;
    file.open(User::filename, ios::app);

    if (!file) {  
        cerr << "Erreur lors de l'ouverture du fichier. Code d'erreur : " << strerror(errno) << endl;
        return -1;
    }
    
    file << U.getNom() << User::delimiter << U.getPrenom() << User::delimiter << U.getDateNaissance() << User::delimiter << U.getSexe() << endl;  
    file.close();
    return 1;
}

bool UserService::loginUser(string login, string password) {
    ifstream file(User::filename);
    if (!file.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier.\n";
        return false;
    }
    
    string fileLogin, filePassword;
    while (file >> fileLogin >> filePassword) {
        if (fileLogin == login && filePassword == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


bool UserService::deleteLine(int lineNumber) {
    ifstream infile(User::filename);
    vector<string> lines;
    string line;
    int currentLine = 1;

    if (infile.is_open()) {
        while (getline(infile, line)) {
            if (currentLine != lineNumber) {
                lines.push_back(line);
            }
            currentLine++;
        }
        infile.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier en lecture." << endl;
        return false;
    }
    ofstream outfile(User::filename);
    if (outfile.is_open()) {
        for (const auto& l : lines) {
            outfile << l << endl;
        }
        outfile.close();
        return true;
    } else {
        cerr << "Impossible d'ouvrir le fichier en écriture." << endl;
    }
    return false;
}

bool UserService::updateLine(User user, int lineNumber) {
    ifstream infile(User::filename);
    vector<string> lines;
    string line;
    int currentLine = 1;

    string updateLine(user.getNom() + User::delimiter + user.getPrenom() + User::delimiter + user.getDateNaissance() + User::delimiter + user.getSexe() );

    if (infile.is_open()) {
        while (getline(infile, line)) {
            if (currentLine != lineNumber) {
                lines.push_back(line);
            }
            else{
                lines.push_back(updateLine);
            }
            currentLine++;
        }
        infile.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier en lecture." << endl;
        return false;
    }
    ofstream outfile(User::filename);
    if (outfile.is_open()) {
        for (const auto& l : lines) {
            outfile << l << endl;
        }
        outfile.close();
        return true;
    } else {
        cerr << "Impossible d'ouvrir le fichier en écriture." << endl;
    }
    return false;
}
