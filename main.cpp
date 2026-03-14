#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string medName;
    string time;
    string dosage;
    Node* next;

    // Constructor to initialize a new node
    Node(string m, string t, string d) {
        medName = m;
        time = t;
        dosage = d;
        next = NULL;
    }
};
class PillReminder {
private:
    Node* head;

public:
    // Constructor
    PillReminder() {
        head = NULL;
    }

    // Function to add reminder at head
    void addReminder(string medName, string time, string dosage) {
        Node* newNode = new Node(medName, time, dosage);
        newNode->next = head; // connect new node to current head
        head = newNode;       // new node becomes head
        cout << "Reminder added successfully!\n";
    }

    // Function to view all reminders
    void viewReminders() {
        if (head == NULL) {
            cout << "No reminders found!\n";
            return;
        }
        Node* current = head;
        while (current != NULL) {
            cout << "Medicine: " << current->medName
                 << ", Time: " << current->time
                 << ", Dosage: " << current->dosage << endl;
            current = current->next;
        }
    }

    // Function to delete a reminder by medicine name
    void deleteReminder(string medName) {
        if (head == NULL) {
            cout << "No reminders to delete!\n";
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        // Traverse to find the node
        while (current != NULL && current->medName != medName) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Medicine not found!\n";
            return;
        }

        // Remove the node
        if (prev == NULL) { // deleting head
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        cout << "Reminder deleted successfully!\n";
    }
};
int main() {
    PillReminder pr;
    int choice;
    string name, time, dosage;

    do {
        cout << "\n--- Pill Reminder Menu ---\n";
        cout << "1. Add reminder\n2. View reminders\n3. Delete reminder\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // to handle newline

        switch(choice) {
            case 1:
                cout << "Medicine name: ";
                getline(cin, name);
                cout << "Time (HH:MM): ";
                getline(cin, time);
                cout << "Dosage: ";
                getline(cin, dosage);
                pr.addReminder(name, time, dosage);
                break;
            case 2:
                pr.viewReminders();
                break;
            case 3:
                cout << "Medicine name to delete: ";
                getline(cin, name);
                pr.deleteReminder(name);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}

