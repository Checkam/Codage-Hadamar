#include "message.h"
#include "commun.h"
#include <iostream>
#include <inttypes.h>


Message::Message(const char * msgCar){
  message = new int8_t[TAILLE_MESSAGE];
  for(int i = 0; i < TAILLE_MESSAGE; i++)
    message[i] = msgCar[i] - '0';
}


Message::Message(){
  message = new int8_t[TAILLE_MESSAGE];
  for(int i = 0; i < TAILLE_MESSAGE; i++)
    message[i] = 0;
}

void Message::afficher(){
  for(int i = 0 ;  i < TAILLE_MESSAGE; i++ )
    printf("%2d ", message[i]);
  printf("\n");
}

int8_t * Message::coder( Hadamar &had, int8_t indice){
  printf("\n\n"COLOR"Codage du message :"DEFAULT_COLOR);
  this->afficher();
  int8_t* messageCoder = new int8_t[TAILLE_MESSAGE * N];
  int8_t* ligneHadamar = had.ligneHadamar(indice);

  for (int8_t i = 0; i < TAILLE_MESSAGE; i++) {
    for (int8_t j = 0; j < N; j++) {
        messageCoder[ j + i * N] = (message[i] == 1) ?  ligneHadamar[j] : -ligneHadamar[j];
    }
  }

  printf("\n\n"COLOR"Message Coder :"DEFAULT_COLOR);
  for (int i = 0; i < TAILLE_MESSAGE; i++) {
    for (int j = 0; j < N; j++) {
      printf(" %2d", messageCoder[j + i * N]);
    }
    printf("    ");
  }
  printf("\n\n");


  return messageCoder;
}


void Message::setMessage(int8_t msg[TAILLE_MESSAGE]){
  for(int i = 0; i < TAILLE_MESSAGE; i++)
    message[i] = msg[i];
}
