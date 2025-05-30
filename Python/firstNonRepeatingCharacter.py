print("Which string do you want to find the first non-repeating character?:\n")
inputString = input()

char_count = {}
for char in inputString:
    char_count[char] = char_count.get(char, 0) + 1

for key, value in char_count.items():
    if (value == 1):
        print(f'First non-repeating character: {key}')
        break;
