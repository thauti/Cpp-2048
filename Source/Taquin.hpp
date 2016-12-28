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
        int partieterminee();
        void jouerlecoup(int dir);
	bool estSolvable(vector<int> vec, int x, int y, int pos);
};
#endif
