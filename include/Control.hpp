#pragma once
#include <SFML/Graphics.hpp>

class Control
{
private:
    sf::Keyboard::Key arriba;
    sf::Keyboard::Key abajo;
    sf::Keyboard::Key derecha;
    sf::Keyboard::Key izquierda;
    
public:
    Control()
    {
        this->arriba = sf::Keyboard::Left;
        this->abajo = sf::Keyboard::Right;
        this->derecha = sf::Keyboard::Up;
        this->izquierda = sf::Keyboard::Down;
    }
    Control(sf::Keyboard::Key arriba,
            sf::Keyboard::Key abajo,
            sf::Keyboard::Key derecha,
            sf::Keyboard::Key izquierda)
    {
        this->arriba = arriba;
        this->abajo = abajo;
        this->derecha = derecha;
        this->izquierda = izquierda;
    }
    ~Control() {}
    sf::Keyboard::Key MoverArriba(){
        return this->arriba;
    }
    sf::Keyboard::Key MoverAbajo(){
        return this->abajo;
    }
    sf::Keyboard::Key MoverIzquierda(){
        return this->izquierda;
    }
    sf::Keyboard::Key MoverDerecha(){
        return this->derecha;
    }
};