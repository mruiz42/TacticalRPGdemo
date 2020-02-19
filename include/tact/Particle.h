// Partcle
// Created by Casey 2/17/20
//

#ifndef CIS29GROUP2GAME_PARTICLE_H
#define CIS29GROUP2GAME_PARTICLE_H

#include <SFML/Graphics/Drawable.hpp>
#include<SFML/Graphics/Transformable.hpp>
#include<SFML/System/Time.hpp>
#include<SFML/Graphics/PrimitiveType.hpp>
#include<SFML/Graphics/Vertex.hpp>
#include<SFML/Graphics/VertexArray.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<cmath>

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:
    ParticleSystem(unsigned int count) :
    m_particles(count),
    m_vertices(sf::Points, count),
    m_lifetime(sf::seconds(3.f)),
    m_emitter(0.f, 0.f)
    {}
    void setEmitter(sf::Vector2f position){m_emitter = position;}
    void update(sf::Time elapsed);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:

    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index);
    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
};

#endif