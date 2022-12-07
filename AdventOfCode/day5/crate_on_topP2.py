import re
with open("./file.txt", "r") as f:
	lines = f.readlines();

crates = [
	['H', 'R', 'B', 'D', 'Z', 'F', 'L', 'S'],
	['T', 'B', 'M', 'Z', 'R'],
	['Z', 'L', 'C', 'H', 'N', 'S'],
	['S', 'C', 'F', 'J'],
	['P', 'G', 'H', 'W', 'R', 'Z', 'B'],
	['V', 'J', 'Z', 'G', 'D', 'N', 'M', 'T'],
	['G',  'L', 'N', 'W', 'F', 'S', 'P', 'Q'],
	['M', 'Z', 'R'],
	['M', 'C', 'L', 'G', 'V', 'R', 'T']
]

arr = []
def move_crates(amount, from_val, to_val):
	while(amount > 0):
		crates[to_val].append(crates[from_val].pop(amount * -1))
		amount -= 1
	print(crates)

""" def move_crates(amount, from_val, to_val):
	if(amount > 1):
		move_crates(amount - 1, from_val, to_val)
	crates[to_val].append(crates[from_val].pop(-1))
	print(crates)
 """


for line in lines:
	#temp.append(line.search(pattern).)
	result = re.search(r"move (\d+) from (\d?) to (\d?)\n", line)
	if(result):
		arr.append([int(i) for i in result.groups()])

print(arr)
for values in arr:
	move_crates(values[0], values[1] - 1, values[2] - 1);

for i in crates:
	print(i[-1])