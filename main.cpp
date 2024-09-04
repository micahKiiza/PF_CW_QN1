#include <iostream>
#include <string>
using namespace std;

// Structure to store account details
struct Account {
    string userID;
    string password;
    double balance = 0.0;  // Initialize balance to 0.0
};

int main() {
    Account account;
    bool loggedIn = false;
    char choice;

    // Loop to display the introduction menu until the user quits
    while (true) {
        // Display the introduction menu
        cout << "Hi! Welcome to the ATM Machine!" << endl;
        cout << "Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cout << "> ";
        cin >> choice;

        if (choice == 'c') {  //
            cout << "Please enter your user name: ";
            cin >> account.userID;
            cout << "Please enter your password: ";
            cin >> account.password;
            account.balance = 0.0;
            cout << "Thank You! Your account has been created!" << endl;
        } else if (choice == 'l') {  // If user chooses to log in
            string enteredID, enteredPassword;
            cout << "Please enter your user id: ";
            cin >> enteredID;  // Take user ID input for login
            cout << "Please enter your password: ";
            cin >> enteredPassword;  // Take password input for login

            // Check if the entered ID and password match the stored values
            if (enteredID == account.userID && enteredPassword == account.password) {
                loggedIn = true;  // Set loggedIn to true if credentials match
                cout << "Access Granted!" << endl;

                // Loop to display the main menu until the user logs out
                while (loggedIn) {
                    cout << "d -> Deposit Money" << endl;
                    cout << "w -> Withdraw Money" << endl;
                    cout << "r -> Request Balance" << endl;
                    cout << "q -> Quit" << endl;
                    cout << "> ";
                    cin >> choice;  // Get the user's choice in the main menu

                    if (choice == 'd') {  // If user chooses to deposit money
                        double deposit;
                        cout << "Amount of deposit: $";
                        cin >> deposit;  // Take deposit amount input
                        account.balance += deposit;  // Add deposit amount to balance
                    } else if (choice == 'w') {  // If user chooses to withdraw money
                        double withdraw;
                        cout << "Amount of withdrawal: $";
                        cin >> withdraw;  // Take withdrawal amount input

                        // Check if balance is sufficient
                        if (withdraw <= account.balance) {
                            account.balance -= withdraw;  // Subtract withdrawal amount from balance
                        } else {
                            cout << "Insufficient funds!" << endl;  // Display error if balance is insufficient
                        }
                    } else if (choice == 'r') {  // If user chooses to request balance
                        cout << "Your balance is $" << account.balance << "." << endl;
                    } else if (choice == 'q') {  // If user chooses to quit the main menu
                        loggedIn = false;  // Set loggedIn to false to exit the main menu loop
                    }
                }
            } else {  // If login credentials do not match
                cout << "*** LOGIN FAILED! ***" << endl;
            }
        } else if (choice == 'q') {  // If user chooses to quit the program
            break;  // Exit the while loop and end the program
        }
    }

    return 0;  // Program ends successfully
}
