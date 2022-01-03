
class SelectionSort {
    void selectionSort(int array[], int size) {
        for(int i = 0; i < size-1 ; i++) {
            int minIndex = i;
            for(int j = i+1; j < size ; j++) {
                if(array[minIndex] > array[j]) {
                    minIndex = j;
                }
            }
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }
}