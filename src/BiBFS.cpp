//
// Created by salen on 4/16/2024.
//

#include "BiBFS.h"
#include "database.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> BFS_Functions::bfs(string start, string end) {
    vector<int> allPaths_BFS;

    // get the id for the start
    int start_id = helper_BFS.getID(start);
    // get the id for the end
    int end_id = helper_BFS.getID(end);

    // check if the id is a redirect
    if (helper_BFS.isRedirect(start_id)) {
        int start_target_id = helper_BFS.redirectTarget(start_id); //use the getTargetId function
        start_id = start_target_id;
    }

//    // create struct for nodes
//    struct qVal{
//        int val;
//        qVal* past;
//    };

    // create map to store ID to its incoming links
    unordered_map<int, vector<int>> tracePaths;
    // add start_id to path pointing to empty vector
    tracePaths[start_id] = {};

    // create queue
    queue<int> q_BFS;

//    queue<qVal> q_BFS;
//
//    qVal startVal {start_id, nullptr};
//    qVal returnVal {0, nullptr};

    //then push it into the queue
    q_BFS.push(start_id);

    int returnID = 0;

    while(!q_BFS.empty() && allPaths_BFS.empty()) {
        int currentVertex = q_BFS.front();
        q_BFS.pop();

//        if (currentVertex == end_id) { //CRUCIAL STEP
//            returnVal = currentPath;
//            break;
//        }

        vector<int> neighbors = helper_BFS.outgoing(currentVertex);
        for (int pageID : neighbors) {
            // check if reached end node
            if (pageID == end_id) { //CRUCIAL STEP
                allPaths_BFS.push_back(pageID);
                allPaths_BFS.push_back(currentVertex);
                while (true) {
                    pageID = tracePaths[currentVertex][0];
                    allPaths_BFS.push_back(pageID);
                    if (pageID == start_id)
                        break;
                    currentVertex = pageID;
                }
                return allPaths_BFS;
            }
            if (helper_BFS.isRedirect(pageID)) {
                int target_id = helper_BFS.redirectTarget(pageID); //use the getTargetID function
                pageID = target_id;
            }
            // duplicate to fix later
            if (pageID == end_id) { //CRUCIAL STEP
                allPaths_BFS.push_back(pageID);
                allPaths_BFS.push_back(currentVertex);
                while (true) {
                    pageID = tracePaths[currentVertex][0];
                    allPaths_BFS.push_back(pageID);
                    if (pageID == start_id)
                        break;
                    currentVertex = pageID;
                }
                return allPaths_BFS;
            }
            if ((visited_BFS.count(pageID) == 0)) { //if it's not in the set, then add it
                // add to number of nodes visited
                numVisited++;
                // add ID to the set
                visited_BFS.insert(pageID);
                tracePaths[pageID] = {currentVertex};
                q_BFS.push(pageID);
            }
        }
    }
    return allPaths_BFS;
}

/*
vector<vector<int>> BFS_Functions::bi_bfs(string start, string end) {
    database helper_BiBFS;

    //get the id for the start
    int front_id = helper_BiBFS.getID(start);
    int back_id = helper_BiBFS.getID(end);

    //then push it into the queue
    q_BiBFS_start.push(front_id);
    q_BiBFS_end.push(back_id);
    while(!q_BiBFS_start.empty() && !q_BiBFS_end.empty()) {
        q_BiBFS_start.pop();

        //BFS from the front
        vector<int> neighbors_front = helper_BiBFS.outgoing(front_id);
        for (int pageID_front : neighbors_front) {
            if (helper_BiBFS.isRedirect(pageID_front)) {
                int target_id = helper_BiBFS.redirectTarget(pageID_front); //use the getTargetID function
                pageID_front = target_id;
            }
            if (visited_BiBFS_start.count(pageID_front) == 0) {
                visited_BiBFS_start.insert(pageID_front);
                q_BiBFS_start.push(pageID_front);
            }
            //check to see if they have met
            if (visited_BiBFS_end.count(pageID_front) > 0) {
                cout << "Meeting point found: " << pageID_front << endl;
                return;
            }
        }

        //BFS from the back
        q_BiBFS_end.pop();
        vector<int> neighbors_end = helper_BiBFS.incoming(back_id);
        for (int pageID_end : neighbors_end) {
            if (helper_BiBFS.isRedirect(pageID_end)) {
                int target_id = helper_BiBFS.redirectTarget(pageID_end); //use the getTargetID function
                pageID_end = target_id;
            }
            if (visited_BiBFS_end.count(pageID_end) == 0) {
                visited_BiBFS_end.insert(pageID_end);
                q_BiBFS_end.push(pageID_end);
            }
            //check to see if they have met
            if (visited_BiBFS_start.count(pageID_end) > 0) {
                cout << "Meeting point found: " << pageID_end << endl;
                return;
            }
        }

    }
}
*/