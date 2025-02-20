#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Struct to represent a hotel room
struct Room {
    int roomNumber;
    string type; // e.g., Single, Double, Suite
    bool isReserved;
    string guestName;
    double price; // Room price
    string checkInTime; // Time of check-in
};

// Function to display all rooms
void displayRooms(Room rooms[], int size) {
    cout << "\nHotel Rooms:\n";
    cout << "Room Number  Type           Price          Status         Guest Name      Check-In Time\n";
    for (int i = 0; i < size; i++) {
        cout << rooms[i].roomNumber << "          " << rooms[i].type << "           $" << rooms[i].price << "          ";
        if (rooms[i].isReserved) {
            cout << "Reserved          " << rooms[i].guestName << "      " << rooms[i].checkInTime << "\n";
        } else {
            cout << "Available         -              -\n";
        }
    }
}

// Function to reserve a room
void reserveRoom(Room rooms[], int size) {
    int roomNumber;
    cout << "\nEnter the room number to reserve: ";
    cin >> roomNumber;

    for (int i = 0; i < size; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (rooms[i].isReserved) {
                cout << "Room " << roomNumber << " is already reserved.\n";
            } else {
                cout << "Enter guest name: ";
                cin.ignore();
                getline(cin, rooms[i].guestName);
                rooms[i].isReserved = true;
                cout << "Room " << roomNumber << " has been reserved successfully!\n";
            }
            return;
        }
    }
    cout << "Room " << roomNumber << " does not exist.\n";
}

// Function to cancel a reservation
void cancelReservation(Room rooms[], int size) {
    int roomNumber;
    cout << "\nEnter the room number to cancel the reservation: ";
    cin >> roomNumber;

    for (int i = 0; i < size; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (rooms[i].isReserved) {
                rooms[i].isReserved = false;
                rooms[i].guestName = "";
                rooms[i].checkInTime = "";
                cout << "Reservation for room " << roomNumber << " has been canceled.\n";
            } else {
                cout << "Room " << roomNumber << " is not currently reserved.\n";
            }
            return;
        }
    }
    cout << "Room " << roomNumber << " does not exist.\n";
}

// Function to check in a guest
void checkIn(Room rooms[], int size) {
    int roomNumber;
    cout << "\nEnter the room number to check in: ";
    cin >> roomNumber;

    for (int i = 0; i < size; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (rooms[i].isReserved) {
                // Get the current time
                time_t now = time(0);
                char* dt = ctime(&now);
                rooms[i].checkInTime = dt;

                cout << "Guest " << rooms[i].guestName << " has been checked into room " << roomNumber << ".\n";
            } else {
                cout << "Room " << roomNumber << " is not reserved. Please reserve it first.\n";
            }
            return;
        }
    }
    cout << "Room " << roomNumber << " does not exist.\n";
}

// Function to check out a guest
void checkOut(Room rooms[], int size) {
    int roomNumber;
    cout << "\nEnter the room number to check out: ";
    cin >> roomNumber;

    for (int i = 0; i < size; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (rooms[i].isReserved && !rooms[i].checkInTime.empty()) {
                rooms[i].isReserved = false;
                rooms[i].guestName = "";
                rooms[i].checkInTime = "";

                cout << "Room " << roomNumber << " has been checked out successfully.\n";
            } else {
                cout << "Room " << roomNumber << " is not checked in.\n";
            }
            return;
        }
    }
    cout << "Room " << roomNumber << " does not exist.\n";
}

int main() {
    Room rooms[] = {
        {101, "Single", false, "", 100.0, ""},
        {102, "Double", false, "", 150.0, ""},
        {103, "Suite", false, "", 300.0, ""},
        {104, "Single", false, "", 100.0, ""},
        {105, "Double", false, "", 150.0, ""}
    };
    int roomCount = 5;

    int choice;
    do {
        cout << "\nHotel Room Reservation System\n";
        cout << "1. Display Rooms\n";
        cout << "2. Reserve a Room\n";
        cout << "3. Cancel a Reservation\n";
        cout << "4. Check In\n";
        cout << "5. Check Out\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayRooms(rooms, roomCount);
                break;
            case 2:
                reserveRoom(rooms, roomCount);
                break;
            case 3:
                cancelReservation(rooms, roomCount);
                break;
            case 4:
                checkIn(rooms, roomCount);
                break;
            case 5:
                checkOut(rooms, roomCount);
                break;
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
// the end

