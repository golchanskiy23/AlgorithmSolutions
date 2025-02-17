import sys
read = open("mixmilk.in")

max_, curr = [0 for _ in range(0,3)], [0 for _ in range(0,3)]
for i in range(0,3):
    str = read.readline().split()
    max_[i], curr[i] = int(str[0]), int(str[1])

for i in range(0,100):
    if max_[(i+1)%3]-curr[(i+1)%3] >= curr[i%3]:
        curr[(i+1)%3] += curr[i%3]
        curr[i%3] = 0
    else:
        curr[i%3] -= (max_[(i+1)%3]-curr[(i+1)%3])
        curr[(i+1)%3] = max_[(i+1)%3]
with open("mixmilk.out", "w") as out:
	for m in curr:
		print(m, file=out)