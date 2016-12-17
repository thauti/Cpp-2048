#include <iostream>
#include "QuaranteHuit.hpp"

using namespace std;

int main()
{
    QuaranteHuit* j = new QuaranteHuit();
    j->creerPlateau();
    j->jouer();
    return 0;
}