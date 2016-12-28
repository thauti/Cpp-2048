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
    char ligne;
    cout << "Nombre de lignes ? ";
    cin >> ligne;
    char colonne;
    cout << "Nombre de colonnes ? ";
    cin >> colonne;
    int l = ligne - '0';
    int c = colonne - '0';
    if(jeu == '1'){
	QuaranteHuit* j = new QuaranteHuit();
    	j->creerPlateau(c,l);
    	j->jouer();
    }
    if(jeu == '2'){
	Taquin* t = new Taquin();
    	t->creerPlateau(c,l);
    	t->jouer();
    }
    if(jeu == '3')
    {
	QuaranteHuitimpaire* j = new QuaranteHuitimpaire();
	j->creerPlateau(c,l);
	j->jouer();
    }
    if(jeu == '4')
    {
	QuaranteHuitNegatif* j = new QuaranteHuitNegatif();
	j->creerPlateau(c,l);
	j->jouer();
    }
    return 0;
}
