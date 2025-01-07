#include<iostream>
#include<windows.h>
#include<fstream>
#include<sstream>
#include <iomanip>
#include <vector>

using namespace std;

//       <-- Function Prototype -->
void welcome();
void header();
int menu();
void adminoptions();
bool adminlogin();
void useroptions();

//       <-- Admin Mode Function Prototype -->
void addTrainDetail();
void displayTrainDetails();
void updateTrainDetails();
void deleteTrainRecord();
void displayBookingDetails();

//       <-- User Mode Function Prototype -->
void searchTrainDetails();
void reserveTrainTicket();
void cancelTicket();

//       <-- MAIN BODY -->
int main()
{
    welcome();
    int choice;

    do
    {
        header();
        choice = menu();

        switch (choice)
        {
        case 1:
            if (adminlogin())
            {
                cout << "\n\t\t\t\t\t-*================================================*-";
                cout << "\n\t\t\t\t\t||    * SUCCESSFULLY LOGGED IN TO ADMIN MENU *    ||";
                cout << "\n\t\t\t\t\t-*================================================*-";
                Sleep(4000);
                system("cls");
                header();
                adminoptions();
            }
            else
            {
                cout << "\n\t\t\t\t\t  INVALID USERNAME OR PASSWORD. PLEASE TRY AGAIN\n";
                Sleep(4000);
                cout << "\n\n\n\n\n\n\tPress Any Key to Continue...";
                cin.ignore();
                cin.get();
                system("cls");
            }
            break;

        case 2:
           
            cout << "\n\t\t\t\t\t-*================================================*-";
            cout << "\n\t\t\t\t\t||             * LOADING USER MENU... *           ||";
            cout << "\n\t\t\t\t\t-*================================================*-";
            Sleep(4000);
            system("cls");
            header();
            useroptions();
            break;

        case 3:
            system("cls");
            system("color 0A");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  THANKS FOR USING MY MANAGEMENT SYSTEM";
            cout << "\n\n\t\t\t\t\t\t\t  HAVE A NICE DAY :)\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cin.ignore();
            break;

        default:
            cout << "Invalid Choice. Please enter a valid Option" << endl;
            break;
        }

    } while (choice != 3);

    return 0;
}

//       <-- WELCOME Function -->
void welcome()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
    cout << "      WELCOME TO TRAIN RESERVATION MANAGEMENT SYSTEM ";
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tCreated By :";
    cout << " \n\t\t\t\t\t\t\t\tMUHAMMAD HASSAN CHOHAN\n\n\t\t\t\t\t\tReg No. :\n\t\t\t\t\t\t\t\t 2023-CS-458";
    cout << "\n\n\t\t\t\t\t\tINSTRUCTOR: \n\t\t\t\t\t\t\t\t DR. NATASHA NIGAR";
    cout << "\n\n\t\t\t\t\t\tCOURSE TITLE: \n\t\t\t\t\t\t\t\t DSA (C++)";
    cout << "\n";
    cin.get();
    system("cls");

    SetConsoleTextAttribute(hConsole, 7);
}

//       <-- Header Function -->
void header()
{
    cout << "******========================================================================================================================******" << endl;
    cout << "*                                            *** TRAIN RESERVATION MANAGEMENT SYSTEM ***                                           *" << endl;
    cout << "******========================================================================================================================******" << endl;
}

//          <-- Main Menu -->
int menu()
{
    int choice;
    cout << endl << endl;
    cout << "\t\t\t\t\t\t-***********************************-" << endl;
    cout << "\t\t\t\t\t\t||        *---MAIN MENU---*        ||" << endl;
    cout << "\t\t\t\t\t\t||---------------------------------||" << endl;
    cout << "\t\t\t\t\t\t||                                 ||" << endl;
    cout << "\t\t\t\t\t\t||  1.  ADMIN MODE                 ||" << endl;
    cout << "\t\t\t\t\t\t||  2.  USER MODE                  ||" << endl;
    cout << "\t\t\t\t\t\t||  3.  EXIT                       ||" << endl;
    cout << "\t\t\t\t\t\t||                                 ||" << endl;
    cout << "\t\t\t\t\t\t-***********************************-" << endl;
    cout << endl;
    cout << "  Enter Your Choice : ";
    cin >> choice;

    return choice;
}

