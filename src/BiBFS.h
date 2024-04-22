//
// Created by salen on 4/16/2024.
//

#ifndef WIKILINK_BIBFS_H
#define WIKILINK_BIBFS_H
#include <iostream>
#include "database.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Traversal_Functions {
private:
    int numVisited; //total number of titles that are visited
    unordered_set<int> visited_BFS;
    unordered_set<int> visited_DFS;
    database helper_BFS;
    database helper_DFS;

public:
    //vector<string> getPageTitle(vector<int> path_BFS);
    vector<int> bfs(string start, string end);
    vector<int> dfs(string start, string end);
};

#endif //WIKILINK_BIBFS_H
