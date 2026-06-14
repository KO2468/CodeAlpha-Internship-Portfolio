#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string DATABASE_FILE = "users.txt";

// Securely hash the password so it's not stored in plain text
string hashPassword(const string &password)
{
    hash<string> hasher;
    return to_string(hasher(password));
}

// Scans the file to see if the username is taken
bool isUsernameDuplicate(const string &username)
{
    ifstream file(DATABASE_FILE);
    if (!file.is_open())
        return false;

    string fileUser, filePass;
    while (file >> fileUser >> filePass)
    {
        if (fileUser == username)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// 1. REGISTRATION
void registerUser()
{
    string username, password;
    cout << "\n--- Create New Account ---" << endl;
    cout << "Enter username (no spaces): ";
    cin >> username;

    if (isUsernameDuplicate(username))
    {
        cout << "\n[ERROR] Username is already taken! Try another." << endl;
        return;
    }

    cout << "Enter password (no spaces): ";
    cin >> password;

    if (password.length() < 4)
    {
        cout << "\n[ERROR] Password must be at least 4 characters long!" << endl;
        return;
    }

    // Save to file
    ofstream file(DATABASE_FILE, ios::app);
    if (file.is_open())
    {
        file << username << " " << hashPassword(password) << "\n";
        file.close();
        cout << "\n[SUCCESS] Registration successful!" << endl;
    }
    else
    {
        cout << "\n[ERROR] System error: Could not update database file." << endl;
    }
}

// 2. LOGGED-IN MENU (The User Dashboard)
void showUserDashboard(const string &username)
{
    int choice;
    do
    {
        cout << "\n=================================" << endl;
        cout << "   WELCOME BACK, " << username << "!" << endl;
        cout << "=================================" << endl;
        cout << "1. View Profile Details\n";
        cout << "2. Account Status\n";
        cout << "3. Secure Logout\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n--- Profile Details ---" << endl;
            cout << "Username: " << username << endl;
            cout << "Storage ID: " << hashPassword(username) << endl;
            break;
        case 2:
            cout << "\n--- Account Status ---" << endl;
            cout << "Account Type: Standard User\n";
            cout << "Security Status: Verified & Hashed\n";
            break;
        case 3:
            cout << "\nLogging out... Safely destroying session." << endl;
            break;
        default:
            cout << "\n[ERROR] Invalid option." << endl;
        }
    } while (choice != 3);
}

// 3. LOGIN INTERFACE
void loginUser()
{
    string username, password;
    cout << "\n--- Account Login ---" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(DATABASE_FILE);
    if (!file.is_open())
    {
        cout << "\n[ERROR] No registered accounts found in the system." << endl;
        return;
    }

    string fileUser, filePass;
    string hashedInputPassword = hashPassword(password);
    bool loginSuccess = false;

    while (file >> fileUser >> filePass)
    {
        if (fileUser == username && filePass == hashedInputPassword)
        {
            loginSuccess = true;
            break;
        }
    }
    file.close();

    if (loginSuccess)
    {
        cout << "\n[SUCCESS] Credentials verified." << endl;
        showUserDashboard(username); // Passes execution to the logged-in dashboard menu
    }
    else
    {
        cout << "\n[ERROR] Incorrect username or password." << endl;
    }
}

// 4. GENERAL SYSTEM ENTRY
int main()
{
    int choice;
    do
    {
        cout << "\n=================================" << endl;
        cout << "        SECURE ACCESS SYSTEM     " << endl;
        cout << "=================================" << endl;
        cout << "1. Register New User\n";
        cout << "2. Login to Existing Account\n";
        cout << "3. Close System\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "\nShutting down portal. Goodbye!" << endl;
            break;
        default:
            cout << "\n[ERROR] Please select 1, 2, or 3." << endl;
        }
    } while (choice != 3);

    return 0;
}
