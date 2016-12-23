#include <iostream>
#include "Plateau.hpp"
#include "Taquin.hpp"
#include <cstdlib>

#define HAUT 0
#define BAS 1
#define DROITE 2
#define GAUCHE 3

using namespace std;

Taquin::Taquin()
{
};

bool Taquin::estSolvable(vector<int> vec, int x, int y, int pos)
{
    int tmp = 0; 
    int cpt = 0;
    int cpt2 = 0;
    set<int> s;
    for(int i = 0; i < (x*y); i++)
    {
	cpt = 0;
	if(s.find(i) != s.end())
	{
	    continue;
	}
	tmp = i;
	do
	{
	    s.insert(tmp);
	    tmp = vec[tmp];
	    cpt++;
	}
	while(tmp != i);
	cpt2 += cpt-1;
    }
    cpt2 += (x*y-1);
    int dis = (y-1-pos/y) + (x-1-pos%x);
    return (cpt2%2) == (dis%2);
}

void Taquin::creerPlateau(int x, int y)
{
    plateau = new Plateau<int>(x,y);
    random_device rd;
    vector<int> vec;
    vector<int> vec2;
    int n = 0;
    while(n < x*y)
    {
      vec.push_back(n++);
    } 
    for(int i = 0; i < plateau->getTaillex(); i++)
    {
      for(int j = 0; j < plateau->getTailley(); j++)
      {
	int k = rd() % vec.size();
	plateau->setValeur(i,j,vec[k]);
	if(vec[k] == 0)
	{
	    n = vec2.size();
	}
	vec2.push_back(vec[k]);
	vec.erase(vec.begin()+k);
      }
    }
    if(!estSolvable(vec2,x,y,n))
    {
	creerPlateau(x,y);
    }
}

string Taquin::format(int n)
{
    string s = n==0?" ":to_string(n);
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
    for(int j=0;j<plateau->getTaillex();j++)
    {
    	cout << "-";
    	for(int j=0;j<plateau->getTailley();j++)
    	{
		cout << "------";
    	}
    	cout << endl << "|";
    	for(int j=0;j<plateau->getTailley();j++)
    	{
		cout << "     |";
    	}
	cout << endl << "|";
        for(int i=0;i<plateau->getTailley();i++)
        {
        	cout << format(plateau->getCase(j,i).getValeur()) << "|";
        }
    	cout << endl << "|";
    	for(int j=0;j<plateau->getTailley();j++)
    	{
		cout << "     |";
    	}
	cout << endl;
    }
    cout << "-";
    for(int j=0;j<plateau->getTailley();j++)
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
	  if(plateau->getCase(i,j).getValeur() != (i*plateau->getTaillex()+j+1) && plateau->getCase(i,j).getValeur() != 0)
	  {
	    return 0;
	  }
	}
    }
    return 1;
}
void Taquin::jouerlecoup(int dir)
{
  if(dir == HAUT)
    {
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
  if(dir == BAS)
    {
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
  if(dir == DROITE)
    {
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
    if(dir == GAUCHE)
    {
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
