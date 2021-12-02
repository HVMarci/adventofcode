// Input split into array [199, 200, 208, ...]
function fn(arr) {
    let c = 0;
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > arr[i - 1]) c++;
    }
    return c;
}

fn(arr);
