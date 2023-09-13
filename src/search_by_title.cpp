#include "header.h"

void search_by_title()
{
    string title;
    do
    {
        cout << "Enter book Title:" << endl;
        cout << "0.back" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(cin, title);
        
            system("clear");
            if (choice > 0)
            {
                result res2= perform_query("CALL get_book_by_id(" + to_string(choice) + ")");
                if(res2.num_row > 0)
                {
                    for (size_t i = 0; i < res2.num_row; i++)
                    {
                        for (size_t j = 1; j < res2.num_colum; j++)
                        {
                            cout << res2.column[j] << " \t:\t " << res2.row[i][j] << endl;
                        } 
                    }
                }
                else
                {
                    cout << "No book found by id " << choice <<endl;
                }
                if (!(cin>>choice))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }       
                break;
            }
            else if(choice==0)
            {
                break;
            }
            else
            {
                system("clear");
                cout << "Invalid Choice" << endl;
            }
            
    } while (true);
}