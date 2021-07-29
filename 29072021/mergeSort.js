// Do implace sort use merge sort

const merge = (list, start, mid, end) => {
	let tempList = [];
	let k = 0, l1 = start, l2 = mid + 1;
	while (l1 <= mid && l2 <= end) {
		if (list[l1] <= list[l2]) tempList[k++] = list[l1++];
		else tempList[k++] = list[l2++];
	}
	while (l1 <= mid) tempList[k++] = list[l1++];
	while (l2 <= end) tempList[k++] = list[l2++];

	for (let i = start; i <= end; i++) {
		list[i] = tempList[i - start];
	}
}

const mergeSort = (list, start = 0, end = list.length - 1) => {
	if (start < end) {
		const mid = Math.floor((start + end) / 2);
		mergeSort(list, start, mid);
		mergeSort(list, mid + 1, end);
		merge(list, start, mid, end);
	}
}



let list = [-2, 34, 1, 3, 5 , 1 , 5, -4, 1, -5, 10, 23, -1, -2, -4, 2, -3];
mergeSort(list);
console.table(list);