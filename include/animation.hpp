#ifndef __THE_PRINCE_ANIMATION_HPP__
#define __THE_PRINCE_ANIMATION_HPP__
/*****************************************************************************
 * ANIMATION API
 * Alistair Hudson
 * version 02.09.2020.0
******************************************************************************/

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"


namespace the_prince
{
class Animation
{
public:
    Animation(  sf::Sprite& sprite, sf::Texture& textureSheet, float timeout, 
                int start_x, int start_y, 
                int frames_x, int frames_y, 
                int width, int height);
    // Animation(Animation& anim);
    // Animation& operator= (Animation& anim);
    // ~Animation();

    // void Play();
    // void Pause();
    void Reset();
    void Play(const float delta_time);



private:
    sf::Sprite& m_sprite;
    sf::Texture& m_textureSheet;
    float m_timeout;
    float m_timer;
    int m_width;
    int m_height;
    sf::IntRect m_start;
    sf::IntRect m_current;
    sf::IntRect m_end;



};

} // namespace the_prince

#endif // __THE_PRINCE_ANIMATION_HPP__