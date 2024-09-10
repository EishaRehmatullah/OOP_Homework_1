#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
 
struct BankAccount() {
    string name;
    int account_number;
    double balance;
    int status;
};
void open_account() {}
// void deposit_amount() {}
// void withdraw_amount() {}
// void generate_statemnt() {}
// void view_all_accounts() {}
// void deduct_tax() {}

int main() {
    cout << "Welcome to Bank Stimulation Program!" << endl << "Are you a Customer (1) or an Employee (2)"
    << endl << "Enter your role  (1) for Customer, (2) for Employee: ";
    int role;
    cin >> role;
    switch (role)
    {
    case 1:
        cout << "Customer Menu: \n1. Open Account \n2. Deposit Amount \n3. Withdraw Amount \n4. Generate Account Statement \n5. Return to Role Menu \n6. Exit \nEnter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) 
        {
            case 1:
            cout << "Enter account holder's name: ";
            string name;
            cin >> name;

        }
        break;
    case 2:
        cout << "Employee Menu: \n1. View All Accounts \n2. Deduct tax \n3. Add Bonus \n4. Change Account Status \n5. Return to Role Menu \n6. Exit \nEnter your choice: ";
        int choice2;
        cin >> choice2;
    
    default:
        break;
    }
}