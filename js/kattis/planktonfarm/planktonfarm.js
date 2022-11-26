const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', (i) => {
    rl.on('line', (j) => {
        rl.on('line', (k) => {
            var b = parseInt(i);
            var a = parseInt(j);
            var c = k.split(" ").map(x => parseInt(x)).sort();
            console.log(c.sort());
        });
    });
});
