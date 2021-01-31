#include "Partida.hpp"
#include "Jogador.hpp"
#include <vector>

Partida::Partida(int num_jogadores)
{
    this->_num_jogadores = num_jogadores;
    this->_jogadores = new Jogador[num_jogadores];
    this->_atualSize = 0;
}
void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe)
{
    bool existeJogador = false;
    Carta cartaAtual(numero_pontos_carta, naipe);
    for (int i = 0; i < this->_num_jogadores; i++)
    {
        if (_jogadores[i].getNomeJogador() == nomeJogador)
        {
            _jogadores[i].adicionaCarta(cartaAtual);
            break;
        }
        else if (i == this->_num_jogadores - 1)
        {
            _jogadores[this->_atualSize].setNomeJogador(nomeJogador);
            _jogadores[this->_atualSize].adicionaCarta(cartaAtual);
            this->_atualSize++;
        }
    }
}
int Partida::getNumJogadores()
{
    return this->_num_jogadores;
}
int Partida::getNumAtualJogadores()
{
    return this->_atualSize;
}
void Partida::setJogadores(Jogador *jogadores)
{
    this->_jogadores = jogadores;
}
Jogador *Partida::getJogadores()
{
    return this->_jogadores;
}
Jogador Partida::getCampeao()
{
    int indiceMenor = 0;
    for (int i = 1; i < this->_atualSize; i++)
    {
        if (this->_jogadores[i].calcularPontuacao() > this->_jogadores[indiceMenor].calcularPontuacao())
        {
            indiceMenor = i;
        }
    }
    return this->_jogadores[indiceMenor];
}
Jogador *Partida::getJogadoresOrdenados()
{
    return this->_jogadores;
}
void Partida::imprimeJogadoresOrdenados()
{
    vector<Jogador> aux;
    for (int i = 0; i < this->_atualSize; i++)
    {
        aux.push_back(this->_jogadores[i]);
    }
    for (int i = 0; aux.size() > 0; i++)
    {
        int indiceMenor = 0;
        for (int j = 0; j < aux.size(); j++)
        {
            if (aux[j].calcularPontuacao() < aux[indiceMenor].calcularPontuacao())
            {
                indiceMenor = j;
            }
        }
        cout << aux[indiceMenor].getNomeJogador() << " " << aux[indiceMenor].calcularPontuacao() << endl;
        aux.erase(aux.begin() + indiceMenor);
    }
}