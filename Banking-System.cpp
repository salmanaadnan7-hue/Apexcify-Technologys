//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//// ---------- TRANSACTION CLASS ----------
//class Transaction
//{
//public:
//    string type;
//    int amount;
//
//    Transaction(string t, int a)
//    {
//        type = t;
//        amount = a;
//    }
//
//    void show()
//    {
//        cout << type << " : " << amount << endl;
//    }
//};
//
//// ---------- CUSTOMER CLASS ----------
//class Customer
//{
//private:
//    int id;
//    string name;
//
//public:
//    void setData()
//    {
//        cout << "Customer ID: ";
//        cin >> id;
//        cin.ignore();
//        cout << "Customer Name: ";
//        getline(cin, name);
//    }
//
//    string getName()
//    {
//        return name;
//    }
//};
//
//// ---------- ACCOUNT CLASS ----------
//class Account
//{
//private:
//    int accNum;
//    float balance;
//    vector<Transaction> history;
//
//public:
//    Account()
//    {
//        accNum = 0;
//        balance = 0;
//    }
//
//    void create(int num)
//    {
//        accNum = num;
//        cout << "Enter initial balance: ";
//        cin >> balance;
//        cout << "Account " << accNum << " created!" << endl;
//    }
//
//    int getAccNumber()
//    {
//        return accNum;
//    }
//
//    float getBalance()
//    {
//        return balance;
//    }
//
//    void deposit()
//    {
//        int amt;
//        cout << "Deposit amount: ";
//        cin >> amt;
//        if (amt > 0)
//        {
//            balance += amt;
//            history.push_back(Transaction("DEPOSIT", amt));
//            cout << "Deposited! Balance: " << balance << endl;
//        }
//        else
//        {
//            cout << "Invalid amount!" << endl;
//        }
//    }
//
//    void withdraw()
//    {
//        int amt;
//        cout << "Withdraw amount: ";
//        cin >> amt;
//        if (amt > 0 && amt <= balance)
//        {
//            balance -= amt;
//            history.push_back(Transaction("WITHDRAW", amt));
//            cout << "Withdrew! Balance: " << balance << endl;
//        }
//        else
//        {
//            cout << "Can't withdraw!" << endl;
//        }
//    }
//
//    void transfer(Account& toAcc, int amt)
//    {
//        if (amt > 0 && amt <= balance)
//        {
//            balance -= amt;
//            toAcc.balance += amt;
//            history.push_back(Transaction("TRANSFER OUT", amt));
//            toAcc.history.push_back(Transaction("TRANSFER IN", amt));
//            cout << "Transferred " << amt << " to account " << toAcc.accNum << endl;
//        }
//        else
//        {
//            cout << "Transfer failed!" << endl;
//        }
//    }
//
//    void showDetails(string name)
//    {
//        cout << endl << "Account Number: " << accNum << endl;
//        cout << "Name: " << name << endl;
//        cout << "Balance: " << balance << endl;
//    }
//
//    void showHistory()
//    {
//        cout << "Transaction History:" << endl;
//        if (history.empty())
//        {
//            cout << "No transactions yet." << endl;
//        }
//        else
//        {
//            for (auto& t : history)
//            {
//                t.show();
//            }
//        }
//    }
//};
//
//// ---------- BANK CLASS ----------
//class Bank
//{
//private:
//    vector<Account> accounts;
//    Customer customer;
//
//    Account* getAccount(int accNum)
//    {
//        for (auto& a : accounts)
//        {
//            if (a.getAccNumber() == accNum)
//            {
//                return &a;
//            }
//        }
//        return nullptr;
//    }
//
//public:
//    void addCustomer()
//    {
//        customer.setData();
//        cout << "Customer added: " << customer.getName() << endl;
//    }
//
//    bool createAccount(int accNum)
//    {
//        if (getAccount(accNum))
//        {
//            cout << "ERROR: Account " << accNum << " already exists!" << endl;
//            return false;
//        }
//        Account newAcc;
//        newAcc.create(accNum);
//        accounts.push_back(newAcc);
//        return true;
//    }
//
//    void deposit(int accNum)
//    {
//        Account* acc = getAccount(accNum);
//        if (acc) acc->deposit();
//        else cout << "Account not found!" << endl;
//    }
//
//    void withdraw(int accNum)
//    {
//        Account* acc = getAccount(accNum);
//        if (acc) acc->withdraw();
//        else cout << "Account not found!" << endl;
//    }
//
//    void transfer(int fromNum, int toNum, int amt)
//    {
//        Account* fromAcc = getAccount(fromNum);
//        Account* toAcc = getAccount(toNum);
//        if (fromAcc && toAcc)
//            fromAcc->transfer(*toAcc, amt);
//        else
//            cout << "One or both accounts not found!" << endl;
//    }
//
//    void showAccount(int accNum)
//    {
//        Account* acc = getAccount(accNum);
//        if (acc) acc->showDetails(customer.getName());
//        else cout << "Account not found!" << endl;
//    }
//
//    void showHistory(int accNum)
//    {
//        Account* acc = getAccount(accNum);
//        if (acc) acc->showHistory();
//        else cout << "Account not found!" << endl;
//    }
//
//    void showAllAccounts()
//    {
//        cout << endl << "All Accounts:" << endl;
//        if (accounts.empty())
//        {
//            cout << "No accounts yet" << endl;
//        }
//        else
//        {
//            for (auto& a : accounts)
//            {
//                cout << "Account " << a.getAccNumber() << "     |    Balance: " << a.getBalance() << endl;
//            }
//        }
//    }
//};
//
//int main()
//{
//    Bank bank;
//    cout << "====== BANKING SYSTEM ======" << endl;
//
//    bank.addCustomer();
//
//    // Create accounts
//    char more;
//    do
//    {
//        int accNum;
//        cout << "Enter account number to create: ";
//        cin >> accNum;
//        bank.createAccount(accNum);
//
//        cout << "Add another account? (y/n): ";
//        cin >> more;
//    } while (more == 'y' || more == 'Y');
//
//    // Transaction menu
//    char choice;
//    do {
//        cout << endl << "--- MENU ---" << endl;
//        cout << "a. Deposit" << endl;
//        cout << "b. Withdraw" << endl;
//        cout << "c. Transfer" << endl;
//        cout << "d. Show Account Details" << endl;
//        cout << "e. Show Transaction History" << endl;
//        cout << "f. Show All Accounts" << endl;
//        cout << "Choice: ";
//        cin >> choice;
//
//        int n1, n2, amt;
//        if (choice == 'a' || choice == 'A')
//        {
//            cout << "Account number: "; cin >> n1;
//            bank.deposit(n1);
//        }
//        else if (choice == 'b' || choice == 'B')
//        {
//            cout << "Account number: "; cin >> n1;
//            bank.withdraw(n1);
//        }
//        else if (choice == 'c' || choice == 'C')
//        {
//            cout << "From account: ";
//            cin >> n1;
//            cout << "To account: ";
//            cin >> n2;
//            cout << "Amount: ";
//            cin >> amt;
//            bank.transfer(n1, n2, amt);
//        }
//        else if (choice == 'd' || choice == 'D')
//        {
//            cout << "Account number: ";
//            cin >> n1;
//            bank.showAccount(n1);
//        }
//        else if (choice == 'e' || choice == 'E')
//        {
//            cout << "Account number: ";
//            cin >> n1;
//            bank.showHistory(n1);
//        }
//        else if (choice == 'f' || choice == 'F')
//        {
//            bank.showAllAccounts();
//        }
//        else
//        {
//            cout << "Invalid choice!" << endl;
//        }
//
//        cout << "Do another transaction? (y/n): ";
//        cin >> choice;
//    } while (choice == 'y' || choice == 'Y');
//
//    cout << "Thank you for using the banking system!" << endl;
//    return 0;
//}