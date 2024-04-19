//
// Created by salen on 4/16/2024.
//

#ifndef WIKILINK_BIBFS_H
#define WIKILINK_BIBFS_H
#include <iostream>
#include <queue>
#include <set>
using namespace std;

class BFS_Functions {
private:
    int numVisited; //total number of titles that are visited
    vector<vector<string>> paths; //all possible paths from the start to the ending title
    queue<int> q_BFS;
    set<int> visited_BFS;
    queue<int> q_BiBFS_start;
    queue<int> q_BiBFS_end;
    set<int> visited_BiBFS_start;
    set<int> visited_BiBFS_end;

public:
    void bfs(string start, string end);
    void bi_bfs(string start, string end);
    string get_Redirect(string title);
};


#endif //WIKILINK_BIBFS_H
