#ifndef __TAQUIN_H__
#define __TAQUIN_H__
#include "Jeu.hpp"

class Taquin : public Jeu<int>
{
    public:
        Taquin();
        void creerPlateau(int x, int y);
        void afficher();
        int partieterminee();
        void jouerlecoup(int dir);
	string format(int n);

    private:
        Plateau<int> *plateau;
};
#endif
