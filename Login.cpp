#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

string getUserInput(const string& prompt) 
{
    cout << prompt;
    string input;
    cin >> input;
    return input;
}
void thankYouPage() 
{
    cout << "\nAre you sure you want to exit? (YES/NO)---";
    char ch;        cin >> ch;
    if (ch == 'Y' || ch == 'y') 
    {
        system("cls");
        system("color 3E");
        cout<<"\n\t\t\t\t\t\t  ________________________________________________________________________";
        cout<<"\n\t\t\t\t\t\t||                                                                        ||";
        cout<<"\n\t\t\t\t\t\t|| ---------- |     |    /\\    |\\    | |  /      \\     / |=====| |    |   ||";
        cout<<"\n\t\t\t\t\t\t||     ||     |     |   /  \\   | \\   | | /        \\   /  |     | |    |   ||";
        cout<<"\n\t\t\t\t\t\t||     ||     |=====|  /====\\  |  \\  | |/          \\=/   |     | |    |   ||";
        cout<<"\n\t\t\t\t\t\t||     ||     |     | /      \\ |   \\ | |\\           |    |     | |    |   ||";
        cout<<"\n\t\t\t\t\t\t||     ||     |     |/        \\|    \\| | \\          |    |=====| |====|   ||";
        cout<<"\n\t\t\t\t\t\t||________________________________________________________________________||\n";

        system("cls");

        // Display a feedback prompt
        cout << "\n\n";
        system("color 2E");
        int choice = 0;
        cout << "Would you like to provide feedback? (1: Yes, 2: No): ";
        cin >> choice;

        if (choice == 1) 
        {
            // Feedback form
            char feedback[1000];
            cout << "\nPlease provide your feedback (up to 999 characters):\n";
            cin.getline(feedback, sizeof(feedback));
            // Save the feedback to a file
            size_t feedback_length = strlen(feedback);
            if (feedback_length > 0 && feedback[feedback_length - 1] == '\n') 
                feedback[feedback_length - 1] = '\0';
            FILE *feedbackFile = fopen("Program Data/feedback.txt", "a");
            if (feedbackFile == NULL)
                cout << "Error saving feedback. Please try again later.\n";
            else 
            {
                fprintf(feedbackFile, "\n%s\n", feedback);
                fclose(feedbackFile);
                cout << "Thank you for your feedback! It has been saved in feedback.txt.\n";
            }

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

        // Display a goodbye message
        cout << "\nGoodbye! Have a great day!\n";
        // Pause for 2 seconds
        this_thread::sleep_for(chrono::seconds(1));
        // Clears the screen
        system("cls");
        // Exit the program
        exit(0);
    } 
    else 
    {
        // If the user chooses not to exit, it goes back to the home page
        main();
    }
}
int main() 
{
    string filename = "users.txt";
    LoginManager login(filename);
    cout<<"||                                                                     ||\n";
    cout<<"\n  _____________________________________________________________________\n";
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
        thankYouPage();
    }   
    return 0;
}