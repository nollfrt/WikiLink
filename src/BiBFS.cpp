//
// Created by salen on 4/16/2024.
//

#include "BiBFS.h"
#include "database.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> Traversal_Functions::bfs(string start, string end) {
    vector<int> path_BFS;

    // get the id for the start
    int start_id = helper_BFS.getID(start);
    // get the id for the end
    int end_id = helper_BFS.getID(end);

    // check if the id is a redirect
    if (helper_BFS.isRedirect(start_id)) {
        int start_target_id = helper_BFS.redirectTarget(start_id); //use the getTargetId function
        start_id = start_target_id;
    }

    // create map to store ID to its incoming links
    unordered_map<int, vector<int>> tracePaths_BFS;
    // add start_id to path pointing to empty vector
    tracePaths_BFS[start_id] = {};

    // create queue
    queue<int> q_BFS;

    //then push it into the queue
    q_BFS.push(start_id);

    while(!q_BFS.empty() && path_BFS.empty()) {
        int currentVertex = q_BFS.front();
        q_BFS.pop();

        vector<int> neighbors = helper_BFS.outgoing(currentVertex);
        for (int pageID : neighbors) {
            // check if reached end node
            if (pageID == end_id) { //CRUCIAL STEP
                path_BFS.push_back(pageID);
                path_BFS.push_back(currentVertex);
                while (true) {
                    pageID = tracePaths_BFS[currentVertex][0];
                    path_BFS.push_back(pageID);
                    if (pageID == start_id)
                        break;
                    currentVertex = pageID;
                }
                return path_BFS;
            }
            if (helper_BFS.isRedirect(pageID)) {
                int target_id = helper_BFS.redirectTarget(pageID); //use the getTargetID function
                pageID = target_id;
            }
            if ((visited_BFS.count(pageID) == 0)) { //if it's not in the set, then add it
                visited_BFS.insert(pageID);
                tracePaths_BFS[pageID] = {currentVertex};
                q_BFS.push(pageID);
            }
        }
    }
    return path_BFS;
}

vector<int> Traversal_Functions::dfs(string start, string end) {
    vector<int> path_DFS;
    int depthLevel = 0;

    // get the id for the start
    int start_id = helper_DFS.getID(start);
    // get the id for the end
    int end_id = helper_DFS.getID(end);

    // check if the id is a redirect
    if (helper_DFS.isRedirect(start_id)) {
        int start_target_id = helper_DFS.redirectTarget(start_id); //use the getTargetId function
        start_id = start_target_id;
    }

    // create map; key is currentVertex; value is parent of currentVertex
    unordered_map<int, int> tracePaths_DFS;
    // add start_id to path pointing to empty vector
    tracePaths_DFS[start_id] = -1;

    // create deque
    deque<int> s_DFS;

    //then push it into the deque
    s_DFS.push_back(start_id);

    while(!s_DFS.empty()) {
        int currentVertex = s_DFS.back();
        s_DFS.pop_back();
        visited_DFS.insert(currentVertex);
        vector<int> neighbors = helper_DFS.outgoing(currentVertex);
        for (int id : neighbors) {
            if(tracePaths_DFS.find(id) == tracePaths_DFS.end()){
                tracePaths_DFS[id] = currentVertex;
            }
            if (visited_DFS.count(id) == 0 && std::find(s_DFS.begin(), s_DFS.end(), id) == s_DFS.end()) {
                if (id == end_id) {
                    path_DFS.push_back(id);
                    while (id != -1) {
                        id = tracePaths_DFS[id];
                        path_DFS.push_back(id);
                        if (id == start_id)
                            break;
                    }
                    reverse(path_DFS.begin(), path_DFS.end());
                    return path_DFS;
                }
                s_DFS.push_back(id);
            }
        }
    }
    return {};
}


