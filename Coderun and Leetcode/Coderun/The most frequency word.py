import sys

def main():
    text = sys.stdin.read().strip()
    words = text.split()
    freq = {}

    for word in words:
        freq[word] = freq.get(word, 0) + 1

    max_count = 0
    best_word = ""

    for word, count in freq.items():
        if count > max_count or (count == max_count and word < best_word):
            max_count = count
            best_word = word

    print(best_word)



if __name__ == "__main__":
    main()