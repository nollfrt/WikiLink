//
// Created by Nolscroll on 4/18/2024.
//

#include "database.h"
#include <sstream>

// Global variable to indicate where database is located
string DATA_PATH = "../database/sdow.sqlite";

database::database() {
    // this code assumes database will always open without issue
    sqlite3_open("../database/sdow.sqlite", &db);
}

void database::queryHelper(string select, string from, string where) {
    // create query string
    const string query = "SELECT " + select + " FROM " + from + " WHERE " + where + ";";
    // prepare sql statement
    sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    // step into result
    sqlite3_step(statement);
}

int database::getID(const string& title) {
    // call helper
    queryHelper("id", "pages", "title=\'" + title + "\' LIMIT 1");
    // return id
    return sqlite3_column_int(statement, 0);
}

bool database::isRedirect(int ID) {
    // call helper
    queryHelper("is_redirect", "pages", "id=" + to_string(ID) + " LIMIT 1");
    // return if ID is redirect
    return sqlite3_column_int(statement, 0);
}

vector<int> database::outgoing(int ID) {
    // call helper
    queryHelper("outgoing_links", "links", "id=" + to_string(ID));
    string links(reinterpret_cast<const char*>(sqlite3_column_text(statement, 0)));

    stringstream linksStream(links);
    vector<int> vec;

    while(getline(linksStream, links, '|')) {
        vec.push_back(stoi(links));
    }


    return vec;
}

vector<int> database::incoming(int ID) {
    // call helper
    queryHelper("incoming_links", "links", "id=" + to_string(ID));
    string links(reinterpret_cast<const char*>(sqlite3_column_text(statement, 0)));

    stringstream linksStream(links);
    vector<int> vec;

    while(getline(linksStream, links, '|')) {
        vec.push_back(stoi(links));
    }


    return vec;
}

int database::redirectTarget(int ID) {
    // call helper
    queryHelper("target_id", "redirects", "source_id=\'" + to_string(ID) + "\' LIMIT=1");
    // return id
    return sqlite3_column_int(statement, 0);
}




