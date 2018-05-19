'''
Q561 - array-partition-i
'''

# my solution - beats 48%

class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        sum=0
        for i in range(0,len(nums)-1,2):
            sum=sum+nums[i]
            
        return sum



# Top solution

'''
Logic : Uses same logic as mine
Usage : extended slicing
'''
class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = sorted(nums)
        
        return sum(l[::2])
    


