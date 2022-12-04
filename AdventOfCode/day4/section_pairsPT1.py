with open('file.txt', 'r') as f:
	lines = f.readlines()

count = 0

for line in lines:
	elves = line.split(',')
	elf1 = [int(i) for i in elves[0].split('-')]
	elf2 = [int(i) for i in elves[1].split('-')]

	if(elf1[0] <= elf2[0] and elf1[1] >= elf2[1]):
		count += 1
	elif(elf2[0] <= elf1[0] and elf2[1] >= elf1[1]):
		count += 1

print(count)