#include "header.h"

void search()
{
    int choice;
    do
    {
        system("clear");
        cout << "Search by:" <<endl;
        cout << "1. Book ID" << endl;
        cout << "2. Title" << endl;
        cout << "3. ISBN" << endl;
        cout << "4. Author" << endl;
        cout << "0. back" << endl;
        if(cin >> choice)
        {
            system("clear");

            if (choice==1)
            {
                search_by_id();
            }
            else if(choice ==2)
            {
                search_by_title();
            }
            else if(choice ==3)
            {
                search_by_isbn();
            }
            else if(choice ==4)
            {
                search_by_author();
            }   
            else if(choice ==0)
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