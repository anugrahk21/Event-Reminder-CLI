#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct Event {
    string name;
    string date;
    string note;
    Event* next;
};

class EventReminder {
private:
    Event* head;

public:
    EventReminder() : head(nullptr) {}

    ~EventReminder() {
        while (head) {
            Event* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Validates date format (YYYY-MM-DD)
    bool isValidDate(const string& date) {
        if (date.length() != 10) return false;
        if (date[4] != '-' || date[7] != '-') return false;
        
        for (int i = 0; i < 10; i++) {
            if (i != 4 && i != 7 && !isdigit(date[i])) return false;
        }
        
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        if (year < 2024 || month < 1 || month > 12 || day < 1 || day > 31) return false;
        return true;
    }

    // Checks if event name already exists
    bool eventExists(const string& name) {
        Event* current = head;
        while (current) {
            if (current->name == name) return true;
            current = current->next;
        }
        return false;
    }

    // Adds event in chronological order
    void addEvent() {
        string name, date, note;
        
        cout << "\n--- Add New Event ---\n";
        cout << "Enter event name: ";
        cin.ignore();
        getline(cin, name);
        
        if (eventExists(name)) {
            cout << "Error: Event with this name already exists!\n";
            return;
        }
        
        cout << "Enter date (YYYY-MM-DD): ";
        getline(cin, date);
        
        if (!isValidDate(date)) {
            cout << "Error: Invalid date format! Use YYYY-MM-DD\n";
            return;
        }
        
        cout << "Enter note (optional): ";
        getline(cin, note);
        
        Event* newEvent = new Event{name, date, note, nullptr};
        
        if (!head || date < head->date) {
            newEvent->next = head;
            head = newEvent;
        } else {
            Event* current = head;
            while (current->next && current->next->date < date) {
                current = current->next;
            }
            newEvent->next = current->next;
            current->next = newEvent;
        }
        
        cout << "Event added successfully!\n";
    }

    // Removes event by name
    void removeEvent() {
        if (!head) {
            cout << "No events to remove!\n";
            return;
        }
        
        string name;
        cout << "\n--- Remove Event ---\n";
        cout << "Enter event name to remove: ";
        cin.ignore();
        getline(cin, name);
        
        if (head->name == name) {
            Event* temp = head;
            head = head->next;
            delete temp;
            cout << "Event removed successfully!\n";
            return;
        }
        
        Event* current = head;
        while (current->next && current->next->name != name) {
            current = current->next;
        }
        
        if (current->next) {
            Event* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Event removed successfully!\n";
        } else {
            cout << "Event not found!\n";
        }
    }

    // Displays all events in chronological order
    void viewAllEvents() {
        cout << "\n--- All Events ---\n";
        if (!head) {
            cout << "No events scheduled!\n";
            return;
        }
        
        Event* current = head;
        int count = 1;
        while (current) {
            cout << count++ << ". " << current->name << "\n";
            cout << "   Date: " << current->date << "\n";
            if (!current->note.empty()) {
                cout << "   Note: " << current->note << "\n";
            }
            cout << "\n";
            current = current->next;
        }
    }

    // Searches for event by name
    void searchEvent() {
        if (!head) {
            cout << "No events to search!\n";
            return;
        }
        
        string name;
        cout << "\n--- Search Event ---\n";
        cout << "Enter event name to search: ";
        cin.ignore();
        getline(cin, name);
        
        Event* current = head;
        while (current) {
            if (current->name == name) {
                cout << "\nEvent Found:\n";
                cout << "Name: " << current->name << "\n";
                cout << "Date: " << current->date << "\n";
                if (!current->note.empty()) {
                    cout << "Note: " << current->note << "\n";
                }
                return;
            }
            current = current->next;
        }
        cout << "Event not found!\n";
    }

    // Edits existing event details
    void editEvent() {
        if (!head) {
            cout << "No events to edit!\n";
            return;
        }
        
        string name;
        cout << "\n--- Edit Event ---\n";
        cout << "Enter event name to edit: ";
        cin.ignore();
        getline(cin, name);
        
        Event* current = head;
        while (current && current->name != name) {
            current = current->next;
        }
        
        if (!current) {
            cout << "Event not found!\n";
            return;
        }
        
        cout << "\nCurrent details:\n";
        cout << "Name: " << current->name << "\n";
        cout << "Date: " << current->date << "\n";
        cout << "Note: " << current->note << "\n";
        
        string newDate, newNote;
        cout << "\nEnter new date (YYYY-MM-DD): ";
        getline(cin, newDate);
        
        if (!isValidDate(newDate)) {
            cout << "Error: Invalid date format!\n";
            return;
        }
        
        cout << "Enter new note: ";
        getline(cin, newNote);
        
        // Remove from current position
        if (current == head) {
            head = head->next;
        } else {
            Event* prev = head;
            while (prev->next != current) {
                prev = prev->next;
            }
            prev->next = current->next;
        }
        
        // Update details
        current->date = newDate;
        current->note = newNote;
        current->next = nullptr;
        
        // Reinsert in correct position
        if (!head || newDate < head->date) {
            current->next = head;
            head = current;
        } else {
            Event* temp = head;
            while (temp->next && temp->next->date < newDate) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        
        cout << "Event updated successfully!\n";
    }

    // Displays main menu
    void displayMenu() {
        cout << "\n=== Event Reminder CLI ===\n";
        cout << "1. Add Event\n";
        cout << "2. Remove Event\n";
        cout << "3. View All Events\n";
        cout << "4. Search Event\n";
        cout << "5. Edit Event\n";
        cout << "6. Exit\n";
        cout << "Choose an option (1-6): ";
    }

    // Main application loop
    void run() {
        int choice;
        cout << "Welcome to Event Reminder CLI!\n";
        
        while (true) {
            displayMenu();
            cin >> choice;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a number.\n";
                continue;
            }
            
            switch (choice) {
                case 1:
                    addEvent();
                    break;
                case 2:
                    removeEvent();
                    break;
                case 3:
                    viewAllEvents();
                    break;
                case 4:
                    searchEvent();
                    break;
                case 5:
                    editEvent();
                    break;
                case 6:
                    cout << "Thank you for using Event Reminder CLI!\n";
                    return;
                default:
                    cout << "Invalid choice! Please select 1-6.\n";
            }
        }
    }
};

int main() {
    EventReminder app;
    app.run();
    return 0;
}
