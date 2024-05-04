# 12-Finding Maximum Flow

## Algorithm:

Finding the maximum flow in a graph is computed by using a standard algorithm called the Ford Fulkerson algorithm. It is as follows:

We start out with 0 flow (max capacity) in all the edges of the graph and try to find a possible path from the source to the sink in the graph. A possible path is any path from the source to the sink in which we can increase the flow such that none of the edges will overflow. This path is also known as an augmenting path. We then find the edge with the least available capacity in the path (called bottleneck) and decrease the capacity of all the edges in one direction and increase them in the opposite direction by this bottleneck value. We keep on finding more such augmenting paths and repeat the same process till there are no available augmenting paths left, i.e. no path from source to sink. We sum the bottlenecks over all augmenting paths which gives us the maximum possible flow in the graph. We can find the augmenting paths using any graph traversal technique like BFS or DFS since it is not explicitly mentioned in the Ford Fulkerson algorithm. I have used BFS to find the augmenting paths (also known as Edmonds-Karp Algorithm) and adjacency matrix to store the graph.

### Time Complexity: O(E * V * V * V) where V is the number of vertices in the graph and E is the number of edges in the graph

### Space Complexity: O(V * V)