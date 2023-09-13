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
            res2.dispaly_all();  
            break;
        }
        else
        {
            break;
        }
            
    } while (true);
}