#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class ItemTracker {

private:
    unordered_map<string, int> numItems;

public:
    // Function to read items from file and populate numItems
    void ReadItemsFromFile(const string& filename) {
        ifstream inputFile(filename);
        string item;

        if (inputFile.is_open()) {
            while (inputFile >> item) {
                numItems[item]++;
            }
            inputFile.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

    // Function to search for an item frequency
    int GetItemFrequency(const string& item) {
        if (numItems.find(item) != numItems.end()) {
            return numItems[item];
        }
        else {
            return 0;
        }
    }

    // Function to print frequency list
    void PrintFrequencyList() {
        for (const auto& pair : numItems) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Function to print histogram
    void PrintHistogram() {
        for (const auto& pair : numItems) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Function to create a backup file
    void CreateBackupFile(const string& filename) {
        ofstream outputFile(filename);

        if (outputFile.is_open()) {
            for (const auto& pair : numItems) {
                outputFile << pair.first << " " << pair.second << endl;
            }
            outputFile.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }
};

int main() {
    ItemTracker tracker;
    string inputFile = "Project 3 Input File.txt";
    string backupFile = "frequency.dat";
    tracker.ReadItemsFromFile(inputFile);
    tracker.CreateBackupFile(backupFile);

    int choice;
    string item;

    //Menu Options
    do {
        cout << "Menu Options:" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Print frequency list" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Type one of the following options to continue: ";
        cin >> choice;

        switch (choice) {

        //Item frequency lookup
        case 1:
            system("cls");
            cout << "Enter item to search: ";
            cin >> item;
            cout << endl << item << " were purchased ";
            cout << tracker.GetItemFrequency(item) << " times.";
            cout << endl << endl;
            break;

        //Print frequency list
        case 2:
            system("cls");
            tracker.PrintFrequencyList();
            cout << endl;
            break;

        //Print histogram.
        case 3:
            system("cls");
            tracker.PrintHistogram();
            cout << endl;
            break;

        //Exit program
        case 4:
            system("cls");
            cout << "Thank you for using the ITEM TRACKER. ";
            cout << "Have a nice day!" << endl;
            break;
        default:
            cout << endl << "Invalid input. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
