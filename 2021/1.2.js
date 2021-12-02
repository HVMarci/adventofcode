function fn(arr) {
    let c = 0;
    for (let i = 3; i < arr.length; i++) {
        if (arr[i] > arr[i - 3]) c++;
    }
    return c;
}

fn(arr);
