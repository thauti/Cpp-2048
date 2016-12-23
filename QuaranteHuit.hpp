#ifndef __2048_H__
#define __2048_H__
#include "Jeu.hpp"
#include <random>

class QuaranteHuit : public Jeu<int>
{
    public:
        QuaranteHuit();
        void creerPlateau(int x, int y);
        int partieterminee();
        void jouerlecoup(int dir);
        virtual void ajouterNombre();
};
#endif
