// Ventana del Juego:

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "Street Fighter - Juego");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // Aquí dibujarás los gráficos.
        window.display();
    }

    return 0;
}


//Gestión de los Personajes:

class Personaje {
private:
    sf::Sprite sprite;
    sf::Texture textura;
    int vida;
    float velocidad;

public:
    Personaje(const std::string& archivo, float x, float y) {
        textura.loadFromFile(archivo);
        sprite.setTexture(textura);
        sprite.setPosition(x, y);
        vida = 100;
        velocidad = 5.0f;
    }

    void mover(float dx, float dy) {
        sprite.move(dx * velocidad, dy * velocidad);
    }

    void dibujar(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    int getVida() { return vida; }
    void recibirDano(int dano) { vida -= dano; }
};


//instancias de los personajes:

Personaje jugador1("sprite_jugador1.png", 100, 400);
Personaje jugador2("sprite_jugador2.png", 600, 400);


//Controles:

void procesarControles(Personaje& jugador1, Personaje& jugador2) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) jugador1.mover(0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) jugador1.mover(0, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) jugador1.mover(-1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) jugador1.mover(1, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) jugador2.mover(0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) jugador2.mover(0, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) jugador2.mover(-1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) jugador2.mover(1, 0);
}