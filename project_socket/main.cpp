#include "../BlackLib/v3_0/BlackGPIO/BlackGPIO.h"
#include <unistd.h>
#include <cstdlib>

int main(int argc, char *argv[])
{
    BlackLib::BlackGPIO   ledR(BlackLib::GPIO_60,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledG(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledB(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode);


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
