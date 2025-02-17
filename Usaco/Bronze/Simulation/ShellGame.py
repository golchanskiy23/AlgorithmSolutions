import sys
read = open("shell.in")

n = int(read.readline())
#n = int(sys.stdin.readline())
arr = [0,1,2]
ans = [0,0,0]
for _ in range(0,n):
    a, b, c = [int(i)-1 for i in read.readline().split()]
    arr[a], arr[b] = arr[b], arr[a]
    ans[arr[c]] += 1
answer = max(max(ans[0],ans[1]), ans[2]);
#print(answer)
print(answer, file=open("shell.out", "w"))