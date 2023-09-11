#include "header.h"

string get_id(string mysql_function)
{
    int temp_id, temp_password;
    string query;
    while (true)
    {
        cout << "Enter id:" << endl;
        if (!(cin >> temp_id))
        {
            system("clear");
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cout << "Enter pin:" << endl;
            if (!(cin >> temp_password))
            {
                system("clear");
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                query = mysql_function + to_string(temp_id) + "," + to_string(temp_password) +")" ;
                result res = perform_query(query);
                
                if (res.row[0][0]=="2")
                {
                    system("clear");
                    return to_string(temp_id);                
                }
                else if (res.row[0][0]=="0")
                {
                    system("clear");
                    cout << "Invalid ID" << endl;
                } 
                else if (res.row[0][0]=="1")
                {
                    system("clear");
                    cout << "Invalid password" << endl;
                }   
                else
                {
                    system("clear");
                    cout << "something went wrong" << endl;
                }  
            }      
        }
    }
    
}