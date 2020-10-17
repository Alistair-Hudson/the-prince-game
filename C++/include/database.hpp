#ifndef __THE_PRINCE_DATABASE_HPP__
#define __THE_PRINCE_DATABASE_HPP__
/*****************************************************************************
 * DATATBASE API
 * Alistair Hudson
 * version 23.08.2020.0
******************************************************************************/


#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "faction.hpp"
#include "action.hpp"
#include "action_factory.hpp"
#include "animation.hpp"

#define TEXT_BOX_X  (0)
#define TEXT_BOX_Y  (800)

namespace the_prince
{
class TextHandler
{
public:
    TextHandler(){}

    sf::Text& operator[](int i)
    {
        return *m_texts[i];
    }
    void AddText(std::string string, std::string font_file)
    {
        sf::Text* text = new sf::Text;
        sf::Font* font = new sf::Font;
        font->loadFromFile(font_file);
        text->setPosition(sf::Vector2f(TEXT_BOX_X, TEXT_BOX_Y));
        text->setString(string);
        text->setFont(*font);
        text->setCharacterSize(24);
        text->setFillColor(sf::Color::Black);
        m_texts.push_back(text);
    }

public:
    std::vector<sf::Text*> m_texts;
};

class SpriteHandler
{
public:
    SpriteHandler(){}

    sf::Sprite& operator[](int i)
    {
        return *m_sprites[i];
    }
    void AddSprite(std::string file)
    {
        sf::Texture* texture = new sf::Texture;
        texture->loadFromFile(file);
        m_sprites.push_back(new sf::Sprite(*texture));
    }

public:
    std::vector<sf::Sprite*> m_sprites;
};

int ActionInitiliser(Factory<ActParams>& factory, TextHandler& text_map);
void CreateFactionMap(std::map<FACTION, Faction>& map);
// void CreateTextureMap(std::map<std::string, sf::Texture>& map);
void CreateSpriteMap(   std::map<FACTION, sf::Sprite>& sprite_map, 
                        std::map<FACTION, sf::Texture>& texture_map);


} // namespace the_prince

#endif // __THE_PRINCE_DATABASE_HPP__