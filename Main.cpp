#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> //for usleep function
#include <stdio.h>   // for mkdir
#include <io.h>      //for mkdir
#include <iomanip>   //for setw
#include <sstream>   // FOR TOSTRING FUNCTION() OF RIDE CLASS
#include <cstdlib>   //RANDOM NUMBER
#include <ctime>     //RANDOM NUMBER
#include <algorithm>

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

    bool checkCredentials(string uname, string pwd)
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

    bool authenticate(string uname, string pwd)
    {
        for (auto &user : users)
        {
            if (user.checkCredentials(uname, pwd))
            {
                return true;
            }
        }
        return false;
    }

    User *loginScreen()
    {
        system("cls");
        system("Color DE");
        cout << "**************************************\n";
        cout << "*                 Login              *\n";
        cout << "**************************************\n";
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        User *ob = new User(username, password);
        if (authenticate(username, password))
            return ob;
        else
        {
            User *o = new User("null", "null");
            return o;
        }
    }
};

class RegistrationManager
{

public:
    static void registerUser(string &filename)
    {
        system("cls");
        system("color A1");
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
            createFolder(username);
            // A important step
        }
        system("cls");
    }

    static void createFolder(string folderName)
    {
        // Create the folder
        mkdir(("./Files/" + folderName).c_str());
        // Create files inside the folder
        string folderPath = "./Files/" + folderName;
        ofstream pastRidesFile(folderPath + "/pastRides.txt");
        ofstream upcomingRidesFile(folderPath + "/upcomingRides.txt");
        ofstream userDetailsFile(folderPath + "/userDetails.txt");
        pastRidesFile << "| Ride ID    | Date       | Time   | Source City | Destination City | Max Passengers | Current Passengers | Car Model    | Fare(Rs) | Distance (km) |" << endl;
        pastRidesFile << "|------------|------------|--------|-------------|------------------|----------------|--------------------|--------------|----------|---------------|" << endl;
        upcomingRidesFile << "| Ride ID    | Date       | Time   | Source City | Destination City | Max Passengers | Current Passengers | Car Model    | Fare(Rs) | Distance (km) |" << endl;
        upcomingRidesFile << "|------------|------------|--------|-------------|------------------|----------------|--------------------|--------------|----------|---------------|" << endl;
        // Close the files
        pastRidesFile.close();
        upcomingRidesFile.close();

        string username, fullName, age, gender, email, address, phone, aadharNo, memberSince, ridesTaken, amountSpent;

        username = folderName;
        cout << "Enter Full Name: ";
        getline(cin, fullName);
        getline(cin, fullName);
        cout << "Enter Age: ";
        getline(cin, age);
        cout << "Enter Gender: ";
        getline(cin, gender);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Aadhar Card No: ";
        getline(cin, aadharNo);
        cout << "Enter Member Since (YYYY-MM-DD): ";
        getline(cin, memberSince);

        // Write user details to file
        userDetailsFile << "Username: " << username << endl;
        userDetailsFile << "Full Name: " << fullName << endl;
        userDetailsFile << "Age: " << age << endl;
        userDetailsFile << "Gender: " << gender << endl;
        userDetailsFile << "Email: " << email << endl;
        userDetailsFile << "Address: " << address << endl;
        userDetailsFile << "Phone: " << phone << endl;
        userDetailsFile << "Aadhar Card No: " << aadharNo << endl;
        userDetailsFile << "Member Since: " << memberSince << endl;
        userDetailsFile << "Total Rides Taken: " << 0 << endl;
        userDetailsFile << "Total Amount Spent: Rs. " << 0 << endl;

        // Close the file
        userDetailsFile.close();
    }
};

