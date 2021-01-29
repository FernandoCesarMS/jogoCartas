#include "Partida.hpp"
#include "Jogador.hpp"

Partida::Partida(int num_jogadores){
    this->_num_jogadores = num_jogadores;
    this->_jogadores = new Jogador[num_jogadores];
    this->_atualSize = 0;
}
void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe){
    bool existeJogador = false;  
    Carta cartaAtual(numero_pontos_carta, naipe);
    for (int i=0;i<this->_num_jogadores;i++){
        if (_jogadores[i].getNomeJogador() == nomeJogador){
            _jogadores[i].adicionaCarta(cartaAtual);
            cout << "Nova carta adicionada!!!" << endl;
            break;
        }
        else if (i == this->_num_jogadores-1){
            cout << "Novo jogador criado!!!" << endl;
            _jogadores[this->_atualSize].setNomeJogador(nomeJogador);
            _jogadores[this->_atualSize].adicionaCarta(cartaAtual);
            this->_atualSize++;
        }
    }
}
int Partida::getNumJogadores(){
    return this->_num_jogadores;
}
int Partida::getNumAtualJogadores(){
    return this->_atualSize;
}
void Partida::setJogadores(Jogador* jogadores){
    this->_jogadores = jogadores;
}
Jogador* Partida::getJogadores(){
    return this->_jogadores;
}
Jogador Partida::getCampeao(){
    int indiceMenor = 0;
    return this->_jogadores[0];
}
Jogador* Partida::getJogadoresOrdenados(){
    return this->_jogadores;
}
void Partida::imprimeJogadoresOrdenados(){
    for (int i=0;i<this->_atualSize;i++){
        cout << endl << this->_jogadores[i].getNomeJogador() << " " << this->_jogadores[i].calcularPontuacao();
    }
}
/*
	~Partida();
	*/