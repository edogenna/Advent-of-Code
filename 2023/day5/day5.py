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
positions = []

for i in range(NUM_MAPS):
    positions.append([])

for i in lines[0].split()[1:]:
    initials.append(int(i))

'''
for i in range(0, len(initials), 2):
    for j in range(initials[i+1]):
        initials_2.append(initials[i] + j)
print("DONE INITIALS 2")

'''


#building the maps
current_map = -1
for i in lines[2:]:
    split = i.split()
    if not split:
        continue
    elif split[0].isnumeric():
        positions[current_map].append(Position(int(split[0]), int(split[1]), int(split[2])))
    else:
      current_map += 1


new_destination = []
initials1 = initials
for map in range(NUM_MAPS):
    for i in initials1:
        destination_i = i
        for j in positions[map]:
            if j.source <= i < j.source + j.range:
                destination_i = - j.source + j.destination + i
                break
        new_destination.append(destination_i)
    initials1 = new_destination
    new_destination = []


print("pt1: ", min(initials1))

def exists_initial(location):
    for map in range(NUM_MAPS-1,-1,-1):
        source = location
        for j in positions[map]:
            if j.destination <= location < j.destination + j.range:
                source = location - j.destination + j.source
                break
        location = source

    for i in range(0,len(initials),2):
        if initials[i] <= location < initials[i] + initials[i+1]:
            return True

    return False

min_range = positions[0][0].range
for map in range(NUM_MAPS):
    for j in positions[map]:
        if j.range < min_range:
            min_range = j.range

min_location = 0
while not exists_initial(min_location):
    min_location += 42890

while exists_initial(min_location):
    min_location -= 1

min_location += 1

print("pt2:",min_location)