class Pages // Define Pages class before main
{
public:
    void fileLoadingPage()
    {
        system("cls");
        system("color 6B");
        ifstream in("CodeRelatedFiles/Welcome.txt"); // displaying welcome ASCII image text on output screen fn1353
        char str[1000];
        while (in)
        {
            in.getline(str, 1000); // delim defaults to '\n' cp
            if (in)
                cout << str << endl;
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
        system("color F6");
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
        else
        {
            system("cls");
            exit(0);
        }
    }
};

class Dashboard : public Pages
{
public:
    void display(string username)
    {
        system("color E4");
        cout << "*************************** User Dashboard ***************************" << endl;
        cout << "User Details:" << endl;
        string filename = "Files/" + username + "/userDetails.txt";
        ifstream file(filename);
        string line;
        while (getline(file, line))
        {
            cout << "\t  " << line << endl;
        }
        cout << "----------------------------------------------------------------------\n"
             << endl;
        file.close();
        cout << "Past Rides Details:" << endl;
        cout << "\t-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        filename = "Files/" + username + "/pastRides.txt";
        ifstream file2(filename);
        while (getline(file2, line))
        {
            cout << "\t" << line << endl;
        }
        cout << "\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n"
             << endl;
        file2.close();
        cout << "Upcoming Rides Details:" << endl;
        cout << "\t-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        filename = "Files/" + username + "/upcomingRides.txt";
        ifstream file3(filename);
        while (getline(file3, line))
        {
            cout << "\t" << line << endl;
        }
        cout << "\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n"
             << endl;
        file3.close();
    }
};

class Ride
{
private:
    string rideID;
    string date;
    string time;
    string sourceCity;
    string destinationCity;
    int maxPassengers;
    int currentPassengers;
    string carModel;
    double fare;
    double distance;

public:
    Ride()
    {
        // do nothing
    }

    Ride(string s)
    {
        stringstream ss(s);
        string temp;
        getline(ss, temp, '|'); // Skip first |
        ss >> ws;               // Skip whitespaces
        getline(ss, rideID, '|');
        ss >> ws; // Skip whitespaces
        getline(ss, date, '|');
        ss >> ws; // Skip whitespaces
        getline(ss, time, '|');
        ss >> ws; // Skip whitespaces
        getline(ss, sourceCity, '|');
        ss >> ws; // Skip whitespaces
        getline(ss, destinationCity, '|');
        ss >> ws; // Skip whitespaces
        getline(ss, temp, '|');
        maxPassengers = stoi(temp);
        ss >> ws; // Skip whitespaces
        getline(ss, temp, '|');
        currentPassengers = stoi(temp);
        ss >> ws; // Skip whitespaces
        getline(ss, carModel, '|');
        ss >> ws; // Skip whitespaces
        getline(ss, temp, '|');
        fare = stod(temp);
        ss >> ws; // Skip whitespaces
        getline(ss, temp, '|');
        distance = stod(temp);
        // Convert string values to integer or double
    }

    Ride(string date, string time, string sourceCity, string destinationCity,
         int maxPassengers, int currentPassengers, string carModel, double fare, double distance)
    {
        this->rideID = generateRandomRideID();
        this->date = date;
        this->time = time;
        this->sourceCity = sourceCity;
        this->destinationCity = destinationCity;
        this->maxPassengers = maxPassengers;
        this->currentPassengers = currentPassengers;
        this->carModel = carModel;
        this->fare = fare;
        this->distance = distance;
    }

    string getRideID() { return rideID; }
    string getDate() { return date; }
    string getTime() { return time; }
    string getSourceCity() { return sourceCity; }
    string getDestinationCity() { return destinationCity; }
    int getMaxPassengers() { return maxPassengers; }
    int getCurrentPassengers() { return currentPassengers; }
    string getCarModel() { return carModel; }
    double getFare() { return fare; }
    double getDistance() { return distance; }

    string generateRandomRideID()
    {
        string alphanumeric = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int idLength = 5;
        string id;
        srand(std::time(0)); // Specify the namespace for time()

        for (int i = 0; i < idLength; ++i)
        {
            id += alphanumeric[rand() % alphanumeric.length()];
        }
        return id;
    }

