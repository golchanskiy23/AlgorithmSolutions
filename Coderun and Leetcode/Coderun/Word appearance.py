import sys


def main():
    m = {}
    x = sys.stdin.read().strip().split()
    for i in x:
        if i not in m:
            print("0 ")
            m[i] = 0
        else:
            m[i] = m.get(i,0)+1
            print(str(m[i]) + " ")
    




if __name__ == '__main__':
    main()