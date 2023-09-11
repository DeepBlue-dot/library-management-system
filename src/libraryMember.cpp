#include "header.h"

void library_member()
{
    int choice;
    libraryMember user;
    user.id = get_id("SELECT check_librarymember_id(");
    
    result res= perform_query("CALL GetLibraryMember("+ user.id + ")");

    user.first_name=res.row[0][0];
    user.last_name=res.row[0][1];

    while (true)
    {
        cout << "Loged in as:" << endl;
        cout << setw(4) << "Fist name : " <<  user.first_name << endl;
        cout << setw(4) <<"last name : " <<  user.last_name << endl;
        cout << setw(4) << "ID : " <<  user.id << endl;
        cout << "1. Recommendation" << endl;
        cout << "2. Browse" << endl;
        cout << "3. search" << endl;
        cout << "4. acount" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
            
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
    

}