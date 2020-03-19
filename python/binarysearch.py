# 递归
def binarysearch_recursion(nums, target, lo, hi):
    if lo > hi:
        return -1
    
    mid = lo + (hi - lo) // 2
    if nums[mid] == target:
        return mid
    if nums[mid] < target:
        return binarysearch(nums,target,mid+1,hi)
    else:
        return binarysearch(nums,target,lo,mid-1)

def binarysearch(nums, target, lo, hi):
    if lo > hi:
        return -1

    while(lo <= hi):
        mid = lo + (hi - lo) // 2  

        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            lo = mid + 1 
        else:
            hi = mid - 1

# nums = [1,2,3,4,5,6]
# val = binarysearch_recursion(nums, 5, 0, len(nums)-1)
# print("val: %d" %val)

# 寻找下边界的条件:
# 1.该数是目标数
# 2.该数左边的一个数必须不是目标数
#    左边的数不存在
#    左边的数小于目标
def binarysearch_lowerbound(nums, target, lo, hi):
    if lo > hi:
        return -1
    
    mid = lo + (hi - lo) // 2
    if nums[mid] == target and (mid == 0 or nums[mid - 1] < nums[mid]):
        return mid
    if nums[mid] >= target:   #同时需要注意nums[mid]=target的情况，需要落在那个半边
        return binarysearch(nums,target,lo,mid-1)
    else:
        return binarysearch(nums,target,mid+1,hi)
        

# 寻找上边界的条件:
# 1.该数是目标数
# 2.该数右边的一个数必须不是目标数
#    右边的数不存在
#    右边的数大于目标
def binarysearch_upperbound(nums, target, lo, hi):
    if lo > hi:
        return -1
    
    mid = lo + (hi - lo) // 2
    if nums[mid] == target and (mid == len(nums) - 1 or nums[mid + 1] > nums[mid]):
        return mid
    if nums[mid] <= target:   #同时需要注意nums[mid]=target的情况，需要落在那个半边
        return binarysearch(nums,target,mid+1,hi)
    else:
        return binarysearch(nums,target,lo,mid-1)

nums = [5,7,8,8,8,10]
lo = binarysearch_lowerbound(nums, 8, 0, len(nums)-1)
hi = binarysearch_upperbound(nums, 8, 0, len(nums)-1)
print("lo: %d, hi: %d" %(lo, hi))