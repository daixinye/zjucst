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
  if (args[args.length - 1] === "0") {
    args.pop();
  }
  for (var i = 0; i < args.length; i++) {
    var num = Number(args[i]);

    var count = 0;

    while (true) {
      if (num > 3) {
        num -= 2;
        count++;
      } else {
        break;
      }
    }
    console.log(count + 1);
  }
});
