

#include <iostream>
#define N 8
#define TAILLE_MESSAGE 3

class Emeteur {
  private:
    int8_t * messageEtaler;

  public:
    Emeteur();
    void etalage(int8_t * messageCoder);
    void afficher();
    int8_t *getMessageEtaler();
};
