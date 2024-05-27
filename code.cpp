# include <iostream>
# include <fstream>
# include <string>

using namespace std;
// Function to query the balance of a user
int queryBalance(const string&account){
    string filePath("./storage/" + account + ".txt");
    ifstream accountFile(filePath);
    if (!accountFile.is_open()){
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
        cin >> choice;
        if (choice == 1) {
            cout << "Enter user account: ";
            string account;
            cin >> account;
            int balance = queryBalance(account);
            cout << "Balance: " << balance << endl;
        } else if (choice == 2) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}