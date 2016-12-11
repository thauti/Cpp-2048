#ifndef __JEU_H__
#define __JEU_H__
#include "Plateau.hpp"

using namespace std;
template <class T>
class Jeu
{
    public:
        Jeu(){};
        Plateau<T> getPlateau()
        {
            return plateau;
        }
        virtual void creerPlateau() = 0;
    private:
        Plateau<T> *plateau;
};
#endif