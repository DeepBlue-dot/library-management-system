#ifndef LMS
#define LMS

#include <mysql/mysql.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <limits>


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
    int num_row;
    int num_colum;
};

result perform_query(string sql_query);
void library_member();
string get_id(string mysql_function);
void recommendation();
void browse(libraryMember libmem);
void search();
void acount();

#endif