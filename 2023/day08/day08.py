from math import gcd

FILE_NAME = "input.txt"


def steps_untill_all_z(map):
    idx = 0
    step = 0
    initial = "AAA"
    while initial != "ZZZ":
        if pattern[idx] == 'L':
            initial = map[initial][0]
        else:
            initial = map[initial][1]
        idx += 1
        step += 1
        idx = idx % len(pattern)
    return step


def steps_ultill_ending_z(map, initial):
    idx = 0
    step = 0
    while initial[-1] != 'Z':
        if pattern[idx] == 'L':
            initial = map[initial][0]
        else:
            initial = map[initial][1]
        idx += 1
        step += 1
        idx = idx % len(pattern)
    return step


f = open(FILE_NAME, "r")
lines = f.readlines()

pattern = lines[0][:-1]
map = {}

for l in lines[2:]:
    splitted = l.split()
    map[splitted[0]] = [splitted[2][1:-1], splitted[3][:-1]]

print("pt1:", steps_untill_all_z(map))

list_steps = []
for m in map:
    if m[-1] == 'A':
        list_steps.append(steps_ultill_ending_z(map, m))

lcm = 1
for i in list_steps:
    lcm = lcm * i // gcd(lcm, i)

print("pt2:", lcm)
