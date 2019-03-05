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
  args.forEach(function(month) {
    var month = Number(month)
    var birthList = [0, 1, 0, 1];
    for (var i = 4; i <= month; i++) {
      var monthBirth = birthList.slice(1, i - 1).reduce(function(prev, curr) {
        return prev + curr;
      });
      birthList.push(monthBirth);
    }
    console.log(
      birthList.reduce(function(prev, curr) {
        return prev + curr;
      })
    );
  });
});