    string toString()
    {
        stringstream ss;

        ss << "| " << setw(10) << left << rideID << "| " << setw(10) << left << date << "| " << setw(6) << left << time << "| "
           << setw(11) << left << sourceCity << "| " << setw(16) << left << destinationCity << "| " << setw(14) << left << maxPassengers
           << " | " << setw(18) << left << currentPassengers << " | " << setw(11) << left << carModel << "| " << setw(7) << left << fare
           << "  | " << setw(13) << left << distance << " |";
        return ss.str();
    }
};

// Parser is the class responsible for sorting rides based on their date and time.
// This class also manages the movement of completed rides to the past rides file, ensuring that the upcoming rides file contains only future rides.
// This segregation facilitates the implementation of features such as carpooling and ensures that users have access to relevant and timely ride information.

class Parser
{
public:
    void sortRides(string upcoming, string past)
    {
        vector<Ride> upcomingRides = parseRides(upcoming);
        vector<Ride> pastRides = parseRides(past);

        // Remove upcoming rides older than or equal to the current date and time
        time_t currentTime = time(nullptr);
        struct tm *now = localtime(&currentTime);
        int currentYear = now->tm_year + 1900;
        int currentMonth = now->tm_mon + 1;
        int currentDay = now->tm_mday;
        int currentHour = now->tm_hour;

        vector<Ride> newUpcomingRides;
        for (auto it = upcomingRides.begin(); it != upcomingRides.end();)
        {
            string rideDate = it->getDate();
            string rideTime = it->getTime();

            // Parse ride date
            int rideYear, rideMonth, rideDay;
            sscanf(rideDate.c_str(), "%d-%d-%d", &rideYear, &rideMonth, &rideDay);

            // Parse ride time
            int rideHour, rideMinute;
            sscanf(rideTime.c_str(), "%d:%d", &rideHour, &rideMinute);

            // Compare dates
            if (rideYear > currentYear || (rideYear == currentYear && rideMonth > currentMonth) || (rideYear == currentYear && rideMonth == currentMonth && rideDay > currentDay) || (rideYear == currentYear && rideMonth == currentMonth && rideDay == currentDay && rideHour > currentHour))
            {
                newUpcomingRides.push_back(*it);
                it = upcomingRides.erase(it);
            }
            else
            {
                pastRides.push_back(*it);
                it = upcomingRides.erase(it);
            }
        }

        // Sort rides based on date for upcoming and past rides
        sort(pastRides.begin(), pastRides.end(), [](Ride &a, Ride &b)
             { return a.getDate() < b.getDate() || (a.getDate() == b.getDate() && a.getTime() < b.getTime()); });
        sort(newUpcomingRides.begin(), newUpcomingRides.end(), [](Ride &a, Ride &b)
             { return a.getDate() < b.getDate() || (a.getDate() == b.getDate() && a.getTime() < b.getTime()); });

        // Write upcoming and past rides to their respective files
        writeRides(upcoming, newUpcomingRides);
        writeRides(past, pastRides);
    }

    vector<Ride> parseRides(string fileName)
    {
        vector<Ride> rides;
        ifstream file(fileName);
        string line;

        getline(file, line); // skip header
        getline(file, line); // skip ----------

        while (getline(file, line))
        {
            Ride ride(line);
            rides.push_back(ride);
        }
        file.close();
        return rides;
    }

