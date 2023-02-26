#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

//Class for grocery item tracking
class ItemTracker 
{
private:
    map<string, int> frequencyMap; //I used map to store frequencies as recomended

public:
 
    ItemTracker() 
    {
        ifstream inputFile("CS210_Project_Three_Input_File.txt"); //reading of txt file is being done in constructor
        string item;
        while (getline(inputFile, item)) {
            frequencyMap[item]++;
        }
        inputFile.close();
    }

  
    void Display_Frequency(string item) 
    { // this method is displaying specific item
        if (frequencyMap.find(item) == frequencyMap.end()) {
            
            cout << "Item not found in records." << endl;
        }
        else {
            cout << "Frequency of " << item << " is " << frequencyMap[item] << endl;
        }
    }

    void DisplayAllFrequencies() 
    {
        // // this method is displaying all item
        cout << "List of all items and their frequencies:" << endl;
        for (auto it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }
    }

    void Display_Histogram() 
    {
        // // this method is displaying  histogram of item frequencies

        cout << "Histogram of Item Frequencies:" << endl;
        for (auto it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
            cout << it->first << " ";
            for (int i = 0; i < it->second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Method to write frequency map to backup file
    void BackupFile()
    {
        ofstream backupFile("frequency.dat");
        for (auto it = frequencyMap.begin(); it != frequencyMap.end(); it++)
        {
            backupFile << it->first << " " << it->second << endl;
        }
        backupFile.close();
    }
};

int main() {
    
    ItemTracker tracker;

    cout << "       Welcome To Grocery Item Tracking Application." << endl << endl;
    int choice;
    string item;
    do {
        cout << endl;
        cout << "1. Display Specific Item"<<endl;
        cout << "2. Display Frequencies of All Items" << endl;
        cout << "3. Display Item Frequencies Histogram" << endl;
        cout<<"4. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item Name: ";
            cin >> item;
            tracker.Display_Frequency(item);
            break;

        case 2:
            tracker.DisplayAllFrequencies();
            break;

        case 3:
            tracker.Display_Histogram();
            break;

        case 4:
            // Write frequency map to backup file and exit program
            tracker.BackupFile();
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
