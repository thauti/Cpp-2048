#ifndef __2048_H__
#define __2048_H__
#include "Jeu.hpp"

class QuaranteHuit : public Jeu<int>
{
    public:
        QuaranteHuit();
        void creerPlateau();
        void afficher();
        int partieterminee();
        void jouerlecoup(int dir);
        void ajouterNombre();

    private:
        Plateau<int> *plateau;
};
#endif