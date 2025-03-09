import sys


def main():
    s = input()
    try:
        print(eval(s))
    except:
        print('WRONG')



if __name__ == '__main__':
    main()