# 9-Patching Array

## Algorithm:

We can use a greedy approach in order to solve this problem. We can maintain a variable to maintain the range in which we can create all numbers using the numbers till i-th index and update it as we iterate over the array. For every number we check whether the number is covered in the range achieved just before the index of the number. It is guarenteed that all the numbers must be covered in the range since the array is sorted. If it is covered, we use to increase the possible range. If not we start patching the array, by adding the number 1 more than the current max of the range, while simultaenously increasing the range till we finally cover the number, and then further increase the range using the number till we reach the desired range, or beyond it.

If we iterate over the entire array and make sure all the numbers in the array are included but we still have not reached our desired range, we patch the array one final time by adding the number which is the difference between the final range and the desired range.

### Time Complexity (Ammortized Worst Case): O(N * log(N))

### Space Complexity: O(1) 