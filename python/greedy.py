# 有 m 个糖果和 n 个孩子。我们现在要把糖果分给这些孩子吃，
# 但是糖果少，孩子多（m < n），所以糖果只能分配给一部分孩子。
# 每个糖果的大小不等，这 m 个糖果的大小分别是s1，s2，s3，……，sm。
# 除此之外，每个孩子对糖果大小的需求也是不一样的，只有糖果的大小大于等于孩子的对糖果大小的需求的时候，
# 孩子才得到满足。假设这 n 个孩子对糖果大小的需求分别是 g1，g2，g3，……，gn。那么如何分配糖果，
# 能尽可能满足最多数量的孩子呢?

def dispatchCandy(gList, sList):
    gList.sort()
    sList.sort()

    maxCandyNum = 0
    for i in range(len(gList)):
        for j in range(len(sList)):
            if gList[i] <= sList[j]:
                maxCandyNum += 1
                sList[j] # T糖果被选中，设置成无效了
                break
    
    return maxCandyNum
    
#小孩对糖果的需求
gList = [1, 2, 4, 6]
# 糖果实际大小
sList = [1, 2, 7, 3]
result = dispatchCandy(gList, sList)
print("result: %d" %result)