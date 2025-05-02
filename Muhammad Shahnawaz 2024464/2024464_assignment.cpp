#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    fstream file;
    string line;
    char choice;

    // Reading from example.txt
    file.open("example.txt", ios::in);
    if (file.is_open()) {
        cout << "File has successfully opened in reading mode.\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Error: failed to open example.txt in reading mode.\n";
    }
    file.close();

    // Writing to output.txt
    file.open("output.txt", ios::out);
    if (file.is_open()) {
        cout << "File has successfully opened in writing mode.\n";
        do {
            do {
                cout << "Enter Y/y to add string to your file, otherwise N/n: ";
                cin >> choice;
                clearInputBuffer();
                if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                    cout << "Invalid choice. Please re-enter.\n";
                }
            } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

            if (choice == 'Y' || choice == 'y') {
                cout << "Enter the string: ";
                getline(cin, line);
                file << line << "\n";
            }
        } while (choice == 'Y' || choice == 'y');
    } else {
        cout << "Failed to open output.txt in writing mode.\n";
    }
    file.close();

    // Appending to log.txt
    file.open("log.txt", ios::out | ios::app);
    if (file.is_open()) {
        cout << "File has successfully opened in append mode.\n";
        do {
            do {
                cout << "Enter Y/y to add string to your file, otherwise N/n: ";
                cin >> choice;
                clearInputBuffer();
                if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                    cout << "Invalid choice. Please re-enter.\n";
                }
            } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

            if (choice == 'Y' || choice == 'y') {
                cout << "Enter the string: ";
                getline(cin, line);
                file << line << "\n";
            }
        } while (choice == 'Y' || choice == 'y');
    } else {
        cout << "Failed to open log.txt in append mode.\n";
    }
    file.close();

    // Reading from truncate.txt before truncating
    file.open("truncate.txt", ios::in);
    if (file.is_open()) {
        cout << "truncate.txt successfully opened in reading mode (before truncation):\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Failed to open truncate.txt in reading mode (before truncation).\n";
    }
    file.close();

    // Truncating truncate.txt
    file.open("truncate.txt", ios::out | ios::trunc);
    file.close();

    // Reading truncate.txt after truncation
    file.open("truncate.txt", ios::in);
    if (file.is_open()) {
        cout << "truncate.txt opened in reading mode after truncation (should be empty):\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Failed to open truncate.txt after truncation.\n";
    }
    file.close();

    // Using seekg on data.txt
    file.open("data.txt", ios::in);
    if (file.is_open()) {
        cout << "data.txt successfully opened for reading using seekg.\n";
        file.seekg(10); // Move 10 bytes forward
        while (getline(file, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Failed to open data.txt for reading.\n";
    }
    file.close();

    // Using seekp on write_test.txt
    file.open("write_test.txt", ios::out);
    if (file.is_open()) {
        cout << "write_test.txt opened in writing mode using seekp.\n";
        file.seekp(5); 
        file << "Hello World!" << endl;
    }
    file.close();

    // Using ate mode
    file.open("append_end.txt", ios::out | ios::ate);
    if (file.is_open()) {
        file << "This line must be added at the end of the file (opened in ate mode).\n";
    } else {
        cout << "Failed to open append_end.txt in ate mode.\n";
    }
    file.close();

    return 0;
}
