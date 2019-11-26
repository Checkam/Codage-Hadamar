#include <iostream>
#include "message.h"
#include "emeteur.h"
#include "commun.h"

int8_t * desetalage(int8_t messageCoder[TAILLE_MESSAGE * N],int8_t indice, Hadamar &had){
  int8_t * messageDecoder = new int8_t[TAILLE_MESSAGE];
  int8_t somme = 0;
  int8_t* ligneHadamar = had.ligneHadamar(indice);
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

int main(){
  printf("\n\n"COLOR"Matrice d'Hadamar :"DEFAULT_COLOR"\n\n");
  Hadamar had = Hadamar(N);
  had.afficherMatrice();
  Emeteur emeteur = Emeteur();

  Message message1 = Message("101");
  Message message2 = Message("011");
  Message message3 = Message("100");

  int8_t * messageCoder1 = message1.coder(had,1);
  int8_t * messageCoder2 = message2.coder(had,3);
  int8_t * messageCoder3 = message3.coder(had,5);

  emeteur.etalage(messageCoder1);
  emeteur.etalage(messageCoder2);
  emeteur.etalage(messageCoder3);

  emeteur.afficher();

  printf("\n\n"COLOR"Decodage :"DEFAULT_COLOR"\n\n");
  Message messageDecoder = Message();

  messageDecoder.setMessage(desetalage(emeteur.getMessageEtaler(), 1, had));
  messageDecoder.afficher();
  messageDecoder.setMessage(desetalage(emeteur.getMessageEtaler(), 3, had));
  messageDecoder.afficher();
  messageDecoder.setMessage(desetalage(emeteur.getMessageEtaler(), 5, had));
  messageDecoder.afficher();

  return EXIT_SUCCESS;
}
