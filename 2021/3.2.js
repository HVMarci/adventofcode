function fn(arr) {
    let arrcpy = [...arr];
    arr = [...arrcpy];
    for (let i = 0; i < arr[0].length && arr.length > 1; i++) {
        let c0 = 0, c1 = 0;
        for (let j = 0; j < arr.length; j++) {
            if (arr[j][i] == '0') {
                c0++;
            } else {
                c1++;
            }
        }

        console.log(i, c0, c1);
        
        if (c0 > c1) {
            for (let j = 0; j < arr.length; j++) {
                if (arr[j][i] != '0') {
                    arr.splice(j, 1);
                    j--;
                } else {
                    console.log(arr[j][i]);
                }
            }
        } else {
            for (let j = 0; j < arr.length; j++) {
                if (arr[j][i] != '1') {
                    arr.splice(j, 1);
                    j--;
                }
            }
        }
    }

    let o2 = Number.parseInt(arr[0], 2);
    console.log(arr);
    arr = arrcpy;
    arrcpy = [...arr];

    for (let i = 0; arr.length > 1; i++) {
        console.log(arr);
        let c0 = 0, c1 = 0;
        for (let j = 0; j < arr.length; j++) {
            if (arr[j][i] == '0') {
                c0++;
            } else {
                c1++;
            }
        }
        
        if (c1 < c0) {
            for (let j = 0; j < arr.length; j++) {
                if (arr[j][i] != '1') {
                    arr.splice(j, 1);
                    j--;
                }
            }
        } else {
            for (let j = 0; j < arr.length; j++) {
                if (arr[j][i] != '0') {
                    arr.splice(j, 1);
                    j--;
                }
            }
        }

    }

    let co2 = Number.parseInt(arr[0], 2);
    console.log(o2, co2, arr);
    
    return o2 * co2;
}
fn(arr);