//          <-- Admin Options -->
void adminoptions()
{
    int choice;
    do
    {
        cout << endl << endl;
        cout << "\t\t\t\t\t\t-***************************************-" << endl;
        cout << "\t\t\t\t\t\t||      *---ADMINISTRATOR MENU---*     ||" << endl;
        cout << "\t\t\t\t\t\t||-------------------------------------||" << endl;
        cout << "\t\t\t\t\t\t||  1. Add Train Details               ||" << endl;
        cout << "\t\t\t\t\t\t||  2. Update Specific Train Detail    ||" << endl;
        cout << "\t\t\t\t\t\t||  3. Display Trains Details          ||" << endl;
        cout << "\t\t\t\t\t\t||  4. Delete Train Record             ||" << endl;
        cout << "\t\t\t\t\t\t||  5. Display Booking Details         ||" << endl;
        cout << "\t\t\t\t\t\t||  6. Return to Main Menu             ||" << endl;
        cout << "\t\t\t\t\t\t-***************************************-" << endl;
        cout << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            header();
            cout << "\n\t\t\t\t\t  -**************************************************-";
            cout << "\n\t\t\t\t\t  ||      *---ADD NEW TRAIN RECORD DETAILS.---*     ||";
            cout << "\n\t\t\t\t\t  -**************************************************-" << endl;
            addTrainDetail();
            break;

        case 2:
            system("cls");
            header();
            cout << "\n\t\t\t\t\t  -**************************************************-";
            cout << "\n\t\t\t\t\t  ||      *---UPDATE TRAIN RECORD DETAILS.---*     ||";
            cout << "\n\t\t\t\t\t  -**************************************************-" << endl;
            updateTrainDetails();
            break;


        case 3:
            system("cls");
            header();
            cout << "\n\t\t\t\t\t  -**************************************************-";
            cout << "\n\t\t\t\t\t  ||          *---TRAIN RECORD DETAILS.---*         ||";
            cout << "\n\t\t\t\t\t  -**************************************************-" << endl;
            displayTrainDetails();
            break;

        case 4:
            system("cls");
            header();
            cout << "\n\t\t\t\t\t  -**************************************************-";
            cout << "\n\t\t\t\t\t  ||      *---DELETE TRAIN RECORD DETAILS.---*      ||";
            cout << "\n\t\t\t\t\t  -**************************************************-" << endl;
            deleteTrainRecord();
            cin.ignore();
            cin.get();
            system("cls");
            header();
            break;

        case 5:
            system("cls");
            header();
            displayBookingDetails();
            cout << "\nPress any key to return to the Admin Menu...";
            cin.ignore();
            cin.get();
            system("cls");
            header();
            break;

        case 6:
            cout << "\n\t\t\tRETURNING TO MAIN MENU." << endl;
            Sleep(3000);
            system("cls");
            return;  // Exit and return to main menu
            break;

        default:
            cout << "\n\t\t\tPlease Enter the Valid Choice: (1-8)." << endl;
            Sleep(4000);
            system("cls");
            header();
        }
    } while (choice != 7);
}




//          <-- Admin Login Credentials -->
bool adminlogin()
{
    string username;
    string password;

    ifstream file("Admin_Credentials.txt");
    if (!file)
    {
        cout << "Unable to Open File. ";
        return false;
    }
    
    cout << "\n\tEnter Admin UserName : ";
    cin >> username;
    cout << "\n\tEnter Admin Password : ";
    cin >> password;
    cout << endl;

    string file_username;
    string file_password;
    while (file >> file_username >> file_password)
    {
        if (username == file_username && password == file_password)
        {
            return true;
        }
    }
    return false;
}




