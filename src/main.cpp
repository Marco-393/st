// Ventana del Juego:

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(int argc, char const *argv[])
{
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


Gestión de los Personajes:

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


instancias de los personajes:

Personaje jugador1("sprite_jugador1.png", 100, 400);
Personaje jugador2("sprite_jugador2.png", 600, 400);


Controles:

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


Mecánicas de Combate:

void manejarAtaque(Personaje& atacante, Personaje& defensor, sf::Keyboard::Key teclaAtaque) {
    if (sf::Keyboard::isKeyPressed(teclaAtaque)) {
        // Comprueba si están cerca para atacar
        if (std::abs(atacante.getSprite().getPosition().x - defensor.getSprite().getPosition().x) < 50) {
            defensor.recibirDano(10);
        }
    }
}


Barra de Vida:

sf::RectangleShape barraVida1(sf::Vector2f(200, 20));
barraVida1.setFillColor(sf::Color::Green);
barraVida1.setPosition(50, 50);

sf::RectangleShape barraVida2(sf::Vector2f(200, 20));
barraVida2.setFillColor(sf::Color::Green);
barraVida2.setPosition(550, 50);


Actualiza las barras según la salud:

barraVida1.setSize(sf::Vector2f(jugador1.getVida() * 2, 20));
barraVida2.setSize(sf::Vector2f(jugador2.getVida() * 2, 20));


Audio:

sf::SoundBuffer bufferGolpe;
bufferGolpe.loadFromFile("golpe.wav");
sf::Sound sonidoGolpe;
sonidoGolpe.setBuffer(bufferGolpe);

sf::Music musica;
musica.openFromFile("musica_fondo.ogg");
musica.play();


Reproduce un sonido cuando ocurre un ataque:

if (atacando) {
    sonidoGolpe.play();
}
