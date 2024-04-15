from functools import cmp_to_key

def compare(s1, s2):
    if s1 + s2 > s2 + s1:
        return -1
    elif s1 + s2 < s2 + s1:
        return 1
    else:
        return 0


if __name__ == "__main__":
    s = str(input())
    nums = s.split()
    nums = sorted(nums, key=cmp_to_key(compare))
    print("".join(nums))