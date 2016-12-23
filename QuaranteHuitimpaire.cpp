#include <iostream>
#include "Plateau.hpp"
#include "QuaranteHuit.hpp"
#include "QuaranteHuitimpaire.hpp"
#include <cstdlib>
#include <ctime>


#define HAUT 0
#define BAS 1
#define DROITE 2
#define GAUCHE 3

QuaranteHuitimpaire::QuaranteHuitimpaire()
{
};
void QuaranteHuitimpaire::creerPlateau(int x, int y)
{
    cout << "Hello" <<endl;
    plateau = new Plateau<int>(x,y); //Taille 2048 4x4
    srand(time(0));
    int x1 = rand() % plateau->getTaillex();
    int y1 = rand() % plateau->getTailley();
    int x2 = x1;
    int y2 = y1;
    while(x2 == x1 || y2 == y1)
    {
        x2 = rand() % plateau->getTaillex();
        y2 = rand() % plateau->getTailley();
    }
    for(int j=0;j<plateau->getTailley();j++)
    {
        for(int i=0;i<plateau->getTaillex();i++)
        {
            plateau->setValeur(i,j,0);
        }
    }
    plateau->setValeur(x1,y1,2);
    plateau->setValeur(x2,y2,2);
}
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
        srand(time(0));
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
   if(k>1)
   {
       srand(time(0));
       tx = rand() % plateau->getTaillex();
       ty = rand() % plateau->getTailley();
       while(plateau->getCase(tx,ty).getValeur() != 0)
       {
           tx = rand() % plateau->getTaillex();
           ty = rand() % plateau->getTailley();
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