#include "message.h"
#include <iostream>
#include <inttypes.h>


Message::Message(const char * msgCar){
  message = new int8_t[TAILLE_MESSAGE];
  for(int i = 0; i < TAILLE_MESSAGE; i++)
    message[i] = msgCar[i] - '0';
}

void Message::afficher(){
  for(int i = 0 ;  i < TAILLE_MESSAGE; i++ )
    printf("%d", message[i]);
}

int8_t * Message::coder( Hadamar &had, int8_t indice){

  int8_t* messageCoder = new int8_t[TAILLE_MESSAGE * N];
  int8_t* ligneHadamar = had.ligneHadamar(indice);
  for (size_t i = 0; i < had.getnbUtilisateursMax(); i++) {
    printf("%3" PRId8"", *(ligneHadamar + i));
  }
  printf("\n");

  for (int8_t i = 0; i < TAILLE_MESSAGE; i++) {
    for (int8_t j = 0; j < N; j++) {
        messageCoder[ j + i * N] = (message[i] == 1) ?  ligneHadamar[j] : -ligneHadamar[j];
    }
  }

  return messageCoder;
}
