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
            cout<< "Set Valeur à " << v << endl; 
            valeur = v;
            cout<< "Valeur à " << valeur << endl; 
        }
        T getValeur()
        {
            cout<< "Get valeur à " << valeur << endl; 

            return valeur;   
        }
    private:
        T valeur;
};
#endif