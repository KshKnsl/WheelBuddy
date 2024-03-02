#include <iostream>
using namespace std;
class BillCalculator
{
    const double FUEL_COST_PER_KM = 12.0;
    const double MAINTENANCE_COST_PER_KM = 0.8;
    const double TOLL_COST_PER_KM = 2.0;
    // Simple distance lookup table for preset supported Indian cities
    string distanceLookup[110][3] =
    {
        {"Mumbai", "Delhi", "1200"}, {"Mumbai", "Bangalore", "980"}, {"Mumbai", "Kolkata", "1960"}, {"Mumbai", "Chennai", "1340"}, {"Mumbai", "Hyderabad", "620"}, {"Mumbai", "Pune", "150"}, {"Mumbai", "Jaipur", "1200"}, {"Mumbai", "Ahmedabad", "530"}, {"Mumbai", "Lucknow", "1500"}, {"Mumbai", "Bhopal", "770"}, {"Delhi", "Bangalore", "1800"}, {"Delhi", "Kolkata", "1470"}, {"Delhi", "Chennai", "2180"}, {"Delhi", "Mumbai", "1200"}, {"Delhi", "Hyderabad", "1500"}, {"Delhi", "Pune", "1550"}, {"Delhi", "Jaipur", "280"}, {"Delhi", "Ahmedabad", "940"}, {"Delhi", "Lucknow", "440"}, {"Delhi", "Bhopal", "780"}, {"Bangalore", "Mumbai", "980"}, {"Bangalore", "Delhi", "1800"}, {"Bangalore", "Kolkata", "2000"}, {"Bangalore", "Chennai", "350"}, {"Bangalore", "Hyderabad", "560"}, {"Bangalore", "Pune", "840"}, {"Bangalore", "Jaipur", "1700"}, {"Bangalore", "Ahmedabad", "1200"}, {"Bangalore", "Lucknow", "2000"}, {"Bangalore", "Bhopal", "1230"}, {"Kolkata", "Mumbai", "1960"}, {"Kolkata", "Delhi", "1470"}, {"Kolkata", "Bangalore", "2000"}, {"Kolkata", "Chennai", "1600"}, {"Kolkata", "Hyderabad", "1450"}, {"Kolkata", "Pune", "1800"}, {"Kolkata", "Jaipur", "1600"}, {"Kolkata", "Ahmedabad", "1850"}, {"Kolkata", "Lucknow", "1050"}, {"Kolkata", "Bhopal", "1450"}, {"Chennai", "Mumbai", "1340"}, {"Chennai", "Delhi", "2180"}, {"Chennai", "Bangalore", "350"}, {"Chennai", "Kolkata", "1600"}, {"Chennai", "Hyderabad", "680"}, {"Chennai", "Pune", "1200"}, {"Chennai", "Jaipur", "2300"}, {"Chennai", "Ahmedabad", "1700"}, {"Chennai", "Lucknow", "2000"}, {"Chennai", "Bhopal", "1650"}, {"Hyderabad", "Mumbai", "620"}, {"Hyderabad", "Delhi", "1500"}, {"Hyderabad", "Bangalore", "560"}, {"Hyderabad", "Kolkata", "1450"}, {"Hyderabad", "Chennai", "680"}, {"Hyderabad", "Pune", "620"}, {"Hyderabad", "Jaipur", "1100"}, {"Hyderabad", "Ahmedabad", "970"}, {"Hyderabad", "Lucknow", "1600"}, {"Hyderabad", "Bhopal", "1020"}, {"Pune", "Mumbai", "150"}, {"Pune", "Delhi", "1550"}, {"Pune", "Bangalore", "840"}, {"Pune", "Kolkata", "1800"}, {"Pune", "Chennai", "1200"}, {"Pune", "Hyderabad", "620"}, {"Pune", "Jaipur", "1300"}, {"Pune", "Ahmedabad", "650"}, {"Pune", "Lucknow", "1700"}, {"Pune", "Bhopal", "1030"}, {"Jaipur", "Mumbai", "1200"}, {"Jaipur", "Delhi", "280"}, {"Jaipur", "Bangalore", "1700"}, {"Jaipur", "Kolkata", "1600"}, {"Jaipur", "Chennai", "2300"}, {"Jaipur", "Hyderabad", "1100"}, {"Jaipur", "Pune", "1300"}, {"Jaipur", "Ahmedabad", "660"}, {"Jaipur", "Lucknow", "550"}, {"Ahmedabad", "Mumbai", "530"}, {"Ahmedabad", "Delhi", "940"}, {"Ahmedabad", "Bangalore", "1200"}, {"Ahmedabad", "Kolkata", "1850"}, {"Ahmedabad", "Chennai", "1700"}, {"Ahmedabad", "Hyderabad", "970"}, {"Ahmedabad", "Pune", "650"}, {"Ahmedabad", "Jaipur", "660"}, {"Ahmedabad", "Lucknow", "1350"}, {"Ahmedabad", "Bhopal", "580"}, {"Lucknow", "Mumbai", "1500"}, {"Lucknow", "Delhi", "440"}, {"Lucknow", "Kolkata", "1050"}, {"Lucknow", "Chennai", "2000"}, {"Lucknow", "Hyderabad", "1600"}, {"Lucknow", "Pune", "1700"}, {"Lucknow", "Jaipur", "550"}, {"Lucknow", "Ahmedabad", "1350"}, {"Lucknow", "Bhopal", "650"}, {"Bhopal", "Mumbai", "770"}, {"Bhopal", "Delhi", "780"}, {"Bhopal", "Bangalore", "1230"}, {"Bhopal", "Kolkata", "1450"}, {"Bhopal", "Chennai", "1650"}, {"Bhopal", "Hyderabad", "1020"}, {"Bhopal", "Pune", "1030"}, {"Bhopal", "Jaipur", "580"}, {"Bhopal", "Ahmedabad", "650"}, {"Bhopal", "Lucknow", "650"}
    };
    int calculateDistance(const string &source, const string &destination)
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
        double additionalCost = carCapacity * 20.0;  // Adjust this value as needed
        double totalCost = fuelCost + maintenanceCost + tollCost + additionalCost;
        return totalCost;
    }

    // Function to print the bill in a proper format
    void printBill(string source, string destination, int distance, int carCapacity)
    {
        system("color A1");
        double totalCost = calculateTotalCost(distance, carCapacity);
        cout<<"\n";
        cout << "\t\t\t\t\t************************** Trip Bill **************************\n";
        cout << "\t\t\t\t\t|\t"<< endl;
        cout << "\t\t\t\t\t|\tSource City: \t\t" << source << endl;
        cout << "\t\t\t\t\t|\tDestination City: \t" << destination << endl;
        cout << "\t\t\t\t\t|\tDistance: \t\t"<< distance << " km\n";
        cout << "\t\t\t\t\t|\tCar Capacity: \t\t" << carCapacity << " passengers\n";
        cout << "\t\t\t\t\t|\t-------------------------------------------------------\n";
        cout << "\t\t\t\t\t|\tFuel Cost: \t\t\tRs." << distance * FUEL_COST_PER_KM << endl;
        cout << "\t\t\t\t\t|\tMaintenance Cost: \t\tRs." << distance * MAINTENANCE_COST_PER_KM << endl;
        cout << "\t\t\t\t\t|\tToll Cost: \t\t\tRs." << distance * TOLL_COST_PER_KM << endl;
        cout << "\t\t\t\t\t|\tAdditional Cost: \t\tRs." << carCapacity * 20.0 << endl;
        cout << "\t\t\t\t\t|\tDriver Cost: \t\t\tRs." << 200 << endl;
        cout << "\t\t\t\t\t|\t-------------------------------------------------------\n";
        cout << "\t\t\t\t\t|\tTotal Cost: \t\t\tRs." << totalCost+200 <<"  only"<< endl;
        cout << "\t\t\t\t\t|\t"<< endl;
        cout << "\t\t\t\t\t************************* Thank You! **************************\n";
    }
}
int main()
{
    int distance=calculateDistance("Delhi","Mumbai");
    printBill("Delhi","Mumbai",distance,5);
    return 0;
}