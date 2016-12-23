#include <iostream>
#include "QuaranteHuit.hpp"
#include "QuaranteHuitimpaire.hpp"
#include "QuaranteHuitNegatif.hpp"
#include "Taquin.hpp"

using namespace std;

int main()
{
    char jeu;
    cout << "1 => 2048 normal | 2 => Taquin | 3 => 2048 impair | 4 => 2048 négatif: ";
    cin >> jeu;
    if(jeu == '1'){
	QuaranteHuit* j = new QuaranteHuit();
    	j->creerPlateau(4,4);
    	j->jouer();
    }
    if(jeu == '2'){
	Taquin* t = new Taquin();
    	t->creerPlateau(4,4);
    	t->jouer();
    }
    if(jeu == '3')
    {
	QuaranteHuitimpaire* j = new QuaranteHuitimpaire();
	j->creerPlateau(4,4);
	j->jouer();
    }
    if(jeu == '4')
    {
	QuaranteHuitNegatif* j = new QuaranteHuitNegatif();
	j->creerPlateau(4,4);
	j->jouer();
    }
    return 0;
}
