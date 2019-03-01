function useArguments() {
    var count = 0
    
    for(var i = 0; i < arguments.length; i++){
        count += arguments[i]
    }
    
    return count
}


console.log(useArguments(1,2,3,4))