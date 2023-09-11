#include "header.h"


int main(int argc, char *argv[])
{
    int choice;
    do
    {
        cout << "1.Library Member" << endl;
        cout << "2.Librarian" << endl;
        cout << "3.Exit" << endl;
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
                exit(0);
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