# 2-GridPaths

## Algorithm:

We can solve this problem using dynamic programming. Since we can only travel in right or down directions, we can conclude that the only way to reach a cell is through its immediate left or top neighbour. Let dp[i][j] be the number of ways to reach matrix[i][j], thus we can see that the dp recurrence will be the following: 

```
dp[i][j] = dp[i-1][j] + dp[i][j-1]  
```

For i-1>=0 and j-1>=0 

We can iterate over all the cells in the matrix and calculate the value for each of them. 

Base case will be as follows since there is only one way to reach the starting cell (by default):

```
dp[0][0] = 1  
```

For the cells which contain traps, we can add them to our base case and say

```
dp[i][j] = 0 if matrix[i][j] == '*'
```

Modular addiion has also been used to prevent integer overflow and meet the problem constraints.

### Time Complexity: O(N*N) where N = number of rows/columns in the matrix

### Space Complexity: O(N*N) where N = number of rows/columns in the matrix.