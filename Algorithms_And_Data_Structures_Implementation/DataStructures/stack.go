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