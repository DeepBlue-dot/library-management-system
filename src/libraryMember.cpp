#include "header.h"

void library_member()
{
    int choice;
    libraryMember user;
    user.id = get_id("SELECT check_librarymember_id(");
    
    result res= perform_query("CALL GetLibraryMember("+ user.id + ")");

    user.first_name=res.row[0][1];
    user.last_name=res.row[0][2];

    while (true)
    {
        system("clear");
        cout << "Loged in as:" << endl;
        cout << "Fist name : " <<  user.first_name << endl;
        cout << "last name : " <<  user.last_name << endl;
        cout << "ID : " <<  user.id << endl;
        cout << "1. Recommendation" << endl;
        cout << "2. Browse" << endl;
        cout << "3. search" << endl;
        cout << "4. acount" << endl;
        cout << "5. exit" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                system("clear");
                recommendation();
                break;
            case 2:
                system("clear");
                browse(user);
                break;
            case 3:
                system("clear");
                search();
                break;
            case 4:
                system("clear");
                acount(user);
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