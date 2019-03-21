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
  args.shift();
  args.forEach(function(str) {
    // AAAAAA => AA
    var pattern1 = /([a-zA-Z])\1{2}/;
    var pattern2 = /([a-zA-Z])\1([a-zA-Z])\2/;

    while (true) {
      if(!pattern1.test(str) && !pattern2.test(str)){
        break
      }
      if (pattern1.test(str)) {
        str = str.replace(pattern1, "$1$1");
        continue
      }
      // AABB => AAB
      if (pattern2.test(str)) {
        str = str.replace(pattern2, "$1$1$2");
        continue
      }
    }

    console.log(str)
  });
});
