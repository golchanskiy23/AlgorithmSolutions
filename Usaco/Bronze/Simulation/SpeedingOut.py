import sys
read = open("speeding.in")

s = read.readline().split()
m, n = int(s[0]), int(s[1])

# Ограничения скорости и скорость коровы на каждом километре
limit = [0] * 101
cow_speed = [0] * 101

last_position = 0
for _ in range(m):
    q, w = map(int, read.readline().split())
    for j in range(last_position, last_position + q):
        limit[j] = w
    last_position += q  # Перемещаемся дальше

last_position = 0
for _ in range(n):
    q, w = map(int, read.readline().split())
    for j in range(last_position, last_position + q):
        cow_speed[j] = w
    last_position += q  # Перемещаемся дальше


# Находим максимальное превышение скорости
answer = max(max(0, cow_speed[i] - limit[i]) for i in range(100))

with open("speeding.out", "w") as write:
    write.write(f"{answer}\n")
