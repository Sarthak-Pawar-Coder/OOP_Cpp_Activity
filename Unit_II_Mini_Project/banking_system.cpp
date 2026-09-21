// Banking System with Account Hierarchy
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Account {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int number, string name, double bal)
        : accountNumber(number), holderName(name), balance(bal) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Rs. " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > balance) {
            cout << "Insufficient balance." << endl;
        }
        else {
            balance -= amount;
            cout << "Withdrawn Rs. " << amount << endl;
        }
    }

    virtual double calculateInterest() const = 0;

    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    virtual ~Account() = default;
};


class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int number, string name, double bal, double rate)
        : Account(number, name, bal), interestRate(rate) {}

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void display() const override {
        cout << "\n--- Savings Account ---" << endl;
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


class CurrentAccount : public Account {
private:
    double interestRate;

public:
    CurrentAccount(int number, string name, double bal, double rate)
        : Account(number, name, bal), interestRate(rate) {}

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void display() const override {
        cout << "\n--- Current Account ---" << endl;
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


class FixedDepositAccount : public Account {
private:
    double interestRate;
    int duration;

public:
    FixedDepositAccount(int number, string name, double bal,
                        double rate, int years)
        : Account(number, name, bal),
          interestRate(rate),
          duration(years) {}

    double calculateInterest() const override {
        return balance * interestRate * duration / 100;
    }

    void display() const override {
        cout << "\n--- Fixed Deposit Account ---" << endl;
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Duration: " << duration << " years" << endl;
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


int main() {

    vector<unique_ptr<Account>> accounts;

    accounts.push_back(
        make_unique<SavingsAccount>(
            1001, "Rahul", 50000, 4.0));

    accounts.push_back(
        make_unique<CurrentAccount>(
            1002, "Priya", 80000, 2.0));

    accounts.push_back(
        make_unique<FixedDepositAccount>(
            1003, "Amit", 100000, 7.0, 2));

    cout << "================================" << endl;
    cout << "     BANKING SYSTEM" << endl;
    cout << "================================" << endl;

    for (auto& account : accounts) {
        account->display();

        account->deposit(5000);
        account->withdraw(2000);

        cout << "Updated Balance: Rs. "
             << " " << endl;
    }

    return 0;
}