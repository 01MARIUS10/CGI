#include "ErrorView.hpp"

void ErrorView::ShowError(vector<string> errors){
    cout << "Content-type: text/html\n\n";
    cout << "<!DOCTYPE html>\n<html lang=\"fr\">\n<head>\n";
    cout << "<meta charset=\"UTF-8\">\n";
    cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    cout << "<title>ERROR </title>\n";
    cout << "<link rel=\"stylesheet\" href=\"/assets/css/style.css\">\n</head>\n<body>\n";
    
    for(int i=0;i<(int)errors.size();i++){
        cout<<"<h1>>"<<errors[i]<<"<h1>>";
    }
}
