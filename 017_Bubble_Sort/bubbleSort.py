def bubbleSort(arr, n):
	for i in range(1, n):

		for j in range(n-1):
			if arr[j] > arr[j+1]:
				arr[j], arr[j+1] = arr[j+1], arr[j]


if __name__ == '__main__':
	arr = [2, 5, 3, 6, 1, 7, 4]
	n = len(arr)

	print("Before sorting")
	print(arr)

	bubbleSort(arr, n)

	print("After sorting")
	print(arr)
