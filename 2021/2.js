function f(arr) {
    let h = 0, v = 0;
    for (let i = 0; i < arr.length; i++) {
        let ut = arr[i][0];
        let num = Number.parseInt(arr[i].split(" ")[1]);
        switch (ut) {
            case 'f':
                v += num;
                break;
            case 'u':
                h -= num;
                break;
            case 'd':
                h += num;
                break;
        }
    }
    return h * v;
}
