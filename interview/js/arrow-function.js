function returnArrowFunction(){
    return () => {
        console.log(this.num)
    }
}

var obj = {num: 1, f:null, F:null}

obj.F = returnArrowFunction
obj.f = obj.F()
obj.f()

var obj2 = {num: 2,f:null}
obj2.f = obj.f
obj2.f()