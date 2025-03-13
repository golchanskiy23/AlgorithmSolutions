package main

import (
    "fmt"
    "bufio"
    "os"
    "strings"
)

type Stack struct {
	elements []rune
}

func (s *Stack) Push(element rune) {
	s.elements = append(s.elements, element)
}

func (s *Stack) Pop() (rune, bool) {
	if len(s.elements) == 0 {
		return 0, false
	}
	index := len(s.elements) - 1
	element := s.elements[index]
	s.elements = s.elements[:index]
	return element, true
}

func (s *Stack) Peek() (rune, bool) {
	if len(s.elements) == 0 {
		return 0, false
	}
	return s.elements[len(s.elements)-1], true
}

func (s *Stack) IsEmpty() bool {
	return len(s.elements) == 0
}

func (s *Stack) Size() int {
	return len(s.elements)
}

func main(){
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	s := []rune(input)
	stack := &Stack{}
	chars := map[rune]rune{')':'(', ']':'[','}':'{'}
	//fmt.Print(input)
	//strNumbers := strings.Split(input, " ")
	for i := 0; i < len(s); i++{
	    if stack.IsEmpty(){
	        stack.Push(s[i])
	        continue
	    }
	    c , _ := stack.Peek()
	    if c == chars[s[i]] {
	        stack.Pop()
	    } else {
	        stack.Push(s[i])
	    }
	}
	
	if stack.IsEmpty(){
	    fmt.Fprintln(writer, "yes")
	} else{
	    fmt.Fprintln(writer, "no")
	}
}