#ifndef __2048I_N__
#define __2048I_N__
#include "Jeu.hpp"
#include "QuaranteHuit.hpp"

class QuaranteHuitNegatif : public QuaranteHuit
{
    public:
        QuaranteHuitNegatif();
        void ajouterNombre() override;
};
#endif
