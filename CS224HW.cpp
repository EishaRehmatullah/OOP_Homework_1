#include <iostream>
#include <string>
using namespace std;

struct BankAccount {
    string accountHolder;
    string accountNumber;
    double balance;
    string status;
    
};

void openAccount(BankAccount &accounts , int &nextAccountNumber) {
    accounts.status = "Active";
    cout << "Enter Account jolder's name: ";
    cin >> accounts.accountHolder;
    accounts.accountNumber = nextAccountNumber;
    accounts.balance = 0.0;
    cout << "Account created successfully!" << "Account Number: " << accounts.accountNumber << endl;
}

void depositAmount(BankAccount &accounts) {
    double balance;
    cout << "Enter the amount to deposit: ";
    cin >> balance;
    if (deposit <= 0) {
        cout << "Invalid amount. Cannot deposit negative amount." << endl;
        return;
    }
    accounts.balance += balance
    cout << "Amount deposited successfully!" ;
}


int main() {
    cout << "Welcome to Bank Simulation Program!" << endl;
    static int nextAccountNumber = 10000000;
    BankAccount accounts[1000000];
    int numberOfAccounts = 0; //to track number of accounts added
    int role;
    do {
        cout << "Are you a Customer (1) or an Employee (2)?" ;
        switch (role) {
            //Option selected: Customer
            case 1:
            int choice;
            cout << "Customer Menu: \n1. Open Account \n2. Deposit Amount \n3. Withdraw Amount \n4. Generate Account Statement \n5. Exit\nEnter your choice: ";
            cin >> choice;

            switch(choice) {
                //Call openAccount function
                case 1:
                    openAccount(accounts[numberOfAccounts] , nextAccountNumber);
                    numberOfAccounts++ ;
                    break;
                //Call depositAmount function
                case 2:
                    int accountNumber;
                    cout << "Enter Account Number: ";
                    cin >> accountNumber;
                    for (int i=0; i < numberOfAccounts; i++ ) {
                        if (accounts[i].accountNumber == accountNumber) {
                            depositAmount(accounts[i]);
                        }
                    }
                    cout << "Account not found." ;
                    break;
                //Call withdrawAmount function
                case 3:
                    int acc_num;
                    cout << "Enter account number: ";
                    cin >> acc_num;
                    for (int i=0; i < numberOfAccounts; i++ ) {
                        if (accounts[i].accountNumber == accountNumber) {
                            withdrawAmount(accounts[i]);
                        }
                    }
                    cout << "Account not found." ;
                    break;

        }
    }
    // return 0;


}  while( role != 0);