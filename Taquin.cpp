#include <iostream>
#include "Plateau.hpp"
#include "Taquin.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>

#define HAUT 0
#define BAS 1
#define DROITE 2
#define GAUCHE 3

using namespace std;

Taquin::Taquin()
{
};
void Taquin::creerPlateau(int x, int y)
{
    plateau = new Plateau<int>(x,y);
    srand(time(0));
    vector<int> vec;
    int n = 0;
    while(n < x*y)
    {
      vec.push_back(n++);
    }
    for(int i = 0; i < plateau->getTaillex(); i++)
    {
      for(int j = 0; j < plateau->getTailley(); j++)
      {
	int k = rand() % vec.size();
	plateau->setValeur(i,j,vec[k]);
	vec.erase(vec.begin()+k);
      }
    }
}

string Taquin::format(int n)
{
    string s = to_string(n);
    int l = s.length();
    for(int i = 0; i < (5-l)/2; i++)
    {
    	s = " " + s;
    }
    int j = (5-l)%2==0?0:1;
    for(int i = 0; i < (5-l)/2+j; i++)
    {
    	s += " ";
    }
    return s;
}

void Taquin::afficher()
{
    for(int j=0;j<plateau->getTailley();j++)
    {
    	cout << "-";
    	for(int j=0;j<plateau->getTaillex();j++)
    	{
		cout << "------";
    	}
    	cout << endl << "|";
    	for(int j=0;j<plateau->getTaillex();j++)
    	{
		cout << "     |";
    	}
	cout << endl << "|";
        for(int i=0;i<plateau->getTaillex();i++)
        {
        	cout << format(plateau->getCase(i,j).getValeur()) << "|";
        }
    	cout << endl << "|";
    	for(int j=0;j<plateau->getTaillex();j++)
    	{
		cout << "     |";
    	}
	cout << endl;
    }
    cout << "-";
    for(int j=0;j<plateau->getTaillex();j++)
    {
	cout << "------";
    }
    cout << endl;
}
int Taquin::partieterminee()
{
    for(int i=0; i<plateau->getTaillex();i++)
    {
        for(int j=0; j<plateau->getTailley();j++)
        {
	  if(plateau->getCase(i,j).getValeur() != (j*plateau->getTailley()+i+1) && plateau->getCase(i,j).getValeur() != 0)
	  {
	    return 0;
	  }
	}
    }
    return 1;
}
void Taquin::jouerlecoup(int dir)
{
  if(dir == GAUCHE)
    {
      cout << "GAUCHE" << endl;
      for(int i=0; i<plateau->getTaillex();i++)
	{
	  for(int j=0; j<plateau->getTailley();j++)
	    {
	      if(plateau->getCase(i,j).getValeur() == 0)
		{
		  if(i == plateau->getTaillex()-1)
		    {
		      cout << "Vous ne pouvez pas jouer ce coup." << endl;
		      return;
		    }
		  plateau->setValeur(i,j,plateau->getCase(i+1,j).getValeur());
		  plateau->setValeur(i+1,j,0);
		return;
		}
	    }
	}
    }
  if(dir == DROITE)
    {
      cout << "DROITE" << endl;
      for(int i=0; i<plateau->getTaillex();i++)
	{
	  for(int j=0; j<plateau->getTailley();j++)
	    {
	      if(plateau->getCase(i,j).getValeur() == 0)
		{
		  if(i == 0)
		    {
		      cout << "Vous ne pouvez pas jouer ce coup." << endl;
		      return;
		    }
		  plateau->setValeur(i,j,plateau->getCase(i-1,j).getValeur());
		  plateau->setValeur(i-1,j,0);
		return;
		}
	    }
	}
    }
  if(dir == BAS)
    {
      cout << "BAS" << endl;
      for(int i=0; i<plateau->getTaillex();i++)
	{
	  for(int j=0; j<plateau->getTailley();j++)
	    {
	      if(plateau->getCase(i,j).getValeur() == 0)
		{
		  if(j == 0)
		    {
		      cout << "Vous ne pouvez pas jouer ce coup." << endl;
		      return;
		    }
		  plateau->setValeur(i,j,plateau->getCase(i,j-1).getValeur());
		  plateau->setValeur(i,j-1,0);
		return;
		}
	    }
	}
    }
    if(dir == HAUT)
    {
      cout << "HAUT" << endl;
      for(int i=0; i<plateau->getTaillex();i++)
	{
	  for(int j=0; j<plateau->getTailley();j++)
	    {
	      if(plateau->getCase(i,j).getValeur() == 0)
		{
		  if(j == plateau->getTailley()-1)
		    {
		      cout << "Vous ne pouvez pas jouer ce coup." << endl;
		      return;
		    }
		  plateau->setValeur(i,j,plateau->getCase(i,j+1).getValeur());
		  plateau->setValeur(i,j+1,0);
		return;
		}
	    }
	}
    }
}
