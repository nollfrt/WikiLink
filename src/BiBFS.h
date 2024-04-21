//
// Created by salen on 4/16/2024.
//

#ifndef WIKILINK_BIBFS_H
#define WIKILINK_BIBFS_H
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class BFS_Functions {
private:
    int numVisited; //total number of titles that are visited
    queue<vector<int>> q_BFS;
    unordered_set<int> visited_BFS;
    queue<int> q_BiBFS_start;
    queue<int> q_BiBFS_end;
    unordered_set<int> visited_BiBFS_start;
    unordered_set<int> visited_BiBFS_end;

public:
    vector<vector<int>> bfs(string start, string end);
    vector<vector<int>> bi_bfs(string start, string end);
};


#endif //WIKILINK_BIBFS_H
