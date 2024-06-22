
#include  <iostream>
#include  <fstream>
#include  <string>
#include  <limits> // added for input handling

using namespace std;
// Function to query the balance of an user
// Input: name of the user account
// Output: amount of money the user have in the bank 
int queryBalance(const string& account) {
    string filePath("./storage/" + account + ".txt");
    ifstream accountFile(filePath);
    if (!accountFile) { // simplified the check
        return 0;
        }
    int balance = 0;
    accountFile >> balance;
    accountFile.close();
    return balance;
}
int main() {
    while (true) {
        cout << "Main Menu:\n";
        cout << "1. Query balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: \n";
        
        int choice;
        while (!(cin >> choice) || choice < 1 || choice > 2) { // input validation
            cout << "Invalid choice. Please try again.\n";
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore bad input
        }

        if (choice == 1) {
            cout << "Enter user account: ";
            string account;
            while (!(cin >> account)) { // input validation
                cout << "Invalid account. Please try again.\n";
                cin.clear(); // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore bad input
            }
            int balance = queryBalance(account);
            cout << "Balance: " << balance << endl;
        } else {
            break;
        }
    }
    return 0;
}

