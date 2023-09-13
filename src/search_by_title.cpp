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
        if (title !="0")
        {
            result res2= perform_query("CALL search_books_by_title(\"" + title +  "\")");
            if(res2.num_row > 0)
            {
                for (size_t i = 0; i < res2.num_row; i++)
                {
                    for (size_t j = 1; j < res2.num_colum; j++)
                    {
                        cout << res2.column[j] << " \t:\t " << res2.row[i][j] << endl;
                    } 
                    cout << endl;
                }
            }
            else
            {
                cout << "No book found by title " << title <<endl;
            }
            cin>>title;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');      
            break;
        }
        else
        {
            break;
        }
            
    } while (true);
}