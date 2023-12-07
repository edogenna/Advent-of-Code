from functools import cmp_to_key

FILE_NAME = "input.txt"
ORDER = ['A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2']
ORDER2 = ['A', 'K', 'Q', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'J']
'''
A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, 2
12,11,10,9, 8, 7, ..              , 0

'''

f = open(FILE_NAME, "r")
lines = f.readlines()


def sort_same_type_hand(h1, h2):
    h1 = h1[0]
    h2 = h2[0]

    for i, j in zip(h1, h2):
        p1 = 12-ORDER.index(i)
        p2 = 12-ORDER.index(j)
        if p1 > p2:
            return 1
        elif p1 < p2:
            return -1

    return 0

def sort_same_type_hand2(h1, h2):
    h1 = h1[0]
    h2 = h2[0]

    for i, j in zip(h1, h2):
        p1 = 12-ORDER2.index(i)
        p2 = 12-ORDER2.index(j)
        if p1 > p2:
            return 1
        elif p1 < p2:
            return -1

    return 0


'''
7 Five of a kind, where all five cards have the same label: AAAAA
6 Four of a kind, where four cards have the same label and one card has a different label: AA8AA
5 Full house, where three cards have the same label, and the remaining two cards share a different label: 23332
4 Three of a kind, where three cards have the same label, and the remaining two cards are each different from any other card in the hand: TTT98
3 Two pair, where two cards share one label, two other cards share a second label, and the remaining card has a third label: 23432
2 One pair, where two cards share one label, and the other three cards have a different label from the pair and each other: A23A4
1 High card, where all cards' labels are distinct: 23456
'''


def type_hand(h):
    h = h[0]
    count = []
    for i in range(13):
        count.append(0)
    for i in h:
        count[12-ORDER.index(i)] += 1
    m = max(count)

    if m > 3:
        return m + 2

    if m == 3:
        if 2 in count:
            return 5  # full house
        return 4  # three of a kind

    if m == 2 and count.count(m) == 2:
        return 3  # two pair

    return m

def type_hand2(h):
    type = type_hand(h)
    js = h[0].count('J')
    if js == 0 or js == 5:
        return type

    #type 7 is the best in any case
    if type == 6 or type == 5: #CCCCJ or CCCJJ or CCJJJ -> CCCCC
        return 7

    if type == 4: #CCCDJ or JJJCD -> CCCCD
        return 6

    if type == 3:
        if js == 2:
            return 6 #JJCDD -> CDDDD
        return 5 #CCDDJ -> CCCDD

    if type == 2: #CCDFJ or JJCDF -> CCCDF
        return 4

    if type == 1: #CDFGJ -> CCDFG
        return 2

def sort_hand(h1, h2):
    d = type_hand(h1) - type_hand(h2)
    if d == 0:
        return sort_same_type_hand(h1, h2)
    return d

def sort_hand2(h1, h2):
    d = type_hand2(h1) - type_hand2(h2)
    if d == 0:
        return sort_same_type_hand2(h1, h2)
    return d


cards = {}
for l in lines:
    splitted = l.split()
    cards[splitted[0]] = splitted[1]


sort = cards
sort = sorted(sort.items(), key=cmp_to_key(sort_hand))
sum = 0
for idx, c in enumerate(sort):
    sum += int(c[1]) * (idx+1)

print("p1:", sum)

sort2 = cards
sort2 = sorted(sort2.items(), key=cmp_to_key(sort_hand2))
sum = 0
for idx, c in enumerate(sort2):
    sum += int(c[1]) * (idx+1)

print("p2:", sum)