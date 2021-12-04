function f(arr) {
    let depth = 0, hPos = 0;
    for (let i = 0; i < arr.length; i++) {
        let ut = arr[i][0];
        let num = Number.parseInt(arr[i].split(" ")[1]);
        switch (ut) {
            case 'f':
                hPos += num;
                break;
            case 'u':
                depth -= num;
                break;
            case 'd':
                depth += num;
                break;
        }
    }
    return depth * hPos;
}
