FILE_NAME = "input.txt"

f = open(FILE_NAME, "r")
lines = f.readlines()


class Number:
    def __init__(self, pos, n, num_d):
        self.pos = pos
        self.n = n
        self.num_d = num_d

    def __repr__(self):
        return f"<pos:{self.pos} n:{self.n} num_d:{self.num_d}>"


numbers = []
symbols = []
gears = []
sum = 0

for row in range(len(lines)):
    numbers.append([])
    symbols.append([])
    gears.append([])

    curr_line = lines[row]
    i = 0
    while i < len(curr_line):
        n = 0
        num_d = 0
        num_found = False
        pos = i
        while curr_line[i].isdigit() and i < len(curr_line):
            num_found = True
            n *= 10
            n += int(curr_line[i])
            num_d += 1
            i += 1

        if num_found:
            numbers[row].append(Number(pos, n, num_d))

        if not curr_line[i].isdigit() and curr_line[i] != '.' and curr_line[i] != '\n':
            symbols[row].append(i)
            if curr_line[i] == '*':
                gears[row].append(i)

        i += 1

numbers_engine = []

for row, i in enumerate(numbers):
    for j in i:
        found = False
        if row > 0:  # not the first row, so check the prev row
            for k in symbols[row - 1]:
                if j.pos - 1 <= k <= j.pos + j.num_d:
                    found = True
                    break

        if not found:  # check the current row
            for k in symbols[row]:
                if k == j.pos - 1 or k == j.pos + j.num_d:
                    found = True
                    break

        if not found and row < len(numbers) - 1:  # not the last row, so check the following row
            for k in symbols[row + 1]:
                if j.pos - 1 <= k <= j.pos + j.num_d:
                    found = True
                    break

        if found:
            numbers_engine.append(j.n)

for i in numbers_engine:
    sum += i

print("pt1: ", sum)
print(gears)

sum_ratio = 0

for row, i in enumerate(gears):
    for j in i:
        num1 = -1
        num2 = -1
        too_many_numbers = False

        if row > 0:  # not the first row, so check the prev row
            for k in numbers[row - 1]:
                if k.pos - 1 <= j <= k.pos + k.num_d:
                    if num1 != -1 and num2 != -1:
                        too_many_numbers = True
                        break
                    elif num1 == -1:
                        num1 = k.n
                    else:
                        num2 = k.n

        if not too_many_numbers:  # check the current row
            for k in numbers[row]:
                if j == k.pos - 1 or k.pos + k.num_d == j:
                    if num1 != -1 and num2 != -1:
                        too_many_numbers = True
                        break
                    elif num1 == -1:
                        num1 = k.n
                    else:
                        num2 = k.n

        if not too_many_numbers and row < len(numbers) - 1:  # not the last row, so check the following row
            for k in numbers[row + 1]:
                if k.pos - 1 <= j <= k.pos + k.num_d:
                    if num1 != -1 and num2 != -1:
                        too_many_numbers = True
                        break
                    elif num1 == -1:
                        num1 = k.n
                    else:
                        num2 = k.n

        if not too_many_numbers and num1 != -1 and num2 != -1:
            print(num1, "  ", num2)
            sum_ratio += num1 * num2

print("pt2: ", sum_ratio)
