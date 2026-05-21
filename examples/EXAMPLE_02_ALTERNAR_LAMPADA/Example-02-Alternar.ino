#include <Arduino.h>
#include <Lampada.h>

Lampada pinLampada(45);


void setup()
{
}

void loop()
{
  
  pinLampada.update();//Este método deve ser chamado sempre no loop();
  pinLampada.alternar();//Alterna o estado do Lampada.
  delay(1000);
 
}
