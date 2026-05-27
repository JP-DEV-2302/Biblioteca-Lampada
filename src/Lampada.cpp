#include "Lampada.h"





Lampada::Lampada(uint8_t pin) : pino(pin),
                        estado(LOW),
                        apagarNoTempo(false),
                        apagarNoMomento(false),
                        tempoEspera(0),
                        tempoAnteriorPisca(0),
{
    pinMode(pino, OUTPUT);
}


void Lampada::acender()
{
    estado = HIGH;
    apagarNoTempo = false;
   
}

void Lampada::acender(uint32_t tempoLigado)
{
    estado = HIGH;
    apagarNoTempo = true;
    apagarNoMomento = millis() + tempoLigado;
   
}

void Lampada::apagar()
{
    estado = LOW;
    digitalWrite(pino, estado);
    apagarNoTempo = false;
    
}

void Lampada::alternar()
{
    estado = !estado;
    apagarNoTempo = false;
   
}

void Lampada::setEstado(bool estado)
{
    this->estado = estado;
    apagarNoTempo = false;
   
}

uint8_t Lampada::getPino()
{

    return pino;
    apagarNoTempo = false;
}

void Lampada::update()
{
    if (apagarNoTempo)
    {
        funcaoApagarNoTempo();
    }

    digitalWrite(pino, estado);
}

void Lampada::funcaoApagarNoTempo()
{
    if (millis() >= apagarNoMomento)
    {
        estado = LOW; // alterna entre HIGH e LOW
        apagarNoTempo = false;
    }
}

