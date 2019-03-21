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
  var num = 1024 - Number(args.pop())
  var num64 = Math.floor(num / 64)
  num -= num64 * 64

  var num16 = Math.floor(num / 16)
  num -= num16 * 16

  var num4 = Math.floor(num/4)
  num -= num4 * 4

  console.log(num64+num16+ num4+ num)
});
