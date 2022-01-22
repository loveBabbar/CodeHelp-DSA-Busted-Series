
def reverse(v):
	s = 0
	e = len(v)-1

	while s <= e:
		v[s], v[e] = v[e], v[s]
		s += 1
		e -= 1

	return v


if __name__ == '__main__':
	v = []

	v.append(11)
	v.append(7)
	v.append(3)
	v.append(12)
	v.append(4)

	print(v)

	ans = reverse(v)
	print("Reverse Array")
	print(ans)
