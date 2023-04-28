# Mini wasalny

## Description

Mini wasalny is a C++ program that allows the user to enter a graph which represents cities and distances between them, and then finds the shortest path to reach the destination from any given source city. The program uses three types or more of data structures in the project, and implements the graph using Adjacency list. The program also saves the graph data in a file so the user can close the program and reopen it to continue working on the saved graph.

The program allows the user to:

- Add a graph (cities and distances between them)
- Display graph data
- Update graph data
  - Add new city
  - Add new edge
  - Delete city (including edges that are connected to this city)
  - Delete edge (the user enters the names of two cities to delete the edge between them)
- Traverse the graph using Breadth First Search (BFS) and Depth First Search (DFS)
- Determine two cities as source and destination, then find the shortest path between them using Dijkstra's Algorithm

The program computes and displays the total distance of the shortest path and displays the shortest path (cities names in the shortest path).

The program applies SOLID principles to improve its design and maintainability.

## Libraries Used

The program uses the following third-party libraries:

- ~~Boost Serialization: for saving and loading the graph data from files.~~
- Saving and Loading Graph Data using nlohmann json.

## How to Use

To use the program, you can follow these steps:

1. Compile the program using a C++ compiler that supports C++11 or later, such as GCC or Clang.
2. Run the program and choose one of the menu options to add, display, or update the graph data.
3. Choose one of the search algorithms to traverse the graph or find the shortest path.

## How to Build

To build the program, you can follow these steps:

1. Clone the repository to your local machine.
2. Install a C++ compiler that supports C++11 or later, such as GCC or Clang.
~~3. Install the Boost Serialization.~~
4. Run the following command to compile the program:

```
g++ -Wall -fexceptions -g  -c main.cpp -o obj/Debug/main.o
g++  -o bin/Debug/mini-wasalny obj/Debug/ConsoleGraph.o obj/Debug/FileEngine.o obj/Debug/Graph.o obj/Debug/GraphMutator.o obj/Debug/GraphTraversal.o obj/Debug/main.o obj/Debug/ShortestPath.o
./bin/Debug/mini-wasalny
```
5. Run the program
