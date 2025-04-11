#include <iostream>
#include <cstring>
#include<windows.h>
#include <stdlib.h>
using namespace std;
const int MAX_FLIGHTS = 3;
const int MAX_PASSENGERS = 2;

const int ECONOMY = 0;
const int BUSINESS = 1;


class Passenger {
private:
    char name[50];
    int age;
    int passengerClass;

public:
    void setData(const char n[], int a, int pc) {
        strcpy(name, n);
        age = a;
        passengerClass = pc;
    }

    void showData() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Class: " << (passengerClass == ECONOMY ? "Economy" : "Business") << endl;
    }
};

class Flight {
private:
    int flightNumber;
    char destination[50];
    float distance;
    float fuelRequired;
    Passenger passengers[MAX_PASSENGERS];
    int numPassengers;

public:
    void setData(int fn, const char dest[], float dist, float fuel) {
        flightNumber = fn;
        strcpy(destination, dest);
        distance = dist;
        fuelRequired = fuel;
        numPassengers = 0;
    }

    void showData() const {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Destination: " << destination << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Fuel Required: " << fuelRequired << " liters" << endl;
        cout << "Passengers:" << std::endl;
        for (int i = 0; i < numPassengers; ++i) {
            passengers[i].showData();
            cout << endl;
        }
    }

    int getFlightNumber() const {
        return flightNumber;
    }

    friend class AirlineManagementSystem;
};

class AirlineManagementSystem {
private:
    Flight flights[MAX_FLIGHTS];
    int numFlights;

public:
    AirlineManagementSystem() : numFlights(0) {}

    void addFlight() {
        int fn;
        char dest[50];
        float dist, fuel;

        cout << "Enter flight number: ";
        cin >> fn;
        cout << "Enter destination: ";
        cin >> dest;
        cout << "Enter distance (in km): ";
        cin >> dist;
        cout << "Enter fuel required (in liters): ";
        cin >> fuel;

        if (numFlights < MAX_FLIGHTS) {
            flights[numFlights].setData(fn, dest, dist, fuel);
            numFlights++;
            cout <<endl;
            cout << "Flight added successfully." << endl;
            cout <<endl;
        } else {
        	cout <<endl;
            cout << "Maximum number of flights reached. Cannot add more." << endl;
            cout <<endl;
        }
    }

    void displayAllFlights() const {
        if (numFlights == 0) {
        	cout <<endl;
            cout << "No flights available." << endl;
            cout <<endl;
            return;
        }

        cout <<endl;
        cout << "All Flights:" << endl;
        for (int i = 0; i < numFlights; ++i) {
            flights[i].showData();
            cout << endl;
        }
        cout<<endl;
    }

    void searchFlight(int flightNumber) const {
        for (int i = 0; i < numFlights; ++i) {
            if (flights[i].getFlightNumber() == flightNumber) {
            	cout <<endl;
                cout << "Flight found:" << endl;
                flights[i].showData();
                cout <<endl;
                return;
            }
        }
        
        cout << "Flight not found." << endl;
      
    }

    void deleteFlight(int flightNumber) {
        for (int i = 0; i < numFlights; ++i) {
            if (flights[i].getFlightNumber() == flightNumber) {
                for (int j = i; j < numFlights - 1; ++j) {
                    flights[j] = flights[j + 1];
                }
                numFlights--;
                cout <<endl;
                cout << "Flight deleted successfully." << endl;
                cout <<endl;
                return;
            }
        }
     
        cout << "Flight not found. Deletion failed." << endl;
        
    }

    void updateFlight(int flightNumber) {
        char newDest[50];
        float newDist, newFuel;

        cout <<endl;
        cout << "Enter new destination: ";
        cin >> newDest;
        cout << "Enter new distance (in km): ";
        cin >> newDist;
        cout << "Enter new fuel required (in liters): ";
        cin >> newFuel;

        for (int i = 0; i < numFlights; ++i) {
            if (flights[i].getFlightNumber() == flightNumber) {
                flights[i].setData(flightNumber, newDest, newDist, newFuel);
                cout << "Flight updated successfully." << endl;
                cout <<endl;
                return;
            }
        }
        cout << "Flight not found. Update failed." << endl;
        cout << endl;
    }

