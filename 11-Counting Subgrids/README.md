# 11-Counting Subgrids

## Algorithm:

For two given rows, we have to check the possible combinations of squares lying in the same column are set as 1. Then out of these combinations of squares, we can combine any two to get a subgrid which has all 4 corners black in colour. Now we can observe that the each row of the matrix can actually be expressed as a bit string, or a binary number. This makes it easier to do computations over rows to check which two squares in the same column are set in O(1) time. Thus, for each row we first calculate all the possible combinations of squares in the same column which are set by simply applying AND operation on the two rows(bit strings). Then we calculate the number of 1s in the resultant bit string, and then count all the possible unique pairs of 1s in order to calculate the number of subgrids where the 4 corners lie in those two rows 2 in each. We then, repeat this for all pairs of rows and sum the answers for all pairs of rows as our final answer.            

### Time Complexity: O(N * N)

### Space Complexity: O(N) (for storing all rows as bitsets)