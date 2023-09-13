#include "header.h"

void browse_gener()
{
    result res = perform_query("CALL get_genre()");
    int choice;
    do
    {
        res.dispaly_all_row();

        if (cin>>choice)
        {
            system("clear");
            if (choice <= res.num_row && choice >0)
            {
                res.dispaly_all();      
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