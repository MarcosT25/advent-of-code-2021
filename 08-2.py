def decode(entry_list):
    decoded_list = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    while len(entry_list) > 0:
        for number in entry_list:
            if len(entry_list) == 1:
                decoded_list[0] = number
                entry_list.pop(entry_list.index(number))
            if len(number) == 2:
                decoded_list[1] = number
                entry_list.pop(entry_list.index(number))
            if len(number) == 3:
                decoded_list[7] = number
                entry_list.pop(entry_list.index(number))
            if len(number) == 4:
                decoded_list[4] = number
                entry_list.pop(entry_list.index(number))
            if len(number) == 7:
                decoded_list[8] = number
                entry_list.pop(entry_list.index(number))
            if len(number) == 5:
                if decoded_list[6] != 0:
                    sum = 0
                    for char in number:
                        if decoded_list[6].find(char) >= 0:
                            sum += 1
                    if sum == 5:
                        decoded_list[5] = number
                        entry_list.pop(entry_list.index(number))
                        break
                if decoded_list[1] != 0 and decoded_list[5] != 0:
                    top_right = decoded_list[1][0]
                    bottom_right = decoded_list[1][1]
                    if number.find(top_right) == -1 or number.find(bottom_right) == -1:
                        decoded_list[2] = number
                        entry_list.pop(entry_list.index(number))
                    else:
                        decoded_list[3] = number
                        entry_list.pop(entry_list.index(number))
            if len(number) == 6:
                if decoded_list[4] != 0:
                    sum = 0
                    for char in decoded_list[4]:
                        if number.find(char) >= 0:
                            sum += 1
                    if sum == 4:
                        decoded_list[9] = number
                        entry_list.pop(entry_list.index(number))
                if decoded_list[1] != 0:
                    top_right = decoded_list[1][0]
                    bottom_right = decoded_list[1][1]
                    if number.find(top_right) == -1 or number.find(bottom_right) == -1:
                        decoded_list[6] = number
                        entry_list.pop(entry_list.index(number))
    return decoded_list

file = open('08.in', 'r')
sum = 0
for line in file:
    entry = line[0:line.find('|')].split()
    output = line[line.find('|') + 2:].split()
    decoded = decode(entry)
    for i in range(4):
        for number in decoded:
            if sorted(output[i]) == sorted(number):
                sum += decoded.index(number) * pow(10, 3 - i)
print(sum)