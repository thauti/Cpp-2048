#include <iostream>
#include "Plateau.hpp"
#include "QuaranteHuit.hpp"
#include "QuaranteHuitimpaire.hpp"
#include <cstdlib>
#include <random>


#define HAUT 0
#define BAS 1
#define DROITE 2
#define GAUCHE 3

QuaranteHuitimpaire::QuaranteHuitimpaire()
{
};
void QuaranteHuitimpaire::ajouterNombre()
{
    cout << "Test" << endl;
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
        int d = rd() % 6;
        switch(d)
        {
            case 0: plateau->setValeur(tx,ty,4);
                    break;
            case 1: plateau->setValeur(tx,ty,2);
                    break;
            case 2: plateau->setValeur(tx,ty,1);
                    break;
            case 3: plateau->setValeur(tx,ty,3);
                    break;
            case 4: plateau->setValeur(tx,ty,5);
                    break;
            case 5: plateau->setValeur(tx,ty,7);
                    break;
            default: plateau->setValeur(tx,ty,2);break;
        }
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
        int d = rand() % 6;
        switch(d)
        {
            case 0: plateau->setValeur(tx,ty,4);
                    break;
            case 1: plateau->setValeur(tx,ty,2);
                    break;
            case 2: plateau->setValeur(tx,ty,1);
                    break;
            case 3: plateau->setValeur(tx,ty,3);
                    break;
            case 4: plateau->setValeur(tx,ty,5);
                    break;
            case 5: plateau->setValeur(tx,ty,7);
                    break;
            default: plateau->setValeur(tx,ty,2);break;
        }
   }
}
