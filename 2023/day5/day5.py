FILE_NAME = "input.txt"
NUM_MAPS = 7

class Position:
    def __init__(self, destination, source, range):
        self.destination = destination
        self.source = source
        self.range = range

    def __repr__(self):
        return f"<destination:{self.destination} source:{self.source} range:{self.range}>"


f = open(FILE_NAME, "r")

lines = f.readlines()
sum = 0

initials = []
initials_2 = []
positions = []
print("a")
for i in range(NUM_MAPS):
    positions.append([])

for i in lines[0].split()[1:]:
    initials.append(int(i))

for i in range(0, len(initials), 2):
    for j in range(initials[i+1]):
        initials_2.append(initials[i] + j)

current_map = -1
for i in lines[2:]:
    splitted = i.split()
    if not splitted:
        continue
    elif splitted[0].isnumeric():
        positions[current_map].append(Position(int(splitted[0]), int(splitted[1]), int(splitted[2])))
    else:
      current_map += 1


new_destination = []
for map in range(NUM_MAPS):
    for i in initials:
        destination_i = i
        for j in positions[map]:
            if j.source <= i < j.source + j.range:
                destination_i = - j.source + j.destination + i
                break
        new_destination.append(destination_i)
    initials = new_destination
    new_destination = []


print("pt1: ", min(initials))



new_destination = []
for map in range(NUM_MAPS):
    for i in initials_2:
        destination_i = i
        for j in positions[map]:
            if j.source <= i < j.source + j.range:
                destination_i = - j.source + j.destination + i
                break
        new_destination.append(destination_i)
    initials_2 = new_destination
    new_destination = []
    print("DONE MAP", map)


print("pt2: ", min(initials_2))


print("END")
