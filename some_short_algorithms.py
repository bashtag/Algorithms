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

