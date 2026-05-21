#include <Arduino.h>
#include <Lampada.h>

Lampada pinLampada(45);
uint32_t tempoEspera;

void setup()
{
}

void loop()
{
  tempoEspera = millis();
  pinLampada.update(); //Este método deve ser chamado sempre no loop();
  pinLampada.acender(1000); //Liga a Lampada.
  if (tempoEspera >= 1000)
  {
    pinLed.apagar();//Desliga a Lampada.
 }
}
