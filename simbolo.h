#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Simbolo {
private:
    string caractere;
    string codigo;
    int quantidade;
    double probabilidade;

public:
    Simbolo *esquerda;
    Simbolo *direita;
    
    Simbolo();
    Simbolo(string caractere, int quantidade);

    string getCaractere();    
    string getCodigo();
    double getProbabilidade();
    int getQuantidade(); 

    void setCaractere(string caractere);
    void setQuantidade(int quantidade);
    void setCodigo(string codigo);
    void setProbabilidade(double probabilidade);
    void setEsquerda(Simbolo *esquerda);
    void setDireita(Simbolo *direita);

    void aumentarQuantidade();
};