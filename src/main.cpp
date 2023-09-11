#include "header.h"

MYSQL_RES *res;
MYSQL_ROW row;
MYSQL_FIELD *field;
MYSQL* connection;

connection_details detail;


int main(int argc, char *argv[])
{
    
    connection_setup(detail);
    int choice;
    do
    {
        cout << "1.Library Member" << endl;
        cout << "2.Librarian" << endl;
        cout << "3.Exite" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                system("clear");
                library_member();
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    } while (choice);
    
    
    return 0;
}