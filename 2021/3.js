function fn(arr) {
    let gama = '', epsilon = '';
    for (let i = 0; i < arr[0].length; i++) {
        let c0 = 0, c1 = 0;
        for (let j = 0; j < arr.length; j++) {
            if (arr[j][i] == '0') {
                c0++;
            } else {
                c1++;
            }
        }
        if (c0 > c1) {
            gama += '0';
            epsilon += '1';
        } else {
            gama += '1';
            epsilon += '0';
        }
    }
    
    return Number.parseInt(gama, 2) * Number.parseInt(epsilon, 2);
}
