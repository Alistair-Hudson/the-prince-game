
/******************************************************************************
 *	Title:		Animation
 *	Authour:	Alistair Hudson
 *	Reviewer:	
 *	Version:	03.09.2020.0
 ******************************************************************************/

#include "animation.hpp"


using namespace the_prince;

/******MACROS******/

/******TYPEDEFS*****/

/****** GLOBAL VARIABLES*****/

/*****STRUCTS*******/

/*****CLASSES******/

/*****FUNCTORS*****/

/******INTERNAL FUNCTION DECLARATION******/


/******CLASS METHODS*******/
/*===Animation===*/
Animation::Animation(   sf::Sprite& sprite, sf::Texture& textureSheet, float timeout, 
                        int start_x, int start_y, 
                        int frames_x, int frames_y, 
                        int width, int height): m_sprite(sprite),
                                                m_textureSheet(textureSheet),
                                                m_timeout(timeout),
                                                m_timer(0),
                                                m_width(width),
                                                m_height(height),
                                                m_start(start_x, start_y, width, height),
                                                m_end(frames_x * width, frames_y* height, width, height)
{
    m_current = m_start;
    m_sprite.setTexture(m_textureSheet, true);
    m_sprite.setTextureRect(m_start);
}

// void Animation::Play()
// {

// }

void Animation::Play(const float delta_time)
{
    //update timer
    m_timer += 10.f * delta_time;
    if (m_timer >= m_timeout)
    {
        //reset timer
        m_timer = 0;
        //Animate
        if(m_current != m_end)
        {
            m_current.left += m_width;
        }
        //Reset
        else
        {
            m_current.left = m_start.left;
        }
        m_sprite.setTextureRect(m_current);
        
    }
}

void Animation::Reset()
{
    m_timer = 0;
    m_current = m_start;

}

/*****FUNCTION DEFINITION******/