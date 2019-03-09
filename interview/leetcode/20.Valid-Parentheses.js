/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    
    
    if (s.length === 0){
        return true
    }
    
    // const left = "({["
    const right = "}])"
    
    var stack = []
    var len = s.length
    for(var i = 0; i < len; i++){
        var char = s[i]
        // 属于右括号时，与栈顶进行匹配
        if(right.indexOf(char) > -1){
            var top = stack.pop()
            if(!match(top,char)){
                return false
            }
        }else{
            // 属于左括号时，加入栈中
            stack.push(char)
        }
    }
    
    if(stack.length === 0){
        return true
    }else{
        return false
    }
};

function match(left,right){
    var matchMap = {
        "{":"}",
        "(":")",
        "[":"]"
    }

    return matchMap[left] === right
}

console.log(isValid("()[]{}"))