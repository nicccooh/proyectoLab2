
#include <SFML/Graphics.hpp>
#include "personaje.h"
#include "personaje.cpp"
int main()
{   //inicio de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "THE DRAGON LORD");
    //limitar FPS a 60/s
    window.setFramerateLimit(60);
    //personaje
    Personaje Divyr;
//fondo
sf::Sprite image;
sf::Texture tex;
tex.loadFromFile("mario.jpg");

image.setTexture(tex);
//gameloop (update del juego)
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //readImput Actualizar los estados de los perifericos de entrada
            //leer cola de mensajes
            if (event.type == sf::Event::Closed)
                window.close();
        }

//update - Actualiza los estados del juego
        Divyr.update();


        window.clear();
        //draw
        window.draw(image);
        window.draw(Divyr);

        //display - flip
        window.display();

    }
//Liberacion del juego
    return 0;
}
