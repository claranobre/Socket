//Programa : Potenciometro - BeagleBone
//Autor : FILIPEFLOP

var b = require('bonescript');


setInterval(teste, 100);


function teste()
{
  b.analogRead('P9_40', acionaled);
}

function acionaled(x)
{
  b.analogWrite('P9_14', x.value, 2000, printJSON);
}


function printJSON(x)
{
  console.log(JSON.stringify(x));
}
