class Q {

  constructor() {
    this.input = [];
    this.output = [];
  }

  add(elem) {
    var min = elem;
    var max = elem;
    if(this.input.length > 0) {
      if(this.input[this.input.length-1][1] < min) min = this.input[this.input.length-1][1];
      if(this.input[this.input.length-1][2] > max) max = this.input[this.input.length-1][2];
    }
    var ewt = [elem, min, max];
    this.input.push(ewt);
  }

  remove() {
    if(this.output.length == 0) {
      if(this.input.length == 0) return false;
      while(this.input.length > 0) {
        var elem = this.input.pop()[0];
        var min = elem;
        var max = elem;
        if(this.output.length > 0) {
          if(this.output[this.output.length-1][1] < min) min = this.output[this.output.length-1][1];
          if(this.output[this.output.length-1][2] > max) max = this.output[this.output.length-1][2];
        }
        var ewt = [elem, min, max];
        this.output.push(ewt);
      }
    }
    var value = this.output.pop()[0];
    return value;
  }

  minimum() {
    if(this.input.length == 0) {
      if(this.output.length == 0) return null;
      return this.output[this.output.length-1][1];
    }

    if(this.output.length == 0) {
      return this.input[this.input.length-1][1];
    }

    if(this.input[this.input.length-1][1] <= this.output[this.output.length-1][1]) return this.input[this.input.length-1][1];
    return this.output[this.output.length-1][1];
  }

  maximum() {
    if(this.input.length == 0) {
      if(this.output.length == 0) return null;
      return this.output[this.output.length-1][2];
    }

    if(this.output.length == 0) {
      return this.input[this.input.length-1][2];
    }

    if(this.input[this.input.length-1][2] >= this.output[this.output.length-1][1]) return this.input[this.input.length-1][2];
    return this.output[this.output.length-1][2];
  }

  size() {
    return Number(this.input.length) + Number(this.output.length);
  }

  print() {
    var str = "";
    for(var i = this.output.length-1; i >= 0; i--) {
      str += this.output[i][0] + "<br>";
    }
    for(var i = 0; i <= this.input.length-1; i++) {
      str += this.input[i][0] + "<br>";
    }
    document.getElementById('output').innerHTML = str;
    return str;
  }

}
