//
// Created by salen on 4/16/2024.
//

#ifndef WIKILINK_BIBFS_H
#define WIKILINK_BIBFS_H
#include <iostream>
#include <queue>
#include <set>
using namespace std;

class BiBFS {
private:
    int numVisited; //total number of titles that are visited
    vector<vector<string>> paths; //all possible paths from the start to the ending title
    queue<string> q;
    set<string> visited;

public:
    void bi_bfs(string start, string end);
    bool is_Redirect(string title);
    string get_Redirect(string title);
};


#endif //WIKILINK_BIBFS_H