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
  var len = Number(args.shift());
  if(len === 0){
    return console.log(0)
  }
  let matrix = args.map(function(s) {
    return s.split("");
  });

  function max(matrix, x1, y1) {
    // 判断对角线是否为1
    var maxLen = 0;
    var x2 = x1,
      y2 = y1;
    var X = matrix[0].length;
    var Y = matrix.length;
    var num = matrix[y1][x1];

    while (true) {
      // 对角线相等
      // x 轴是否都是 num ?
      for (var x = x1; x <= x2; x++) {
        if (matrix[y2][x] !== num) {
          return maxLen;
        }
      }
      // y 轴是否都是 num ?
      for (var y = y1; y <= y2; y++) {
        if (matrix[y][x2] !== num) {
          return maxLen;
        }
      }
      maxLen++;
      y2++;
      x2++;
      if (x2 >= X || y2 >= Y) {
        return maxLen;
      }
      if (matrix[y2][x2] !== num) {
        return maxLen;
      }
    }
  }

  var maxCount = 0;
  for (var x = 0; x < matrix[0].length; x++) {
    for (var y = 0; y < len; y++) {
      var _max = max(matrix, x, y);
      console.log(_max,x,y)
      if (maxCount < _max) {
        maxCount = _max;
      }
    }
  }

  console.log(maxCount * maxCount);
});
