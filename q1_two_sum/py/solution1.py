class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        delidx = []
        for i in range(len(nums)):
            num = nums[i]
            try:
                dict[num].append(i)
                if 2 * num != target:
                    delidx.append(num)
                else:
                    return dict[num]
            except KeyError:
                dict[num] = [i]

        for num in set(delidx):
            del dict[num]

        for key in dict.keys():
            delta = target - key
            try:
                if dict[key][0] != dict[delta][0]:
                    return [dict[key][0], dict[delta][0]]
            except KeyError:
                pass
