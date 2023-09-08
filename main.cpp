#include <mysql/mysql.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;


struct connection_details
{
    string server;
    string user;
    string password;
    string database;
};

map <string, connection_details> create_conn()
{
    map <string, connection_details> temp;

    connection_details online;
    online.server = "sql8.freesqldatabase.com";
    online.user = "sql8644806";		
    online.password = "N34CeGNhyy"; 
    online.database = "sql8644806";

    connection_details home;
    home.server = "localhost";
    home.user = "root";
    home.password = "1234";
    home.database = "library";

    temp["online"]= online;
    temp["home"]= home;

    return temp;
}

MYSQL* mysql_connection_setup(connection_details mysql_details)
{
     // first of all create a mysql instance and initialize the variables within
    MYSQL *connection = mysql_init(NULL);
    
    // connect to the database with the details attached.
    if (!mysql_real_connect(connection,mysql_details.server.c_str(), mysql_details.user.c_str(), mysql_details.password.c_str(), mysql_details.database.c_str(), 3306, NULL, 0))
    {
      cout <<"Conection error :\n" << mysql_error(connection) << endl;
      exit(1);
    }
    return connection;
}

MYSQL_RES* mysql_perform_query(MYSQL *connection, string sql_query)
{
    // send the query to the database
    if (mysql_query(connection, sql_query.c_str()))
    {
        cout << "MySQL query error : \n"<< mysql_error(connection);
        exit(1);
    }
    
    return mysql_use_result(connection);
}

void input(int n, connection_details & conn, string & table, char *argv[])
{
    string temp;
    if(n<2)
    {
        cout << "host: ";
        getline(cin,conn.server);
        cout << "user: ";
        getline(cin,conn.user);
        cout << "password: ";
        getline(cin, conn.password);
        cout << "database: ";
        getline(cin, conn.database);
    }
    if (n<3)
    {
        cout << "enter table name: ";
        getline(cin, temp);
        table+=temp;
    }
    if (n==3)
    {
        map <string, connection_details> list_conne = create_conn();
        conn=list_conne[argv[1]];
        table += argv[2];
    } 
    if(n==2)
    {
        map <string, connection_details> list_conne = create_conn();
        conn=list_conne[argv[1]];
    }
}

int main(int argc, char *argv[])
{
    MYSQL *conn;		// the connection
    MYSQL_RES *res;	// the results
    MYSQL_ROW row;	// the results row (line by line)
    MYSQL_FIELD *field;
    connection_details main_conn;
    string table= "SELECT * FROM " ;

    input(argc, main_conn, table, argv);
    // connect to the mysql database
    conn = mysql_connection_setup(main_conn);

    // assign the results return to the MYSQL_RES pointer
    

    res = mysql_perform_query(conn, table.c_str());

    while ((field = mysql_fetch_field(res)) != NULL) 
    {
        std::cout << field->name << "\t";
    }
    std::cout << std::endl;
  
    while ((row = mysql_fetch_row(res)) !=NULL)
    {
        for (size_t i = 0; i < mysql_num_fields(res); i++)
        {
            cout << row[i] << setw(10);
        }
        cout << endl;
    }
  
  /* clean up the database result set */
    mysql_free_result(res);
    /* clean up the database link */
    mysql_close(conn);
    
    return 0;
}