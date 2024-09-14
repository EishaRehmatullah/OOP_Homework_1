#include <iostream>
#include <string>
using namespace std;

struct BankAccount {
    string accountHolder;
    int accountNumber;
    double balance;
    string status;
    
};

void openAccount(BankAccount &accounts , int &nextAccountNumber) {
    accounts.status = "Active";
    cout << "Enter Account holder's name: ";
    cin >> accounts.accountHolder;
    accounts.accountNumber = nextAccountNumber;
    accounts.balance = 0.0;
    cout << "Account created successfully!" << "Account Number: " << accounts.accountNumber << endl;
}

void depositAmount(BankAccount &accounts) {
    double balance;
    if (accounts.status == "Frozen") {
        cout << "Your Account is frozen. Cannot perform any actions" << endl;
        return;
    }
    cout << "Enter the amount to deposit: ";
    cin >> balance;
    if (balance  <= 0) {
        cout << "Invalid amount. Cannot deposit negative amount." << endl;
        return;
    }
    accounts.balance += balance;
    cout << "Amount deposited successfully!" ;
}

void withdrawAmount(BankAccount &accounts) {
    double balance;
    if (accounts.status == "Frozen") {
        cout << "Your Account is frozen. Cannot perform any actions" << endl;
        return;
    }
    cout << "Enter the amount you want to withdraw: ";
    cin >> balance;
    if (balance > accounts.balance) {
        cout << "Insufficient funds." << endl;
        return;
    }
    accounts.balance -= balance;
    cout << "Amount withdrawn successfully!" ;
}

void generateStatement(BankAccount accounts[], int numAccounts, const string &name) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountHolder == name) {
            cout << "Account Holder Name: " << accounts[i].accountHolder << endl;
            cout << "Account Number: " << accounts[i].accountNumber << endl;
            cout << "Balance: $" << accounts[i].balance << endl;
            cout << "Account Status: " << accounts[i].status << endl;
            cout << "------------------------------------" << endl;
        }
    }
    cout << "No account found under your name.";
}

void viewAllAccounts(BankAccount accounts[], int numAccounts) {
    for (int i = 0; i < numAccounts; ++i) {
        cout << "Account Holder Name: " << accounts[i].accountHolder << endl;
        cout << "Account Number: " << accounts[i].accountNumber << endl;
        cout << "Balance: $" << accounts[i].balance << endl;
        cout << "Account Status: " << accounts[i].status << endl;
        cout << "------------------------------------" << endl;
    }
}

void deductTax(BankAccount accounts[], int numAccounts) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].status == "Active") {
            double tax = accounts[i].balance * 0.10;
            accounts[i].balance -= tax;
        }
        cout << "Tax deducted from all accounts successfully.";
    }
}

void addBonus(BankAccount accounts[], int numAccounts) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].status == "Active") {
            double bonus = accounts[i].balance * 0.10;
            accounts[i].balance += bonus;
        }
        cout << "Bonus added to all accounts successfully.";
    }
}

void changeAccountStatus(BankAccount &accounts) {
    string acc_status;
    cout << "Enter New Status (Active/Frozen): ";
    cin >> acc_status;
    accounts.status = acc_status;
    cout << "Account status changed successfully!" ;

    
}



int main() {
    cout << "Welcome to Bank Simulation Program!" << endl;
    static int nextAccountNumber = 10000000;
    BankAccount accounts[1000];
    int numberOfAccounts = 0; // To track number of accounts added
    int role;

    do {
        cout << "Are you a Customer (1) or an Employee (2)? ";
        cin >> role;

        switch (role) {
            // Option selected: Customer
            case 1: {
                int choice;
                cout << "Customer Menu: \n1. Open Account \n2. Deposit Amount \n3. Withdraw Amount \n4. Generate Account Statement \n5. Return to role menu \n6. Exit\nEnter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        openAccount(accounts[numberOfAccounts], nextAccountNumber);
                        numberOfAccounts++;
                        break;
                    case 2: {
                        int acc_num;
                        bool found = false; // Track if account is found
                        cout << "Enter Account Number: ";
                        cin >> acc_num;
                        for (int i = 0; i < numberOfAccounts; i++) {
                            if (accounts[i].accountNumber == acc_num) {
                                depositAmount(accounts[i]);
                                found = true;
                                break;
                            }
                        }
                        if (!found) cout << "Account not found." << endl;
                        break;
                    }
                    case 3: {
                        int account_num;
                        bool found = false;
                        cout << "Enter account number: ";
                        cin >> account_num;
                        for (int i = 0; i < numberOfAccounts; i++) {
                            if (accounts[i].accountNumber == account_num) {
                                withdrawAmount(accounts[i]);
                                found = true;
                                break;
                            }
                        }
                        if (!found) cout << "Account not found." << endl;
                        break;
                    }
                    case 4: {
                        string name;
                        cout << "Enter account holder's name: ";
                        cin >> name;
                        generateStatement(accounts, numberOfAccounts, name);
                        break;
                    }
                    case 5:
                        break;
                    case 6:
                        return 0;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            }

            // Option selected: Employee
            case 2: {
                int choice2;
                cout << "Employee Menu: \n1. View All Accounts \n2. Deduct Tax \n3. Add Bonus \n4. Change Account Status \n5. Return to Role Menu \n6. Exit \nEnter your choice: ";
                cin >> choice2;

                switch (choice2) {
                    case 1:
                        viewAllAccounts(accounts, numberOfAccounts);
                        break;
                    case 2:
                        deductTax(accounts, numberOfAccounts);
                        break;
                    case 3:
                        addBonus(accounts, numberOfAccounts);
                        break;
                    case 4: {
                        int acc_num;
                        bool found = false;
                        cout << "Enter Account Number: ";
                        cin >> acc_num;
                        for (int i = 0; i < numberOfAccounts; i++) {
                            if (accounts[i].accountNumber == acc_num) {
                                changeAccountStatus(accounts[i]);
                                found = true;
                                break;
                            }
                        }
                        if (!found) cout << "Account not found." << endl;
                        break;
                    }
                    case 5:
                        break;
                    case 6:
                        return 0;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            }

            default:
                cout << "Invalid role. Please choose 1 for Customer, 2 for Employee." << endl;
        }
    } while (role != 0); 
}