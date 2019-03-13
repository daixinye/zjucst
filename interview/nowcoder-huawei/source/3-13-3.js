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
  var map = args.map(function(a){return a.split(" ")})
  console.log(map)
  var len = map.length

  function value(x,y){
    if(x < len && y < len){
      return map[y][x]
    }else{
      return null
    }
  }
  
  // 搜寻  
  var min = [[]]
  var curr = 2
  var nx,ny
  function search(x,y,curr,steps,fx,fy){
    console.log(x,y)
    var val = value(x,y)
    // 碰到边界
    if(val === null || val > curr){
      return false
    }
    // 碰到要打的怪兽
    if(val === curr){
      nx = x
      ny = y
      if(min[curr]){
        min[curr].push(steps)
      }else{
        min[curr] = [steps]
        return true
      }
    }

    // 开始 search
    var top = !(fx ===x && fy ===y+1 ) && search(x,y+1,curr,steps+1,x,y+1)
    var bottom = !(fx ===x && fy ===y-1 ) && search(x,y-1,curr, steps+1,x,y+1)
    var left = !(fx ===x-1 && fy ===y ) && search(x-1, y, curr, steps+1,)
    var right = !(fx === x+1 && fy ===y) && search(x+1,y,curr,steps+1)

    if(top||bottom||left||right){
      curr++
      search(nx,ny,curr,0,nx,ny)
    }
  }

  search(0,0,2,0,0,0)

  // 遍历，看看还有没有怪兽没被消灭的

  // 输出最小值
});
