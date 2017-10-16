import sys

def break_every_n(text, n=80):
    words = text.split(' ')
    chars = 0
    text = ""
    for word in words:
        wlen = len(word)
        not_too_many_chars = (chars + wlen + 1) < n
        no_newlines = ("\n" not in word)
        if (not_too_many_chars and no_newlines):
            chars += (wlen + 1)
            text += word + " "
        else:
            if "\n" in word:
                subwords = word.split("\n")
                for i in subwords[:-1]:
                    text += i
                new_text = "\n" + subwords[-1] + " "
            else:
                new_text = word + " "
            text += "\n" + new_text
            chars = len(new_text)
    print(text.strip(" "))


if __name__ == '__main__':
    break_every_n(sys.argv[1])
