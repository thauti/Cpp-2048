#include <iostream>
#include "QuaranteHuit.hpp"

using namespace std;

int main()
{
    QuaranteHuit* j = new QuaranteHuit();
    j->creerPlateau();
    j->afficher();
    return 0;
}