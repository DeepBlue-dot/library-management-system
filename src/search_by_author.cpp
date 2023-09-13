#include "header.h"

void search_by_author()
{
    string author;
    int choice;
    do
    {
        cout << "Enter book Author:" << endl;
        cout << "0.back" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(cin, author);
        
        system("clear");
        if (author !="0")
        {
            result res= perform_query("CALL search_books_by_author(\"" + author +  "\")");
            
            while (res.dispaly_all_row())
            {
                if (cin>>choice)
                {
                    system("clear");
                    if (choice <= res.num_row && choice >0)
                    {
                        result res2= perform_query("CALL get_book_by_author(\"" + res.row[choice-1][0] + "\",\"" + res.row[choice-1][1] + "\")");
                        res2.dispaly_all();      
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
            } 
            break;
        }
        else
        {
            break;
        }
            
    } while (true);
}