#ifndef __CASE_H__
#define __CASE_H__

using namespace std;
template <class T>
class Case
{
    public:
        Case(T v){
            valeur = v;
        }
        Case()
        {
            valeur = 0;
        }
        void setValeur(T v)
        {
            valeur = v;
        }
        T getValeur()
        {
            return valeur;   
        }
    private:
        T valeur;
};
#endif