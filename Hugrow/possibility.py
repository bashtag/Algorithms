from math import factorial

def ikili_tekrarli_perm(x1: int, x2: int):
	result = 1
	for i in range(x2):
		result *= x1 + x2 - i
	return result / factorial(x2)

def possibility(distance: int):
	total = 0
	counter = 0
	result = 0.0

	for i in range(int(distance/2) + 1):
		total = 2*i
		counter = 0
		while distance != total:
			counter += 1
			total += 1

		poss = ((1/2) ** float(i + counter)) * ikili_tekrarli_perm(counter, i)
		poss = round(poss,6)
		result += poss

	return result

# if __name__ == "__main__":
# 	loop = int(input())
# 	distences = []
# 	for i in range(loop):
# 		x = int(input())
# 		distences.append(x)
# 	for index in range(len(distences)):
# 		output = str(possibility(distences[index]))
# 		if len(output) == 8:
# 			print(output, end="")
# 		else:
# 			print(output, end="")
# 			print("0"*(8 - len(output)), end="")
# 		if index != len(distences) - 1:
# 			print()

