n = int(input())
arr = {}
for i in input().split():
	arr.push_back(i)

for i in arr:
	y = 1
	for j in arr:
		if j == -i:
			y = 1
	print(y)
	# if y:
		# if i > 0: 
			# print('Thieu giay trai co', i)
		# else:
			# print('Thieu giay phai co', -i)
	# break
		