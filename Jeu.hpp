#ifndef __JEU_H__
#define __JEU_H__
#include "Plateau.hpp"

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
        int jouer()
        {
            while(partieterminee() != 1) // TO DO == 2 (Perdu)
            {
                afficher();
                char input;
                cout << "Veuillez entrer une direction (h)aut, (b)as, (d)roite, (g)auche : ";
                cin >> input;
                while(!entreevalide(input))
                {
                    cout << "Invalide" << endl;
                    cout << "Veuillez entrer une direction (h)aut, (b)as, (d)roite, (g)auche : ";
                    cin >> input;
                }
                
            }
        }
        bool entreevalide(char c){
            if(c == 'h' || c =='b' || c == 'd' || c == 'g')
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
            }
        }
        virtual void creerPlateau() = 0;
        virtual int partieterminee() = 0;
        virtual void afficher() = 0;
        virtual void jouerlecoup(int dir) = 0;

    private:
        Plateau<T> *plateau;
};
#endif