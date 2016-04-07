/*
gpio_initialized = 0;

initialized_gpio_leds();

GPIO.setup("P8_8", GPIO.OUT);
GPIO.setup("P8_1O", GPIO.OUT);

gpio_initialized = 1;
*/



/*
 #include <iostream>
 #include <stdio.h>
 #include <unistd.h>
 using namespace std;

 int main(){
 cout << "LED Flash Start" << endl;
 FILE *LEDHandle = NULL;
 const char *LEDBrightness="/sys/class/leds/beaglebone:green:usr0/brightness";

 for(int i=0; i<10; i++){
    if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){
        fwrite("1", sizeof(char), 1, LEDHandle);
        fclose(LEDHandle);
    }
    usleep(1000000);

    if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){
        fwrite("0", sizeof(char), 1, LEDHandle);
        fclose(LEDHandle);
    }
    usleep(1000000);
  }
  cout << "LED Flash End" << endl;
 }
*/



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
