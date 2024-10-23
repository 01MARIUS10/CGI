#include "Request.hpp"

Request::Request(){
    method = getenv("REQUEST_METHOD");
    if (method.c_str() && strcmp(method.c_str(), "POST") == 0) {
        int len = atoi(getenv("CONTENT_LENGTH"));
        string postData(len, '\0');
        cin.read(&postData[0], len);
        Request::urlDecode(postData, decodedData);
    }
    else if(method.c_str() && strcmp(method.c_str(), "GET") == 0){
        const char* getData = getenv("QUERY_STRING");
        Request::urlDecode(getData, decodedData);
    } else {
        cout << "Content-type: text/html\n\n";
        cout << "<html><body><h1>Erreur : méthode non supportée|"<<method<<"|</h1></body></html>";
    }
}

bool Request::isPost(){
    if(method=="POST") return true;
    return false;
}
bool Request::isGet(){
    if(method=="GET") return true;
    return false;
}

void Request::urlDecode(const string& src, string& dest) {
    dest.clear();
    for (size_t i = 0; i < src.length(); ++i) {
        if (src[i] == '+') {
            dest += ' ';
        } else if (src[i] == '%' && i + 2 < src.length()) {
            int code;
            sscanf(src.substr(i + 1, 2).c_str(), "%x", &code);
            dest += static_cast<char>(code);
            i += 2;
        } else {
            dest += src[i];
        }
    }
}


string Request::getParams(string str){
    int size = (int)str.size();
    string param("");
    size_t paramPos = decodedData.find(str);
    if (paramPos != string::npos) {
        param = decodedData.substr(paramPos + size, decodedData.find('&', paramPos) - (paramPos + size));
    }
    return param;
}