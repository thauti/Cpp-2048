#include <iostream>
#include "Plateau.hpp"
#include "QuaranteHuit.hpp"

using namespace std;

QuaranteHuit::QuaranteHuit()
{
    plateau = new Plateau<int>(10,10);
};
void QuaranteHuit::creerPlateau()
{
    plateau = new Plateau<int>(5,5); //Taille 2048 5x5
    plateau->setValeur(0,1,2);
}
void QuaranteHuit::afficher()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout << plateau->getCase(i,j).getValeur();
        }
            cout << endl;
    }
}