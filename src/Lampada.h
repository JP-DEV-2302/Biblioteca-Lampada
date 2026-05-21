#ifndef LAMPADA_h
#define LAMPADA_h

#include <Arduino.h> 


/**
   * @class Lampada
   * @brief Classe para controle não bloqueante de uma Lampada,
   *
   * Permite Ligar, desligar, ligar por um tempo.
   *
   * @param pin  pino ao qual a Lampada foi conectado.
   * 
   * 
   * 
   * @note O método update() deve ser chamado continuamente no loop.
   */
class Lampada
{
private:
  uint8_t pino;
  bool estado;
  bool apagarNoTempo;
  uint32_t apagarNoMomento;
  uint32_t tempoEspera;
  bool estadoPiscar;
  uint32_t tempoAnteriorPisca;
  uint16_t repeticoes;


  /**
   * @brief Processa o desligamento temporizado. 
   */
  void funcaoApagarNoTempo();


public:
  /**
   * @brief Constrói um objeto Led.
   * 
   * @param pin Número do pino digital onde a Lampada está conectado.
   */
  Led(uint8_t pin);


 /**
  * @brief Liga o Led continuamente. 
  */
  void acender();

  /**
   *  @brief Liga a Lampada por um tempo determinado.
   * 
   * @param tempoLigado Tempo, em milissegundos, que o Lampada ficará ligado.
   */
  void acender(uint32_t tempoLigado);

/**
 * @brief Desliga a Lampada e cancela modos automáticos. 
 */
  void apagar();


  /**
   * @brief Alterna o estado de HIGH para LOW ou vice versa.
   */
  void alternar();

  /**
   * @brief Permite que eu altere o estado da Lampada localmente sem mexer na biblioteca. 
   * 
   * @param estado Estado, é o parâmetro que define se a Lampada liga ou não.
   */
  void setEstado(bool estado);


  /**
   * @brief Permite que eu peça para o programa me retornar o pino que a Lampada está locada.
   */
  uint8_t getPino();


  /**
   * @brief Atualiza a lógica interna da classe e escreve no pino.
   * 
   * @note Deve ser chamado repetidamente dentro da função loop().
   */
  void update();
};

#endif