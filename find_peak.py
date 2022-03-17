def rand_list(n):
	import random
	rl = []
	for i in range(n):
		rl.append(random.randint(0, 1000))
	return rl

def rand_list_of_lists(n,m):
	import random
	rl = []
	for i in range(n):
		fl = []
		for j in range(m):
			fl.append(random.randint(0, 1000))
		rl.append(fl)
	return rl

def peek_straightforward_1d(rl, n= None):
	log = []
	if n == None:
		n = round(len(rl) / 2)
	
	if n < 0 and n >= len(rl):
		return None

	while (True):
		if n == 0 and rl[n] >= rl[n + 1]:
			log.append(n)
			return (rl[n], n), log
		
		if n == len(rl) - 1 and rl[n] >= rl[n - 1]:
			log.append(n)
			return (rl[n], n), log
		
		if n != len(rl) - 1 and n != 0 and rl[n] >= rl[n + 1] and rl[n] >= rl[n - 1]:
			log.append(n)
			return (rl[n], n), log

		if rl[n] >= rl[n + 1] or n == len(rl) - 1:
			log.append(n)
			n = n - 1
			continue
		else:
			log.append(n)
			n = n + 1
			continue

def peek_straightforward_2d(rl, n = None, m = None):
	log = []
	if n == None:
		n = round(len(rl) / 2)
	if n < 0 or n >= len(rl):
		return None
	if m == None:
		m = round(len(rl) / 2)
	if m < 0 or m >= len(rl):
		return None

	while (True):
		if n == 0:
			if m == 0 and rl[n][m] >= rl[n+1][m] and rl[n][m] >= rl[n][m+1] :
				log.append([n,m])
				return (rl[n][m], log[-1]),log
			if m != 0 and m != len(rl[0])-1 and rl[n][m] >= rl[n+1][m] and rl[n][m] >= rl[n][m-1] :
				log.append([n,m])
				return (rl[n][m], log[-1]),log
			if m == len(rl[0])-1 and rl[n][m] >= rl[n+1][m] and rl[n][m] >= rl[n][m-1] :
				log.append([n,m])
				return (rl[n][m], log[-1]),log	
		elif m == 0:
			if n != 0 and n != len(rl) - 1 and  rl[n][m] >= rl[n+1][m] and rl[n][m] >= rl[n][m+1] and rl[n][m] >= rl[n-1][m] :
				log.append([n,m])
				return (rl[n][m], log[-1]),log
			if n == len(rl) - 1 and rl[n][m] >= rl[n][m+1] and rl[n][m] >= rl[n-1][m] :
				log.append([n,m])
				return (rl[n][m], log[-1]),log
		else:
			if n != len(rl)-1 and m != len(rl[0])-1 and  rl[n][m] >= rl[n+1][m] and rl[n][m] >= rl[n][m+1] and rl[n][m] >= rl[n-1][m] and rl[n][m] >= rl[n][m-1]:
				log.append([n,m])
				return (rl[n][m], log[-1]),log
			elif n == len(rl)-1:
				if m != len(rl[0])-1 and rl[n][m] >= rl[n][m+1] and rl[n][m] >= rl[n-1][m] and rl[n][m] >= rl[n][m-1]:
					log.append([n,m])
					return (rl[n][m], log[-1]),log
				elif m == len(rl[0])-1 and rl[n][m] >= rl[n-1][m] and rl[n][m] >= rl[n][m-1]:
					log.append([n,m])
					return (rl[n][m], log[-1]),log
			elif m == len(rl[0])-1 and rl[n][m] >= rl[n-1][m] and rl[n][m] >= rl[n][m-1] and rl[n][m] >= rl[n+1][m] :
					log.append([n,m])
					return (rl[n][m], log[-1]),log

		if n != 0 and rl[n-1][m] >= rl[n][m]:
			log.append([n,m])
			n = n-1
			continue

		elif m != 0 and rl[n][m-1] >= rl[n][m]:
			log.append([n,m])
			m = m-1
			continue

		elif n != len(rl)-1 and rl[n+1][m] >= rl[n][m]:
			log.append([n,m])
			n=n+1
			continue

		elif m != len(rl[0])-1 and  rl[n][m+1] >= rl[n][m] :
			log.append([n,m])
			m=m+1
			continue

# rl = [[485, 972, 829], [522, 32, 696], [651, 965, 476], [389, 724, 185]]
# print(peek_straightforward_2d(rl))

"""
# This function isn't working yet
def peak_divide_conquer_1d(rl, n = None):
	log = []
	if n == None:
		n = round(len(rl) / 2)

	if n < 0 and n >= len(rl):
		return None

	while (True):
		print(n)
		if n == 0 and rl[n] >= rl[n + 1]:
			log.append(n)
			return (rl[n], n), log
		
		if n == len(rl) - 1 and rl[n] >= rl[n - 1]:
			log.append(n)
			return (rl[n], n), log
		
		if n != len(rl) - 1 and n != 0 and rl[n] >= rl[n + 1] and rl[n] >= rl[n - 1]:
			log.append(n)
			return (rl[n], n), log

		if n != 0 and rl[n] < rl[n - 1]:
			log.append(n)
			n = round((n - 1) / 2)
			continue

		if n != len(rl) - 1 and rl[n] < rl[n + 1]:
			log.append(n)
			n = round(n + len(rl[n+1:])/2)
			continue
"""


"""
peak_divide_conquer_2d

I haven't written this function yet
"""