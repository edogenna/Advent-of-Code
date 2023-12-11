FILE_NAME = "input.txt"

f = open(FILE_NAME, "r")
lines = f.readlines()

def is_list_same_num(list):
    if len(list) == 0:
        return True

    first = list[0]
    for i in list:
        if i != first:
            return False

    return True

sum_succ = 0
sum_prec = 0
for idx, i in enumerate(lines):
    s = i.split()
    diff = [[]]
    for j in range(len(s) - 1):
        diff[-1].append(int(s[j + 1]) - int(s[j]))

    while not is_list_same_num(diff[-1]):
        diff.append([])
        for j in range(len(diff[-2]) - 1):
            diff[-1].append(diff[-2][j+1] - diff[-2][j])

    succ = diff[-1][0]
    prec = diff[-1][0]
    for j in range(len(diff)-2,-1,-1):
        succ += diff[j][-1]
        prec = diff[j][0] - prec
    succ += int(s[-1])
    prec = int(s[0]) - prec

    sum_succ += succ
    sum_prec += prec

print("succ:",sum_succ," prec:",sum_prec)