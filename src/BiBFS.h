//
// Created by salen on 4/16/2024.
//

#ifndef WIKILINK_BIBFS_H
#define WIKILINK_BIBFS_H
#include <iostream>
#include "database.h"
#include <unordered_set>
using namespace std;

class BFS_Functions {
private:
    int numVisited; //total number of titles that are visited
    unordered_set<int> visited_BFS;
    database helper_BFS;
//    queue<int> q_BiBFS_start;
//    queue<int> q_BiBFS_end;
    unordered_set<int> visited_BiBFS_start;
    unordered_set<int> visited_BiBFS_end;

public:
    vector<vector<int>> bfs(string start, string end);
    vector<vector<int>> bi_bfs(string start, string end);
};


#endif //WIKILINK_BIBFS_H
