#include "header.h"

void connection_setup (connection_details detail)
{
    connection = mysql_init(NULL);

    if(!mysql_real_connect(connection, detail.server.c_str(), detail.user.c_str(), detail.password.c_str(), detail.database.c_str(), 3306, NULL, 0))
    {
        cout << "Connection failed!" << endl;
        cout << mysql_error(connection);
        exit(1);
    }
}