//          <-- User Options -->
void useroptions()
{
    int choice;
    do
    {
        cout << endl << endl;
        cout << "\t\t\t\t\t\t-***************************************-" << endl;
        cout << "\t\t\t\t\t\t||         *---USER MENU---*         ||" << endl;
        cout << "\t\t\t\t\t\t||-----------------------------------||" << endl;
        cout << "\t\t\t\t\t\t||  1. Search Train Details          ||" << endl;
        cout << "\t\t\t\t\t\t||  2. Reserve Train Ticket          ||" << endl;
        cout << "\t\t\t\t\t\t||  3. Cancel Train Ticket           ||" << endl;
        cout << "\t\t\t\t\t\t||  4. Return to Main Menu           ||" << endl;
        cout << "\t\t\t\t\t\t-*************************************-" << endl;
        cout << endl;
        cout << " Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            searchTrainDetails();
            break;

        case 2:
            system("cls");
            header();
            reserveTrainTicket();
            cout << "\nPress any key to continue...";

            cin.ignore();
            cin.get();
            system("cls");
            header();
            break;

        case 3:
            system("cls");
            header();
            cancelTicket();
            cout << "\nPress any key to continue...";

            cin.ignore();
            cin.get();
            system("cls");
            header();
            
            
            break;

        case 4:
            cout << "\n\tReturning to Main Menu...\n";
            Sleep(3000);
            system("cls");
            
            return;  // Exit and return to the main menu
            
            break;

        default:
            cout << "\n\tInvalid choice. Please try again.\n";
            break;
        }

    } while (true);  // Infinite loop, will exit on 'return' when option 5 is chosen
}




// Train Node Structure
struct Train
{
    string trainNo;
    string trainName;
    string boardingStation;
    string destinationStation;
    string departureTime;
    string arrivalTime;
    string dateOfTravel;
    int economySeats;
    int acSeats;
    int businessSeats;
    float economyFare;
    float acFare;
    float businessFare;
    Train* next;

    Train() : next(nullptr) {}
};

// Head of Linked List
Train* head = nullptr;

// Function to Add Train Details
void addTrainDetail()
{
    string addMore;
    do
    {
        Train* newTrain = new Train();

        cout << "\n\tEnter Train Number: ";
        cin >> newTrain->trainNo;

        cout << "\tEnter Train Name: ";
        cin.ignore();
        getline(cin, newTrain->trainName);

        cout << "\n\tEnter Boarding Station: ";
        getline(cin, newTrain->boardingStation);

        cout << "\tEnter Destination Station: ";
        getline(cin, newTrain->destinationStation);

        cout << "\n\tEnter Total Number of Economy Class Seats: ";
        cin >> newTrain->economySeats;

        cout << "\tEnter Fare for Economy Class: ";
        cin >> newTrain->economyFare;

        cout << "\n\tEnter Total Number of AC Standard Class Seats: ";
        cin >> newTrain->acSeats;

        cout << "\tEnter Fare for AC Standard Class: ";
        cin >> newTrain->acFare;

        cout << "\n\tEnter Total Number of Business Class Seats: ";
        cin >> newTrain->businessSeats;

        cout << "\tEnter Fare for Business Class: ";
        cin >> newTrain->businessFare;

        cout << "\n\tEnter Departure Time (in format HH:MM): ";
        cin.ignore();
        getline(cin, newTrain->departureTime);

        cout << "\tEnter Arrival Time (in format HH:MM): ";
        getline(cin, newTrain->arrivalTime);

        cout << "\n\tEnter Date of Travel (in format DD-MM-YYYY): ";
        getline(cin, newTrain->dateOfTravel);

        // Append to Linked List
        if (head == nullptr)
        {
            head = newTrain;
        }
        else
        {
            Train* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newTrain;
        }

        // Save to File
        ofstream file("TrainDetails.txt", ios::app);
        if (!file)
        {
            cout << "Unable to open file.\n";
            return;
        }
        file << newTrain->trainNo << ' '
            << newTrain->trainName << ' '
            << newTrain->boardingStation << ' '
            << newTrain->destinationStation << ' '
            << newTrain->economySeats << ' '
            << newTrain->economyFare << ' '
            << newTrain->acSeats << ' '
            << newTrain->acFare << ' '
            << newTrain->businessSeats << ' '
            << newTrain->businessFare << ' '
            << newTrain->departureTime << ' '
            << newTrain->arrivalTime << ' '
            << newTrain->dateOfTravel << '\n';
        file.close();

        cout << "\n\t\t\t\t\t      -*========================================*-";
        cout << "\n\t\t\t\t\t      ||  SUCCESSFULLY SAVED THE TRAIN RECORD.  ||";
        cout << "\n\t\t\t\t\t      -*========================================*-";
        cout << endl;
        cout << "\n\tDo you want to add more records? (Yes/No): ";
        cin >> addMore;
        system("cls");
        header(); 
        

    } while (addMore == "yes" || addMore == "y");
}

