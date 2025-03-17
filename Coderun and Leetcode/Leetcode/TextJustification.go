func justify(line []string, lineLen, maxWidth int) string{
    if len(line) == 1{
        return line[0]+strings.Repeat(" ", maxWidth-lineLen)
    }
    var sb strings.Builder
    totalSpaces, positions := maxWidth-lineLen, len(line)-1
    spaces, extraSpaces := totalSpaces/positions, totalSpaces%positions
    for i,  val := range line{
        sb.WriteString(val)
        if i < positions{
            sb.WriteString(strings.Repeat(" ", spaces))
            if extraSpaces > 0{
                sb.WriteString(" ")
                extraSpaces--
            }
        }
    }
    return sb.String()
}

func fullJustify(words []string, maxWidth int) []string {
    var result,line []string
    lineLen := 0

    for _,word := range words{
        if lineLen+len(word)+len(line) > maxWidth{
            result = append(result, justify(line,lineLen,maxWidth))
            lineLen = 0
            line = []string{}
        }
        line = append(line, word)
        lineLen += len(word)
    }

    lastline := strings.Join(line, " ")
    lastline += strings.Repeat(" ",maxWidth-len(lastline))
    result = append(result, lastline)
    return result
}