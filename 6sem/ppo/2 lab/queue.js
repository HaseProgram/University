class Q {

  constructor() {
    this.input = [];
    this.output = [];
  }

  add(elem) {
    var min = elem;
    var max = elem;
    if(this.input.length > 0) {
      if(this.input[this.input.length-1].minimum < min) min = this.input[this.input.length-1].minimum;
      if(this.input[this.input.length-1].maximum > max) max = this.input[this.input.length-1].maximum;
    }
    var ewt = {value: elem, minimum: min, maximum: max};
    this.input.push(ewt);
  }

  remove() {
    if(this.output.length == 0) {
      if(this.input.length == 0) return false;
      while(this.input.length > 0) {
        var elem = this.input.pop().value;
        var min = elem;
        var max = elem;
        if(this.output.length > 0) {
          if(this.output[this.output.length-1].minimum < min) min = this.output[this.output.length-1].minimum;
          if(this.output[this.output.length-1].maximum > max) max = this.output[this.output.length-1].maximum;
        }
        var ewt = {value: elem, minimum: min, maximum: max};
        this.output.push(ewt);
      }
    }
    var value = this.output.pop().value;
    return value;
  }

  minimum() {
    if(this.input.length == 0) {
      if(this.output.length == 0) return null;
      return this.output[this.output.length-1].minimum;
    }

    if(this.output.length == 0) {
      return this.input[this.input.length-1].minimum;
    }

    if(this.input[this.input.length-1].minimum <= this.output[this.output.length-1].minimum) {
		return this.input[this.input.length-1].minimum;
	}
    return this.output[this.output.length-1].minimum;
  }

  maximum() {
    if(this.input.length == 0) {
      if(this.output.length == 0) return null;
      return this.output[this.output.length-1].maximum;
    }

    if(this.output.length == 0) {
      return this.input[this.input.length-1].maximum;
    }

    if(this.input[this.input.length-1].maximum >= this.output[this.output.length-1].maximum) {
		return this.input[this.input.length-1].maximum;
	}
    return this.output[this.output.length-1].maximum;
  }

  size() {
    return Number(this.input.length) + Number(this.output.length);
  }

  print(html) {
    var str = "";
	var br = " ";
	if(html) br = "<br>";
    for(var i = this.output.length-1; i >= 0; i--) {
      str += this.output[i].value + br;
    }
    for(var i = 0; i <= this.input.length-1; i++) {
      str += this.input[i].value + br;
    }
    if(html) document.getElementById('output').innerHTML = str;
    return str;
  }

}
