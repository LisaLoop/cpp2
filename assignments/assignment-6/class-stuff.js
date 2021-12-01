/***  INHERITANCE  ***/

class Rectangle {
  #width = 0;
  #height = 0;

  constructor (width = 0, height = 0) {
    this.#width = width;
    this.#height = height;
  }

  calculatePerimeter () {
    return 2 * (this.#width + this.#height);
  }

  calculateArea () {
    return this.#width * this.#height;
  }

  setWidth (width) {
    this.#width = width;
  }

  setHeight (height) {
    this.#height = height;
  }
}

class Square extends Rectangle {
  constructor (size = 1) {
    super(size, size);
  }
}

const square = new Square(5);
square.setWidth(3);
square.setHeight(20);

square.calculatePerimeter(); // 46
square.calculateArea(); // 60



/*** MIX-IN ***/

function calculatePerimeter () {
  return this.width * 2 + this.height * 2;
}

function calculateArea () {
  return this.width * this.height;
}


const Square = (size) => ({
  width: size,
  height: size,
  calculateArea,
  calculatePerimeter
});

const Rectangle = (width, height) => ({
  width,
  height,
  calculatePerimeter,
  calculateArea
});




+Base_Option_A {
  Iceberg Lettuce
}

+Base_Option_B {
  Romaine Lettuce
}

+Bread {
  Croutons
}

+Veggies_Option_A {
  Sliced Cucumber
  Shredded Carrot
  Diced Onion
}

+Veggies_Option_B {
  Chopped Mushroom
  Tomato
  Avocado
}

+Dressing_Option_A {
  Olive Oil
}

+Dressing_Option_B {
  Ranch
}

+Dressing_Option_C {
  Caesar
  Cheese
}



CaesarSalad {
  Base_Option_B();
  Bread();
  Dressing_Option_C();
}

GreekSalad {
  Base_Option_A();
  Bread();
  Veggies_Option_A();
  Dressing_Option_A();
}


const obj = {
  otherThing: "hi",
  method: () => {
    return this.otherThing = "something else";
  }
}