    void writeRides(string fileName, vector<Ride> &rides)
    {
        ofstream file(fileName);
        file << "| Ride ID    | Date       | Time   | Source City | Destination City | Max Passengers | Current Passengers | Car Model    | Fare(Rs) | Distance (km) |" << endl;
        file << "|------------|------------|--------|-------------|------------------|----------------|--------------------|--------------|----------|---------------|" << endl;

        for (Ride &ride : rides)
        {
            file << ride.toString() << endl;
        }

        file.close();
    }
};

class Menu : public Pages
{
public:
    // Display the menu options
    void displayMenu(User *user)
    {
        // this is just a outline you will have to modify it for proper working
        cout << "\t\t\t\t\t||========================================= Menu =========================================||" << endl;
        cout << "\t\t\t\t\t|| 1. Book a Ride\t\t2. Offer a Ride\t\t3. View Upcoming Rides \t\t  ||" << endl;
        cout << "\t\t\t\t\t|| 4. View Past Rides\t\t5. Manage Profile\t6. Old Bills       \t\t  ||" << endl;
        cout << "\t\t\t\t\t|| 7. Search for Rides\t\t8. Join a Pool\t\t9. Cancel Booking  \t\t  ||" << endl;
        cout << "\t\t\t\t\t|| 10. Rate and Review\t\t11. Feedback\t\t12. Invite Friends   \t\t  ||" << endl;
        cout << "\t\t\t\t\t|| 13. View Rewards/Incentives\t14. CO2 Calculator\t15. Exit \t\t\t  ||" << endl;
        cout << "\t\t\t\t\t||========================================================================================||" << endl;
        bool flag = false;
        do
        {
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;
            // Execute the selected option based on user input
            switch (choice)
            {
            case 1:
                flag = true;
                bookRide(user);
                break;
            case 2:
                flag = true;
                offerRide();
                break;
            case 3:
                flag = true;
                viewUpcomingRides();
                break;
            case 4:
                flag = true;
                viewPastRides();
                break;
            case 5:
                flag = true;
                manageProfile();
                break;
            case 6:
                flag = true;
                OldBills();
                break;
            case 7:
                flag = true;
                searchRides();
                break;
            case 8:
                flag = true;
                joinPool();
                break;
            case 9:
                flag = true;
                cancelBooking();
                break;
            case 10:
                flag = true;
                rateAndReview();
                break;
            case 11:
                flag = true;
                feedback();
                break;
            case 12:
                flag = true;
                inviteFriends();
                break;
            case 13:
                flag = true;
                viewRewards();
                break;
            case 14:
                flag = true;
                calculateCO2Emission();
                break;
            case 15:
                flag = true;
                exitProgram();
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 15" << endl;
                flag = false;
            }
        } while (flag == false);
    }

private:
    void bookRide(User* user)
    {
        cout << "Booking a ride..." << endl;
        // Implementing logic for booking a ride
        string rideID, date, time, sourceCity, destinationCity, carModel;
        int maxPassengers, currentPassengers;
        double fare, distance;

        cout << "Enter Ride ID: ";
        cin >> rideID;
        cout << "Enter Date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter Time (HH:MM): ";
        cin >> time;
        cout << "Enter Source City: ";
        cin >> sourceCity;
        cout << "Enter Destination City: ";
        cin >> destinationCity;
        cout << "Enter Max Passengers: ";
        cin >> maxPassengers;
        cout << "Enter Current Passengers: ";
        cin >> currentPassengers;
        cout << "Enter Car Model: ";
        cin >> carModel;
        cout << "Enter Fare (Rs): ";
        cin >> fare;
        cout << "Enter Distance (km): ";
        cin >> distance;

        Ride r(date, time, sourceCity, destinationCity, maxPassengers, currentPassengers, carModel, fare, distance);
        string s=r.toString();
        string fileName = "./Files/" + user->getUsername() + "/upcomingRides.txt";
        string adminName = "./Files/admin/upcomingRides.txt";

        ofstream file(fileName, ios::app); // Open file in append mode
        file<<s<<endl;
    }
    void offerRide()
    {
        cout << "Offering a ride..." << endl;
        // Implementing logic for offering a ride
        string date, time, sourceCity, destinationCity, carModel;
        int maxPassengers, currentPassengers;
        double fare, distance;

        cout << "Enter date (DD/MM/YYYY): ";
        cin >> date;
        cout << "Enter time (HH:MM): ";
        cin >> time;
        cout << "Enter source city: ";
        cin >> sourceCity;
        cout << "Enter destination city: ";
        cin >> destinationCity;
        cout << "Enter maximum passengers: ";
        cin >> maxPassengers;
        cout << "Enter current passengers: ";
        cin >> currentPassengers;
        cout << "Enter car model: ";
        cin >> carModel;
        cout << "Enter fare: ";
        cin >> fare;
        cout << "Enter distance: ";
        cin >> distance;

        Ride newRide(date, time, sourceCity, destinationCity, maxPassengers, currentPassengers, carModel, fare, distance);

        cout << "Ride offered successfully!" << endl;
        
    }
    void viewUpcomingRides()
    {
        cout << "Viewing upcoming rides..." << endl;
        // // Implementing logic for viewing upcoming rides

        // Parser parser;
        // vector<Ride> upcomingRides = parser.parseRides("upcomingRides.txt");
        // cout << "Upcoming Rides:" << endl;
        // cout << "| Ride ID    | Date       | Time   | Source City | Destination City | Max Passengers | Current Passengers | Car Model    | Fare(Rs) | Distance (km) |" << endl;
        // cout << "|------------|------------|--------|-------------|------------------|----------------|--------------------|--------------|----------|---------------|" << endl;

        // for (const Ride &ride : upcomingRides)
        // {
        //     cout << ride.toString() << endl;
        // }
    }
    void viewPastRides()
    {
        cout << "Viewing past rides..." << endl;
        // Implementing logic for viewing past rides
        // Parser parser;
        // vector<Ride> pastRides = parser.parseRides("pastRides.txt");
        // cout << "Past Rides:" << endl;
        // cout << "| Ride ID    | Date       | Time   | Source City | Destination City | Max Passengers | Current Passengers | Car Model    | Fare(Rs) | Distance (km) |" << endl;
        // cout << "|------------|------------|--------|-------------|------------------|----------------|--------------------|--------------|----------|---------------|" << endl;

        // for (const Ride &ride : pastRides)
        // {
        //     cout << ride.toString() << endl;
        // }
    }
    void manageProfile()
    {
        cout << "Managing profile..." << endl;
        // Implement logic for managing profile

    }
    void OldBills()
    {
        BillCalculator b;
        b.printBill(source,destination,distance,carCapacity);
        string id;
        cout<<"Please enter Ride id:"<<endl;
        cin>>id;
        string fileName = "./Files/" + user->getUsername() + "/upcomingRides.txt";
        vector<Ride> rides;
        ifstream file(fileName);
        string line;

        getline(file, line); // skip header
        getline(file, line); // skip ----------

        while (getline(file, line))
        {
            Ride ride(line);
            rides.push_back(ride);
        }
        file.close();
        for(int i=0;i<v.size(),i++){
            
        }

    
    }
    void searchRides()
    {
        // cout << "Searching for rides..." << endl;
        // // Implement logic for searching rides
        // string sourceCity, destinationCity, date, time;
        // cout << "Enter source city: ";
        // cin >> sourceCity;
        // cout << "Enter destination city: ";
        // cin >> destinationCity;
        // cout << "Enter date (YYYY-MM-DD): ";
        // cin >> date;
        // cout << "Enter time (HH:MM): ";
        // cin >> time;

        // // Load rides data (assuming Parser class is used)
        // Parser parser;
        // vector<Ride> allRides = parser.parseRides("all_rides.txt");

        // // Filter rides based on search criteria
        // vector<Ride> matchingRides;
        // for (const Ride &ride : allRides)
        // {
        //     if (ride.getSourceCity() == sourceCity &&
        //         ride.getDestinationCity() == destinationCity &&
        //         ride.getDate() == date &&
        //         ride.getTime() == time)
        //     {
        //         matchingRides.push_back(ride);
        //     }
        // }

        // // Display matching rides
        // if (matchingRides.empty())
        // {
        //     cout << "No rides found matching the search criteria." << endl;
        // }
        // else
        // {
        //     cout << "Matching rides:" << endl;
        //     cout << "| Ride ID    | Date       | Time   | Source City | Destination City | Max Passengers | Current Passengers | Car Model    | Fare(Rs) | Distance (km) |" << endl;
        //     cout << "|------------|------------|--------|-------------|------------------|----------------|--------------------|--------------|----------|---------------|" << endl;
        //     for (const Ride &ride : matchingRides)
        //     {
        //         cout << ride.toString() << endl;
        //     }
        // }
    }
    void joinPool()
    {
        cout << "Joining a pool..." << endl;
        // Implement logic for joining a pool
    }
    void cancelBooking()
    {
        cout << "Canceling booking..." << endl;
        // Implement logic for canceling booking
    }
    void rateAndReview()
    {
        cout << "Rating and reviewing..." << endl;
        // Implement logic for rating and reviewing
    }
    void feedback()
    {
        cout << "Providing feedback..." << endl;
        // Implement logic for providing feedback
    }
    void inviteFriends()
    {
        cout << "Inviting friends..." << endl;
        // Implement logic for inviting friends
    }
    void viewRewards()
    {
        cout << "Viewing rewards..." << endl;
        // Implement logic for viewing rewards
    }
    void calculateCO2Emission()
    {
        cout << "Calculating CO2 emission..." << endl;
        // Implement logic for calculating CO2 emission
    }
    void exitProgram()
    {
        cout << "Exiting program..." << endl;
        // Implement logic for exiting program
    }
};

int main()
{
    Pages page;
    bool loggedIn = false;
    bool exitProgramFlag = false; // Flag to indicate if the program should exit
    page.fileLoadingPage();
    User *user;

    string filename = "CodeRelatedFiles/Credentials.txt";
    int choice = page.homePage();
    do
    {
        switch (choice)
        {
        case 1:
        {
            LoginManager login(filename);
            user = login.loginScreen();
            if (user->getUsername() != "null" && user->getPassword() != "null")
            {
                cout << "*************************************************\n";
                cout << "*    Login Successful, welcome to WheelBuddy    *\n";
                cout << "*************************************************\n";
                loggedIn = true;
                Sleep(3000);
                system("cls");
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
            exitProgramFlag = false;
            break;

        case 3:
            exitProgramFlag = true;
            break;
        default:
            cout << "Program Terminated due to wrong input";
        }

        if (exitProgramFlag)
        {
            page.thankYouPage();
            break; // Break out of the loop after calling exitProgram()
        }
    } while (!loggedIn);

    if (loggedIn == true)
    {
        // Parsing is the class for sorting the rides based on their time and date
        // Also this class moves the finished rides to a different rides so upcoming rides has only coming rides data which can be further used to implement the features of carpooling
        // after logging in run the parser first
        string folderLocName = "./Files/" + user->getUsername(); // Replace with actual folder name
        Parser parser;
        parser.sortRides(folderLocName + "/upcomingRides.txt", folderLocName + "/pastRides.txt");
        // Also run the parser for the admin
        folderLocName = "./Files/admin";
        parser.sortRides(folderLocName + "/upcomingRides.txt", folderLocName + "/pastRides.txt");

        // Now display the dashboard
        Dashboard dash;
        dash.display(user->getUsername());
        Sleep(5000);

        Menu menu;
        // Display the menu
        menu.displayMenu(user);
    }

    // demo to use bill calculator
    //  BillCalculator calcob;
    //  int distance = calcob.calculateDistance("Mumbai","Pune");
    //  calcob.printBill("Mumbai","Pune",distance,5);

    // Demo to use the ride class functions
    //  Ride ride("| A1B2C      | 2023-12-20 | 08:00  | Mumbai      | Delhi            | 4              | 3                  | Toyota Camry | 1200     | 1200          |");
    //  cout << "Ride Details: " << ride.toString() << endl;
    page.thankYouPage();
    return 0;
}

class BillCalculator
{
    const double FUEL_COST_PER_KM = 12.0;
    const double MAINTENANCE_COST_PER_KM = 0.8;
    const double TOLL_COST_PER_KM = 2.0;
    // Simple distance lookup table for preset supported Indian cities

    string distanceLookup[110][3] =
        {
            {"Mumbai", "Delhi", "1200"}, {"Mumbai", "Bangalore", "980"}, {"Mumbai", "Kolkata", "1960"}, {"Mumbai", "Chennai", "1340"}, {"Mumbai", "Hyderabad", "620"}, {"Mumbai", "Pune", "150"}, {"Mumbai", "Jaipur", "1200"}, {"Mumbai", "Ahmedabad", "530"}, {"Mumbai", "Lucknow", "1500"}, {"Mumbai", "Bhopal", "770"}, {"Delhi", "Bangalore", "1800"}, {"Delhi", "Kolkata", "1470"}, {"Delhi", "Chennai", "2180"}, {"Delhi", "Mumbai", "1200"}, {"Delhi", "Hyderabad", "1500"}, {"Delhi", "Pune", "1550"}, {"Delhi", "Jaipur", "280"}, {"Delhi", "Ahmedabad", "940"}, {"Delhi", "Lucknow", "440"}, {"Delhi", "Bhopal", "780"}, {"Bangalore", "Mumbai", "980"}, {"Bangalore", "Delhi", "1800"}, {"Bangalore", "Kolkata", "2000"}, {"Bangalore", "Chennai", "350"}, {"Bangalore", "Hyderabad", "560"}, {"Bangalore", "Pune", "840"}, {"Bangalore", "Jaipur", "1700"}, {"Bangalore", "Ahmedabad", "1200"}, {"Bangalore", "Lucknow", "2000"}, {"Bangalore", "Bhopal", "1230"}, {"Kolkata", "Mumbai", "1960"}, {"Kolkata", "Delhi", "1470"}, {"Kolkata", "Bangalore", "2000"}, {"Kolkata", "Chennai", "1600"}, {"Kolkata", "Hyderabad", "1450"}, {"Kolkata", "Pune", "1800"}, {"Kolkata", "Jaipur", "1600"}, {"Kolkata", "Ahmedabad", "1850"}, {"Kolkata", "Lucknow", "1050"}, {"Kolkata", "Bhopal", "1450"}, {"Chennai", "Mumbai", "1340"}, {"Chennai", "Delhi", "2180"}, {"Chennai", "Bangalore", "350"}, {"Chennai", "Kolkata", "1600"}, {"Chennai", "Hyderabad", "680"}, {"Chennai", "Pune", "1200"}, {"Chennai", "Jaipur", "2300"}, {"Chennai", "Ahmedabad", "1700"}, {"Chennai", "Lucknow", "2000"}, {"Chennai", "Bhopal", "1650"}, {"Hyderabad", "Mumbai", "620"}, {"Hyderabad", "Delhi", "1500"}, {"Hyderabad", "Bangalore", "560"}, {"Hyderabad", "Kolkata", "1450"}, {"Hyderabad", "Chennai", "680"}, {"Hyderabad", "Pune", "620"}, {"Hyderabad", "Jaipur", "1100"}, {"Hyderabad", "Ahmedabad", "970"}, {"Hyderabad", "Lucknow", "1600"}, {"Hyderabad", "Bhopal", "1020"}, {"Pune", "Mumbai", "150"}, {"Pune", "Delhi", "1550"}, {"Pune", "Bangalore", "840"}, {"Pune", "Kolkata", "1800"}, {"Pune", "Chennai", "1200"}, {"Pune", "Hyderabad", "620"}, {"Pune", "Jaipur", "1300"}, {"Pune", "Ahmedabad", "650"}, {"Pune", "Lucknow", "1700"}, {"Pune", "Bhopal", "1030"}, {"Jaipur", "Mumbai", "1200"}, {"Jaipur", "Delhi", "280"}, {"Jaipur", "Bangalore", "1700"}, {"Jaipur", "Kolkata", "1600"}, {"Jaipur", "Chennai", "2300"}, {"Jaipur", "Hyderabad", "1100"}, {"Jaipur", "Pune", "1300"}, {"Jaipur", "Ahmedabad", "660"}, {"Jaipur", "Lucknow", "550"}, {"Ahmedabad", "Mumbai", "530"}, {"Ahmedabad", "Delhi", "940"}, {"Ahmedabad", "Bangalore", "1200"}, {"Ahmedabad", "Kolkata", "1850"}, {"Ahmedabad", "Chennai", "1700"}, {"Ahmedabad", "Hyderabad", "970"}, {"Ahmedabad", "Pune", "650"}, {"Ahmedabad", "Jaipur", "660"}, {"Ahmedabad", "Lucknow", "1350"}, {"Ahmedabad", "Bhopal", "580"}, {"Lucknow", "Mumbai", "1500"}, {"Lucknow", "Delhi", "440"}, {"Lucknow", "Kolkata", "1050"}, {"Lucknow", "Chennai", "2000"}, {"Lucknow", "Hyderabad", "1600"}, {"Lucknow", "Pune", "1700"}, {"Lucknow", "Jaipur", "550"}, {"Lucknow", "Ahmedabad", "1350"}, {"Lucknow", "Bhopal", "650"}, {"Bhopal", "Mumbai", "770"}, {"Bhopal", "Delhi", "780"}, {"Bhopal", "Bangalore", "1230"}, {"Bhopal", "Kolkata", "1450"}, {"Bhopal", "Chennai", "1650"}, {"Bhopal", "Hyderabad", "1020"}, {"Bhopal", "Pune", "1030"}, {"Bhopal", "Jaipur", "580"}, {"Bhopal", "Ahmedabad", "650"}, {"Bhopal", "Lucknow", "650"}};

public:
    int calculateDistance(string source, string destination)
    {
        for (int i = 0; i < 110; i++)
        {
            if (distanceLookup[i][0] == source && distanceLookup[i][1] == destination)
            {
                return stoi(distanceLookup[i][2]);
            }
        }
        return 0;
    }

    // Function to calculate the total cost based on distance, car capacity, and fixed costs
    double calculateTotalCost(int distance, int carCapacity)
    {
        double fuelCost = distance * FUEL_COST_PER_KM;
        double maintenanceCost = distance * MAINTENANCE_COST_PER_KM;
        double tollCost = distance * TOLL_COST_PER_KM;
        double additionalCost = carCapacity * 20.0; // Adjust this value as needed
        double totalCost = fuelCost + maintenanceCost + tollCost + additionalCost;
        return totalCost;
    }

    // Function to print the bill in a proper format
    void printBill(string source, string destination, int distance, int carCapacity)
    {
        system("cls");
        system("color A1");
        double totalCost = calculateTotalCost(distance, carCapacity);
        cout << "\n";
        cout << "\n";
        cout << "\t\t\t\t\t\t" << "\n";

        cout << "\t\t\t\t\t\t" << setw(60) << "|************************* Trip Bill **************************|\n";
        cout << "\t\t\t\t\t\t" << "|                                                              |" << endl;
        cout << "\t\t\t\t\t\t" << "|\tSource City: \t\t" << setw(25) << left << source << "      |" << endl;
        cout << "\t\t\t\t\t\t" << "|\tDestination City: \t" << setw(25) << left << destination << "      |" << endl;
        cout << "\t\t\t\t\t\t" << "|\tDistance: \t\t" << setw(15) << left << distance << " km             |\n";
        cout << "\t\t\t\t\t\t" << "|\tCar Capacity: \t\t" << setw(15) << left << carCapacity << " passengers     |\n";
        cout << "\t\t\t\t\t\t" << "|\t-------------------------------------------------------|\n";
        cout << "\t\t\t\t\t\t" << "|\tFuel Cost: \t\t\tRs." << setw(20) << left << distance * FUEL_COST_PER_KM << "|" << endl;
        cout << "\t\t\t\t\t\t" << "|\tMaintenance Cost: \t\tRs." << setw(20) << left << distance * MAINTENANCE_COST_PER_KM << "|" << endl;
        cout << "\t\t\t\t\t\t" << "|\tToll Cost: \t\t\tRs." << setw(20) << left << distance * TOLL_COST_PER_KM << "|" << endl;
        cout << "\t\t\t\t\t\t" << "|\tAdditional Cost: \t\tRs." << setw(20) << left << carCapacity * 20.0 << "|" << endl;
        cout << "\t\t\t\t\t\t" << "|\tDriver Cost: \t\t\tRs." << setw(20) << left << 200 << "|" << endl;
        cout << "\t\t\t\t\t\t" << "|\t-------------------------------------------------------|\n";
        cout << "\t\t\t\t\t\t" << "|\tTotal Cost: \t\t\tRs." << setw(10) << left << totalCost + 200 << "  only    |" << endl;
        cout << "\t\t\t\t\t\t" << "|                                                              |" << endl;
        cout << "\t\t\t\t\t\t" << setw(60) << "|   # This is a computer-generated invoice and it does not     |" << endl;
        cout << "\t\t\t\t\t\t" << setw(60) << "|     require an authorized signature #                        |" << endl;
        cout << "\t\t\t\t\t\t" << "|                                                              |" << endl;
        cout << "\t\t\t\t\t\t" << setw(60) << "|//////////////////////////////////////////////////////////////|" << endl;
        cout << "\t\t\t\t\t\t" << setw(60) << "|You are advised to pay up the amount before the due date.     |" << endl;
        cout << "\t\t\t\t\t\t" << setw(60) << "|\t\tOtherwise, a penalty fee will be applied       |" << endl;
        cout << "\t\t\t\t\t\t" << setw(60) << "|//////////////////////////////////////////////////////////////|" << endl;
        cout << "\t\t\t\t\t\t" << "|                                                              |" << endl;
        cout << "\t\t\t\t\t\t" << setw(60) << "************************** Thank You! **************************\n";
    }
};
