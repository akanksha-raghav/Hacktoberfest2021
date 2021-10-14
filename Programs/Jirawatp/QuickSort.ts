const partition = (array: number[], left: number = 0, right: number = array.length - 1): number => {
  const pivot = array[Math.floor((right + left) / 2)];

  while (left <= right) {
    while (array[left] < pivot) {
      left++;
    }

    while (array[right] > pivot) {
      right--;
    }

    if (left <= right) {
      [array[left], array[right]] = [array[right], array[left]];
      left++;
      right--;
    }
  }

  return left;
}

const quickSort = (array: number[], left: number = 0, right: number = array.length - 1): number[] => {
  let index: number;

  if (array.length > 1) {
    index = partition(array, left, right);

    if (left < index - 1) {
      quickSort(array, left, index - 1);
    }

    if (index < right) {
      quickSort(array, index, right);
    }
  }

  return array;
}

const testInput: number[] = [9, 10, 1, 5, 3, 4];

const sortedArray = quickSort(testInput);
console.log(`Sorted list: ${sortedArray} `);