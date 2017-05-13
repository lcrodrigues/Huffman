#include <cstdio>
#include <iostream>
#include <string>
#include "simbolo.h"

using namespace std;

Simbolo::Simbolo() {}

Simbolo::Simbolo(string caractere, int quantidade) { 
    this->caractere = caractere;
    this->quantidade = quantidade;
}

string Simbolo::getCaractere() { return this->caractere; }
string Simbolo::getCodigo() { return this->codigo; }
double Simbolo::getProbabilidade(){ return this->probabilidade; }
int Simbolo::getQuantidade() { return this->quantidade; }

void Simbolo::setCaractere(string caractere) { this->caractere = caractere; }
void Simbolo::setQuantidade(int quantidade) { this->quantidade = quantidade; }
void Simbolo::setCodigo(string codigo) { this->codigo = codigo; }
void Simbolo::setProbabilidade(double probabilidade) { this->probabilidade = probabilidade; }
void Simbolo::setEsquerda(Simbolo *esquerda) { this->esquerda = esquerda; }
void Simbolo::setDireita(Simbolo *direita) { this->direita = direita; }

void Simbolo::aumentarQuantidade() { this->quantidade++; } 