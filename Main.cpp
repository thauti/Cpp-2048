#include <iostream>
#include "QuaranteHuit.hpp"
#include "QuaranteHuitimpaire.hpp"
#include "Taquin.hpp"

using namespace std;

int main()
{
    int jeu = 2;
    if(jeu == 1){
	QuaranteHuit* j = new QuaranteHuit();
    	j->creerPlateau(4,4);
    	j->jouer();
    }
    if(jeu == 2){
	Taquin* t = new Taquin();
    	t->creerPlateau(4,4);
    	t->jouer();
    }
    if(jeu == 3)
    {
	QuaranteHuitimpaire* j = new QuaranteHuitimpaire();
	j->creerPlateau(4,4);
	j->jouer();
    }
    return 0;
}
