
array = [[1,2,3,4,5],
		[6,7,8,9,10],
		[11,12,13,14,15],
		[16,17,18,19,20],
		[21,22,23,24,25]]

def top(array):
	top_snail = []
	for index in range(int(len(array)/2 + 1/2)):
		top_snail.append(array[index][index:len(array[0])-index])

	return top_snail

def bottom(array):
	bot_snail = []
	for index in range(len(array) - 1, int(len(array)/2) - 1, -1):
		row_list = array[index][len(array[0]) - 1 - index: index + 1]
		row_list.reverse()
		bot_snail.append(row_list)

	return bot_snail

def right_side(array):
	r_snail = []
	for index in range(len(array[0]) - 1, int(len(array[0])/2) - 1, -1):
		buf = []
		for row in array[len(array) - 1 - index + 1: index + 1 - 1]:
			buf.append(row[index])
		r_snail.append(buf)
	
	return r_snail

def left_side(array):
	l_side = []
	for index in range(int(len(array[0])/2 + 1/2)):
		buf = []
		for row in array[index + 1: len(array) - index - 1]:
			buf.append(row[index])
		buf.reverse()
		l_side.append(buf)
	return l_side

def snail(array):
	snail = []

	if array == [[]]:
		return []
	for index in range(int(len(array)/2 + 1/2)):
		snail.extend(top(array)[index])
		snail.extend(right_side(array)[index])
		snail.extend(bottom(array)[index])
		snail.extend(left_side(array)[index])
	if len(array) % 2 == 0:
		return snail
	else:
		return snail[:-1]

print(snail(array))