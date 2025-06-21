#include<iostream>
#include<fstream>
using namespace std;

class Account {
    int accNo;
    string name;
    float balance;

public:
    void createAccount() {
        cout << "Enter Account No: "; cin >> accNo;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Initial Balance: "; cin >> balance;
    }

    void displayAccount() const {
        cout << "Acc No: " << accNo << "\nName: " << name << "\nBalance: " << balance << endl;
    }

    int getAccNo() const { return accNo; }
};

void writeAccount() {
    Account acc;
    ofstream outFile("accounts.dat", ios::binary | ios::app);
    acc.createAccount();
    outFile.write(reinterpret_cast<char *>(&acc), sizeof(Account));
    outFile.close();
}

void displayAllAccounts() {
    Account acc;
    ifstream inFile("accounts.dat", ios::binary);
    while(inFile.read(reinterpret_cast<char *>(&acc), sizeof(Account))) {
        acc.displayAccount();
        cout << "---------------------\n";
    }
    inFile.close();
}

int main() {
    int choice;
    do {
        cout << "\n1. Create Account\n2. View All Accounts\n3. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: writeAccount(); break;
            case 2: displayAllAccounts(); break;
            case 3: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 3);
    return 0;
}
