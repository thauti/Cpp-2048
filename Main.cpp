#include <iostream>
#include "QuaranteHuit.hpp"
#include "Taquin.hpp"

using namespace std;

int main()
{
    if(!true){
	QuaranteHuit* j = new QuaranteHuit();
    	j->creerPlateau(4,4);
    	j->jouer();
    }
    else{
	Taquin* t = new Taquin();
    	t->creerPlateau(2,2);
    	t->jouer();
    }
    return 0;
}
