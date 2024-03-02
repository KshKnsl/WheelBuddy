#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>//for usleep function
using namespace std;
class User 
{
private:
    string username;
    string password;

public:
    User(const string& uname, const string& pwd) 
    {   
        username = uname;
        password = pwd;
    }

    string getUsername() {
        return username;
    }

    string getPassword() {
        return password;
    }

    bool checkCredentials(const string& uname, const string& pwd) {
        return (username == uname && password == pwd);
    }
};
class LoginManager 
{
private:
    vector<User> users;
public:
    LoginManager(const string& filename) 
    {
        ifstream fileIn(filename);
        if (!fileIn.is_open()) {
            cerr << "Error: Unable to open file for user data." << endl;
            return;
        }
        string username, password;
        while(fileIn >> username >> password)
            users.push_back(User(username, password));

        fileIn.close();
    }

    bool authenticate(const string& uname, const string& pwd) const {
        for (const auto& user : users) {
            if (user.checkCredentials(uname, pwd)) 
            {
                return true; 
            }
        }
        return false;
    }
};
class RegistrationManager 
{
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

string getUserInput(const string& prompt) 
{
    cout << prompt;
    string input;
    cin >> input;
    return input;
}
class Pages
{
    public:
    //this function returns the choice of the user
    int homePage()
    {
        system("color 2A");
        cout<<"\n  _____________________________________________________________________\n";
        cout<<"||                                                                     ||\n";
        cout<<"||   \\      /\\      / |===== |      |====== /=====\\ |\\    /| |=====    ||\n";
        cout<<"||    \\    /  \\    /  |_____ |      |       |     | | \\  / | |_____    ||\n";
        cout<<"||     \\  /    \\  /   |      |      |       |     | |  \\/  | |         ||\n";
        cout<<"||      \\/      \\/    |===== |_____ |====== \\=====/ |      | |=====    ||\n";
        cout<<"||                           TO WHEEL BUDDY                            ||\n";
        cout<<"||     MENU:-                                                          ||\n";
        cout<<"||   1. Login                                                          ||\n";
        cout<<"||   2. Create a new account                                           ||\n";
        cout<<"||   3. CLOSE WHEELBUDDY                                               ||\n";
        cout<<"||_____________________________________________________________________||\n";
        cout<<"ENTER YOUR CHOICE: ";
        int choice;
        cin>>choice;
        cout<<"\nLoading.....\n";
        Sleep(3000);
        return choice;
    }
    void thankYouPage() 
    {
        cout << "\nAre you sure you want to exit? (YES/NO)---";
        string ch;        cin >> ch;
        cin.ignore();
        if (ch == "YES" || ch == "yes" || ch=="Yes") 
        {
            system("cls");       system("color 6D");
            cout<<"\n\t\t\t\t\t\t  ________________________________________________________________________";
            cout<<"\n\t\t\t\t\t\t||                                                                        ||";
            cout<<"\n\t\t\t\t\t\t|| ---------- |     |    /\\    |\\    | |  /      \\     / |=====| |    |   ||";
            cout<<"\n\t\t\t\t\t\t||     ||     |     |   /  \\   | \\   | | /        \\   /  |     | |    |   ||";
            cout<<"\n\t\t\t\t\t\t||     ||     |=====|  /====\\  |  \\  | |/          \\=/   |     | |    |   ||";
            cout<<"\n\t\t\t\t\t\t||     ||     |     | /      \\ |   \\ | |\\           |    |     | |    |   ||";
            cout<<"\n\t\t\t\t\t\t||     ||     |     |/        \\|    \\| | \\          |    |=====| |====|   ||";
            cout<<"\n\t\t\t\t\t\t||________________________________________________________________________||\n";
            Sleep(4000);
            system("cls");
            // Display a feedback prompt
            cout << "\n\n";       system("color 5E");
            int choice = 0;
            cin.ignore();
            cout << "Would you like to provide feedback? (1: Yes, 2: No): ";
            cin >> choice;
            if (choice == 1) 
            {
                // Feedback form
                string feedback;
                cout << "\nPlease provide your feedback (up to 999 characters):\n";
                getline(cin ,feedback);
                cin.ignore();
                // Save the feedback to a file
                FILE *feedbackFile = fopen("Files/feedback.txt", "a");
                if(feedbackFile == NULL)
                    cout << "Error saving feedback. Please try again later.\n";
                else 
                {
                    fprintf(feedbackFile, "\nAFeedBack:  %s.\n", feedback);
                    fclose(feedbackFile);
                    cout << "Thank you for your feedback! It has been saved in feedback.txt.\n";
                }
                Sleep(1000);
                system("cls");
                // Prompt the user to rate the program
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
int main() 
{
    string filename = "Credentials.txt";
    LoginManager login(filename);
    Pages page;
    int choice = page.homePage();
    //homePage() function returns the choice of the user
    //MENU: 1 for login and 2 for create account and 3 or any other number for exit
    switch(choice)
    {
        case 1: 
            string username, password;
            cout << "Enter username: ";
            username = getUserInput("");
            cout << "Enter password: ";
            password = getUserInput("");
            if (login.authenticate(username, password))
                cout << "Login successful. Welcome, " << username << "!\n";
            else
            {
                cout << "Login failed. Incorrect username or password.\n";
                cout << "Do you want to create a new account? (yes/no): ";
                string response;
                response = getUserInput("");
                if (response == "yes")
                    RegistrationManager::registerUser(filename);
            }
        break;
        case 2:
           RegistrationManager::registerUser(filename);
        break;
        default:
           page.thankYouPage();
    }
           page.thankYouPage();
    return 0;
}