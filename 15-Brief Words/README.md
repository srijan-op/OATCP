# 15-Brief Words

## Algorithm:

The algorithm constructs a bipartite graph, where one set of vertices represents the input strings, and the other set represents the distinct short strings (of length 4 or less). An edge is created between a string vertex and a short string vertex if the input string can be transformed into that short string. To find a valid transformation, the algorithm attempts to find a perfect matching in the bipartite graph, where each input string is assigned a unique short string. This is done by performing a DFS on the graph, starting from each input string vertex. During the DFS, if a valid assignment of a short string to the current input string is found, the search continues recursively to assign short strings to the remaining input strings. If a perfect matching exists, the corresponding short string for each input string is obtained from the map and printed as the output.

### Time Complexity: O(N * M), where N is the number of input strings and M is the maximum length of a string

### Space Complexity: O(N * M), where N is the number of input strings and M is the maximum length of a string