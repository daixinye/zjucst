function f(line) {
  var chars = line.split("")
  var stack = []
  var result = []
  var isQuot = false
  chars.forEach(function(char){
    if(char === "\""){
        if(isQuot){
            stack.length ? result.push(stack.join("")) : null
            isQuot = false
            stack = []
            return
        }else{
            isQuot = true
            return
        }
    }

    if(!isQuot && char === " "){
        stack.length ? result.push(stack.join("")) : null
        stack = []
    }else{
        stack.push(char)
    }

  })
  stack.length ? result.push(stack.join("")) : null
  result = result.length + "\n" + result.join("\n")
  print(result);
}

function print(v) {
  console.log(v);
}
f('gqpj /lrl d:\ a:\ c:\ /nkb')
// f("ho /mx /ni c:\\ /c d:\\ c:\\");
// f('a b "c d e" f g "h i j" k');
