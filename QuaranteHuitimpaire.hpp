#ifndef __2048I_H__
#define __2048I_H__
#include "Jeu.hpp"
#include "QuaranteHuit.hpp"

class QuaranteHuitimpaire : public QuaranteHuit
{
    public:
        QuaranteHuitimpaire();
        void ajouterNombre() override;
};
#endif
