FILE_NAME = "input.txt"


def first_digit(s):
    for c in s:
        if c.isdigit():
            return int(c)


def last_digit(s):
    s = s[::-1]
    return first_digit(s)


digits = {"one": 1, "two": 2, "three": 3, "four": 4, "five": 5, "six": 6, "seven": 7, "eight": 8, "nine": 9}
digits_backwords = {}
for d in digits.keys():
    digits_backwords[d[::-1]] = digits[d]


def digit_word(s, d):
    for i in range(len(s)):
        if s[i].isdigit():
            return int(s[i])

        for j in d:
            if s[i:i + len(j)] == j:
                return d[j]
    print("error")
    return 0


f = open(FILE_NAME, "r")

lines = f.readlines()
sum = 0
for l in lines:
    sum += first_digit(l) * 10 + last_digit(l)
print("pt 1:", sum)

f.seek(0)
lines = f.readlines()
sum = 0
for l in lines:
    sum += digit_word(l, digits) * 10 + digit_word(l[::-1], digits_backwords)
print("pt 2: ", sum)
