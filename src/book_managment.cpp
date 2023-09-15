#include "header.h"

void Book_Managment()
{
    int choice;
    do
    {
        system("clear");
        cout << "1. Add a book" << endl;
        cout << "2. Edite a book" << endl;
        cout << "3. Add a copy" << endl;
        cout << "4. Editi a copy" << endl;
        cout << "5. Search a book" << endl;
        cout << "0. Back" << endl;
        if(cin >> choice)
        {
            system("clear");
            if (choice==1)
            {
                
            }
            else if(choice ==2)
            {
               
            }
            else if(choice ==3)
            {
               
            }
            else if(choice ==4)
            {
                    
                break; 
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