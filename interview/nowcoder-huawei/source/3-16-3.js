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
  var n = Number(args.shift());
  while (n--) {
    var person = args.shift();
    var score = args.shift().split(" ");
    var ans = score.map(function() {
      return 1;
    });

    var needLoop = true;

    while (true) {
      // 终止条件
      if (needLoop === false) {
        break;
      }
      needLoop = false;
      for (var i = 0; i < score.length; i++) {
        var prev = i - 1 < 0 ? score.length - 1 : i - 1;
        var next = i + 1 >= score.length ? 0 : i + 1;
        var curr = i;
        if(score[curr] > score[next] && ans[curr] <= ans[next]){
          ans[curr]++;
          needLoop = true;
        }
        if ( ans[curr] <= ans[prev] && score[curr] > score[prev]) {
            ans[curr]++;
            needLoop = true;
        }
      }
    }
    console.log(ans.reduce(function(prev,curr){return prev+curr}));
  }
});
