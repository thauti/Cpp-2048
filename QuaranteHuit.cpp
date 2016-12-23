#include <iostream>
#include "Plateau.hpp"
#include "QuaranteHuit.hpp"
#include <cstdlib>
#include <random>


#define HAUT 0
#define BAS 1
#define DROITE 2
#define GAUCHE 3

using namespace std;

QuaranteHuit::QuaranteHuit()
{

};
void QuaranteHuit::creerPlateau(int x, int y)
{
    plateau = new Plateau<int>(x,y); //Taille 2048 4x4
    random_device rd;
    int x1 = rd() % plateau->getTaillex();
    int y1 = rd() % plateau->getTailley();
    int x2 = x1;
    int y2 = y1;
    while(x2 == x1 || y2 == y1)
    {
        x2 = rd() % plateau->getTaillex();
        y2 = rd() % plateau->getTailley();
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
void QuaranteHuit::afficher()
{
    for(int j=0;j<plateau->getTailley();j++)
    {
        for(int i=0;i<plateau->getTaillex();i++)
        {
            cout << plateau->getCase(i,j).getValeur()<< " ";
        }
            cout << endl;
    }
}
int QuaranteHuit::partieterminee()
{
    int k = 0;
    for(int i=0; i<plateau->getTaillex();i++)
    {
        for(int j=0; j<plateau->getTailley();j++)
        {
            if(plateau->getCase(i,j).getValeur() == 2048){
                return 1;
            }
            if(plateau->getCase(i,j).getValeur() == 0)
            {
                k++;
            }
        }
    }
    if(k == 0)
    {
        return 2;
    }

    return 0;
}
void QuaranteHuit::jouerlecoup(int dir)
{
    if(dir == HAUT)
    {
        for(int j = 0; j<plateau->getTailley();j++)
        {
            for(int i =0; i<plateau->getTaillex();i++)
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
                        if(abs(plateau->getCase(i,u-1).getValeur()) == abs(plateau->getCase(i,j).getValeur()))
                        {
                            int tmp = plateau->getCase(i,j).getValeur();
                            plateau->setValeur(i,j, 0);
                            plateau->setValeur(i,u-1,tmp + plateau->getCase(i,u-1).getValeur());
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
        for(int j = plateau->getTailley()-1; j>=0;j--)
        {
            for(int i =0; i<plateau->getTaillex();i++)
            {
                if(j!=plateau->getTailley()-1 && plateau->getCase(i,j).getValeur() != 0)
                {
                    int u = j;
                    while(u < plateau->getTailley()-1 && plateau->getCase(i,u+1).getValeur() == 0)
                    {
                        u=u+1;
                    }
                    if(u+1 <= plateau->getTailley()-1)
                    {
                        if(abs(plateau->getCase(i,u+1).getValeur()) == abs(plateau->getCase(i,j).getValeur()))
                        {
                            int tmp = plateau->getCase(i,j).getValeur();
                            plateau->setValeur(i,j, 0);
                            plateau->setValeur(i,u+1,tmp + plateau->getCase(i,u+1).getValeur());
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



    if(dir == GAUCHE)
    {
        for(int j = 0; j<plateau->getTailley();j++)
        {
            for(int i =0; i<plateau->getTaillex();i++)
            {
                if(i!=0 && plateau->getCase(i,j).getValeur() != 0)
                {
                    int u = i;
                    while(u > 0 && plateau->getCase(u-1,j).getValeur() == 0)
                    {
                        u=u-1;
                    }
                    if(u-1 >= 0)
                    {
                        if(abs(plateau->getCase(u-1,j).getValeur()) == abs(plateau->getCase(i,j).getValeur()))
                        {
                            int tmp = plateau->getCase(i,j).getValeur();
                            plateau->setValeur(i,j, 0);
                            plateau->setValeur(u-1,j,tmp + plateau->getCase(u-1,j).getValeur());
                        }
                        else
                        {
                            int tmp = plateau->getCase(i,j).getValeur();
                            plateau->setValeur(i,j, 0);
                            plateau->setValeur(u,j, tmp);
                        }
                    }
                    else
                    {
                        int tmp = plateau->getCase(i,j).getValeur();
                        plateau->setValeur(i,j, 0);
                        plateau->setValeur(u,j, tmp);
                    }

                }
            }
        }
    }
        if(dir == DROITE)
    {
        for(int j =0; j<plateau->getTailley(); j++)
        {
            for(int i= plateau->getTaillex()-1; i>=0; i--)
            {
                if(i!=plateau->getTaillex()-1 && plateau->getCase(i,j).getValeur() != 0)
                {
                    int u = i;
                    while(u < plateau->getTaillex()-1 && plateau->getCase(u+1,j).getValeur() == 0)
                    {
                        u=u+1;
                    }
                    if(u+1 <= plateau->getTaillex()-1)
                    {
                        if(abs(plateau->getCase(u+1,j).getValeur()) == abs(plateau->getCase(i,j).getValeur()))
                        {
                            int tmp = plateau->getCase(i,j).getValeur();
                            plateau->setValeur(i,j, 0);
                            plateau->setValeur(u+1,j,tmp + plateau->getCase(u+1,j).getValeur());
                        }
                        else
                        {
                            int tmp = plateau->getCase(i,j).getValeur();
                            plateau->setValeur(i,j, 0);
                            plateau->setValeur(u,j, tmp);
                        }
                    }
                    else
                    {
                        int tmp = plateau->getCase(i,j).getValeur();
                        plateau->setValeur(i,j, 0);
                        plateau->setValeur(u,j, tmp);
                    }

                }
            }
        }
    }
    ajouterNombre();
}

 void QuaranteHuit::ajouterNombre()
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
       int d = rd() % 2;
       if(d == 0)
       {
           plateau->setValeur(tx,ty,4);
       }
       else
       {plateau->setValeur(tx,ty,2);}

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
       plateau->setValeur(tx,ty,2);
   }
}
