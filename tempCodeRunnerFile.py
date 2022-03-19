inputs = input().split()
lens = []
for num in inputs:
	lens.append(int(num))

o_team = list(map(int,input().strip().split()))[:lens[0]]
e_team = list(map(int,input().strip().split()))[:lens[1]]

result = soldier(o_team, e_team)

for index in range(len(result)):
	print(result[index], end="")
	if index != len(result) - 1:
		print(end=" ")