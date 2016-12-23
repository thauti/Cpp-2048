#ifndef __JEU_H__
#define __JEU_H__
#include "Plateau.hpp"
#include <ctime>
#include <iostream>
#include <random>

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
        void jouer()
        {
            while(partieterminee() != 1 && partieterminee() != 2)
            {
                afficher();
                char input;
                cout << "Veuillez entrer une direction (h)aut, (b)as, (d)roite, (g)auche ou (i)a: ";
                cin >> input;
                while(!entreevalide(input))
                {
                    cout << "Invalide" << endl;
                    cout << "Veuillez entrer une direction (h)aut, (b)as, (d)roite, (g)auche  ou (i)a: ";
                    cin >> input;
                }
                if(input == 'i')
                {
                    jouerIA();
                }
                else
		{
		    jouerlecoup(chartocode(input));
		}
                
            }
            afficher();
            if(partieterminee() == 1)
            {
                cout << "Gagné !" << endl;
            }
            if(partieterminee() == 2)
            {
                cout << "Perdu :(" << endl;
            }
        }
        void jouerIA()
        {
	    random_device rd;
            int i = rd() % 4;
            jouerlecoup(i);

        }
        bool entreevalide(char c){
            if(c == 'h' || c =='b' || c == 'd' || c == 'g' || c == 'i')
            {
                return true;
            }
            else{
                return false;
            }
        }
        int chartocode(char c)
        {
            switch(c){
                case 'h': return 0;
                case 'b': return 1;
                case 'd': return 2;
                case 'g': return 3;
		default: return -1;
            }
        }
	string format(int n)
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

	void afficher()
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
        virtual void creerPlateau(int x, int y) = 0;
        virtual int partieterminee() = 0;
        virtual void jouerlecoup(int dir) = 0;

    protected:
        Plateau<T> *plateau;
};
#endif
