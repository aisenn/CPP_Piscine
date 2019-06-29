#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy
{
    protected:
        int _hp;
        std::string _type;

        Enemy( void );
        
    public:
       
        Enemy( int hp, std::string const & type );
        Enemy( Enemy &obj );
        virtual ~Enemy();

        std::string const & getType() const;
        int getHP() const;

        virtual void takeDamage( int );

		Enemy &operator = ( Enemy const & obj );
};

#endif //ENEMY_HPP