
const main = () => {
  let a;
  let b;
  let c;

  const readLine = () => {
    const [aInput, bInput, cInput] = somehowGetValuesFromLine();
    a = aInput;
    b = bInput;
    c = cInput;
  };

};



const readLine = (a, b, c) => {
  const [aInput, bInput, cInput] = somehowGetValuesFromLine();
  if (isSomeError(aInput, bInput, cInput)) {
    return someErrorCode;
  }

  a = aInput;
  b = bInput;
  c = cInput;
  return successCode;
};

const main = () => {
  let a;
  let b;
  let c;

  const readError = readLine(a, b, c);
  if (readError === 0) {
    doHappyPath;
  } else {
    doUnhappyPath;
  }
};
