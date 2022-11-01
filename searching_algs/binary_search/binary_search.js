let binarySearch = (arr, l, r, key) => {
    if (r >= l) {
        let mid = l + Math.floor((r - l) / 2);
        if (arr[mid] === key) {
            return mid;
        }
        if (arr[mid] > key) {
            return binarySearch(arr, l, mid - 1, key);
        }
        return binarySearch(arr, mid + 1, r, key);
    }
    return -1;
}

let main = () => {
    let arr = [1, 2, 3, 4, 5, 6, 7];
    let len = arr.length - 1;
    let key = 5;
    let test1 = binarySearch(arr, 0, len, key);
    let test2 = binarySearch(arr, 0, len, 0);

    if(test1 == 4) {
        console.log("Element found test 1 \t\t passed");
    } else {
        console.log("Element not found test 1 \t\t failed");
    }

    if(test2 == -1) {
        console.log("Element not found test 2 \t passed");
    } else {
        console.log("Element not found test 2 \t failed");
    }
    return 0;
};

main();
