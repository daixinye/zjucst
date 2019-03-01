// 题目描述
// 实现一个打点计时器，要求
// 1、从 start 到 end（包含 start 和 end），每隔 100 毫秒 console.log 一个数字，每次数字增幅为 1
// 2、返回的对象中需要包含一个 cancel 方法，用于停止定时操作
// 3、第一个数需要立即输出

function count(start, end) {
    function timer(){
        var ct = start
        console.log(ct)
        ct++
        
        
        var _timer = setInterval(function(){
            if(ct <= end){
                console.log(ct)
                ct++
            }else{
                clearInterval(_timer)
            }
        },100)
        
        return {
            cancel: function(){
                clearInterval(_timer)
            }
        }
    }
    
    return timer()
}

count(1,10)