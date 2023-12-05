FILE_NAME = "input.txt"

f = open(FILE_NAME, "r")

lines = f.readlines()
sum = 0

for l in lines:
    points = 0
    winning = []
    ls = l.split()

    i = 2
    while ls[i] != '|':
        winning.append(int(ls[i]))
        i += 1
    i += 1
    while i < len(ls):
        if int(ls[i]) in winning:
            if points == 0:
                points = 1
            else:
                points *= 2
        i += 1
    sum += points

print("pt1: ", sum)



f.seek(0)

lines = f.readlines()
sum = 0
cards = {}

for l in range(len(lines)):
    if l in cards:
        cards[l] += 1
    else:
        cards[l] = 1

    count = 0
    winning = []
    ls = lines[l].split()

    i = 2
    while ls[i] != '|':
        winning.append(int(ls[i]))
        i += 1
    i += 1
    while i < len(ls):
        if int(ls[i]) in winning:
            count += 1
        i += 1

    for j in range(count):
        if l+j+1 in cards:
            cards[l+j+1] += cards[l]
        else:
            cards[l+j+1] = cards[l]

for k in cards:
    sum += cards[k]

print("pt2: ", sum)




