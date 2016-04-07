//Carrega a biblioteca bonescript
var b = require('bonescript');
var contador = 0;

//Definicao dos pinos dos leds
b.pinMode('P8_12', b.OUTPUT);
b.pinMode('P8_14', b.OUTPUT);
b.pinMode('P8_16', b.OUTPUT);

setInterval(check,2000);

function check()
{
   contador = contador+1;
   if (contador === 3)
   {
       contador = 0;
   }
   if (contador === 0)
   {
     console.log("Led Vermelho ligado !");
     b.digitalWrite('P8_12', b.HIGH);
     b.digitalWrite('P8_14', b.LOW);
     b.digitalWrite('P8_16', b.LOW);
   }

   if (contador === 1)
   {
     console.log("Led verde ligado !");
     b.digitalWrite('P8_12', b.LOW);
     b.digitalWrite('P8_14', b.HIGH);
     b.digitalWrite('P8_16', b.LOW);
   }
   if (contador === 2)
   {
     console.log("Led amarelo ligado !");
     b.digitalWrite('P8_12', b.LOW);
     b.digitalWrite('P8_14', b.LOW);
     b.digitalWrite('P8_16', b.HIGH);
   }
}
