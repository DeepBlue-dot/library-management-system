#include "header.h"

void search()
{
    int choice;
    do
    {
        cout << "Search by:" <<endl;
        cout << "1. Book ID" << endl;
        cout << "2. Title" << endl;
        cout << "3. ISBN" << endl;
        cout << "4. Author" << endl;
        cout << "0. Genre" << endl;
        if(cin >> choice)
        {
            system("clear");

            if (choice==1)
            {
                /* code */
            }
            else if(choice ==2)
            {
                /* code */
            }
            else if(choice ==3)
            {
                /* code */
            }
            else if(choice ==4)
            {
                /* code */
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