#include "personaje.h"

Personaje::Personaje()
{
    //textura
    _velocidad={4,4};
    _texture.loadFromFile("Divyr.png");
    _sprite.setTexture(_texture);
    //para girarlo en su propio eje
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
}
void Personaje::update()
{
     _velocidad={0,0};
//movimientos con teclado
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
    _velocidad.y=-4;
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
{
    _velocidad.y=4;
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
    _velocidad.x=-4;
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
   _velocidad.x=4;
}

_sprite.move(_velocidad);

//mira para donde camina
if(_velocidad.x<0)
{
    _sprite.setScale(-1,1);
}
else if(_velocidad.x>0)
{
    _sprite.setScale(1,1);

}
//gira en su eje



//para que no salga de la pantalla
//margen superior izquierdo
if(_sprite.getGlobalBounds().left<0)
{
    _sprite.setPosition(_sprite.getOrigin().x,_sprite.getPosition().y);
}
if(_sprite.getGlobalBounds().top<0)
{
    _sprite.setPosition(_sprite.getPosition().x,_sprite.getOrigin().y);
}


//margen inferior derecho
if(_sprite.getGlobalBounds().left+_sprite.getGlobalBounds().width>800)
{
    _sprite.setPosition(800-(_sprite.getGlobalBounds().width - _sprite.getOrigin().x),_sprite.getPosition().y);
}
if(_sprite.getGlobalBounds().top+_sprite.getGlobalBounds().height>600)
{
    _sprite.setPosition(_sprite.getPosition().x,600 + (_sprite.getGlobalBounds().height-_sprite.getOrigin().y) );
}
}

void Personaje::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
    target.draw(_sprite, states);
}
