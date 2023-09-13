#include "header.h"

void search_by_isbn()
{
    int ISBN;
    do
    {
        cout << "Enter ISBN:" << endl;
        cout << "0.back" << endl;

        if(cin >> ISBN)
        {
            system("clear");
            if (ISBN > 0)
            {
                result res2= perform_query("CALL search_books_by_ISBN(\"" + to_string(ISBN) + "\")");
                res2.dispaly_all();                      
                break;
            }
            else if(ISBN==0)
            {
                break;
            }
            else
            {
                system("clear");
                cout << "Invalid Choice" << endl;
            }
            
        }
        else
        {
            system("clear");
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}