FILE_NAME = "input.txt"
MAX_R = 12
MAX_G = 13
MAX_B = 14

f = open(FILE_NAME, "r")

lines = f.readlines()
sum = 0
for l in lines:
    ls = l.split()
    id = int(ls[1][:-1])
    r = g = b = 0
    for i in range(2, len(ls), 2):
        if ls[i + 1][0] == 'r':
            r = int(ls[i])
        elif ls[i + 1][0] == 'g':
            g = int(ls[i])
        else:
            b = int(ls[i])

        if r > MAX_R or g > MAX_G or b > MAX_B:
            id = 0
            break
        if ls[i + 1][-1] == ';' or ls[i + 1][-1].isalpha():
            r = g = b = 0

    sum += id

print("pt1 :", sum)


f.seek(0)

lines = f.readlines()
sum = 0
for l in lines:
    ls = l.split()
    id = int(ls[1][:-1])
    r_min = g_min = b_min = 0
    for i in range(2, len(ls), 2):
        if ls[i + 1][0] == 'r':
            r = int(ls[i])
            if r > r_min: r_min = r
        elif ls[i + 1][0] == 'g':
            g = int(ls[i])
            if g > g_min: g_min = g
        else:
            b = int(ls[i])
            if b > b_min: b_min = b
    sum += r_min * g_min * b_min

print("pt2 :", sum)
