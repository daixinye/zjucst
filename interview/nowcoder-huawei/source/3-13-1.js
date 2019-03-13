var readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let args = [];
rl.on("line", function(line) {
  args.push(line);
});
rl.on("close", function() {
  args = args[0].split(" ");
  var ip1 = args[0].split(".").map(function(n) {
    return Number(n);
  });
  var ip2 = args[1].split(".").map(function(n) {
    return Number(n);
  });
  var mask = args[2].split(".").map(function(n) {
    return Number(n);
  });

  ip1 = ip1
    .map(function(n, i) {
      return n & mask[i];
    })
    .join(".");

  ip2 = ip2
    .map(function(n, i) {
      return n & mask[i];
    })
    .join(".");

  if (ip1 === ip2) {
    console.log(1+' '+ip1);
  } else {
    console.log(0+' '+ip1);
  }
});
