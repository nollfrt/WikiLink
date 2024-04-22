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

    // create map to store ID to its incoming links
    unordered_map<int, vector<int>> tracePaths_DFS;
    // add start_id to path pointing to empty vector
    tracePaths_DFS[start_id] = {};

    // create stack
    stack<int> s_DFS;

    //then push it into the stack
    s_DFS.push(start_id);

    while(!s_DFS.empty() && path_DFS.empty()) {
        int currentVertex = s_DFS.top();
        s_DFS.pop();

        vector<int> neighbors = helper_DFS.outgoing(currentVertex);
        for (int pageID : neighbors) {
            // check if reached end node
            if (pageID == end_id) { //CRUCIAL STEP
                path_DFS.push_back(pageID);
                path_DFS.push_back(currentVertex);
                while (true) {
                    pageID = tracePaths_DFS[currentVertex][0];
                    path_DFS.push_back(pageID);
                    if (pageID == start_id)
                        break;
                    currentVertex = pageID;
                }
                return path_DFS;
            }
            if (helper_DFS.isRedirect(pageID)) {
                int target_id = helper_DFS.redirectTarget(pageID); //use the getTargetID function
                pageID = target_id;
            }
            if ((visited_DFS.count(pageID) == 0)) { //if it's not in the set, then add it
                visited_DFS.insert(pageID);
                tracePaths_DFS[pageID] = {currentVertex};
                s_DFS.push(pageID);
            }
        }
    }
    return path_DFS;
}
