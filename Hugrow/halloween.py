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