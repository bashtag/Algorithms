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
