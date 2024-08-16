#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

void getvalue (string get, string *val1, string *val2) 
{
    int pos1 = get.find('=');
    int pos2 = get.find('&');
    *val1 = get.substr(pos1 + 1,pos2 - pos1 - 1);

    int pos3 = get.find('=',pos2);
    string cle2 = get.substr(pos2 + 1,pos3 - pos2 - 1);
    *val2 = get.substr(pos3 + 1);
}

bool compare(string str) {
    string val1,val2,data1 = "tsy ato",data2;

    ifstream fs("/var/www/site/site1/data.txt");

    if (fs.fail()) {
        cout << "erreur lors de l'ouverture du fichier";
    }
    else{
        fs >> data1 >> data2;
    }

    getvalue(str, &val1, &val2);    
    return (val1 == data1 && val2 == data2);
}

int main() {
    string input = getenv("QUERY_STRING");

    cout << "Content-type: text/html\n\n";

    if (compare(input)) {
        cout << "<!DOCTYPE html>\n";
        cout << "<html>\n";
        cout << "<head><meta charset='UTF-8'>\n";
        cout << "<title>Bienvenue</title>\n";
        cout << "<style>\n";
        cout << "body { font-family: Arial, sans-serif; background-color: #f0f0f0; color: #333; }\n";
        cout << ".container { max-width: 600px; margin: 100px auto; padding: 20px; background-color: #fff; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); }\n";
        cout << "h1 { color: #4CAF50; }\n";
        cout << "p { font-size: 18px; }\n";
        cout << "</style>\n";
        cout << "</head>\n";
        cout << "<body>\n";
        cout << "<div class=\"container\">\n";
        cout << "<h1>Bienvenue !</h1>\n";
        cout << "<p>Vous êtes connecté avec succès.</p>\n";
        cout << "</div>\n";
        cout << "</body>\n";
        cout << "</html>\n";
    } else {
        cout << "<!DOCTYPE html>\n";
        cout << "<html lang=\"en\">\n";
        cout << "<head>\n";
        cout << "    <meta charset=\"UTF-8\">\n";
        cout << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
        cout << "    <title>Document</title>\n";
        cout << "    <style>\n";
        cout << "        body {\n";
        cout << "            font-family: Arial, sans-serif;\n";
        cout << "            background-color: #f0f0f0;\n";
        cout << "            color: #333;\n";
        cout << "            display: flex;\n";
        cout << "            justify-content: center;\n";
        cout << "            align-items: center;\n";
        cout << "            height: 100vh;\n";
        cout << "            margin: 0;\n";
        cout << "        }\n";
        cout << "        form {\n";
        cout << "            background-color: #fff;\n";
        cout << "            padding: 20px;\n";
        cout << "            border-radius: 8px;\n";
        cout << "            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);\n";
        cout << "            width: 300px;\n";
        cout << "            display: flex;\n";
        cout << "            flex-direction: column;\n";
        cout << "        }\n";
        cout << "        label {\n";
        cout << "            margin-bottom: 10px;\n";
        cout << "            font-weight: bold;\n";
        cout << "        }\n";
        cout << "        input[type=\"text\"],\n";
        cout << "        input[type=\"password\"] {\n";
        cout << "            width: 100%;\n";
        cout << "            padding: 8px;\n";
        cout << "            margin-bottom: 15px;\n";
        cout << "            border: 1px solid #ccc;\n";
        cout << "            border-radius: 4px;\n";
        cout << "            font-size: 16px;\n";
        cout << "        }\n";
        cout << "        input[type=\"submit\"] {\n";
        cout << "            background-color: #4CAF50;\n";
        cout << "            color: white;\n";
        cout << "            padding: 10px;\n";
        cout << "            border: none;\n";
        cout << "            border-radius: 4px;\n";
        cout << "            cursor: pointer;\n";
        cout << "            font-size: 16px;\n";
        cout << "        }\n";
        cout << "        input[type=\"submit\"]:hover {\n";
        cout << "            background-color: #45a049;\n";
        cout << "        }\n";
        cout << "    </style>\n";
        cout << "</head>\n";
        cout << "<body>\n";
        cout << "    <form action=\"/cgi-bin/traitement.cgi\" method=\"get\">\n";
        cout << "        <label for=\"login\">Login</label>\n";
        cout << "        <input type=\"text\" name=\"login\" id=\"login\">\n";
        cout << "        <label for=\"mdp\">mot de passe</label>\n";
        cout << "        <input type=\"password\" name=\"mdp\" id=\"mdp\">\n";
        cout << "        <input type=\"submit\" value=\"Se connecter\">\n";
        cout << "    </form>\n";
        cout << "</body>\n";
        cout << "</html>\n";
    }
    

    return 0;
}
