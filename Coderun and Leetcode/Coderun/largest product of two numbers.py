import sys

def main():
    # Чтение данных и преобразование элементов в числа
    a = list(map(int, sys.stdin.readline().split()))
    
    # Сортировка списка
    a.sort()
    
    # Вычисление максимального произведения
    if a[0] * a[1] >= a[-1] * a[-2]:
        print(str(a[0])+" "+str(a[1]))
    else:
        print(str(a[-2])+" "+str(a[-1]))
    #ans = max(a[0] * a[1], a[-1] * a[-2])
    
    # Вывод результата
    #print(ans)

if __name__ == '__main__':
    main()