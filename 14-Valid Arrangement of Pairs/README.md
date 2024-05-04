# 14-Valid Arrangement of Pairs

## Algorithm:

The pairs of numbers can be expressed as a directed graph where {n, m} denotes an edge from n vertex to m vertex. Thus, this problem can be reduced to finding a Eulerian path in the graph. This is done using a standard algorithm known as the Hierholzer's Algorithm. It is as follows:

1. First we check whether the graph contains a Eulerian path, which is done by checking if the number of vertices where the indegree and outdegree differ by 1 are atmost 2 and all the other vertices have the same indegree and outdegree.
2. Next, we select one of the two nodes which have differing indegree and outdegree (the node which has more outdegree than indegree) as the start node, if no such node exists we can pick any node as the start node as the graph contains a Eulerian circuit instead. 
3. We initialize a stack, and call the DFS on the start node.
4. In each DFS call, we call the DFS recursively on the adjacent nodes till we have exhausted all the possible outgoing edges for the node. Then we push the node in the stack.
5. After the recursive DFS is over, we pop the nodes in the stack and append them to the path vector, thus resulting in the answer. 

### Time Complexity: O(V + E) where V is the number of vertices in the graph and E is the number of edges in the graph

### Space Complexity: O(1)