/*
gpio_initialized = 0;

initialized_gpio_leds();

GPIO.setup("P8_8", GPIO.OUT);
GPIO.setup("P8_1O", GPIO.OUT);

gpio_initialized = 1;
*/

#include "../BlackLib/v3_0/BlackGPIO/BlackGPIO.h"
#include <unistd.h>
#include <cstdlib>

int main(int argc, char *argv[])
{
    BlackLib::BlackGPIO   ledR(BlackLib::GPIO_12,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledG(BlackLib::GPIO_14,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledB(BlackLib::GPIO_16,BlackLib::output, BlackLib::SecureMode);


    if (atoi(argv[1]) == 1){
        ledR.setValue(BlackLib::high);
        ledG.setValue(BlackLib::low);
        ledB.setValue(BlackLib::low);
        sleep(3);
        ledR.setValue(BlackLib::low);
        ledG.setValue(BlackLib::low);
        ledB.setValue(BlackLib::low);
    }
    else if (atoi(argv[1]) == 2)
    {
        ledR.setValue(BlackLib::low);
        ledG.setValue(BlackLib::high);
        ledB.setValue(BlackLib::low);
        sleep(3);
        ledR.setValue(BlackLib::low);
        ledG.setValue(BlackLib::low);
        ledB.setValue(BlackLib::low);
    }
    else if (atoi(argv[1]) == 3)
    {
        ledR.setValue(BlackLib::low);
        ledG.setValue(BlackLib::low);
        ledB.setValue(BlackLib::high);
        sleep(3);
        ledR.setValue(BlackLib::low);
        ledG.setValue(BlackLib::low);
        ledB.setValue(BlackLib::low);
    }
    else
    {
        ledR.setValue(BlackLib::high);
        ledG.setValue(BlackLib::high);
        ledB.setValue(BlackLib::high);
        sleep(3);
        ledR.setValue(BlackLib::low);
        ledG.setValue(BlackLib::low);
        ledB.setValue(BlackLib::low);
    }
return 0;
}
/*
//Carrega a biblioteca bonescript
var b = require('bonescript');
var contador = 0;

//Definicao dos pinos dos leds
b.pinMode('P9_12', b.OUTPUT);
b.pinMode('P9_14', b.OUTPUT);
b.pinMode('P9_16', b.OUTPUT);

setInterval(check,4000);

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
     b.digitalWrite('P9_12', b.HIGH);
     b.digitalWrite('P9_14', b.LOW);
     b.digitalWrite('P9_16', b.LOW);
   }

   if (contador === 1)
   {
     console.log("Led verde ligado !");
     b.digitalWrite('P9_12', b.LOW);
     b.digitalWrite('P9_14', b.HIGH);
     b.digitalWrite('P9_16', b.LOW);
   }
   if (contador === 2)
   {
     console.log("Led amarelo ligado !");
     b.digitalWrite('P9_12', b.LOW);
     b.digitalWrite('P9_14', b.LOW);
     b.digitalWrite('P9_16', b.HIGH);
   }
}
*/
