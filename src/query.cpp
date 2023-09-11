#include "header.h"

connection_details detail;

result perform_query(string sql_query)
{
    MYSQL *connection = nullptr;
    MYSQL_RES *res= nullptr;
    MYSQL_FIELD *fields = nullptr;
    MYSQL_ROW row;
    result temp_result;

    connection = mysql_init(NULL);

    if(!mysql_real_connect(connection, detail.server.c_str(), detail.user.c_str(), detail.password.c_str(), detail.database.c_str(), 3306, NULL, 0))
    {
        cout << "Connection failed!" << endl;
        cout << mysql_error(connection);
        exit(1);
    }

    if (mysql_query(connection, sql_query.c_str()))
    {
        cout << "MySQL query error:\n" << mysql_error(connection);
        exit(1);
    }

    res= mysql_store_result(connection);
    if (res != nullptr) 
    {
        temp_result.num_colum = mysql_num_fields(res);
        temp_result.num_row = mysql_num_rows(res);
        fields= mysql_fetch_fields(res);

        for (size_t i = 0; i < temp_result.num_colum; i++)
        {
            temp_result.column.push_back(fields[i].name);
            temp_result.columntype.push_back(fields[i].type);
        }
        
        while ((row = mysql_fetch_row(res)) != NULL) 
        {
            vector<string> row_data;
            for (int i = 0; i <temp_result.num_colum; i++) 
            {
                if (row[i] != NULL)
                    row_data.push_back(row[i]);
                else
                    row_data.push_back("NULL");
            }
            temp_result.row.push_back(row_data);
        }

        mysql_free_result(res);
        mysql_close(connection);
        return temp_result;
    }
    mysql_close(connection);
    mysql_free_result(res);
    return temp_result;

}