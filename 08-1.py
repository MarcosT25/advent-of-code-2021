file = open('08.in', 'r')
sum = 0
for line in file:
    numbers = line[line.find('|') + 2:].split()
    for number in numbers:
        if len(number) == 2 or len(number) == 3 or len(number) == 4 or len(number) == 7:
            sum += 1
print(sum)