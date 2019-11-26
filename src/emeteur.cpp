#include "emeteur.h"
#include <iostream>


Emeteur::Emeteur(){
  messageEtaler = new int8_t[TAILLE_MESSAGE * N];
  for (int8_t i = 0; i < TAILLE_MESSAGE; i++) {
    for (int8_t j = 0; j < N; j++) {
      messageEtaler[j + i * N] =  0;
    }
  }
}

void Emeteur::etalage(int8_t * messageCoder){
    for (int8_t i = 0; i < TAILLE_MESSAGE; i++) {
      for (int8_t j = 0; j < N; j++) {
        messageEtaler[j + i * N]  +=  messageCoder[ j + i * N];
      }
    }
}


void Emeteur::afficher(){
  printf("\n\nMessage Etaler : ");
  for(int i = 0 ;  i < TAILLE_MESSAGE; i++ ){
    for (int j = 0; j < N; j++)
      printf("%2d ", messageEtaler[j + i * N]);
    printf("   ");
  }
  printf("\n");
}


int8_t* Emeteur::getMessageEtaler(){
  return messageEtaler;
}
