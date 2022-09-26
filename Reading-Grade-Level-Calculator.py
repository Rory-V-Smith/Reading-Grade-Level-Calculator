from cs50 import get_string
import re

# get text from user    
text = get_string("Text: ")

# count alphabetical characters
letter_count = len(re.findall("[a-zA-Z]", text))
print(f"letter(s): {letter_count}")

# count words (deliniated by spaces)
word_count = len(re.findall("\s", text)) + 1  # + 1 to account for words finishing with a comma for full-stop
print(f"word(s): {word_count}")

# count sentances
sentence_count = len(re.findall("[.|!|?]", text))
print(f"sentence(s): {sentence_count}")

# Coleman-Liau index
L = letter_count / word_count * 100
S = sentence_count / word_count * 100

# determine grade
grade = round(0.0588 * L - 0.296 * S - 15.8)

# print grade
if grade > 15:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")
