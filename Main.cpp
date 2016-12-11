#include <iostream>
#include "Case.hpp"
#include "Plateau.hpp"
using namespace std;

int main()
{
    Plateau<int> *p = new Plateau<int>(10,10);
    p->setValeur(1,1,20);
    cout << p->getCase(1,1).getValeur() << endl;
    return 0;
}