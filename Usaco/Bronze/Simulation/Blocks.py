import sys

read = open("blocks.in")
alphabet = [0]*26
n = int(read.readline())
for i in range(0, n):
    a, b = map(str, read.readline().split())
    s = set()
    for j in a:
        s.add(j)
    for j in b:
        s.add(j)
    for t in s:
        alphabet[ord(t) - ord('a')] += 1

with open("blocks.out", "w") as file:
    for i in alphabet:
        file.write(str(i) + '\n')
