#ifndef __PLATEAU_H__
#define __PLATEAU_H__
#include "Case.hpp"

template <class T>
class Plateau
{
    public:
        Plateau(const int x, const int y)
        {
            plateau = new Case<T>*[x];
            for(int i = 0; i<x;i++)
            {
                plateau[i] = new Case<T>[y];
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
        Case<T> getCase(int x, int y)
        {
            return plateau[x][y];
        }
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