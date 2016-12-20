#include <iostream>
#include "QuaranteHuit.hpp"

using namespace std;

int main()
{
    QuaranteHuit* j = new QuaranteHuit();
    j->creerPlateau(10,10);
    j->jouer();
    return 0;
}