type MinStack struct {
    Stack, MinSlice []int
}


func Constructor() MinStack {
    return MinStack{
        Stack : make([]int, 0),
        MinSlice : make([]int, 0),
    }
}

func min(a, b int) int{
    if a < b {return a}
    return b
}

func (this *MinStack) Push(val int)  {
       if len(this.Stack) == 0{
            this.MinSlice = append(this.MinSlice, val)
       } else{
            currLength := len(this.MinSlice)
            m := min(this.MinSlice[currLength-1], val)
            this.MinSlice = append(this.MinSlice, m)
       }
       this.Stack = append(this.Stack, val)
}


func (this *MinStack) Pop()  {
    n := len(this.Stack)
    this.Stack, this.MinSlice = this.Stack[:n-1], this.MinSlice[:n-1]
}


func (this *MinStack) Top() int {
    return this.Stack[len(this.Stack)-1]
}


func (this *MinStack) GetMin() int {
    return this.MinSlice[len(this.MinSlice)-1]
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */