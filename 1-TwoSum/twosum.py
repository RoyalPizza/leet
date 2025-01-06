# python3 twosum.py
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for x in range(len(nums)):
            for y in range(x + 1, len(nums)):
                if nums[x] + nums[y] == target:
                    print(f"{x},{y} equals {target}")
                    return [x, y]
        return None
    
    def twoSumHash(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for i in range(len(nums)):
            temp = target - nums[i]
            if (temp in map):
                print(f"{i},{map[temp]} equals {target}")
                return [i, map[temp]]
            map[nums[i]] = i
        return None

solution = Solution()
result = solution.twoSumHash([2, 7, 11, 15], 9)
result = solution.twoSumHash([3, 2, 4], 6)
result = solution.twoSumHash([3, 3], 6)