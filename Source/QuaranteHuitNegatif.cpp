#include <iostream>
#include "Plateau.hpp"
#include "QuaranteHuit.hpp"
#include "QuaranteHuitNegatif.hpp"
#include <cstdlib>
#include <random>

#define HAUT 0
#define BAS 1
#define DROITE 2
#define GAUCHE 3

QuaranteHuitNegatif::QuaranteHuitNegatif()
{
};

void QuaranteHuitNegatif::ajouterNombre()
{
    int tx, ty;
    int k = 0;
    for(int j=0;j<plateau->getTailley();j++)
    {
        for(int i=0; i<plateau->getTaillex();i++)
        {
            if(plateau->getCase(i,j).getValeur() == 0)
            {
                k++;
                tx = i;
                ty = j;
            }
        }
    }
   if(k == 1)
   {
        random_device rd;
        int d = ((rd() % 2) + 1) * 2;
	int d2 = (rd() % 2);
	d = d2==0?d:(d*(-1));
        plateau->setValeur(tx,ty,(d));

   }
   if(k>1)
   {
       random_device rd;
       tx = rd() % plateau->getTaillex();
       ty = rd() % plateau->getTailley();
       while(plateau->getCase(tx,ty).getValeur() != 0)
       {
           tx = rd() % plateau->getTaillex();
           ty = rd() % plateau->getTailley();
       }
	int d = ((rd() % 2) + 1) * 2;
	int d2 = (rd() % 2);
	d = d2==0?d:(d*(-1));
        plateau->setValeur(tx,ty,(d));
   }
}
