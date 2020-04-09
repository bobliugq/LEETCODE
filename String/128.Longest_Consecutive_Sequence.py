// Date:        2020.4.8
// GA algorithm

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        maxArr = 1
        nums = set(nums)
        for x in nums:
            if x - 1 not in nums:
                y = x + 1;
                cur = 1;
                while y + 1 in nums:
                    cur += 1
                    y += 1
                maxArr = max(maxArr, cur)
        return maxArr
