#ifndef _MESSAGE
#define _MESSAGE
#include "hadamar.h"
#include <iostream>
#define N 8
#define TAILLE_MESSAGE 3

class Message {
  private:
    int8_t * message;

  public:
    Message();
    Message(const char * msgCar);
    int8_t * coder( Hadamar &had,int8_t indice);
    void afficher();
    void setMessage(int8_t message[TAILLE_MESSAGE]);
};



#endif
