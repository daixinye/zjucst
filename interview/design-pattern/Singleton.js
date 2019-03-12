const Singleton = function(_constructor) {
  let _instance = null;

  this.getInstance = function() {
    if (!_instance) {
      _instance = new _constructor();
    }

    return _instance;
  };
};

const Constructor = function() {
  this.name = "dxy";
  this.sayName = function() {
    console.log(this.name);
  };
};

const singleton = new Singleton(Constructor);
const instance = singleton.getInstance();
instance.sayName();
