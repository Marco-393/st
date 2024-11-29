#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Personaje
{
public:
    Personaje(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);

        std::string personaje_1 = "ken.png";

        // Cargar la imagen desde un archivo
        
        if (!texture.loadFromFile("assets/images/" + personaje_1))
        {
        
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
  
    }

    void draw(sf::RenderWindow &window)
    {
        
        window.draw(this->sprite);
        
    }

    void update(){
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 64)+200, 133, 100, 100));
            clock.restart();
        }
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 4; // Número total de frames en la animación
    int frameWidth = 32;
    int frameHeight = 32;
};

class Personaje2
{
public:
    Personaje2(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);

        std::string personaje_2= "pikachu.png";
        // Cargar la imagen desde un archivo
        
        if (!texture.loadFromFile("assets/images/" + personaje_2))
        {
        
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
  
    }

    void draw(sf::RenderWindow &window)
    {
        
        window.draw(this->sprite);
        
    }

    void update(){
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 64)+200, 133, 100, 100));
            clock.restart();
        }
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 4; // Número total de frames en la animación
    int frameWidth = 32;
    int frameHeight = 32;
};

double velocidad = 0.1;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DinoChrome");

    Personaje Ken(sf::Vector2f(100, 350), sf::Color::Red);
    Personaje2 pika(sf::Vector2f(600, 350), sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        //Ken
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Ken.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Ken.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Ken.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Ken.move(0, velocidad);
        }

        //Pika
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            pika.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            pika.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            pika.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            pika.move(0, velocidad);
        }


        // Actualizar animacion pikachu
        Ken.update();
        pika.update();

        window.clear();
        Ken.draw(window);
        pika.draw(window);
        window.display();
    }

    return 0;
}