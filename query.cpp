#include "header.h"

MYSQL_RES* perform_query(MYSQL* connection, string sql_query)
{
    if(mysql_query(connection, sql_query.c_str()))
    {
        cout << "MYSQL QUERY ERROR!" << endl;
        cout << mysql_error(connection);
        exit(1);
    }
    return mysql_use_result(connection);
}