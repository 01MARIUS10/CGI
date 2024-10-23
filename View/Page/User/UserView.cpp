#include "UserView.hpp"

void UserView::ListUser(vector<User> users ){
    cout << "Content-type: text/html\n\n";
    cout << "<!DOCTYPE html>\n<html lang=\"fr\">\n<head>\n";
    cout << "<meta charset=\"UTF-8\">\n";
    cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    cout << "<title>Liste des Utilisateurs</title>\n";
    cout << "<link rel=\"stylesheet\" href=\"/assets/css/style.css\">\n</head>\n<body>\n";
    cout << " <div class=\"flex justify-between align-center \">\n";
    cout << "<h2>Liste des Utilisateurs</h2>\n";
    cout << "<button type=\"button\"><a href=\"/inscription.html\">Ajouter un utilisateur</a></button></div>\n";
    cout << "<table>\n<thead>\n<tr>\n";
    cout << "<th>ID</th>\n<th>Nom</th>\n<th>Prénom</th>\n<th>Date de naissance</th>\n<th>Sexe</th>\n<th>Actions</th>\n";
    cout << "</tr>\n</thead>\n<tbody>\n";

    for (int i = 0; i < (int)users.size(); ++i) {
        cout << "<tr>\n";
        cout << "<td>" << i+1 << "</td>\n";
        cout << "<td>" << users[i].getNom() << "</td>\n";
        cout << "<td>" << users[i].getPrenom() << "</td>\n";
        cout << "<td>" << users[i].getDateNaissance() << "</td>\n";
        cout << "<td>" << users[i].getSexe() << "</td>\n";
        cout << "<td>\n<div class=\"actions\">\n";
        cout << "<button class=\"btn btn-view\">Voir</button>\n";
        cout << "<button class=\"btn btn-edit\"><a href=\"userEdit.cgi?action=edit&id="<<i+1<<"\">Modifier</a></button>\n";
        cout << "<button class=\"btn btn-delete\"><a href=\"Api/user_action.cgi?action=delete&id="<<i+1<<"\">Supprimer</a></button>\n";
        cout << "</div>\n</td>\n</tr>\n";
    }
};


void UserView::ShowUser(User user ){
    cout << "Content-type: text/html\n\n";
    cout << "<!DOCTYPE html>\n<html lang=\"fr\">\n<head>\n";
    cout << "<meta charset=\"UTF-8\">\n";
    cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    cout << "<title>voir Utilisateur</title>\n";
    cout << "<link rel=\"stylesheet\" href=\"/assets/css/style.css\">\n</head>\n<body>\n";
    cout << " <div class=\"flex justify-between align-center \">\n";
    cout << "<h2>voir Utilisateur</h2>\n";
    cout<< user.getNom()<<user.getPrenom()<<user.getSexe()<<endl;
}


void UserView::editUser(User user,int index) {
    cout << "Content-type: text/html\n\n";
    cout << "<!DOCTYPE html>\n<html lang=\"fr\">\n<head>\n";
    cout << "<meta charset=\"UTF-8\">\n";
    cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    cout << "<title>voir Utilisateur</title>\n";
    cout << "<link rel=\"stylesheet\" href=\"/assets/css/style.css\">\n</head>\n<body>\n";
    
    cout << "<form class=\"\" action=\"Api/user_action.cgi\" method=\"POST\">\n";
    cout << "        <input type=\"text\" name=\"action\" value=\"saveEdit"<<"\">\n";
    cout << "        <input type=\"text\" name=\"id\" value=\""<<index <<"\">\n";

    // Nom
    cout << "    <div class=\"form\">\n";
    cout << "        <label for=\"nom\">Nom :</label>\n";
    cout << "        <input type=\"text\" name=\"nom\" value=\"" << user.getNom() << "\">\n";
    cout << "    </div>\n";

    // Prénom
    cout << "    <div class=\"form\">\n";
    cout << "        <label for=\"prenom\">Prenom :</label>\n";
    cout << "        <input type=\"text\" name=\"prenom\" value=\"" << user.getPrenom() << "\">\n";
    cout << "    </div>\n";

    // Date de Naissance
    cout << "    <div class=\"form\">\n";
    cout << "        <label for=\"date_naissance\">Date de Naissance :</label><br>\n";
    cout << "        <input type=\"date\" id=\"date_naissance\" name=\"date_naissance\" value=\"" << user.getDateNaissance() << "\" required><br><br>\n";
    cout << "    </div>\n";

    // Sexe
    cout << "    <div class=\"form\">\n";
    cout << "        <label for=\"sexe\">Sexe :</label><br>\n";

    // Homme
    cout << "        <input type=\"radio\" id=\"homme\" name=\"sexe\" value=\"homme\"";
    if (user.getSexe() == "homme") cout << " checked";
    cout << " required>\n";
    cout << "        <label for=\"homme\">Homme</label><br>\n";

    // Femme
    cout << "        <input type=\"radio\" id=\"femme\" name=\"sexe\" value=\"femme\"";
    if (user.getSexe() == "femme") cout << " checked";
    cout << ">\n";
    cout << "        <label for=\"femme\">Femme</label><br>\n";

    // Autre
    cout << "        <input type=\"radio\" id=\"autre\" name=\"sexe\" value=\"autre\"";
    if (user.getSexe() == "autre") cout << " checked";
    cout << ">\n";
    cout << "        <label for=\"autre\">Autre</label><br><br>\n";
    cout << "    </div>\n";

    cout << "    <div class=\"action\">\n";
    cout << "        <button type=\"submit\">enregistrer</button>\n";
    cout << "    </div>\n";

    cout << "</form>\n";
}