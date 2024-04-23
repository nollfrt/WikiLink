# How to utilize the program

To utilize the program, the user would type in the first article link to be used as the first node. Then the user would type in the second article link in the second text box. They would then press the "Generate search" button to start the BFS and DFS. After the searches have been done, the new screen will pop up and will show in the left most box, the BFS amount of nodes that it used and in the rightmost box the DFS for the amount of nodes done. To exit the program, you simply press the exit or close button at the top right to exit the program.

# How to build the program

Configurations for building the program are provided in the cmake-build-debug directory. That, in combination with the CMakeLists.txt should enable you to build the project. The database is needed in the database directory; we could not include it in git because of its big size (12 gigs). There is also a .exe file in the cmake-build-debug directory that contains the built project.

# References

For the font: https://www.fontspace.com/category/ttf
· For the spider man image from Google search: https://purepng.com/tags/spider-man
· for the Mario image from Google search: https://pngimg.com/image/30596
· for how to open a website using SFML libraries:
https://www.codeproject.com/Questions/265461/Opening-A-Website-with-Cplusplus
· SFM tutorials website: https://www.sfml-dev.org/tutorials/2.6/
- Utilized SFML tactics from Savannah minesweeper (was not uploaded on GitHub.
- Utilized geeksforgeeks for help with the BFS implementation:
https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
- Utilized geeksforgeeks for help with the DFS implementation:
https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
- Utilized this github for the database and understanding the information in the database:
https://github.com/jwngr/sdow/blob/master/docs/data-source.md (we DID NOT use the
code from this github; they coded the project in python and implemented a BiBFS
traversal on the database. We used C++ and implemented a BFS and DFS traversal on the
database)
