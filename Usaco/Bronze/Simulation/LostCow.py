import sys

read = open("lostcow.in")

def greater(a: int, b: int)->int:
    distance, curr_pos, before  = 0, 1, a
    while True:
        after = a + curr_pos
        if after >= b > before or after <= b < before:
                distance += abs(b-before)
                break
        distance += abs(after-before)
        before = after
        curr_pos = curr_pos*(-2)
    return distance
 
def solution(a: int, b:int)->int:
    if a == b:
        return 0
    return greater(a,b)

a,b=map(int, read.readline().split())
print(solution(a,b), file=open("lostcow.out", "w"))
