# Prims Algorithm
- It is used to find Minimum spanning tree in a Graph

## How it works?

- Import the `prims_MST` in your python file and pass a Graph matrix as show below in the function. The function will print the Minimum spanning tree in Graph

```
# Example Matrix
graph =[[0,4,3,0,0,0,1,0],
        [4,0,0,0,3,0,0,0],
        [3,0,0,8,0,5,0,0],
        [0,0,8,0,0,0,5,0],
        [0,3,0,0,0,0,6,0],
        [0,0,5,0,0,0,2,7],
        [1,0,0,0,6,2,0,0],
        [0,0,0,5,0,7,0,0]]

```

```
# Example Output:

0->1, weight = 4
0->2, weight = 3
7->3, weight = 5
1->4, weight = 3
6->5, weight = 2
0->6, weight = 1
5->7, weight = 7
```
