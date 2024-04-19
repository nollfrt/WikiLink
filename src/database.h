//
// Created by Nolscroll on 4/18/2024.
//

#ifndef WIKILINK_DATABASE_H
#define WIKILINK_DATABASE_H

#include "../requirements/sqlite3.h"
#include <string>

using namespace std;


class database {
private:
    sqlite3* db;
public:
    int getID(string title);
    bool isRedirect(int ID);
};


#endif //WIKILINK_DATABASE_H
