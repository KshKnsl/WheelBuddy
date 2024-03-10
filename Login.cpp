#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> //for usleep function
using namespace std;

class Pages; // Forward declaration

class User
{
private:
    string username;
    string password;

public:
    User(string uname, string pwd)
    {
        username = uname;
        password = pwd;
    }

    string getUsername()
    {
        return username;
    }

    string getPassword()
    {
        return password;
    }

    bool checkCredentials(string uname,string pwd)
    {
        return (username == uname && password == pwd);
    }
};
class LoginManager
{
private:
    vector<User> users;
public:
    LoginManager(string filename)
    {
        ifstream fileIn(filename);
        if (!fileIn.is_open())
        {
            cerr << "Error: Unable to open file for user data." << endl;
            return;
        }
        string username, password;
        while (fileIn >> username >> password)
            users.push_back(User(username, password));
        fileIn.close();
    }
    bool authenticate(string uname,string pwd)
    {
        for(auto &user : users)
        {
            if (user.checkCredentials(uname, pwd))
            {
                return true;
            }
        }
        return false;
    }
    User* loginScreen()
    {
        system("cls");
        cout << "**************************************\n";
        cout << "*                 Login              *\n";
        cout << "**************************************\n";
        string username, password;
        cout << "Enter username: ";
        cin>>username;
        cout << "Enter password: ";
        cin>>password;
        User *ob = new User(username, password);
        if(authenticate(username, password))
            return ob;
        else
        {
            User *o = new User("null","null");
            return o;
        }
    }
};

class RegistrationManager
{
public:
    static void registerUser(string filename)
    {
        system("cls");
        system("color 8D");
        cout << "*****************************************\n";
        cout << "*         CREATE A NEW ACCOUNT          *\n";
        cout << "*****************************************\n";
        string username, password;
        cout << "Enter a new username: ";
        cin >> username;
        cout << "Enter a new password: ";
        cin >> password;

        ofstream fileOut(filename, ios::app);
        if (fileOut.is_open())
        {
            fileOut << username << " " << password << endl;
            fileOut.close();
            cout << "Account created successfully!\n";
        }
        else
        {
             cerr << "Error: Unable to open file for user data." << endl;
             return;
        }
        system("cls");
    }
};

class Pages // Define Pages class before main
{
public:
    void fileLoadingPage()
    {
        system("color 6B");
        ifstream in("CodeFiles/Welcome.txt"); // displaying welcome ASCII image text on output screen fn1353
        char str[1000];
        while (in)
        {
            in.getline(str, 1000); // delim defaults to '\n' cp
            if (in)   cout << str << endl;
        }
        in.close();
        Sleep(1000);
        cout << "\nStarting the program please wait....." << endl;
        Sleep(1000);
        cout << "\nloading up files....." << endl;
        Sleep(1000);
        system("cls");
    }
    // this function returns the choice of the user
    int homePage()
    {
        system("color 7A");
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
        cin>>choice;
        cout << "\nLoading.....\n";
        Sleep(1000);
        return choice;
    }
    void thankYouPage()
    {
        cout << "\nAre you sure you want to exit? (YES/NO)---";
        string ch;
        cin >> ch;
        cin.ignore();
        if (ch == "YES" || ch == "yes" || ch == "Yes")
        {
            system("cls");
            system("color 6D");
            cout << " ________  __                            __              __      __                         __  __ \n";
            cout << "/        |/  |                          /  |            /  \\    /  |                       /  |/  |\n";
            cout << "$$$$$$$$/ $$ |____    ______   _______  $$ |   __       $$  \\  /$$/______   __    __       $$ |$$ |\n";
            cout << "   $$ |   $$      \\  /      \\ /       \\ $$ |  /  |       $$  \\/$$//      \\ /  |  /  |      $$ |$$ |\n";
            cout << "   $$ |   $$$$$$$  | $$$$$$  |$$$$$$$  |$$ |_/$$/         $$  $$//$$$$$$  |$$ |  $$ |      $$ |$$ |\n";
            cout << "   $$ |   $$ |  $$ | /    $$ |$$ |  $$ |$$   $$<           $$$$/ $$ |  $$ |$$ |  $$ |      $$/ $$/ \n";
            cout << "   $$ |   $$ |  $$ |/$$$$$$$ |$$ |  $$ |$$$$$$  \\           $$ | $$ \\__$$ |$$ \\__$$ |       __  __ \n";
            cout << "   $$ |   $$ |  $$ |$$    $$ |$$ |  $$ |$$ | $$  |          $$ | $$    $$/ $$    $$/       /  |/  |\n";
            cout << "   $$/    $$/   $$/  $$$$$$$/ $$/   $$/ $$/   $$/           $$/   $$$$$$/   $$$$$$/        $$/ $$/ \n";
            Sleep(1000);
            cout << "\n\n";
            system("color 5E");
            system("color 46");
            cout << "\nGoodbye! Have a great day!\n";
            Sleep(3000);
            system("cls");
            exit(0);
        }
    }
};
int main()
{
    Pages page;
    bool loggedIn = false;
    bool exitProgramFlag = false;  // Flag to indicate if the program should exit
    page.fileLoadingPage();
    string filename = "Files/Credentials.txt";
    int choice;

    do
    {
        choice = page.homePage();
        switch (choice)
        {
            case 1:
            {
                LoginManager login(filename);
                User *user = login.loginScreen();
                if (user->getUsername() != "null" && user->getPassword() != "null")
                {
                     cout << "*************************************************\n";
                     cout << "*    Login Successful, welcome to WheelBuddy    *\n";
                     cout << "*************************************************\n";
                     loggedIn = true;
                }
                else
                {
                    cout << "Login failed. Incorrect username or password.\n";
                    cout << "Do you want to create a new account? (yes/no): ";
                    string response;
                    cin >> response;

                    if (response == "yes")
                    {
                        RegistrationManager::registerUser(filename);
                        choice = 1;
                    }
                    else
                    {
                        exitProgramFlag = true;
                    }
                }
                break;
            }
            case 2:
                RegistrationManager::registerUser(filename);
                choice = 1;
                break;
            case 3:
                exitProgramFlag = true;
                break;
        }

        if (exitProgramFlag)
        {
            page.thankYouPage();
            break;  // Break out of the loop after calling exitProgram()
        }
    }while (!loggedIn);
    return 0;
}
