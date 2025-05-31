#include <iostream>
#include <string>
using namespace std;


class BankAccount {
public:
    string accountHolder;
    int accountNumber;
    double balance;
    double fdrBalance;
    double dpsBalance;
    double interestRate;


    BankAccount() {
        accountHolder = "";
        accountNumber = 0;
        balance = 0.0;
        fdrBalance = 0.0;
        dpsBalance = 0.0;
        interestRate = 5.0;
    }


    void createAccount(string name, int accNum, double initialDeposit) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialDeposit;
        cout << "Account created for " << accountHolder << " with account number " << accountNumber << endl;
    }


    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Error deposit amount!" << endl;
        }
    }


    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << ". New balance : $" << balance<< endl;
        } else {
            cout << "Error or not enough funds." << endl;
        }
    }


    void startFDR(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            fdrBalance += amount;
            cout << "Fdr started with $" << amount << ". Fdr balance: $" << fdrBalance << endl;
        } else {
            cout << "Error or not enough funds for fdr." << endl;
        }
    }


    void calculateFDRInterest() {
        double interest = fdrBalance * (interestRate / 100);
        fdrBalance += interest;
        cout << "Fdr interest added. New fdr balance: $" << fdrBalance << endl;
    }


    void startDPS(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            dpsBalance += amount;
            cout << "Dps started with $" << amount << ". Dps balance: $" << dpsBalance << endl;
        } else {
            cout << "Error or not enough funds for DPS. " << endl;
        }
    }


    void calculateDPSInterest() {
        double interest = dpsBalance * (interestRate / 100);
        dpsBalance += interest;
        cout << "Dps interest added. New DPS balance: $" << dpsBalance << endl;
    }


    void display() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
        cout << "FDR Balance: $" << fdrBalance << endl;
        cout << "DPS Balance: $" << dpsBalance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {

    BankAccount accounts[10];


    accounts[0].createAccount("Rahim", 1001, 1000.0);
    accounts[1].createAccount("Karim", 1002, 1500.0);
    accounts[2].createAccount("Salam", 1003, 2000.0);
    accounts[3].createAccount("Sojib", 1004, 1200.0);
    accounts[4].createAccount("Sakib", 1005, 1800.0);
    accounts[5].createAccount("Rakib", 1006, 900.0);
    accounts[6].createAccount("Mahim", 1007, 2500.0);
    accounts[7].createAccount("Shakil", 1008, 3000.0);
    accounts[8].createAccount("Hasib", 1009, 1100.0);
    accounts[9].createAccount("Nafis", 1010, 1700.0);


    cout << "\nPerforming some transactions...\n";


    accounts[0].deposit(500.0);
    accounts[1].deposit(200.0);


    accounts[2].withdraw(300.0);
    accounts[3].withdraw(150.0);


    accounts[4].startFDR(1000.0);
    accounts[4].calculateFDRInterest();


    accounts[5].startDPS(500.0);
    accounts[5].calculateDPSInterest();

    cout << "\nAll Account details:\n";
    for (int i = 0; i < 10; i++) {
        cout << "\n Account " << (i + 1) << ":\n";
        accounts[i].display();
    }

    return 0;
}
