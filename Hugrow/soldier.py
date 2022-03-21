def countingSortForRadix(inputArray, placeValue):
    # We can assume that the number of digits used to represent
    # all numbers on the placeValue position is not grater than 10
    countArray = [0] * 10
    inputSize = len(inputArray)

    # placeElement is the value of the current place value
    # of the current element, e.g. if the current element is
    # 123, and the place value is 10, the placeElement is
    # equal to 2
    for i in range(inputSize): 
        placeElement = (inputArray[i] // placeValue) % 10
        countArray[placeElement] += 1

    for i in range(1, 10):
        countArray[i] += countArray[i-1]

    # Reconstructing the output array
    outputArray = [0] * inputSize
    i = inputSize - 1
    while i >= 0:
        currentEl = inputArray[i]
        placeElement = (inputArray[i] // placeValue) % 10
        countArray[placeElement] -= 1
        newPosition = countArray[placeElement]
        outputArray[newPosition] = currentEl
        i -= 1
        
    return outputArray

def radixSort(inputArray):
    # Step 1 -> Find the maximum element in the input array
    maxEl = max(inputArray)

    # Step 2 -> Find the number of digits in the `max` element
    D = 1
    while maxEl > 0:
        maxEl /= 10
        D += 1
    
    # Step 3 -> Initialize the place value to the least significant place
    placeVal = 1

    # Step 4
    outputArray = inputArray
    while D > 0:
        outputArray = countingSortForRadix(outputArray, placeVal)
        placeVal *= 10  
        D -= 1

    return outputArray


def soldier(o_team, e_team):
	counter = 0
	result = []

	o_team.sort()
	e_team.sort()

	for i in range(len(e_team)):
		if i != 0 and e_team[i] == e_team[i - 1]:
			result.append(result[i-2])
		else:
			counter = 0
			for j in range(len(o_team)):
				if e_team[i] <= o_team[j]:
					result.append(counter)
					break
				counter += 1

	return result


if __name__ == "__main__":
	inputs = input().split()
	lens = []
	for num in inputs:
		lens.append(int(num))

	o_team = list(map(int,input().strip().split()))[:lens[0]]
	e_team = list(map(int,input().strip().split()))[:lens[1]]

	result = soldier(o_team, e_team)

	print(" ".join(map(str, result)), end="")


# time limit exceeded
def soldier_0(o_team: list[int], e_team: list[int]):
	
	result = []

	for soldier in e_team:
		counter = 0
		for other in o_team:
			if soldier > other:
				counter += 1
		result.append(counter)

	result.sort()
	
	return result

# if __name__ == "__main__":
# 	inputs = input().split()
# 	lens = []
# 	for num in inputs:
# 		lens.append(int(num))

# 	o_str_list = input().split()
# 	e_str_list = input().split()

# 	o_team = []
# 	for num in o_str_list:
# 		o_team.append(int(num))

# 	e_team = []
# 	for num in e_str_list:
# 		e_team.append(int(num))

# 	result = soldier(o_team, e_team)

# 	sp = "1 1 1 1 3 3".split()
# 	new_sp = []
# 	for num in sp:
# 		new_sp.append(int(num))
# 	for i in range(len(new_sp)):
# 		if new_sp[i] == result[i]:
# 			print(True)
# 		else:
# 			print("Not equal: ")
# 			print(f"sp: {new_sp[i]}, res: {result[i]}")

# 	for index in range(len(result)):
# 		print(result[index], end="")
# 		if index != len(result) - 1:
# 			print(end=" ")