void displayTrainDetails()
{
    if (head == nullptr)
    {
        
        cout << "\n\tNo train records found.\n";
        Sleep(4000);
        system("cls");
        header();
        return;
        
    }

    Train* temp = head;

    while (temp != nullptr)
    {
        cout << "\n====================================================================================================================================\n";
        cout << "| TRAIN NO.  | TRAIN NAME       | BOARDING.STATION      | DESTINATION.STATION      | ECOMONY CLASS SEATS   | ECOMONY CLASS FARE    |\n";
        cout << "====================================================================================================================================\n";
        cout << "|  " << setw(10) << temp->trainNo
             << setw(18) << temp->trainName
             << setw(25) << temp->boardingStation
             << setw(26) << temp->destinationStation
             << setw(25) << temp->economySeats
             << setw(22) << fixed << setprecision(2) << temp->economyFare
             << " |" << endl;

        cout << "====================================================================================================================================\n";
        cout << "| AC.STANDARD SEATS  | AC.STANDARD FARE   | BUSINESS SEATS  | BUSINESS CLASS FARE | DEPARTURE TIME   | ARRIVAL TIME   | TRAVEL DATE |\n";
        cout << "====================================================================================================================================\n";
        cout << "| " << setw(18) << temp->acSeats
             << setw(18) << fixed << setprecision(2) << temp->acFare
             << setw(18) << temp->businessSeats
             << setw(18) << fixed << setprecision(2) << temp->businessFare
             << setw(18) << temp->departureTime
             << setw(17) << temp->arrivalTime
             << setw(18) << temp->dateOfTravel
             << "   |" << endl;

        cout << "====================================================================================================================================\n\n";
        temp = temp->next;
    }

    cout << "\n\tPress Enter to Continue... ";
    cin.ignore(); // Clear Input Buffer
    cin.get();
    system("cls");
    header();
}







