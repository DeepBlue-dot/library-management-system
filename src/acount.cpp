#include "header.h"

void acount(libraryMember user)
{
    result res= perform_query("CALL GetLibraryMember("+ user.id + ")");
    res.dispaly_all();
    
}