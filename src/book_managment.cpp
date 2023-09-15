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
        cout << "6. Search a copy" << endl;
        cout << "0. Back" << endl;
        if(cin >> choice)
        {
            system("clear");
            if (choice==1)
            {
                Add_a_book();
            }
            else if(choice ==2)
            {
               Edite_a_book();
            }
            else if(choice ==3)
            {
               Add_a_copy();
            }
            else if(choice ==4)
            {
                Editi_a_copy();
                break; 
            }   
            else if(choice == 5)
            {
                Search_a_book();
                break; 
            }  
            else if(choice == 6)
            {
                Search_a_copy(); 
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