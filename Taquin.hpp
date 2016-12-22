#ifndef __TAQUIN_H__
#define __TAQUIN_H__
#include "Jeu.hpp"
#include <vector>
#include <set>
#include <random>

class Taquin : public Jeu<int>
{
    public:
        Taquin();
        void creerPlateau(int x, int y);
        void afficher();
        int partieterminee();
        void jouerlecoup(int dir);
	string format(int n);
	bool estSolvable(vector<int> vec, int x, int y, int pos);

    private:
        Plateau<int> *plateau;
};
#endif
