function fn(arr) {
    let aim = 0, hPos = 0, depth = 0;
    for (let i = 0; i < arr.length; i++) {
        let ut = arr[i][0];
        let num = Number.parseInt(arr[i].split(" ")[1]);
        switch (ut) {
            case 'd':
                aim += num;
                break;
            case 'u':
                aim -= num;
                break;
            case 'f':
                hPos += num;
                depth += aim * num;
                break;
        }
    }

    return hPos * depth;
}
