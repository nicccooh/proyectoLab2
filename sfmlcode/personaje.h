#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
#include <SFML\Graphics.hpp>

class Personaje: public sf::Drawable
{
    private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocidad;
    public:
        Personaje();
        void update();
        void draw(sf::RenderTarget& target,sf::RenderStates states)const override;

};


#endif // PERSONAJE_H_INCLUDED