    void addPassengerToFlight(int flightNumber) {
        char name[50];
        int age;
        char classChoice;
        
        cout << endl;
        cout << "Enter passenger name: ";
        cin >> name;
        cout << "Enter passenger age: ";
        cin >> age;
        cout << "Enter passenger class (E for Economy, B for Business): ";
        cin >> classChoice;

        int pc = ECONOMY;
        if (classChoice == 'B' || classChoice == 'b') {
            pc = BUSINESS;
        }

        for (int i = 0; i < numFlights; ++i) {
            if (flights[i].getFlightNumber() == flightNumber) {
                if (flights[i].numPassengers < MAX_PASSENGERS) {
                    flights[i].passengers[flights[i].numPassengers].setData(name, age, pc);
                    flights[i].numPassengers++;
                    cout << "Passenger added to the flight successfully." << endl;
                    cout << endl;
                } else {
                    cout << "Maximum number of passengers reached for this flight." << endl;
                    cout << endl;
                }
                return;
            }
        }
        cout << "Flight not found. Could not add passenger." << endl;
        cout << endl;
    }
};

bool login() {
    const char adminUsername[] = "admin";
    const char adminPassword[] = "password";

    char username[50];
    char password[50];

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (strcmp(password, adminPassword) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t\t                                 "<<endl;
	cout<<"\t\t\t\t\t                                 "<<endl;
	cout<<"\t\t\t\t\t                                 "<<endl;
	cout<<"\t\t\t\t\t...............Welcome..........."<<endl;
	cout<<"\t\t\t\t\t.................To.............."<<endl;
	cout<<"\t\t\t\t\t..........FRIEND AIRLINES........"<<endl;
	cout<<"\t\t\t\t\t                                 "<<endl;
	cout<<"\t\t\t\t\t                                 "<<endl;
	cout<<"\t\t\t\t\t                                 "<<endl;
	system("color 3F");
	Sleep(2000);
    bool loginSuccess = false;
    cout<<endl;
    cout<<endl;
    
    cout << "\t\t\t\t\t\t<<<Login System>>>"<<endl;
   
    if (!login()) {
        cout << "Invalid username or password. Exiting program.\n";
        return 1;
    }
    
                 AirlineManagementSystem ams;

    int choice;
    do {
        cout << "\n\t<<<AIRLINE MANAGEMENT SYSTEM>>>\n";
        cout << "\n\t\t <<<MENU>>>\n";
        cout << " ___________________________\n";
        cout << "|1.| Add Flight             |\n";
        cout << " ___________________________\n";
        cout << "|2.| Display All Flights    |\n";
        cout << " ___________________________\n";
        cout << "|3.| Search Flight          |\n";
        cout << " ___________________________\n";
        cout << "|4.| Delete Flight          |\n";
        cout << " ___________________________\n";
        cout << "|5.| Update Flight          |\n";
        cout << " ___________________________\n";
        cout << "|6.| Add Passenger to Flight|\n";
        cout << " ___________________________\n";
        cout << "|7.| Exit                   |\n";
        cout << " ___________________________\n";
        cout << "\nEnter your choice:";
        cin >> choice;
        cout <<endl;
        switch (choice) {
            case 1:
                ams.addFlight();
                break;
            case 2:
                ams.displayAllFlights();
                break;
            case 3: {
                int fn;
                cout << "Enter flight number to search: ";
                cin >> fn;
                ams.searchFlight(fn);
                break;
            }
            case 4: {
                int fn;
                cout << "Enter flight number to delete: ";
                cin >> fn;
                ams.deleteFlight(fn);
                break;
            }
            case 5: {
                int fn;
                cout << "Enter flight number to update: ";
                cin >> fn;
                ams.updateFlight(fn);
                break;
            }
            case 6: {
                int fn;
                cout << "Enter flight number to add passenger: ";
                cin >> fn;
                ams.addPassengerToFlight(fn);
                break;
            }
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7.\n";
        }
    } while (choice != 7);
            
    return 0;
}