void updateTrainDetails()
{
    if (head == nullptr)
    {
        cout << "\n\tNo train records found.\n";
        Sleep(3000);
        system("cls");
        
        return;
    }
    
    string searchTrainNo;
    cout << "\n\tEnter Train Number to Update: ";
    cin >> searchTrainNo;

    Train* temp = head;
    bool found = false;

    // Search for the train in the linked list
    while (temp != nullptr)
    {
        if (temp->trainNo == searchTrainNo)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found)
    {
        cout << "\n\tError: Train with number " << searchTrainNo << " not found!\n";
        Sleep(4000);
       
        system("cls");
        return;
        
        header();
        
    }

    // Update seats and time details
    cout << "\n\tTrain Found: " << temp->trainName << " (" << temp->trainNo << ")";
    cout << "\n\tEnter New Seat and Time Details:\n";

    cout << "\tEnter New Total Economy Class Seats: ";
    cin >> temp->economySeats;

    cout << "\tEnter New Total AC Standard Class Seats: ";
    cin >> temp->acSeats;

    cout << "\tEnter New Total Business Class Seats: ";
    cin >> temp->businessSeats;

    cout << "\n\tEnter New Departure Time (HH:MM): ";
    cin.ignore(); // Clear input buffer
    getline(cin, temp->departureTime);

    cout << "\tEnter New Arrival Time (HH:MM): ";
    getline(cin, temp->arrivalTime);

    // Update the file
    ofstream file("TrainDetails.txt");
    if (!file)
    {
        cout << "\n\tUnable to open file for writing updates.\n";
        return;
    }

    Train* current = head;
    while (current != nullptr)
    {
        file << current->trainNo << ' '
            << current->trainName << ' '
            << current->boardingStation << ' '
            << current->destinationStation << ' '
            << current->economySeats << ' '
            << current->economyFare << ' '
            << current->acSeats << ' '
            << current->acFare << ' '
            << current->businessSeats << ' '
            << current->businessFare << ' '
            << current->departureTime << ' '
            << current->arrivalTime << ' '
            << current->dateOfTravel << '\n';
        current = current->next;
    }
    file.close();

    cout << "\n\tTrain details updated successfully!\n";

    Sleep(3000);
    system("cls");
    header();
}


