#ifndef LMS
#define LMS

#include <mysql/mysql.h>
#include <iostream>
#include <string>
#include <vector>
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

struct libraryMember
{
    string id;
    string first_name;
    string last_name;
};
struct result
{
    vector<vector<string>>row;
    vector<string> column;
    vector<int> columntype;
};

extern MYSQL *connection;



result perform_query(string sql_query);
void connection_setup ();
void library_member();
string get_id(string mysql_function);

#endif