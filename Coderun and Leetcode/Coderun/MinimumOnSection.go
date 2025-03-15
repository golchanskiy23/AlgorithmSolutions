package main

import (
	"bufio"
	"fmt"
	"os"
	"container/list"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	fmt.Fscan(reader, &n, &k)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	// Двусторонняя очередь для хранения индексов
	deque := list.New()

	// Для каждого окна
	for i := 0; i < n; i++ {
		// Убираем элементы, которые не принадлежат окну
		if deque.Len() > 0 && deque.Front().Value.(int) <= i-k {
			deque.Remove(deque.Front())
		}

		// Убираем все элементы, которые больше текущего, чтобы сохранить минимум в начале
		for deque.Len() > 0 && arr[deque.Back().Value.(int)] >= arr[i] {
			deque.Remove(deque.Back())
		}

		// Добавляем текущий элемент в очередь
		deque.PushBack(i)

		// Выводим минимум в окне, если окно полностью заполнено
		if i >= k-1 {
			fmt.Fprintln(writer, arr[deque.Front().Value.(int)])
		}
	}
}