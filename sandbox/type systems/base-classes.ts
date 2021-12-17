// Base classes are generally part of a NOMINAL type system

class Bird {
  fly () {}
  swim () {}
  diveUnderwater () {}
  molt () {}
  layEgg () {}
}

class AttackHelicopter extends Bird {}

const h = new AttackHelicopter();

h.layEgg();



class GameObject {}

class RenderableGameObject extends GameObject {
  draw() {}
}

class Vehicle extends RenderableGameObject {
  _applyWheelFriction () {}
  drive() {}
  brake() {}
  retractLandingGear() {}
  dispatchLandingGear() {}
  // fillGasTank() {}
}

class Car extends Vehicle {
  fillGasTank() {}
}

class Tank extends Vehicle {
  fillGasTank() {}
}

class F15 extends Vehicle {
  fillGasTank() {}
}

class Submarine extends Vehicle {
  _ejectUraniumRods() {}
  _replaceUraniumRods() {}

  replaceFuelRods () {}
}


256_000_000_000

let RAM = [5, 6, 7, 8];

let pointerToX = 0;

let x = RAM[pointerToX];
let y = RAM[pointerToX + 1];

RAM[pointerToX + 2] = RAM[pointerToX + 2] + 1;
let z = RAM[pointerToX + 2];
