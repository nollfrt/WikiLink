//
// Created by salen on 4/16/2024.
//

#include "BiBFS.h"
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

bool BiBFS::is_Redirect(std::string title) {
    //check to see if the page is a redirect
    //if is_redirect within pages in the table is a 1 then find the correct article title

}

string BiBFS::get_Redirect(std::string title) {
    //find the actual article title that is associated with the redirect
}

void BiBFS::bi_bfs(string start, string end) {
    //check to see if the database is opened
    if(is_Redirect(start) == true){
        string new_start = get_Redirect(start);
        start = new_start;
    }
    //then push it into the queue
    q.push(start);
    while(!q.empty()) {
        string u = q.front();
        q.pop();
        vector<string> neighbors; //this needs to be initialized
        for (string page : neighbors) {
            if(is_Redirect(page) == true){ //checks to see if any of the neighbors are redirects
                string new_start_ = get_Redirect(page);
                start = new_start_; //change this to not be start
            }
            if (visited.count(page) == 0) {
                visited.insert(page);
                q.push(page);
            }
            //this is the general code for a regular BFS
            //figure out how to make this bidirectional, fix some of the comments I made, make sure that the set
            // is unique for each path and it doesn't carry over to another path search
        }
    }

}
