#include "header.h"

void browse_auther()
{
    result res = perform_query("CALL get_author()");
    int choice;
    do
    {
        for (size_t i = 0; i < res.num_row; i++)
        {
            cout << i+1 << "."<<res.row[i][0] << " " << res.row[i][1] << endl;
        }
        cout << "0.back" << endl;

        if(cin >> choice)
        {
            system("clear");
            if (choice <= res.num_row && choice >0)
            {
                result res2= perform_query("CALL get_book_by_author(\"" + res.row[choice-1][0] + "\",\"" + res.row[choice-1][1] + "\")");
                for (size_t i = 0; i < res2.num_row; i++)
                {
                    for (size_t j = 1; j < res2.num_colum; j++)
                    {
                        cout << res2.column[j] << " \t:\t " << res2.row[i][j] << endl;
                    } 
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