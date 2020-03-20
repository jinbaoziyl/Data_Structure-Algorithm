# 无重复字符的最长子串
def MaxSubStr(str):
    if str == None:
        return 0
    nums = []
    for i in range(len(str)):
        arr = [0]*256
        icount = 0
        for j in range(i, len(str)):
            if arr[ord(str[j])] == 1:
                break
            else:
                arr[ord(str[j])] += 1
                icount += 1
        nums.append(icount)
    
    return max(nums)

# str = 'abcabcabc'
# str = 'bbbbbbbbbbbb'
# str = 'pwwkew'
# val = MaxSubStr(str)
# print('val: %d' %val)

# 寻找两个有序数组中的中位数
def Median(arr1, arr2):
    if arr1 == None and arr2 == None:
        return -1
    size = len(arr1)+len(arr2)
    res = [0]*size
    idx1, idx2 = 0, 0
    for i in range(size):
        if idx1 > len(arr1)-1:
            res[i] = arr2[idx2]
            idx2 += 1
        elif idx2 > len(arr2)-1:
            res[i] = arr1[idx1]
            idx1 += 1
        elif arr1[idx1] < arr2[idx2]:
            res[i] = arr1[idx1]
            idx1 += 1
        else:
            res[i] = arr2[idx2]
            idx2 += 1

    if size % 2 == 1:
        return res[size//2]
    else:
        return (res[size//2] + res[size//2+1])//2

arr1 = [1,2]
arr2 = [3,4]
val = Median(arr1, arr2)
print('val: %d' %val)


