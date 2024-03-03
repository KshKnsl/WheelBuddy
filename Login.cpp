#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // for Sleep function
using namespace std;

class User {
protected:
    string username;
    string password;

public:
    User(const string& uname, const string& pwd) : username(uname), password(pwd) {}

    string getUsername() const {
        return username;
    }

    string getPassword() const {
        return password;
    }

    virtual bool authenticate(const string& uname, const string& pwd) const {
        return (username == uname && password == pwd);
    }

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

    static bool checkUserExists(const string& filename, const string& uname) {
        ifstream fileIn(filename);
        if (!fileIn.is_open()) {
            cerr << "Error: Unable to open file for user data." << endl;
            return false;
        }

        string storedUsername, storedPassword;
        while (fileIn >> storedUsername >> storedPassword) {
            if (storedUsername == uname) {
                fileIn.close();
                return true; // User exists
            }
        }

        fileIn.close();
        return false; // User does not exist
    }
};

class Authenticate : public User {
public:
    Authenticate(const string& uname, const string& pwd) : User(uname, pwd) {}

    bool authenticate(const string& uname, const string& pwd) const override {
        return User::authenticate(uname, pwd);
    }
};

class Pages {
public:
    int homePage() {
        system("color 2A");
        cout << "\n  _____________________________________________________________________\n";
        cout << "||                                                                     ||\n";
        cout << "||   \\      /\\      / |===== |      |====== /=====\\ |\\    /| |=====    ||\n";
        cout << "||    \\    /  \\    /  |_____ |      |       |     | | \\  / | |_____    ||\n";
        cout << "||     \\  /    \\  /   |      |      |       |     | |  \\/  | |         ||\n";
        cout << "||      \\/      \\/    |===== |_____ |====== \\=====/ |      | |=====    ||\n";
        cout << "||                           TO WHEEL BUDDY                            ||\n";
        cout << "||     MENU:-                                                          ||\n";
        cout << "||   1. Login                                                          ||\n";
        cout << "||   2. Create a new account                                           ||\n";
        cout << "||   3. CLOSE WHEELBUDDY                                               ||\n";
        cout << "||_____________________________________________________________________||\n";
        cout << "ENTER YOUR CHOICE: ";
        int choice;
        cin >> choice;
        cout << "\nLoading.....\n";
        Sleep(3000);
        return choice;
    }

    void thankYouPage() {
        cout << "\nAre you sure you want to exit? (YES/NO)---";
        string ch;
        cin >> ch;
        cin.ignore();
        if (ch == "YES" || ch == "yes" || ch == "Yes") {
            system("cls");
            system("color 6D");
            cout << "\n\t\t\t\t\t\t  ________________________________________________________________________";
            cout << "\n\t\t\t\t\t\t||                                                                        ||";
            cout << "\n\t\t\t\t\t\t|| ---------- |     |    /\\    |\\    | |  /      \\     / |=====| |    |   ||";
            cout << "\n\t\t\t\t\t\t||     ||     |     |   /  \\   | \\   | | /        \\   /  |     | |    |   ||";
            cout << "\n\t\t\t\t\t\t||     ||     |=====|  /====\\  |  \\  | |/          \\=/   |     | |    |   ||";
            cout << "\n\t\t\t\t\t\t||     ||     |     | /      \\ |   \\ | |\\           |    |     | |    |   ||";
            cout << "\n\t\t\t\t\t\t||     ||     |     |/        \\|    \\| | \\          |    |=====| |====|   ||";
            cout << "\n\t\t\t\t\t\t||________________________________________________________________________||\n";
            Sleep(4000);
            system("cls");

            cout << "\n\n";
            system("color 5E");
            int choice = 0;
            cin.ignore();
            cout << "Would you like to provide feedback? (1: Yes, 2: No): ";
            cin >> choice;
            if (choice == 1) {
                string feedback;
                cout << "\nPlease provide your feedback (up to 999 characters):\n";
                cin.ignore();
                getline(cin, feedback);
                ofstream feedbackFile("Files/feedback.txt", ios::app);
                if (!feedbackFile.is_open())
                    cout << "Error saving feedback. Please try again later.\n";
                else {
                    feedbackFile << "\nFeedback:  " << feedback << ".\n";
                    feedbackFile.close();
                    cout << "Thank you for your feedback! It has been saved in feedback.txt.\n";
                }
                Sleep(1000);
                system("cls");
                cout << "\nRATE US NOW!!\n";
                cout << "1. *\n";
                cout << "2. **\n";
                cout << "3. ***\n";
                cout << "4. ****\n";
                cout << "5. *****\n";
                int rate;
                cin >> rate;
            }
            system("cls");
            system("color 26");
            cout << "\nGoodbye! Have a great day!\n";
            Sleep(3000);
            system("cls");
            exit(0);
        }
    }
};

string getUserInput(const string& prompt) {
    cout << prompt;
    string input;
    cin >> input;
    return input;
}

int main() {
    string filename = "Credentials.txt";
    Pages page;
    int choice = page.homePage();

    string username, password;

    switch (choice) {
    case 1:
        cout << "Enter username: ";
        username = getUserInput("");
        cout << "Enter password: ";
        password = getUserInput("");
        {
            Authenticate user(username, password);
            if (user.authenticate(username, password))
                cout << "Login successful. Welcome, " << username << "!\n";
            else {
                cout << "Login failed. Incorrect username or password.\n";
                cout << "Do you want to create a new account? (yes/no): ";
                string response;
                response = getUserInput("");
                if (response == "yes")
                    User::registerUser(filename);
            }
        }
        break;
    case 2:
        User::registerUser(filename);
        break;
    default:
        page.thankYouPage();
    }

    page.thankYouPage();
    return 0;
}
