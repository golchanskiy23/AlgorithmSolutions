type Queue struct {
    items []int
}

func (q *Queue) Push(item int) {
    q.items = append(q.items, item)
}

func (q *Queue) Pop() int {
    if len(q.items) == 0 {
        panic("Queue is empty")
    }

    item := q.items[0]
    q.items = q.items[1:]
    return item
}

func (q Queue) Front() int {
    if len(q.items) == 0 {
        panic("Queue is empty")
    }
    return q.items[0]
}

func (q Queue) IsEmpty() bool {
    return len(q.items) == 0
}