//
// Created by Nolscroll on 4/18/2024.
//

#include "database.h"

// Global variable to indicate where database is located
string DATA_PATH = "../database/sdow.sqlite";

database::database() {
    // this code assumes database will always open without issue
    sqlite3_open("../database/sdow.sqlite", &db);
}

void database::queryHelper(string column, string table, string where) {
    // create query string
    const string query = "SELECT " + column + " FROM " + table + " WHERE " + where + ";";
    // prepare sql statement
    sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    // step into result
    sqlite3_step(statement);
}

int database::getID(const string& title) {
    // call helper
    queryHelper("id", "pages", "title=\'" + title + "\'");
    // return id
    return sqlite3_column_int(statement, 0);
}

bool database::isRedirect(int ID) {
    // call helper
    queryHelper("is_redirect", "pages", "id=" + to_string(ID));
    // return if ID is redirect
    return sqlite3_column_int(statement, 0);
}




