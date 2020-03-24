# 5.二分搜索
二分搜索算法
看似简单，写对很难
变形很多
在面试中常来考察code能力

优点:
二分搜索也称对数搜索，时间复杂度 O(lgn)，是一种非常高效的搜索

缺点:
要求待搜索数组或区间是排好序的
若要求对数组进行动态地删除或者插入操作并完成查找，平均时间复杂度O(n)
--采用平衡二叉查找树

当: 输入的数组或者区间是有序的，且不会常变动， 要求从中找出一个满足条件的元素
-->采用二分搜索法

基本题解模板:
递归:
优点简洁
缺点执行消耗大

非递归

无bug的二分搜索，有三个关键点需要注意:
1. 计算mid的下标;
   不能简单地用(low+high)/2, 这样会导致溢出
2. 去左半边和右半边时，
   左半边: [low, mid - 1]
   右半边: [mid+1, hi], 这是两个闭区间
   我们确定了mid点不是我们需要的点，因此没必要加入左、右半边了
3. 对于长度为奇数的数组， 按照mid = lo + (hi - lo) >> 1来计算,  mid点就是中间的位置
   [1,2,3,4,5]为例， 3就是中间的点
   对于长度为偶然的数组， mid点就是中间靠左边的位置
   [1,2,3,4]为例， 2就是中间的点

扩展问题:
寻找下边界的条件:
1.该数是目标数
2.该数左边的一个数必须不是目标数
   左边的数不存在
   左边的数小于目标

寻找上边界的条件:
1.该数是目标数
2.该数右边的一个数必须不是目标数
   右边的数不存在
   右边的数大于目标

找模糊的边界:
二分搜索可以用来找一些模糊的边界
模糊的边界，即边界的值不等于目标的值，而是大于或者小于目标的值
1.这个数字要大于6
2.这个数有可能是数组中的第一个数，或者它前一个数字比6小

二分搜索旋转过的排序数组:
核心： 每次二分搜索操作，都能找到一个半边是排好序的、
只要比较nums[lo]和nums[mid]，
如果nums[lo]<=nums[mid], 那么左边这部分是排好序的，否则右边是排好序的


二分搜索变形题:
-------寻找上下边界-----------
1. leetcode 34.最长子序列的长度
-------找模糊的边界-----------   
2. 从数组中，例如{-2,0,1,4,7,9,10}中找到第一个大于6的数
3. leetcode 33.旋转过的排序数组