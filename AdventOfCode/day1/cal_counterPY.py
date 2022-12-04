with open('/home/noona/Documents/myhtmls/AdventOfCode/day1/file.txt', 'r') as file:
	lines = file.readlines()

current = 0
max = 0

for line in lines:
	if line != '\n':
		current += int(line)
	else:
		if current > max:
			max = current
		current = 0
print("max is: ")
print(max)