void deleteTrainRecord()
{
    if (head == nullptr)
    {
        cout << "\n\tNo train records found.\n";
        return;
    }

    string deleteTrainNo;
    cout << "\n\tEnter Train Number to Delete: ";
    cin >> deleteTrainNo;

    Train* temp = head;
    Train* prev = nullptr;
    bool found = false;

    // Search for the train to delete
    while (temp != nullptr)
    {
        if (temp->trainNo == deleteTrainNo)
        {
            found = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found)
    {
        cout << "\n\tError: Train with number " << deleteTrainNo << " not found!\n";
        return;
    }

    // If the train to delete is the head node
    if (temp == head)
    {
        head = head->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp; // Free memory
    cout << "\n\tTrain record deleted successfully!\n";

    // Update the file
    ofstream file("TrainDetails.txt");
    if (!file)
    {
        cout << "\n\tUnable to open file for writing updates.\n";
        return;
    }

    Train* current = head;
    while (current != nullptr)
    {
        file << current->trainNo << ' '
            << current->trainName << ' '
            << current->boardingStation << ' '
            << current->destinationStation << ' '
            << current->economySeats << ' '
            << current->economyFare << ' '
            << current->acSeats << ' '
            << current->acFare << ' '
            << current->businessSeats << ' '
            << current->businessFare << ' '
            << current->departureTime << ' '
            << current->arrivalTime << ' '
            << current->dateOfTravel << '\n';
        current = current->next;
    }
    file.close();
}



void displayBookingDetails()
{
    ifstream inFile("TrainPassengerDetails.txt");
    if (!inFile) {
        cout << "Unable to open the file." << endl;
        return;
    }

    string line;
    bool hasData = false;

    cout << "\n--- Booking Details ---\n";

    // Read through the file and display all bookings
    while (getline(inFile, line)) {
        // Display each line of the booking details (each ticket is separated by a line of "-----------------------------------")
        cout << line << endl;
        if (line == "--------------------------------------") {
            hasData = true;  // Indicating there is booking data
        }
    }

    inFile.close();

    if (!hasData) {
        cout << "No booking details found.\n";
    }

    
    
}


void searchTrainDetails()
{
    string sourceStation, destStation, travelDate;
    bool found = false;

    // Get user input for source, destination, and travel date
    cout << "\n\tEnter Source Station: ";
    cin.ignore();
    getline(cin, sourceStation);

    cout << "\tEnter Destination Station: ";
    getline(cin, destStation);

    cout << "\tEnter Date of Travel (DD-MM-YYYY): ";
    getline(cin, travelDate);

    Train* temp = head; // Start from the head of the linked list

    // Search through all trains
    while (temp != nullptr)
    {
        // Check if the train matches the input criteria
        if (temp->boardingStation == sourceStation && temp->destinationStation == destStation && temp->dateOfTravel == travelDate)
        {
            found = true;
            // Display the matching train details
            cout << "\n\tTrain Found:\n";
            cout << setw(10) << "Train No" << setw(20) << "Train Name" << setw(20) << "Boarding"
                << setw(20) << "Destination" << setw(15) << "Economy Seats" << setw(10)
                << "AC Seats" << setw(15) << "Business Seats" << endl;
            cout << setw(10) << temp->trainNo
                << setw(20) << temp->trainName
                << setw(20) << temp->boardingStation
                << setw(20) << temp->destinationStation
                << setw(15) << temp->economySeats
                << setw(10) << temp->acSeats
                << setw(15) << temp->businessSeats
                << endl;

            // Display more details
            cout << setw(22) << fixed << setprecision(2) << temp->economyFare
                << setw(22) << fixed << setprecision(2) << temp->acFare
                << setw(22) << fixed << setprecision(2) << temp->businessFare
                << setw(18) << temp->departureTime
                << setw(17) << temp->arrivalTime
                << setw(15) << temp->dateOfTravel
                << " |\n";
            cout << "\n==========================================================================================================================\n";
        }
        temp = temp->next;
    }

    if (!found)
    {
        cout << "\n\tNo trains found matching your search criteria.\n";
    }

    // Wait for the user to press any key before continuing
    cout << "\n\tPress Any Key to Continue...\n";
    cin.ignore();  // To clear the input buffer
    cin.get();  // Wait for the user to press any key

    system("cls");
    header();
    // After pressing any key, return to the user menu
    return; 
}
void reserveTrainTicket()
{
    string sourceStation, destStation, travelDate;
    cout << "\nEnter Source Station: ";
    cin.ignore();
    getline(cin, sourceStation);

    cout << "Enter Destination Station: ";
    getline(cin, destStation);

    cout << "Enter Date of Travel (DD-MM-YYYY): ";
    getline(cin, travelDate);

    Train* temp = head;
    vector<Train*> matchingTrains;

    // Search for matching trains
    while (temp != nullptr)
    {
        if (temp->boardingStation == sourceStation && temp->destinationStation == destStation &&
            temp->dateOfTravel == travelDate)
        {
            matchingTrains.push_back(temp);
        }
        temp = temp->next;
    }

    if (matchingTrains.empty())
    {
        cout << "\nNo trains found for the given route and date.\n";
        return;
    }

    // Display matching trains
    cout << "\nMatching Trains:\n";
    for (size_t i = 0; i < matchingTrains.size(); ++i)
    {
        cout << i + 1 << ". Train No: " << matchingTrains[i]->trainNo
            << ", Train Name: " << matchingTrains[i]->trainName
            << ", Seats Available: Economy=" << matchingTrains[i]->economySeats
            << ", AC=" << matchingTrains[i]->acSeats
            << ", Business=" << matchingTrains[i]->businessSeats
            << endl;
    }

    int trainChoice;
    cout << "\nSelect a train by number (1-" << matchingTrains.size() << "): ";
    cin >> trainChoice;

    if (trainChoice < 1 || trainChoice > matchingTrains.size())
    {
        cout << "\nInvalid choice.\n";
        return;
    }

    Train* selectedTrain = matchingTrains[trainChoice - 1];

    // Ask for seat type
    int seatChoice;
    cout << "\nSelect Seat Type:\n";
    cout << "1. Economy\n2. AC\n3. Business\n";
    cout << "Enter your choice: ";
    cin >> seatChoice;

    int availableSeats = 0;
    float fare = 0.0;

    switch (seatChoice)
    {
    case 1:
        availableSeats = selectedTrain->economySeats;
        fare = selectedTrain->economyFare;
        break;
    case 2:
        availableSeats = selectedTrain->acSeats;
        fare = selectedTrain->acFare;
        break;
    case 3:
        availableSeats = selectedTrain->businessSeats;
        fare = selectedTrain->businessFare;
        break;
    default:
        cout << "\nInvalid seat type.\n";
        return;
    }

    if (availableSeats <= 0)
    {
        cout << "\nSorry, no available seats for the selected seat type.\n";
        return;
    }

    // Ask for passenger details
    string passengerName, passengerCNIC, passengerPhone;
    int passengerAge;

    cout << "\nEnter Passenger Name: ";
    cin.ignore();
    getline(cin, passengerName);

    cout << "Enter Passenger Age: ";
    cin >> passengerAge;

    cout << "Enter Passenger CNIC: ";
    cin.ignore();
    getline(cin, passengerCNIC);

    cout << "Enter Passenger Phone: ";
    getline(cin, passengerPhone);

    // Generate a unique Ticket ID
    srand(time(0));
    int ticketID = rand() % 1000000 + 1;

    // Update train data (reduce available seats)
    switch (seatChoice)
    {
    case 1:
        selectedTrain->economySeats--;
        break;
    case 2:
        selectedTrain->acSeats--;
        break;
    case 3:
        selectedTrain->businessSeats--;
        break;
    }

    // Save ticket details to file
    ofstream outFile("TrainPassengerDetails.txt", ios::app);

    if (!outFile.is_open())
    {
        cout << "\nError: Unable to open the file 'TrainPassengerDetails.txt'.\n";
        return;  // Exit the function if the file can't be opened
    }

    // Write ticket details to the file
    outFile << "Ticket ID: " << ticketID << "\n"
        << "Train No: " << selectedTrain->trainNo << "\n"
        << "Train Name: " << selectedTrain->trainName << "\n"
        << "Passenger Name: " << passengerName << "\n"
        << "Passenger Age: " << passengerAge << "\n"
        << "Passenger CNIC: " << passengerCNIC << "\n"
        << "Passenger Phone: " << passengerPhone << "\n"
        << "Seat Type: " << (seatChoice == 1 ? "Economy" : seatChoice == 2 ? "AC" : "Business") << "\n"
        << "Fare: " << fare << "\n"
        << "Departure Date: " << selectedTrain->dateOfTravel << "\n"
        << "--------------------------------------\n";

    outFile.close();
    cout << "\nReservation successful! Ticket ID: " << ticketID << ". Details saved to 'TrainPassengerDetails.txt'.\n";
}



void cancelTicket()
{
    int ticketID;
    cout << "Enter Ticket ID to Cancel: ";
    cin >> ticketID;

    ifstream inFile("TrainPassengerDetails.txt");
    if (!inFile) {
        cout << "Unable to open the file." << endl;
        return;  // Exit if the file can't be opened
    }

    string line;
    bool ticketFound = false;
    ofstream tempFile("temp.txt", ios::app);

    // Read through the file and find the ticket ID
    while (getline(inFile, line)) {
        // Look for the exact line with the ticket ID (ensure format is correct)
        if (line.find("Ticket ID: " + to_string(ticketID)) != string::npos) {
            ticketFound = true;
            cout << "Ticket ID found. Removing the ticket...\n";
            continue;  // Skip this ticket (don't write it to the temporary file)
        }
        tempFile << line << endl;  // Write other details to the temp file
    }

    inFile.close();
    tempFile.close();

    if (ticketFound) {
        // Replace the original file with the updated file (without the canceled ticket)
        if (remove("TrainPassengerDetails.txt") != 0) {
            cout << "Error deleting original file.\n";
            return;
        }
        if (rename("temp.txt", "TrainPassengerDetails.txt") != 0) {
            cout << "Error renaming temporary file.\n";
            return;
        }
        cout << "Ticket has been canceled successfully.\n";
    }
    else {
        cout << "Ticket ID not found.\n";
        remove("temp.txt");  // Clean up if ticket wasn't found
    }
}