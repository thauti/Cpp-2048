#ifndef __PLATEAU_H__
#define __PLATEAU_H__
#include "Case.hpp"

template <class T>
class Plateau
{
    public:
        Plateau(const int x, const int y)
        {
            plateau = new Case<T>*[y];
            for(int i = 0; i<x;i++)
            {
                plateau[i] = new Case<T>[x];
            }
            taillex = x;
            tailley = y;
        }
        int getTaillex(){
            return taillex;
        }
        int getTailley(){
            return tailley;
        }
        /*
        Ne fonctionne pas, renvoie une copie de l'objet et non une référence
        */
        Case<T> getCase(int x, int y)
        {
            return plateau[x][y];
        }
        /*
        Solution tricky
        */
        void setValeur(int x, int y, int v)
        {
            plateau[x][y] = v;
        }
    private:
        int taillex;
        int tailley;
        Case<T>** plateau;
};
#endif