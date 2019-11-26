#include <iostream>
#include "message.h"

void afficherTab(int8_t * tab, int C, char separateur){
    for (int j = 0; j < C; j++) {
      printf(" %d %c", tab[j], separateur);
    }
}

int8_t * etalage(int8_t ** messageEtaler, int8_t * messageCoder){
  if(!(*messageEtaler)){
    *messageEtaler = new int8_t[TAILLE_MESSAGE * N];

    for (int8_t i = 0; i < TAILLE_MESSAGE; i++) {
      for (int8_t j = 0; j < N; j++) {
        (*messageEtaler)[j + i * N] =  messageCoder[ j + i * N];
      }
    }
  }else{
    for (int8_t i = 0; i < TAILLE_MESSAGE; i++) {
      for (int8_t j = 0; j < N; j++) {
        (*messageEtaler)[j + i * N]  +=  messageCoder[ j + i * N];
      }
    }
  }

  return (*messageEtaler);
}

int8_t * desetalage(int8_t messageCoder[TAILLE_MESSAGE * N],int8_t indice, Hadamar &had){
  int8_t * messageDecoder = new int8_t[TAILLE_MESSAGE];
  int8_t somme = 0;
  int8_t* ligneHadamar = had.ligneHadamar(indice);
  had.afficherMatrice();
  for (int8_t i = 0; i < TAILLE_MESSAGE; i++) {
    for (int8_t j = 0; j < N; j++) {
      somme += (messageCoder[j + i * N] * ligneHadamar[j]);
    }
    if( somme == N){
      messageDecoder[i] = 1;
    }else if(somme == -N){
      messageDecoder[i] = 0;
    }
    somme = 0;
  }
  return messageDecoder;
}


void afficher1(int8_t * tab, const char * msg){
  printf("%s", msg);
  for (int i = 0; i < TAILLE_MESSAGE; i++) {
    for (int j = 0; j < N; j++) {
      printf(" %2d", tab[j + i * N]);
    }
    printf("    ");
  }
  printf("\n\n");
}



int main(){

  Hadamar had = Hadamar(N);
  had.afficherMatrice();
  int8_t * messageEtaler = NULL;
  printf(" --- apres creation : ");
  had.atab();

  Message message1 = Message("101");
  Message message2 = Message("011");
  Message message3 = Message("100");

  printf(" --- avant envoie : ");
  had.atab();
  int8_t * messageCoder1 = message1.coder(had,1);
  int8_t * messageCoder2 = message2.coder(had,3);
  int8_t * messageCoder3 = message3.coder(had,5);

  printf("\n\nCodage du message :");  message1.afficher();  afficher1(messageCoder1, "\n\nMessage Coder :");

  printf("\n\nCodage du message :");  message2.afficher();  afficher1(messageCoder2, "\n\nMessage Coder :");

  printf("\n\nCodage du message :");  message3.afficher();  afficher1(messageCoder3, "\n\nMessage Coder :");

  messageEtaler = etalage(&messageEtaler, messageCoder1);
  etalage(&messageEtaler, messageCoder2);
  etalage(&messageEtaler, messageCoder3);

  afficher1(messageEtaler, "\n\nMessage Etaler :");

  printf("Decodage : \n\n");
  int8_t * messageDecoder = desetalage(messageEtaler, 1, had); afficherTab(messageDecoder, TAILLE_MESSAGE,' '); printf("\n");
  messageDecoder = desetalage(messageEtaler, 3, had); afficherTab(messageDecoder, TAILLE_MESSAGE,' '); printf("\n");
  messageDecoder = desetalage(messageEtaler, 5, had); afficherTab(messageDecoder, TAILLE_MESSAGE,' '); printf("\n");

  return EXIT_SUCCESS;
}
