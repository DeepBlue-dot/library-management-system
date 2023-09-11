#include "header.h"

result perform_query(string sql_query)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    MYSQL_FIELD *fields;
    result temp_result;
    int num_fields;
    
    if (mysql_query(connection, sql_query.c_str()))
    {
        cout << "MySQL query error:\n" << mysql_error(connection);
        mysql_free_result(res);
        exit(1);
    }

    res= mysql_store_result(connection);
    if (res != nullptr) 
    {
        num_fields = mysql_num_fields(res);
        fields= mysql_fetch_fields(res);

        for (size_t i = 0; i < num_fields; i++)
        {
            temp_result.column.push_back(fields[i].name);
            temp_result.columntype.push_back(fields[i].type);
        }
        

        while ((row = mysql_fetch_row(res)) != NULL) 
        {
            vector<string> row_data;
            for (int i = 0; i < num_fields; i++) 
            {
                if (row[i] != NULL)
                    row_data.push_back(row[i]);
                else
                    row_data.push_back("NULL");
            }
            temp_result.row.push_back(row_data);

            cout << endl;
        }

        mysql_free_result(res);
        return temp_result;
    }
    return temp_result;

}