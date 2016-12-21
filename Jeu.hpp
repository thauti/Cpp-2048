#ifndef __JEU_H__
#define __JEU_H__
#include "Plateau.hpp"
#include <ctime>
#include <iostream>

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
            while(partieterminee() != 1 && partieterminee() != 2) // TO DO == 2 (Perdu)
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
            srand(time(0));
            int i = rand() % 4;
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
        virtual void creerPlateau(int x, int y) = 0;
        virtual int partieterminee() = 0;
        virtual void afficher() = 0;
        virtual void jouerlecoup(int dir) = 0;

    private:
        Plateau<T> *plateau;
};
#endif
