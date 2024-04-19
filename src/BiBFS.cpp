//
// Created by salen on 4/16/2024.
//

#include "BiBFS.h"
#include "database.h"
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

void BFS_Functions::bfs(string start, string end) {
    database helper_BFS;

    //get the id for the start
    int start_id = helper_BFS.getID(start);

    //check if the id is a redirect
    if (helper_BFS.isRedirect(start_id)) {
        int start_target_id = helper_BFS.redirectTarget(start_id); //use the getTargetId function
        start_id = start_target_id;
    }

    //then push it into the queue
    q_BFS.push(start_id);
    while(!q_BFS.empty()) {
        q_BFS.pop();
        vector<int> neighbors = helper_BFS.outgoing(start_id);
        for (int pageID : neighbors) {
            if (helper_BFS.isRedirect(pageID)) {
                int target_id = helper_BFS.redirectTarget(pageID); //use the getTargetID function
                pageID = target_id;
            }
            if (visited_BFS.count(pageID) == 0) {
                visited_BFS.insert(pageID);
                q_BFS.push(pageID);
            }
        }
        visited_BFS.clear();
    }
}
void BFS_Functions::bi_bfs(string start, string end) {
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
