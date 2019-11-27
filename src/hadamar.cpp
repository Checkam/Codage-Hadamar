#include "hadamar.h"

#include <iostream>

#include <inttypes.h>

#define H0 1
#define TAILLE_MAX 128

Hadamar::Hadamar( uint8_t nbUtilisateurs) {

    if ( nbUtilisateurs <= 0 || nbUtilisateurs > TAILLE_MAX ) {

        printf("nbUtilisateurs inccorect, impossible d'initialiser la matrice (max : %d)\n", TAILLE_MAX);
        tab = NULL;
        return;
    }

    if ( nbUtilisateurs == 1 ) {

        tab = new int8_t *[1];
        (*tab) = new int8_t[1];

        **tab = 1;
        nbUtilisateursMax = H0;
        return;
    }

    /* calcul de la taille de la matrice */

    int utilisateursMax = 2;

    while ( utilisateursMax < nbUtilisateurs )
        utilisateursMax *= 2;

    nbUtilisateursMax = utilisateursMax;

    uint8_t taille = 2, taillePre = 1;

    tab = new int8_t *[taille];

    for ( uint8_t i ; i < taille ; i++ )
        *(tab + i) = new int8_t[taille];

    **tab = H0;
    **(tab + 1) = H0;
    *((*tab) + 1) = H0;
    *((*(tab + 1)) + 1) = -H0;

    int8_t tabPre[TAILLE_MAX][TAILLE_MAX];

    while ( taille != utilisateursMax ) {

        for ( uint8_t i = 0 ; i < taille ; i++ )
            for ( uint8_t j = 0 ; j < taille ; j++ )
                tabPre[i][j] = *((*(tab + i)) + j);

        for ( uint8_t i = 0 ; i < taille ; i++ )
            delete[] (*(tab + i));
        delete[] tab;

        taillePre *= 2;
        taille *= 2;

        /***tab = malloc( sizeof( int8_t *) * taille );*/
        tab = new int8_t *[taille];

        for ( uint8_t i = 0 ; i < taille ; i++ )
            /**(tab + i) = malloc( sizeof( int8_t) * taille );*/
            *(tab + i) = new int8_t[taille];

        /* carre en haut a gauche */

        for ( int i = 0 ; i < taillePre ; i++ ) {
            for ( int j = 0 ; j < taillePre ; j++ ) {
                /*printf("tabPre : %" PRId8" === i : %d = j : %d\n", tabPre[i][j], i, j);
                printf("tabval : %p\n", ((*(tab + i)) + j));*/
                *((*(tab + i)) + j) = tabPre[i][j];
            }
        }

        /* carre en haut a droite */

        for ( uint8_t i = 0 ; i < taillePre ; i++ )
            for ( uint8_t j = 0 ; j < taillePre ; j++ )
                *((*(tab + i)) + j + taillePre) = tabPre[i][j];

        /* carre en bas a gauche */

        for ( uint8_t i = 0 ; i < taillePre ; i++ )
            for ( uint8_t j = 0 ; j < taillePre ; j++ )
                *((*(tab + i + taillePre)) + j) = tabPre[i][j];

        /* carre en bas a droite */

        for ( uint8_t i = 0 ; i < taillePre ; i++ )
            for ( uint8_t j = 0 ; j < taillePre ; j++ )
                *((*(tab + i + taillePre)) + j + taillePre) = -(tabPre[i][j]);
    }
}

uint8_t Hadamar::getnbUtilisateursMax() {

    return nbUtilisateursMax;
}

int8_t *Hadamar::ligneHadamar( uint8_t ligne ) {

    if ( ligne < 0 || ligne > nbUtilisateursMax - 1 ) {

        printf("La ligne %d n'est pas comprise dans la matrice ( ligne 0 a %" PRIu8")\n", ligne, nbUtilisateursMax);
        return NULL;
    }

    return *(tab + ligne);
}

void Hadamar::atab() {

  printf("%p\n", tab);
}

void Hadamar::afficherMatrice() {

    for ( uint8_t i = 0 ; i < nbUtilisateursMax ; i++ ) {

        for ( uint8_t j = 0 ; j < nbUtilisateursMax ; j++ ) {

            printf("%2" PRId8"", *((*(tab + i)) + j));
        }
        printf("\n");
    }
}

Hadamar::~Hadamar() {

    for ( uint8_t i = 0 ; i < nbUtilisateursMax ; i++ )
        delete[] (*(tab + i));
    delete[] tab;
}
