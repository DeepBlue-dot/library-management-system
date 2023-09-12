#include "header.h"

void browse(libraryMember libmem)
{
    int choice;
    do
    {
        cout << "Browse by:" <<endl;
        cout << "1. History" << endl;
        cout << "2. Genre" << endl;
        cout << "3. Author" << endl;
        cout << "4. Title" << endl;
        cout << "0. Back" << endl;
        if(cin >> choice)
        {
            system("clear");
            if (choice==1)
            {
                result res= perform_query("CALL get_history(" + libmem.id + ")" );
                for (size_t i = 0; i < res.num_row; i++)
                {
                    for (size_t j = 1; j < res.num_colum; j++)
                    {
                        cout << res.column[j] << " \t:\t " << res.row[i][j] << endl;
                    } 
                }
                

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