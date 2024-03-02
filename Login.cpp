#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class User {
private:
    string username;
    string password;

public:
     User(const string& uname, const string& pwd) {
       
        username = uname;
        password = pwd;
    }

    string getUsername() const {
        return username;
    }

    string getPassword() const {
        return password;
    }

    bool checkCredentials(const string& uname, const string& pwd) const {
        return (username == uname && password == pwd);
    }
};

class LoginManager {
private:
    vector<User> users;

public:
    LoginManager(const string& filename) {
        ifstream fileIn(filename);
        if (!fileIn.is_open()) {
            cerr << "Error: Unable to open file for user data." << endl;
            return;
        }

        string username, password;
        while (fileIn >> username >> password) {
            users.push_back(User(username, password));
        }

        fileIn.close();
    }

    bool authenticate(const string& uname, const string& pwd) const {
        for (const auto& user : users) {
            if (user.checkCredentials(uname, pwd)) {
                return true; 
            }
        }
        
        return false;
    }
};

class RegistrationManager {
public:
    static void registerUser(const string& filename) {
        string username, password;
        cout << "Enter a new username: ";
        cin >> username;
        cout << "Enter a new password: ";
        cin >> password;

        ofstream fileOut(filename, ios::app);
        if (!fileOut.is_open()) {
            cerr << "Error: Unable to open file for user data." << endl;
            return;
        }

        fileOut << username << " " << password << endl;
        fileOut.close();

        cout << "Account created successfully!\n";
    }
};

string getUserInput(const string& prompt) {
    cout << prompt;
    string input;
    cin >> input;
    return input;
}

int main() {
    string filename = "users.txt";
    LoginManager login(filename);

    cout << "Welcome to WHEEL BUDDY\n";
     cout <<"------------your onestop solution-------------\n";
    cout << "----------------------------------------------\n";
    

    string username, password;
    cout << "Enter username: ";
    username = getUserInput("");
    cout << "Enter password: ";
    password = getUserInput("");

    if (login.authenticate(username, password)) {
        cout << "Login successful. Welcome, " << username << "!\n";
    } 
    else
     {
        cout << "Login failed. Incorrect username or password.\n";
        cout << "Do you want to create a new account? (yes/no): ";
        string response;
        response = getUserInput("");
        if (response == "yes")
         {
            RegistrationManager::registerUser(filename);
        }
    }

    return 0;
}






