from math import factorial
import string
from typing import SupportsIndex

def find_uniq(arr):
	unique = arr[0]
	if unique != arr[1] and unique != arr[2]:
		return unique
	for i in arr[1:]:
		if unique != i:
			return i
	
def find_uniq_legend(arr):
	a, b = set(arr)
	return a if arr.count(a) == 1 else b
	
def generate_hashtag(s):
	ht = "#"
	for word in s.split():
		ht += word.capitalize()
	if ht == "#" or len(ht) > 140:
		return False
	return ht

def valid_parentheses(string):
	opening = 0
	closing = 0
	for i in string:
		if i == '(':
			opening += 1
		elif i == ')':
			closing += 1
	if opening == closing:
		if len(string) >= 2:
			for i in string:
				if i == '(':
					break
				if i == ')':
					return False
			for i in string[::-1]:
				if i == ")":
					break
				if i == "(":
					return False
			return True
		elif len(string) < 2:
			return True
		else:
			return False
	return False

def rot13(message):
	string = ""
	for i in message:
		if ord('a') <= ord(i) <= ord('m'):
			string += chr(ord(i) + 13)
		elif ord('n') <= ord(i) <= ord('z'):
			string += chr(ord('a') + 12 - (ord('z') - ord(i)))
		elif ord('A') <= ord(i) <= ord('M'):
			string += chr(ord(i) + 13)
		elif ord('N') <= ord(i) <= ord('Z'):
			string += chr(ord('A') + 12 - (ord('Z') - ord(i)))
	return string
	
def digital_root(n):
	n_lst = [int(a) for a in str(n)]
	n = 0
	for val in n_lst:
		n += val
	return digital_root(n) if len(str(n)) > 1 else n

def isValidWalk(walk):
	return len(walk) == 10 and walk.count('n') == walk.count('s') and walk.count('e') == walk.count('w')

def find_outlier(int):
	odds = [x for x in int if x%2!=0]
	evens= [x for x in int if x%2==0]
	return odds[0] if len(odds)<len(evens) else evens[0]

def sort_array(arr):
  odds = sorted((x for x in arr if x%2 != 0), reverse=True)
  return [x if x%2==0 else odds.pop() for x in arr]

def snail(array):
	import numpy as np
	m = []
	array = np.array(array)
	while len(array) > 0:
		m += array[0].tolist()
		array = np.rot90(array[1:])
	return m

# the sum of two terms must be equal to target
# return this two indeces
class Solution:
	def twoSum(self, nums: list[int], target: int) -> list[int]:
		indexes = []
		for i in nums:
			for j in nums[nums.index(i)+1:]:
				if i + j == target:
					print(i,j)
					indexes.append(nums.index(i))
					indexes.append(nums.index(j, nums.index(i)+1))
					return indexes

	def calPoints(self, ops: list[str]) -> int:
		record = []
		for element in ops:
			if element.isdigit() or element[0] == "-" and element[1:].isdigit():
				record.append(int(element))
			elif element == "+":
				record.append(record[-1] + record[-2])
			elif element == "C":
				record = record[:-1]
			elif element == "D":
				record.append(record[-1]*2)
		return sum(record)

def old_zero(len: int, string: str):
	counter = 0
	for z in string:
		if z == "z":
			print(string[string.index(z) + 1:])
			for e in string[string.index(z) + 1:]:
				if e == "e":
					print(string[string.index(e) + 1:])
					for r in string[string.index(e) + 1:]:
						if r == "r":
							print(string[string.index(r) + 1:])
							for o in string[string.index(r) + 1:]:
								if o == "o":
									counter += 1
	return counter

def zero(len: int, string: str):
	counter = 0
	for z in range(len):
		if string[z] == "z":
			print(string[z + 1:])
			for e in range(z + 1, len):
				if string[e] == "e":
					print(string[e + 1:])
					for r in range(e + 1, len):
						if string[r] == "r":
							print(string[r + 1:])
							for o in range(r + 1, len):
								if string[o] == "o":
									counter += 1
	return counter


def halloween(len: int, child_candy: list[int], arda: int):
	total_candy = sum(child_candy) + arda
	average_candy = float(total_candy) / float(len)
	flag = True
	if not average_candy.is_integer():
		return False
	for value in child_candy:
		if value > average_candy:
			flag = False
	return flag


# class Pos:
# 	def __init__(self) -> None:
# 		self.counter = 0.0
# 		self.result = 0.0
# 	def possibility(self, distance: int):
# 		print(self.result)
# 		print(self.counter)
# 		if self.counter > 50:
# 			return None
# 		self.counter += 1
# 		total = 0
# 		while distance != total:
# 			total += 1

# ihtimal = Pos()

# ihtimal.possibility(3)

# print(ihtimal.result)

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

def soldier(o_team: list[int], e_team: list[int]):
	
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