
def check_subroutine(arr):
	for i in arr:
		if arr.count(i) > 1:
			return 1

	return 0

def rec_find_routine(arr, index):
	while check_subroutine(arr) != 0:
		arr.pop(0)
		arr.append(text[index])
		index += 1
		
	print(arr)
	return index



with open("./file.txt", "r") as f:
	text = f.read()

arr = []
index = 0

for i in range(0, 14):
	arr.append(text[i])
	index += 1

print(rec_find_routine(arr, index))