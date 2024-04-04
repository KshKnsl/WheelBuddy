
int main() 
{
    string folderLocName = "./Files/1234"; // Replace with actual folder name
    Parser parser;
    parser.sortRides(folderLocName + "/upcomingRides.txt", folderLocName + "/pastRides.txt");
    return 0;
}