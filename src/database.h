//
// Created by Nolscroll on 4/18/2024.
//

#ifndef WIKILINK_DATABASE_H
#define WIKILINK_DATABASE_H

#include "../requirements/sqlite3.h"
#include <string>
#include <vector>

using namespace std;


class database {
private:
    sqlite3* db;
    sqlite3_stmt* statement;
public:
    database();
    void queryHelper(string column, string table, string where);
    int getID(const string& title);
    string getTitle(int ID);
    bool isRedirect(int ID);
    vector<int> outgoing(int ID);
    vector<int> incoming(int ID);
    int redirectTarget(int ID);
    string getTitle(int id);
};


#endif //WIKILINK_DATABASE_H
