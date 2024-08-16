#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void urlDecode(char src[], char dest[]) {
    int i = 0, j = 0;
    while (src[i]) {
        //remplace espace
        if (src[i] == '+') 
        {
            dest[j] = ' ';
        } 
        //remplace charactere special
        else if (src[i] == '%' && src[i + 1] && src[i + 2]) 
        {
            int code;
            sscanf(&src[i + 1], "%2x", &code);
            dest[j] = (char)code;
            i += 2;
        } 
        else 
        {
            dest[j] = src[i];
        }
        i++;
        j++;
    }
    dest[j] = '\0';
}

int ServiceLogin(const char *filename, const char *login, const char *password) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;  
    }
    char fileLogin[50], filePassword[50];
    while (fscanf(file, "%s %s", fileLogin, filePassword) != EOF) {
        if (strcmp(fileLogin, login) == 0 && strcmp(filePassword, password) == 0) {
            fclose(file);
            return 1;  
        }
    }

    fclose(file);
    return 0;  
}


int main() {
    char *method = getenv("REQUEST_METHOD");
    int len;
    char *postData;

    if (method && strcmp(method, "POST") == 0) {
        len = atoi(getenv("CONTENT_LENGTH"));
        postData = (char *)malloc(len + 1);

        // Lecture ana donnee post
        fread(postData, 1, len, stdin);
        postData[len] = '\0';  

        // Extraction ana donnee
        char decodedData[1024];
        char login[50], password[50];
        urlDecode(postData, decodedData);
        sscanf(strstr(decodedData, "login=") + 6, "%[^&]", login);
        sscanf(strstr(decodedData, "password=") + 9, "%[^&]", password);

        //authentication
        if(ServiceLogin("users.txt",login,password)){
            printf("Status: 302 Found\n");
            printf("Location: /index.cgi?login=%s&password=%s\n\n",login,password);
        }

        // Resultat autentification successfil
        printf("Content-type: text/html\n\n");  
        printf("<html><body>");
        printf("<h1>Login: %s</h1>", login);
        printf("<h1>Password: %s</h1>", password);
        printf("<a href=\"%s\">%s</a>", "/", "retourer a la page d\'acceuil");


        printf("</body></html>");
        

    } else {
        printf("<html><body><h1>Erreur : méthode non supportée</h1></body></html>");
    }

    return 0;
}
