# 8-Smallest Integer

## Algorithm:

This problem can be solved using a greedy algorithm. We maintain a monotonic stack and we iterate over all the numbers present in the string. For each number, we keep popping the top of the stack till either we find a number which is smaller than our current number or we run out of numbers we can remove from the string or the stack becomes empty. If we iterate over all the numbers and still have some numbers we have to remove, we start popping those from the top of the stack till we run out of numbers to remove. Finally, we pop all numbers from the leftover stack, form a string from those numbers, reverse the string and remove any trailing zeroes which gives us the final answer.

The reason why we greedily pick the smallest numbers possible in the start is because we want to keep the smallest digits possible in the most significant places in order to achieve the smallest possible integer.

### Time Complexity: O(N) where N = length of the number string

### Space Complexity: O(N) where N = length of the number string