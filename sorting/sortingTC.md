
```

| **Sort**     | **Best Case** | **Average Case** | **Worst Case** | **Space** | **Stable?** | **Description**                                                                   |
| ------------ | ------------- | ---------------- | -------------- | --------- | ----------- | --------------------------------------------------------------------------------- |
| 🔵 Bubble    | O(n)          | O(n²)            | O(n²)          | O(1)      | ✅ Yes       | Repeatedly swaps adjacent elements if they are in wrong order.                    |
| 🟢 Insertion | O(n)          | O(n²)            | O(n²)          | O(1)      | ✅ Yes       | Builds sorted array one element at a time by inserting into correct position.     |
| 🟡 Selection | O(n²)         | O(n²)            | O(n²)          | O(1)      | ❌ No        | Finds the minimum element and places it at the beginning.                         |
| 🟣 Counting  | O(n + k)      | O(n + k)         | O(n + k)       | O(n + k)  | ✅ Yes       | Uses a frequency array (hashing) — good for small range integers.                 |
| 🔵 Merge     | O(n log n)    | O(n log n)       | O(n log n)     | O(n)      | ✅ Yes       | Divide and conquer; merges two sorted arrays.                                     |
| 🔴 Quick     | O(n log n)    | O(n log n)       | O(n²)          | O(log n)  | ❌ No        | Picks a pivot and partitions the array around it. Fastest in practice.            |
| 🔶 Heap      | O(n log n)    | O(n log n)       | O(n log n)     | O(1)      | ❌ No        | Uses binary heap to repeatedly extract the max/min element.                       |
| 🟤 Radix     | O(nk)         | O(nk)            | O(nk)          | O(n + k)  | ✅ Yes       | Sorts digits place by place using counting sort as subroutine. Good for integers. |

```
---

1. 🔵 Bubble Sort

   ```cpp
                    for i = 0 to n-2:
                        for j = 0 to n-2-i:
                            if arr[j] > arr[j+1]:
                                 swap arr[j] and arr[j+1]

2. 🟢 Insertion Sort

   ```cpp
                   for i = 1 to n-1:
                      key = arr[i]
                          j = i - 1
                            while j >= 0 and arr[j] > key:
                                  arr[j+1] = arr[j]
                                    j = j - 1
                                    arr[j+1] = key



3. 🟡 Selection Sort

   ```cpp
                  for i = 0 to n-2:
                  minIndex = i
                  for j = i+1 to n-1:
                  if arr[j] < arr[minIndex]:
                        minIndex = j
                  swap arr[i] and arr[minIndex]


4. 🟣 Counting Sort (for non-negative integers only)

   ```cpp
                   find max value in arr
                  create count array of size max+1, initialized to 0

                  for each num in arr:
                      count[num] += 1

                  index = 0
                  for i = 0 to max:
                      while count[i] > 0:
                  arr[index] = i
                  index += 1
                 count[i] -= 1


5. 🔵  Merge Sort

    ```cpp
    function mergeSort(arr, left, right):
    if left >= right:
        return
    mid = (left + right) // 2
    mergeSort(arr, left, mid)
    mergeSort(arr, mid+1, right)
    merge(arr, left, mid, right)

    function merge(arr, left, mid, right):
    create leftArray and rightArray from arr
    merge them into sorted order

6. 🔴 Quick Sort

    ```cpp
    function quickSort(arr, low, high):
    if low < high:
        pivotIndex = partition(arr, low, high)
        quickSort(arr, low, pivotIndex - 1)
        quickSort(arr, pivotIndex + 1, high)

    function partition(arr, low, high):
    pivot = arr[low]
    i = low
    j = high
    while i < j:
        while arr[i] <= pivot and i <= high-1:
            i++
        while arr[j] > pivot and j >= low+1:
            j--
        if i < j:
            swap arr[i] and arr[j]
    swap arr[low] and arr[j]
    return j

