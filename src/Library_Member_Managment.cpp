#include "header.h"

void Library_Member_Managment()
{
    int choice;
    do
    {
        system("clear");
        cout << "1. Add Library Member" << endl;
        cout << "2. Editi Library Member" << endl;
        cout << "3. Remove Library Member" << endl;
        cout << "4. Search Library Member" << endl;
        cout << "0. Back" << endl;
        if(cin >> choice)
        {
            system("clear");
            if (choice==1)
            {
                Add_Library_Member();
            }
            else if(choice ==2)
            {
                Editi_Library_Member();
            }
            else if(choice ==3)
            {
                Remove_Library_Member();
            }
            else if(choice ==4)
            {
                Search_Library_Member();
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