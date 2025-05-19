package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func InputN(scanner *bufio.Reader) int {
	nLine, _ := scanner.ReadString('\n')
	nLine = strings.TrimSpace(nLine)
	n, _ := strconv.Atoi(nLine)
	return n
}

func InputNArray(scanner *bufio.Reader) []int {
	str, _ := scanner.ReadString('\n')
	str = strings.TrimSpace(str)
	nums := strings.Split(str, " ")
	var arr = make([]int, 0)
	for i := 0; i < len(nums); i++ {
		num, _ := strconv.Atoi(nums[i])
		arr = append(arr, num)
	}
	return arr
}

type MinStack struct {
	buff, minBuff []int
	len           int
}

func Min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func (stack *MinStack) Push(i int) {
	if stack.len == 0 {
		stack.minBuff = append(stack.minBuff, i)
		stack.buff = append(stack.buff, i)
		stack.len++
		return
	}
	minNum := Min(stack.minBuff[stack.len-1], i)
	stack.minBuff = append(stack.minBuff, minNum)
	stack.buff = append(stack.buff, i)
	stack.len++
}

func (stack *MinStack) Pop() {
	stack.buff = stack.buff[:stack.len-1]
	stack.minBuff = stack.minBuff[:stack.len-1]
	stack.len--
}

func (stack MinStack) Top() int {
	return stack.buff[stack.len-1]
}

func (stack MinStack) Min() int {
	return stack.minBuff[stack.len-1]
}

func (stack MinStack) Empty() bool {
	return stack.len == 0
}

// 1 - add , 2 - delete, 3 - min
func task1() {
	scanner := bufio.NewReader(os.Stdin)
	n := InputN(scanner)
	stack := &MinStack{}
	for i := 0; i < n; i++ {
		line := InputNArray(scanner)
		switch line[0] {
		case 1:
			stack.Push(line[1])
		case 2:
			stack.Pop()
		case 3:
			fmt.Println(stack.Min())
		}
	}
}

func task2() int {
	scanner := bufio.NewReader(os.Stdin)
	arr := InputNArray(scanner)
	stack1, stack2 := &MinStack{}, &MinStack{}
	i := 0
	for i < len(arr) {
		currElem := arr[i]
		ptr := 0
		for !stack2.Empty() && stack2.Top() == currElem {
			stack1.Push(currElem)
			ptr++
			stack2.Pop()
		}

		for i < len(arr) && arr[i] == currElem {
			stack1.Push(arr[i])
			ptr++
			i++
		}

		if ptr < 3 {
			for !stack1.Empty() && ptr > 0 {
				stack2.Push(currElem)
				stack1.Pop()
				ptr--
			}
		}
	}
	return stack1.len
}

type Deque struct {
	idArr, sortedArr []int
	translator       map[int]int
	len, UUID        int
}

func find(arr []int, id int) int {
	l, r := 0, len(arr)-1
	for l <= r {
		mid := l + (r-l)/2
		if arr[mid] == id {
			return mid
		} else if arr[mid] > id {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return -1
}

func (d *Deque) pushBack(id int) {
	d.idArr = append(d.idArr, id)
	d.translator[id] = d.UUID
	d.len++
	d.UUID++
	d.sortedArr = append(d.sortedArr, d.translator[id])
}

func (d *Deque) popFront() {
	d.idArr = d.idArr[1:]
	d.sortedArr = d.sortedArr[1:]
	d.len--
}

func (d *Deque) popBack() {
	d.idArr = d.idArr[:d.len-1]
	d.sortedArr = d.sortedArr[:d.len-1]
	d.len--
}

func (d Deque) beforeId(id int) int {
	return find(d.sortedArr, d.translator[id])
}

func (d Deque) Front() int {
	return d.idArr[0]
}

func (d *Deque) PushFront(val int) {
	d.idArr = append([]int{val}, d.idArr...)
	d.len++
}

// 1 - pushBack(id)
// 2 - popFront()
// 3 - popBack
// 4 - beforeId(id) int
// 5 - Front() int
func task3() {
	scanner := bufio.NewReader(os.Stdin)
	n := InputN(scanner)
	deque := &Deque{translator: make(map[int]int)}
	for i := 0; i < n; i++ {
		arr := InputNArray(scanner)
		switch arr[0] {
		case 1:
			deque.pushBack(arr[1])
		case 2:
			deque.popFront()
		case 3:
			deque.popBack()
		case 4:
			fmt.Println(deque.beforeId(arr[1]))
		case 5:
			fmt.Println(deque.Front())
		}
	}
}

func task4() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Быстрое считывание чисел
	readInt := func() int {
		scanner.Scan()
		val, _ := strconv.Atoi(scanner.Text())
		return val
	}

	readChar := func() byte {
		scanner.Scan()
		return scanner.Text()[0]
	}

	n := readInt()
	left := &Deque{translator: make(map[int]int)}
	right := &Deque{translator: make(map[int]int)}

	for i := 0; i < n; i++ {
		op := readChar()
		if op == '+' {
			num := readInt()
			right.pushBack(num)
		} else if op == '*' {
			num := readInt()
			right.PushFront(num)
		} else { // op == '-'
			fmt.Println(left.Front())
			left.popFront()
		}

		if left.len < right.len {
			left.pushBack(right.Front())
			right.popFront()
		}
	}
}

func task5() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str := scanner.Text()
	tokens := strings.Split(str, " ")
	stack := &MinStack{}
	for _, token := range tokens {
		if num, err := strconv.Atoi(token); err == nil {
			stack.Push(num)
		} else {
			f := stack.Top()
			stack.Pop()
			s := stack.Top()
			stack.Pop()
			switch token {
			case "+":
				stack.Push(s + f)
			case "-":
				stack.Push(s - f)
			case "*":
				stack.Push(s * f)
			}
		}
	}
	return stack.Top()
}

