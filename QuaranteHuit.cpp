#include <iostream>
#include "Plateau.hpp"
#include "QuaranteHuit.hpp"
#include <cstdlib>
#include <ctime>

#define SIZE 4
#define HAUT 0
#define BAS 1
#define DROITE 2
#define GAUCHE 3

using namespace std;

QuaranteHuit::QuaranteHuit()
{
    plateau = new Plateau<int>(SIZE,SIZE);
};
void QuaranteHuit::creerPlateau()
{
    plateau = new Plateau<int>(SIZE,SIZE); //Taille 2048 4x4
    srand(time(0));
    int x1 = rand() % 4;
    int y1 = rand() % 4;
    int x2 = x1;
    int y2 = y1;
    while(x2 == x1 || y2 == y1)
    {
        x2 = rand() % 4;
        y2 = rand() % 4;
    }
    plateau->setValeur(x1,y1,2);
    plateau->setValeur(x2,y2,2);
    plateau->setValeur(x2,y2+1,2);
}
void QuaranteHuit::afficher()
{
    for(int j=0;j<SIZE;j++)
    {
        for(int i=0;i<SIZE;i++)
        {
            cout << plateau->getCase(i,j).getValeur();
        }
            cout << endl;
    }
}
int QuaranteHuit::partieterminee()
{
    for(int i=0; i<SIZE;i++)
    {
        for(int j=0; j<SIZE;j++)
        {
            if(plateau->getCase(i,j).getValeur() == 2048){
                return 1;
            }

            /*
                TO DO: Implementer la cas où on peut plus jouer et dans ce cas retourner 2 
            */
        }
    }
    return 0;
}
void QuaranteHuit::jouerlecoup(int dir)
{
    if(dir == HAUT)
    {
        cout << "Haut" << endl;
        for(int j = 0; j<SIZE;j++)
        {
            for(int i =0; i<SIZE;i++)
            {
                if(j!=0 && plateau->getCase(i,j).getValeur() != 0)
                {
                    int u = j;
                    while(u > 0 && plateau->getCase(i,u-1).getValeur() == 0)
                    {
                        u=u-1;
                    }
                    if(u-1 >= 0)
                    {
                        if(plateau->getCase(i,u-1).getValeur() == plateau->getCase(i,j).getValeur())
                        {
                            int tmp = plateau->getCase(i,j).getValeur();
                            plateau->setValeur(i,j, 0);
                            plateau->setValeur(i,u-1,tmp + plateau->getCase(i,u-1).getValeur());
                            cout << "Addition" << endl;
                        }
                        else
                        {
                            int tmp = plateau->getCase(i,j).getValeur();
                            plateau->setValeur(i,j, 0);
                            plateau->setValeur(i,u, tmp);
                        }
                    }
                    else
                    {
                        int tmp = plateau->getCase(i,j).getValeur();
                        plateau->setValeur(i,j, 0);
                        plateau->setValeur(i,u, tmp);
                    }

                }
            }
        }
    }
        if(dir == BAS)
    {
        cout << "BAS" << endl;
        for(int j = SIZE-1; j>=0;j--)
        {
            for(int i =0; i<SIZE;i++)
            {
                if(j!=SIZE-1 && plateau->getCase(i,j).getValeur() != 0)
                {
                    int u = j;
                    while(u < SIZE-1 && plateau->getCase(i,u+1).getValeur() == 0)
                    {
                        u=u+1;
                    }
                    if(u+1 <= SIZE-1)
                    {
                        if(plateau->getCase(i,u+1).getValeur() == plateau->getCase(i,j).getValeur())
                        {
                            int tmp = plateau->getCase(i,j).getValeur();
                            plateau->setValeur(i,j, 0);
                            plateau->setValeur(i,u+1,tmp + plateau->getCase(i,u+1).getValeur());
                            cout << "Addition" << endl;
                        }
                        else
                        {
                            int tmp = plateau->getCase(i,j).getValeur();
                            plateau->setValeur(i,j, 0);
                            plateau->setValeur(i,u, tmp);
                        }
                    }
                    else
                    {
                        int tmp = plateau->getCase(i,j).getValeur();
                        plateau->setValeur(i,j, 0);
                        plateau->setValeur(i,u, tmp);
                    }

                }
            }
        }
    }
    switch(dir)
    {
        case HAUT: break; // Jouer vers le HAUT
        case BAS: break;
        case DROITE: break;
        case GAUCHE: break;
    }
}