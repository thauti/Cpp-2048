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
    plateau = new Plateau<int>(SIZE,SIZE); //Taille 2048 5x5
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
}
void QuaranteHuit::afficher()
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
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
}
void QuaranteHuit::jouerlecoup(int dir)
{
    switch(dir)
    {
        case HAUT: break; // Jouer vers le HAUT
        case BAS: break;
        case DROITE: break;
        case GAUCHE: break;
    }
}