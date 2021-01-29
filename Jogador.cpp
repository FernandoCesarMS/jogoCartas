#include "Jogador.hpp"
#include "Carta.hpp"

Jogador::Jogador () {
	this->_nomeJogador = "";
}

void Jogador::adicionaCarta (Carta carta){
	this->_cartas.push_back(carta);
}
	
string Jogador::getNomeJogador(){
	return this->_nomeJogador;
}

void Jogador::setNomeJogador(string nome){
	this->_nomeJogador = nome;
}

int Jogador::calcularPontuacao(){
	int total_pontos = 0;
	for (int i=0;i<this->_cartas.size();i++) {
        total_pontos += this->_cartas[i].getTotalPontos();
    }
	return total_pontos;
}

vector<Carta> Jogador::getCartas(){
	return this->_cartas;
}

void Jogador::setCartas(vector<Carta> cartas){
	this->_cartas = cartas;
}