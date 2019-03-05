var readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const args = [];
rl.on("line", function(line) {
  args.push(line);
});
rl.on("close", function() {
  args.forEach(function(meter) {
    var meters = [Number(meter)];
    for (var i = 1; i < 5; i++) {
      meters[i] = meters[i - 1] / 2;
    }
    var total =
      meters.reduce(function(prev, curr) {
        return prev + curr;
      }) *
        2 -
      meter;
    var fifth = meters[4];
    console.log(total);
    console.log(fifth / 2);
  });
});
