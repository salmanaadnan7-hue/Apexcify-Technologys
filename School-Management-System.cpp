//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//class UserManager
//{
//private:
//    string name, password;
//public:
//    void registerUser()
//    {
//        cout << "Register" << endl;
//        cout << "Enter Username: ";
//        getline(cin, name);
//        ifstream checkFile(name + ".txt");
//        if (checkFile)
//        {
//            cout << "Error: Username already exists!" << endl;
//            return;
//        }
//        cout << "Enter Password: ";
//        getline(cin, password);
//        ofstream outFile(name + ".txt");
//        outFile << password;
//        outFile.close();
//        cout << "Registration Successful!" << endl;
//    }
//    bool loginUser()
//    {
//        string inputUser, inputPass, storedPass;
//        cout << "Login" << endl;
//        cout << "Enter Username: ";
//        getline(cin, inputUser);
//        cout << "Enter Password: ";
//        getline(cin, inputPass);
//        ifstream inFile(inputUser + ".txt");
//        if (inFile >> storedPass)
//        {
//            if (inputPass == storedPass)
//            {
//                cout << "Login Successful! Welcome, " << inputUser << "." << endl;
//                return true;
//            }
//            else
//            {
//                cout << "Error: Incorrect password." << endl;
//            }
//        }
//        else
//        {
//            cout << "Error: User not found." << endl;
//        }
//        return false;
//    }
//};
//int main()
//{
//    UserManager system;
//    int choice;
//    while (true)
//    {
//        cout << "\n 1)Register\n 2)Login\n 3)Exit\nSelect Option: ";
//        if (!(cin >> choice))
//        {
//            cin.clear();
//            cin.ignore(1000, '\n');
//            cout << "Invalid input! Please enter a number.\n";
//            continue;
//        }
//        cin.ignore();
//        switch (choice)
//        {
//        case 1:
//            system.registerUser();
//            break;
//        case 2:
//            system.loginUser();
//            break;
//        case 3:
//            cout << "Exiting program." << endl;
//            return 0;
//        default:
//            cout << "Invalid choice!" << endl;
//            break;
//        }
//    }
//    return 0;
//}
//
