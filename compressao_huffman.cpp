#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "simbolo.h"
#include <queue>
#include <sstream>
#include <functional>
#include <stack>

using namespace std;

struct MaiorProbabilidade {
    bool operator () (Simbolo* lhs, Simbolo* rhs) const { 
        return lhs->getProbabilidade() > rhs->getProbabilidade(); 
    }
};

bool buscarNaLista(vector<Simbolo*> vec_s, string s) {
    for(int i = 0; i < vec_s.size(); i++) {
        int c = s.compare(vec_s.at(i)->getCaractere());

        if(c == 0) {
            vec_s.at(i)->aumentarQuantidade();
            return true;
        }
    }   
    return false;
}

struct Raiz {
    Simbolo *raiz_arvore;
};

void gerarArvore(priority_queue<Simbolo*, vector<Simbolo*>, MaiorProbabilidade> *pq_simbolo, struct Raiz *r) {

    while(pq_simbolo->size() > 1) {
        Simbolo *s = new Simbolo();

        s->setDireita(pq_simbolo->top());
        pq_simbolo->pop();

        s->setEsquerda(pq_simbolo->top());
        pq_simbolo->pop();

        s->setCaractere(s->esquerda->getCaractere() + s->direita->getCaractere());
        s->setQuantidade(s->esquerda->getQuantidade() + s->direita->getQuantidade());
        s->setProbabilidade(s->esquerda->getProbabilidade() + s->direita->getProbabilidade());

        pq_simbolo->push(s);
    }

    r->raiz_arvore = new Simbolo();
    r->raiz_arvore = pq_simbolo->top();
    pq_simbolo->pop();
}

void calcularProbabilidade(vector<Simbolo*> vec_s, double total) {
    for(int i = 0; i < vec_s.size(); i++) {
        double p = vec_s.at(i)->getQuantidade() / total;
        vec_s.at(i)->setProbabilidade(p);
    }
}

void gerarTabela(Simbolo *raiz, vector<int> *comp, vector<int> *cod, stack<string> *pbits) {
    
    stack<string> pilha_codigo = *pbits;

    cout << pilha_codigo.top() << endl;
    pilha_codigo.pop();

 /*   if(!raiz) {
        pbits->push("0");
        gerarTabela(raiz->esquerda, comp, cod, pbits);
        pbits->pop();

        pbits->push("1");
        gerarTabela(raiz->direita, comp, cod, pbits);
        pbits->pop();

    }
    else{
        stack<string> pilha_codigo = *pbits;

        while(!pilha_codigo.empty()) {
            cout << pilha_codigo.top() << endl;
            pilha_codigo.pop();
        }

    }   */
}   

void exibirArvore(Simbolo *s) {
    cout << s->getCaractere() << endl;
    if(s->esquerda)
        exibirArvore(s->esquerda);
    if(s->direita)
        exibirArvore(s->direita);    
}

int main(){

    string entrada;
    vector<Simbolo*> vec_s;

    cout << "Entrada para compressão: \n";
    getline(cin, entrada);

    int total = entrada.length();

    for(int i = 0; i < total; i++) {
        stringstream ss;
        string aux;

        ss << entrada[i];
        ss >> aux;

        if(vec_s.empty())
            vec_s.push_back(new Simbolo(aux, 1));
        else {
            if(!buscarNaLista(vec_s, aux))
                vec_s.push_back(new Simbolo(aux, 1));
            
        }
    }

    double t = (double) total;
    calcularProbabilidade(vec_s, t);

    for(int i = 0; i < vec_s.size(); i++) {
        cout << "Caractere " << vec_s.at(i)->getCaractere();
        cout << ", repetições " <<  vec_s.at(i)->getQuantidade();
        cout << ", probabilidade " << vec_s.at(i)->getProbabilidade() * 100 << "%" << endl;
    }
    cout << endl << endl;

    priority_queue<Simbolo*, vector<Simbolo*>, MaiorProbabilidade> pq_simbolo; 

    for(int i = 0; i < vec_s.size(); i++) {
        pq_simbolo.push(vec_s.at(i));
    }

    struct Raiz *raiz = new struct Raiz;

    gerarArvore(&pq_simbolo, raiz);
    
    stack<string> pbits;
    vector<int> comp;
    vector<int> cod;

    pbits.push("4");
    pbits.push("4");
    pbits.push("4");
    pbits.push("4");
    pbits.push("4");
    pbits.push("4");

    gerarTabela(raiz->raiz_arvore, &comp, &cod, &pbits);
    
    return 0;
}
