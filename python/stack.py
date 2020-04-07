# 有效的括号
def  ValidParenthesis(vlist):
    stack = []  # 辅助结构栈
    for c in vlist:
        if c == '(' or c == '[' or c == '{':
            stack.append(c)
        elif c == ')' or c == ']' or c == '}':
            tmp = stack.pop()
            if (c==')' and tmp=='(') or (c==']' and tmp=='[') or (c=='}' and tmp=='{'):
                continue
            else:
                return False
        else:
            print('invalid param')
            return False
    if stack:
        return False
    else:
        return True

# vlist = input()
# print(ValidParenthesis(list(vlist)))

#后缀表达式
def postfix_calculate(s):
    """注意-号和/号的顺序问题"""
    stack = []
    for x in s:
        if x.isdigit():
            stack.append(x)
        elif x == "+":
            a = stack.pop()
            b = stack.pop()
            stack.append(int(a)+int(b))
        elif x == "-":
            a = stack.pop()
            b = stack.pop()
            stack.append(int(b)-int(a))
        elif x == "*":
            a = stack.pop()
            b = stack.pop()
            stack.append(int(a)*int(b))
        elif x == "/":
            a = stack.pop()
            b = stack.pop()
            stack.append(int(b)/int(a))
 
    return stack[-1]

# 每日温度(经典题)
def dailyTemperatures(T):
    ans = [0] * len(T)
    stack = [] #indexes from hottest to coldest
    for i in range(len(T) - 1, -1, -1):
        while stack and T[i] >= T[stack[-1]]:
            stack.pop()
        if stack:
            ans[i] = stack[-1] - i
        stack.append(i)
    return ans

vlist = input()
print(dailyTemperatures(list(map(int, vlist.strip().split()))))
