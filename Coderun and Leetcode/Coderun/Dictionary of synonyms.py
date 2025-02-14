import sys


def main():
    m1 = {}
    m2 = {}
    n, i = int(input()), 0
    while i < n:
        b = input().split()
        m1[b[0]] = b[1]
        m2[b[1]] = b[0]
        i += 1
    c = input()
    if c in m1:
        print(m1[c])
    else:
        print(m2[c])


if __name__ == '__main__':
    main()