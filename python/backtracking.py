def backtracking(cadidates, target, start, solution, results):
    if target < 0:
        return 
    if target == 0:
        results.append(solution[:])
        return

    for i in range(start, len(cadidates)):
        solution.append(cadidates[i])
        backtracking(cadidates, target-cadidates[i], i, solution, results)
        solution.pop()

    return
def combinationSum(cadidates:list, target:int):
    results = []
    backtracking(cadidates, target, 0, [], results)
 
    return results

def check(row, col, columns):
    for r in range(row):
        if columns[r] == col or row - r == abs(columns[r]-col):
            return False
    return True

count = 0
def backtracking_queens(n, row, columns):
    # 是否在所有n行里都摆好了皇后
    if row == n:
        count += 1 # 找到新摆法
        return
    # 尝试将皇后放置在当前行中的每一列
    for col in range(n):
        columns[row] = col
        # 检测是否合法,如果合法就进行下一行
        if check(row, col, columns):
            backtracking_queens(n, row+1, columns)
        # 如果不合法，就不要把皇后放到该列中
        columns[col] = -1


# Leetcode 52.N皇后II
def totalNQueens(n):
    columns = [0]*n
    backtracking_queens(n, 0, columns)
    return count

candidates = [2,3,6,7]
target = 7
res = combinationSum(candidates, target)

for s in res:
    print(s)
