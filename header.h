#ifndef LMS
#define LMS

#include <mysql/mysql.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <limits>
#include <map>

using namespace std;

struct connection_details
{
    string server= "localhost";
    string user = "root";
    string password = "1234";
    string database = "library";
};

extern connection_details detail;

extern MYSQL *connection;
extern MYSQL_RES *res;	
extern MYSQL_ROW row;	
extern MYSQL_FIELD *field;

MYSQL_RES* perform_query(MYSQL* connection, string sql_query);
void connection_setup ();

#endif