#include "header.h"

void recommendation()
{
    result res = perform_query("CALL get_genre()");
    int choice;
    do
    {
        res.dispaly_all_row();

        if(cin >> choice)
        {
            system("clear");
            if (choice <= res.num_row && choice >0)
            {
                result res2= perform_query("CALL get_book_genre(\"" + res.row[choice-1][0] + "\")");
                srand(time(0));
                int randomIndex = rand() % res2.num_row;
                res2.dispaly_one(randomIndex); 
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