#include "Phone.h"
#include "userInput.h"

void Phone::eraseEntireBook(void)
{
    if (object.empty() == true) {
        cout << "Nothing to delete!!" << endl;
    }
    else if (object.empty() == false) {
        cout << "PhoneBook is not empty\n"
             << "Total Contact: " << object.size() << endl;
        object.clear();
        cout << "Now your phone book is empty !!" << endl;
    }
    else {
        cout << "We are not sure what's happening!!!" << endl;
    }
}

void Phone::findAndChange(void)
{
    string nameParam;
    cout << "Please give the name which you want to search: ";
    cin >> nameParam;

    for (auto& it : object) {
        if (it.getName() == nameParam) {
            cout << "Found !" << endl;
            cout << it.getName() << "'s number: " << it.getNumber() << endl;

            cout << "Want to change phone number??"
                 << "(y/n)" << endl;
            char choice;
            cin >> choice;
            cin.ignore(INT_MAX, '\n');
            switch (choice) {
            case 'y': {
                it.setNumber();
                cout << "Number changed successfully !" << endl;
                break;
            }
            case 'n':
                break;
            default:
                printException();
                break;
            }

            break;
        }
    }
    if (it == object.end()) {
        cout << "Not Found" << endl;
    }
}

void Phone::addNewContact(Phone& PhoneDairy)
{
    setName();
    setNumber();
    object.push_back(PhoneDairy);

    ofstream addContactFile("contact.txt", ios::app | ios::in | ios::out);

    if (!addContactFile) {
        cerr << "File could not be opened" << endl;
        return;
    }

    addContactFile << left << setw(40) << getName() << left
                   << getNumber() << endl;

    cout << "New contact is added successfully\n";
}

void Phone::printException(void)
{
    cout << "you didn't press expected key :(" << endl;
}
