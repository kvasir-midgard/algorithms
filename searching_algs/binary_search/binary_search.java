
class binarySearch{
    public static int search(int arr[], int l, int r, int key){
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == key)
                return mid;
            if (arr[mid] > key){
                return search(arr, l, mid - 1, key);
            }
            return search(arr, mid + 1, r, key);
        }
        return -1;
    }

    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5, 6, 7};
        int len = arr.length - 1;
        int key = 5;

        int test1 = search(arr, 0, len, key);
        int test2 = search(arr, 0, len, 0);

        if(test1 == 4) {
            System.out.print("Element found test 1 \t\t passed \n");
        } else {
            System.out.print("Element not found test 1 \t\t failed \n");
        }
    
        if(test2 == -1) {
            System.out.print("Element not found test 2 \t passed \n");
        } else {
            System.out.print("Element not found test 2 \t failed \n");
        }
    }
}