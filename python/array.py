#翻转字符串
def reverse_str(str):
    lo, hi = 0, len(str)-1
    while lo <= hi:
        str[lo], str[hi] = str[hi], str[lo]
        lo += 1
        hi -= 1

# str = list(input())
# reverse_str(str)
# print("".join(str))

#字符个数统计
def char_count(vstr):
    lut = [0]*256
    for i in range(len(vstr)):
        lut[ord(vstr[i])] += 1
    count = 0
    for j in range(len(lut)):
        if lut[j] > 0:
            count += 1
    return count

# str = list(input())
# res = char_count(str)
# print(res)

# 字符串合并处理
import sys
def encode_str(input_str):
    result = ''
    enc_str = '1234567890abcdefABCDEF'
    for i in input_str:
        if i in enc_str:
            int_i = int('0x' + i, 16)
            revers_b = '{:04b}'.format(int_i)[::-1]
            chr_i = hex(int(revers_b, 2)).replace('0x', '')
            if chr_i.isalpha():
                result += chr_i.upper()
            else:
                result += chr_i
        else:
            result += i
    return result

def ProcessString(str1, str2):
    str_merge = str1 + str2
    tmp_str1 = []
    tmp_str2 = []
    for i in range(1, len(str_merge)+1):
        if i%2==0:
            tmp_str2.append(str_merge[i-1])
        else:
            tmp_str1.append(str_merge[i-1])
    #排序
    tmp_str1.sort()
    tmp_str2.sort()

    # vstr = "".join(tmp_str1) + "".join(tmp_str2)
    vstr = tmp_str1 + tmp_str2
    return encode_str(vstr)

# str1, str2 = sys.stdin.readline().strip().split()
# str_res = ProcessString(str1, str2)
# print(str_res)

#数字颠倒
def reverse_num(a):
    vlist = []

    while a:
        vlist.append(a%10)
        a = a // 10
    ss = list(map(str, vlist))
    print("".join(ss))

# vstr = input()
# reverse_num(int(vstr))

# 数字转变成二进制1的个数
def bit_num(a):
    count = 0
    while a != 1:
        b = a % 2
        if b == 1:
            count += 1
        a = a // 2
    
    return count+1

# vstr = input()
# print(bit_num(int(vstr)))

# 华为机试-2020/4/6
import sys
import re
def sort_words(sword):
    l = []
    temp = sword.split(" ")
    for i in temp:
        if i.lower() not in [j.lower() for j in l]:
            l.append(i)
    return " ".join(sorted(l, key=str.lower))

def main():
    while True:
        words = sys.stdin.readline()
        if len(words) <= 255:
            pat = re.compile(r"^[a-zA-Z\s]{0,255}$")
            if pat.match(words):
                #正确输入
                test = sort_words(words)
                print("%s" %test)
                break
            else:
                print("Input words invalid, re-Input again!")
        else:
            print("Input words' length should less then 255!")

# if __name__ == '__main__':
#     main()

# 有效的字母异位词
def EccentricLetters(word1, word2):
    assert isinstance(word1,str)
    assert isinstance(word2,str)

    lut = [0]*256
    for i in range(len(word1)):
        lut[ord(word1[i])] += 1

    for j in range(len(word2)):
        lut[ord(word2[j])] -= 1
    
    for ele in lut:
        if ele != 0:
            return False
    return True

words = input()
vword = words.strip().split()
print(EccentricLetters(vword[0], vword[1]))

