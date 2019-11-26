#include <stdint.h>

class Hadamar {

    private :

        uint16_t nbUtilisateursMax;
        int8_t **tab;

    public :

        /* constructeur */

        /*Hadamar();*/
        Hadamar( uint8_t nbUtilisateurs);
        /*Hadamar( const Hadamar &);*/

        /* méthode */

        uint8_t getnbUtilisateursMax();
        int8_t *ligneHadamar( uint8_t ligne );
        void atab();
        void afficherMatrice();

        /* destructeur */

        ~Hadamar();
};
