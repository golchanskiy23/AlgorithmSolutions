package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func max(left int, right int) int{
    if left > right{
        return left
    }
    return right
}

type Node struct{
    Val int
    Left *Node
    Right *Node
}

func insert(root *Node, value int) *Node{
    if root == nil{
        return &Node{
            Val : value,
            Left : nil,
            Right : nil,
        }
    }
    if(value < root.Val){
        root.Left = insert(root.Left, value)
    } else if value > root.Val {
        root.Right = insert(root.Right, value)
    }

    return root
}

func height(root *Node, depth int) int{
    if root == nil{
        return depth
    }
    return 1+max(height(root.Left, depth), height(root.Right, depth))
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	strNumbers := strings.Split(input, " ")

    var tree *Node = nil
    
    for _, val := range strNumbers{
        num, _ := strconv.Atoi(val)
        if num == 0{
            break
        }
        tree = insert(tree, num)
    }
    
    fmt.Fprintln(writer, height(tree,0))
}