func isSorted(arr []int) bool {
	curr := arr[0]
	for i := 1; i < len(arr); i++ {
		if arr[i] < curr {
			return false
		}
		curr = arr[i]
	}
	return true
}

func task6() {
	scanner := bufio.NewReader(os.Stdin)
	n := InputN(scanner)
	arr := InputNArray(scanner)
	stack1, stack2 := &MinStack{}, &MinStack{}
	for i := n - 1; i >= 0; i-- {
		stack1.Push(arr[i])
	}
	ans, sortedArr := make([]string, 0), make([]int, 0)

	for !stack1.Empty() {
		curr := stack1.Top()
		if stack2.Empty() || curr <= stack2.Top() {
			ans = append(ans, "push")
			stack2.Push(stack1.Top())
			stack1.Pop()
		} else {
			for !stack2.Empty() && curr > stack2.Top() {
				ans = append(ans, "pop")
				sortedArr = append(sortedArr, stack2.Top())
				stack2.Pop()
			}
		}
	}

	for !stack2.Empty() {
		sortedArr = append(sortedArr, stack2.Top())
		stack2.Pop()
		ans = append(ans, "pop")
	}

	if isSorted(sortedArr) {
		for _, str := range ans {
			fmt.Println(str)
		}
	} else {
		fmt.Println("impossible")
	}
}

type DSUNode struct {
	Parent, Rank, MinElement, MaxElement, CountElement int
}

func NewDSUNode(i int) DSUNode {
	return DSUNode{
		Parent:       i,
		Rank:         0,
		MinElement:   i,
		MaxElement:   i,
		CountElement: 1,
	}
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func Find(dsu []DSUNode, v int) int {
	if v == dsu[v].Parent {
		return v
	}
	dsu[v].Parent = Find(dsu, dsu[v].Parent)
	return dsu[v].Parent
}

func Union(dsu []DSUNode, a, b int) {
	a, b = Find(dsu, a), Find(dsu, b)
	if a != b {
		if dsu[a].Rank < dsu[b].Rank {
			a, b = b, a
		}
		if dsu[a].Rank == dsu[b].Rank {
			dsu[a].Rank += 1
		}

		dsu[b].Parent = a
		dsu[a].MinElement = Min(dsu[a].MinElement, dsu[b].MinElement)
		dsu[a].MaxElement = Max(dsu[a].MaxElement, dsu[b].MaxElement)
		dsu[a].CountElement += dsu[b].CountElement
	}
}

func task7() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())

	dsu := make([]DSUNode, num+1)
	for i := 1; i <= num; i++ {
		dsu[i] = NewDSUNode(i)
	}
	for scanner.Scan() {
		line := strings.TrimSpace(scanner.Text())
		if line == "" {
			break
		}
		tokens := strings.Fields(line)
		if len(tokens) == 0 {
			continue
		}
		a1, _ := strconv.Atoi(tokens[1])
		switch tokens[0] {
		case "get":
			node := dsu[Find(dsu, a1)]
			fmt.Println(node.MinElement, node.MaxElement, node.CountElement)

		case "union":
			a2, _ := strconv.Atoi(tokens[2])
			Union(dsu, a1, a2)
		}
	}
}

type DsuNode struct {
	parent int
	rank   int
	teamxp int
}

func NewDsuNode(i int) DsuNode {
	return DsuNode{
		parent: i,
		rank:   0,
		teamxp: 0,
	}
}

func dsuGet(dsu []DsuNode, v int) (int, int) {
	if v == dsu[v].parent {
		return v, 0
	}
	root, delta := dsuGet(dsu, dsu[v].parent)
	dsu[v].parent = root
	dsu[v].teamxp += delta
	return dsu[v].parent, dsu[v].teamxp
}

func dsuUnion(dsu []DsuNode, a, b int) {
	ra, xpa := dsuGet(dsu, a)
	rb, xpb := dsuGet(dsu, b)
	if ra != rb {
		if dsu[ra].rank < dsu[rb].rank {
			ra, rb = rb, ra
			xpa, xpb = xpb, xpa
		}
		if dsu[ra].rank == dsu[rb].rank {
			dsu[ra].rank++
		}
		dsu[rb].parent = ra
		dsu[rb].teamxp -= dsu[a].teamxp
	}
}

func dsuAdd(dsu []DsuNode, a, val int) {
	root, _ := dsuGet(dsu, a)
	dsu[root].teamxp += val
}

func task8() {
	scanner := bufio.NewReader(os.Stdin)
	arr := InputNArray(scanner)
	n, m := arr[0], arr[1]
	dsu := make([]DsuNode, n+1)
	for i := 1; i <= n; i++ {
		dsu[i] = NewDsuNode(i)
	}

	for i := 0; i < m; i++ {
		line, _ := scanner.ReadString('\n')
		line = strings.TrimSpace(line)
		tokens := strings.Split(line, " ")
		x, _ := strconv.Atoi(tokens[1])

		switch tokens[0] {
		case "join":
			y, _ := strconv.Atoi(tokens[2])
			dsuUnion(dsu, x, y)

		case "add":
			v, _ := strconv.Atoi(tokens[2])
			dsuAdd(dsu, x, v)

		case "get":
			root, _ := dsuGet(dsu, x)
			xp := dsu[x].teamxp
			if root != x {
				xp += dsu[root].teamxp
			}
			fmt.Println(xp)
		}
	}
}

func main() {
	task8()
}
