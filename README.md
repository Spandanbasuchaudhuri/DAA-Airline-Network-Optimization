# Shortest Path Algorithms in C

This repository contains implementations of two shortest path algorithms in C:

- **Dijkstra's Algorithm**: Finds the shortest path from a single source to all other vertices in a weighted graph.
- **Floyd-Warshall Algorithm**: Computes shortest paths between all pairs of vertices in a graph.

## Features
- Takes an adjacency matrix as input.
- Provides an option to run Dijkstra's, Floyd-Warshall, or both algorithms.
- Displays shortest path distances in a structured format.

## Getting Started

### Prerequisites
- A C compiler (e.g., GCC)
- Command-line interface

### Compilation
To compile the program, run:
```sh
gcc shortest_path.c -o shortest_path
```

### Execution
Run the executable:
```sh
./shortest_path
```

Follow the prompts to enter the adjacency matrix and select the algorithm.

## Usage
1. Enter the number of vertices in the graph.
2. Input the adjacency matrix (0 for self-loops, and a large value for no direct connection).
3. Choose an algorithm:
   - 1: Dijkstra's Algorithm
   - 2: Floyd-Warshall Algorithm
   - 3: Both Algorithms

## Example Input
```
Enter the number of vertices in the graph: 4
Enter the adjacency matrix representing the graph:
0 3 INF 7
8 0 2 INF
5 INF 0 1
2 INF INF 0
```

## Example Output
### Dijkstra's Algorithm Output
```
Vertex   Distance from Source
0        0
1        3
2        5
3        6
```

### Floyd-Warshall Algorithm Output
```
  0   3   5   6
  8   0   2   3
  5   8   0   1
  2   5   7   0
```

## License
This project is open-source and free to use.

## Contributions
Feel free to submit issues and pull requests to enhance the project!

