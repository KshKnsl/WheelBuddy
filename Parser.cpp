class Parser 
{
    public:
    static void sortRides(string upcoming, string past) 
    {
        vector<Ride> upcomingRides = parseRides(upcoming);
        vector<Ride> pastRides = parseRides(past);

        // Remove upcoming rides older than current date and time
        time_t currentTime = time(nullptr);
        struct tm* now = localtime(&currentTime);
        string currentDate = to_string(now->tm_year + 1900) + '-' + to_string(now->tm_mon + 1) + '-' + to_string(now->tm_mday);
        string currentTimeStr = to_string(now->tm_hour) + ':' + to_string(now->tm_min);

        for (auto it = upcomingRides.begin(); it != upcomingRides.end();) 
        {
            if (it->getDate() < currentDate || (it->getDate() == currentDate && it->getTime() < currentTimeStr)) 
            {
                pastRides.push_back(*it);
                it = upcomingRides.erase(it);
            } 
            else 
            {
                ++it;
            }
        }

        // Sort rides based on date
        //Using STL here
        sort(pastRides.begin(), pastRides.end(),         [](const Ride& a, const Ride& b) {      return a.getDate() < b.getDate();     });
        sort(upcomingRides.begin(), upcomingRides.end(), [](const Ride& a, const Ride& b) {      return a.getDate() < b.getDate();     });

        writeRides(upcoming, upcomingRides);
        writeRides(past, pastRides);
    }

    vector<Ride> parseRides(string fileName) 
    {
        vector<Ride> rides;
        ifstream file(fileName);
        string line;
        getline(file, line);//skip header 
        getline(file, line);//skip ---------- 
        while (getline(file, line)) 
        {
            Ride ride(line);
            rides.push_back(ride);
        }
        file.close();
        return rides;
    }

    static void writeRides(string fileName,vector<Ride>& rides) 
    {
        ofstream file(fileName);
        file <<     "| Ride ID    | Date       | Time   | Source City | Destination City | Max Passengers | Current Passengers | Car Model    | Fare(Rs) | Distance (km) |" << endl;
        file <<     "|------------|------------|--------|-------------|------------------|----------------|--------------------|--------------|----------|---------------|" << endl;
        for(Ride& ride : rides) 
        {
            file << ride.toString() << endl;
        }
        file.close();
        cout << "Rides sorted and written to file: " << fileName << endl;
    }
};
int main() 
{
    string folderLocName = "./Files/1234"; // Replace with actual folder name
    Parser parser;
    parser.sortRides(folderLocName + "/upcomingRides.txt", folderLocName + "/pastRides.txt");
    return 0;
}