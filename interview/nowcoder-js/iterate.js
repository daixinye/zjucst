function iterate(obj) {
    var result = []
    for (var key in obj){
        if(obj.hasOwnProperty(key)){
            result.push(key+": "+obj[key])
        }
    }
    return result
}

var C = function() {this.foo = 'bar'; this.baz = 'bim';}; 
C.prototype.bop = 'bip'; 
iterate(new C());