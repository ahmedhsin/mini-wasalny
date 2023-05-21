# Mini Wasalny

## Description

Mini Wasalny is a C++ program that allows the user to enter a graph representing cities and distances between them, and then find the shortest path to reach the destination from any given source city. The program uses three or more types of data structures in the project and implements the graph using an adjacency list. The program also saves the graph data in a file so that the user can close the program and reopen it to continue working on the saved graph.

- Project video in runtime link:https://bit.ly/3q5pzVZ

The program provides the following functionalities:

- Add a graph (cities and distances between them)
- Display graph data
- Update graph data
  - Add a new city
  - Add a new edge
  - Delete a city (including edges connected to this city)
  - Delete an edge (the user enters the names of two cities to delete the edge between them)
  - Undo the previous operation
- Traverse the graph using Breadth-First Search (BFS), and Depth-First Search (DFS)
- Determine two cities as the source and destination, then find the shortest path between them using Dijkstra's Algorithm or Bellman-Ford algorithm

The program computes and displays the total distance of the shortest path and displays the shortest path (city names in the shortest path).

The program applies SOLID principles to improve its design and maintainability.

## Libraries Used

The program uses the following third-party libraries:

- nlohmann json: for saving and loading graph data from files.
- Qt: for the graphical user interface (GUI).
- SFML: for graph visualization.

Please make sure to have these libraries installed and properly configured before running the program.
