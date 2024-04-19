//
// Created by salen on 4/16/2024.
//

#include "BiBFS.h"
#include "database.h"
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

/*
string BiBFS::get_Redirect(std::string s_title) {
    //find the actual article title that is associated with the redirect
    bool redirect = false;
    if(SELECT is_redirect FROM pages == 1) {
        redirect = true;
        unsigned int targetPageID = SELECT target_id FROM redirects;
        for (unsigned int i : SELECT id FROM pages) {
            if (i == targetPageID)
                s_title = SELECT title.at(i) FROM pages;
        }
    }
    return s_title;
}
*/

void BiBFS::bi_bfs(string start, string end) {
    database helper;

    //get the id for the start
    int start_id = helper.getID(start);

    //then push it into the queue
    q.push(start_id);
    while(!q.empty()) {
        unsigned int u = q.front();
        q.pop();
        vector<int> neighbors = helper.outgoing(start_id);
        for (int pageID : neighbors) {
            string new_start_ = get_Redirect(//of the specific title at that page ID);
            if (visited.count(pageID) == 0) {
                visited.insert(pageID);
                q.push(pageID);
            }
            //this is the general code for a regular BFS
            //figure out how to make this bidirectional, fix some of the comments I made, make sure that the set
            // is unique for each path and it doesn't carry over to another path search
        }
    }
}
void BiBFS::bfs(string start, string end) {
    database helper;

    //get the id for the start
    unsigned int start_id = helper.getID(start);

    //then push it into the queue
    q.push(start_id);
    while(!q.empty()) {
        unsigned int u = q.front();
        q.pop();
        vector<int> neighbors = helper.outgoing(start_id);
        for (int pageID : neighbors) {
            string new_start_ = get_Redirect(//of the specific title at that page ID);
            if (visited.count(pageID) == 0) {
                visited.insert(pageID);
                q.push(pageID);
            }
            //this is the general code for a regular BFS
            //figure out how to make this bidirectional, fix some of the comments I made, make sure that the set
            // is unique for each path and it doesn't carry over to another path search
        }
    }
}
