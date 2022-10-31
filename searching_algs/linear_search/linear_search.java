
class linearSearch{
    public static int search(int arr[], int key){
        for(int i=0; i<arr.length; i++){
            if(arr[i] == key){
                return i;
            }
        }
        return -1;    
    }

    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5, 6, 7};
        int key = 5;

        int test1 = linearSearch.search(arr, key);
        int test2 = linearSearch.search(arr, 0);

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