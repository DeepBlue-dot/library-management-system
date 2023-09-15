#include "header.h"

void Librarian()
{
    int choice;
    librarian user;
    user.id = get_id("SELECT check_librarian(");

    result res = perform_query("CALL get_librarian(" + user.id + ")");

    user.first_name = res.row[0][1];
    user.last_name = res.row[0][2];

    while (true)
    {
        system("clear");
        cout << "Loged in as:" << endl;
        cout << "Fist name : " << user.first_name << endl;
        cout << "last name : " << user.last_name << endl;
        cout << "ID : " << user.id << endl;
        cout << "1. Book Managment" << endl;
        cout << "2. Library Member Managment" << endl;
        cout << "3. Transaction" << endl;
        cout << "4. Acount" << endl;
        cout << "5. exit" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                system("clear");
                break;
            case 2:
                system("clear");
                break;
            case 3:
                system("clear");
                break;
            case 4:
                res.dispaly_all();
                system("clear");
                break;
            case 5:
                exit(0);
                break;

            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
}
