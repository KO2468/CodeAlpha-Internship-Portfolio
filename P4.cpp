#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

class Transaction
{
private:
    string type;
    double amount;
    string details;

public:
    Transaction(string t, double amt, string det = "")
    {
        type = t;
        amount = amt;
        details = det;
    }

    void displayTransaction() const
    {
        cout << left << setw(15) << type
             << " | $" << setw(10) << fixed << setprecision(2) << amount
             << " | " << details << endl;
    }
};

class Account
{
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactionHistory;

public:
    Account(int accNum, double initialBalance)
    {
        accountNumber = accNum;
        balance = initialBalance;
    }

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            transactionHistory.push_back(Transaction("Deposit", amount, "Self Deposit"));
            cout << "[SUCCESS] Deposited $" << amount << " successfully.\n";
        }
        else
        {
            cout << "[ERROR] Invalid deposit amount.\n";
        }
    }

    bool withdraw(double amount, string customDetail = "Cash Withdrawal")
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            transactionHistory.push_back(Transaction("Withdrawal", amount, customDetail));
            cout << "[SUCCESS] Withdrew $" << amount << " successfully.\n";
            return true;
        }
        else
        {
            cout << "[ERROR] Insufficient funds or invalid amount.\n";
            return false;
        }
    }

    void addTransferRecord(double amount, string detail)
    {
        balance += amount;
        transactionHistory.push_back(Transaction("Transfer In", amount, detail));
    }

    void displayAccountDetails() const
    {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "---------------------------------------------\n";
        cout << left << setw(15) << "Type" << " | " << setw(11) << "Amount" << " | Details\n";
        cout << "---------------------------------------------\n";
        if (transactionHistory.empty())
        {
            cout << "No recent transactions found.\n";
        }
        else
        {
            for (const auto &tx : transactionHistory)
            {
                tx.displayTransaction();
            }
        }
        cout << "---------------------------------------------\n";
    }
};

class Customer
{
private:
    string name;
    int customerID;
    vector<Account> accounts;

public:
    Customer(string n, int id)
    {
        name = n;
        customerID = id;
    }

    string getName() const { return name; }
    int getCustomerID() const { return customerID; }
    vector<Account> &getAccounts() { return accounts; }

    void addAccount(int accNum, double initialDeposit)
    {
        accounts.push_back(Account(accNum, initialDeposit));
        cout << "[SUCCESS] Account #" << accNum << " created for " << name << ".\n";
    }

    Account *findAccount(int accNum)
    {
        for (auto &acc : accounts)
        {
            if (acc.getAccountNumber() == accNum)
            {
                return &acc;
            }
        }
        return nullptr;
    }
};

// Global variables to simulate database
vector<Customer> bankCustomers;
int nextAccountNumber = 1001;
int nextCustomerID = 501;

Customer *findCustomer(int custID)
{
    for (auto &customer : bankCustomers)
    {
        if (customer.getCustomerID() == custID)
        {
            return &customer;
        }
    }
    return nullptr;
}

Account *findAccountGlobally(int accNum)
{
    for (auto &customer : bankCustomers)
    {
        Account *acc = customer.findAccount(accNum);
        if (acc != nullptr)
            return acc;
    }
    return nullptr;
}

int main()
{
    int choice;

    // Seed data
    Customer alice("Alice Smith", nextCustomerID++);
    alice.addAccount(nextAccountNumber++, 500.00);
    bankCustomers.push_back(alice);

    do
    {
        cout << "\n=================================" << endl;
        cout << "       APEX BANKING SYSTEM       " << endl;
        cout << "=================================" << endl;
        cout << "1. Register New Customer\n";
        cout << "2. Open New Account for Existing Customer\n";
        cout << "3. Make a Deposit\n";
        cout << "4. Make a Withdrawal\n";
        cout << "5. Transfer Funds\n";
        cout << "6. View Account & Transaction Statements\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        cin.ignore(); // CRITICAL: Clear buffer after choice input

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "\nEnter customer full name: ";
            getline(cin, name); // Now handles spaces (e.g., "John Doe")

            Customer newCust(name, nextCustomerID);
            cout << "[SUCCESS] Customer Profile registered! Assigned ID: " << nextCustomerID << endl;
            nextCustomerID++;
            bankCustomers.push_back(newCust);
            break;
        }
        case 2:
        {
            int id;
            double initialDeposit;
            cout << "\nEnter Customer ID: ";
            cin >> id;
            Customer *cust = findCustomer(id);
            if (cust != nullptr)
            {
                cout << "Enter initial deposit amount: $";
                cin >> initialDeposit;
                cust->addAccount(nextAccountNumber++, initialDeposit);
            }
            else
            {
                cout << "[ERROR] Customer ID not found.\n";
            }
            break;
        }
        case 3:
        {
            int accNum;
            double amt;
            cout << "\nEnter Account Number: ";
            cin >> accNum;
            Account *acc = findAccountGlobally(accNum);
            if (acc != nullptr)
            {
                cout << "Enter Deposit Amount: $";
                cin >> amt;
                acc->deposit(amt);
            }
            else
            {
                cout << "[ERROR] Account not found.\n";
            }
            break;
        }
        case 4:
        {
            int accNum;
            double amt;
            cout << "\nEnter Account Number: ";
            cin >> accNum;
            Account *acc = findAccountGlobally(accNum);
            if (acc != nullptr)
            {
                cout << "Enter Withdrawal Amount: $";
                cin >> amt;
                acc->withdraw(amt);
            }
            else
            {
                cout << "[ERROR] Account not found.\n";
            }
            break;
        }
        case 5:
        {
            int srcAcc, destAcc;
            double amt;
            cout << "\nEnter Your Account Number (Source): ";
            cin >> srcAcc;
            cout << "Enter Recipient Account Number (Destination): ";
            cin >> destAcc;
            cout << "Enter Transfer Amount: $";
            cin >> amt;

            Account *source = findAccountGlobally(srcAcc);
            Account *dest = findAccountGlobally(destAcc);

            if (source != nullptr && dest != nullptr)
            {
                if (source->withdraw(amt, "Transfer to #" + to_string(destAcc)))
                {
                    dest->addTransferRecord(amt, "Received from #" + to_string(srcAcc));
                    cout << "[SUCCESS] Transfer complete.\n";
                }
            }
            else
            {
                cout << "[ERROR] One or both account numbers are invalid.\n";
            }
            break;
        }
        case 6:
        {
            int accNum;
            cout << "\nEnter Account Number to view statement: ";
            cin >> accNum;
            Account *acc = findAccountGlobally(accNum);
            if (acc != nullptr)
            {
                acc->displayAccountDetails();
            }
            else
            {
                cout << "[ERROR] Account not found.\n";
            }
            break;
        }
        case 7:
            cout << "\nExiting Banking System. Have a nice day!" << endl;
            break;
        default:
            cout << "\n[ERROR] Invalid choice. Select 1-7.\n";
        }
    } while (choice != 7);

    return 0;
}