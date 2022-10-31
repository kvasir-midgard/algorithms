let linearsearch = (arr, key) => {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === key) {
            return i;
        }
    }
    return -1; 
}

let main = () => {
    let arr = [1, 2, 3, 4, 5, 6, 7];
    let key = 5;
    let test1 = linearsearch(arr, key);
    let test2 = linearsearch(arr, 0);

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
