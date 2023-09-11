#include "header.h"

void recommendation()
{
    result res = perform_query("CALL get_genre()");
    int choice;
    do
    {
        for (size_t i = 0; i < res.num_row; i++)
        {
            cout << i+1 << "."<<res.row[i][0] << endl;
        }
        cout << "0.back" << endl;

        if(cin >> choice)
        {
            system("clear");
            if (choice <= res.num_row && choice >0)
            {
                result res2= perform_query("CALL get_book_genre(\"" + res.row[choice-1][0] + "\")");
                srand(time(0));
                int randomIndex = rand() % res2.num_row;
                for (size_t j = 1; j < res2.num_colum; j++)
                {
                    cout << res2.column[j] << " \t:\t " << res2.row[randomIndex][j] << endl;
                } 
                cout << "0.back" <<endl;
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