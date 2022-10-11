'''
LeetCode - problem 53
'''

    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0] 
        curSum = 0 
        
        for num in nums:
            if curSum + num < num:
                curSum = num 
            else:
                curSum = curSum + num 
            maxSum = max(maxSum, curSum)
        return maxSum
