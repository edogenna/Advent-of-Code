import math

FILE_NAME = "input.txt"
f = open(FILE_NAME, "r")
lines = f.readlines()


def numbers_solutions(t, d):
    rad_delta = math.sqrt(t ** 2 - 4 * d)
    x_1 = math.ceil((t + rad_delta) / 2) - 1
    x_2 = math.floor((t - rad_delta) / 2) + 1
    return x_1 - x_2 + 1


times = list(map(int, lines[0].split()[1:]))
distances = list(map(int, lines[1].split()[1:]))

n = 1
for t, d in zip(times, distances):
    n *= numbers_solutions(t, d)

print("pt1:", n)

time_tot = int(''.join(lines[0].split()[1:]))
distance_tot = int(''.join(lines[1].split()[1:]))

print("pt2:", numbers_solutions(time_tot, distance_tot))
