#ifndef __2048_H__
#define __2048_H__
#include "Jeu.hpp"

class QuaranteHuit : public Jeu<int>
{
    public:
        QuaranteHuit();
        void creerPlateau(int x, int y);
        void afficher();
        int partieterminee();
        void jouerlecoup(int dir);
        virtual void ajouterNombre();
        Plateau<int> *plateau;
    private:
};
#endif