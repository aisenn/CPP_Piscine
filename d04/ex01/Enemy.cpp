#include "Enemy.hpp"

Enemy::Enemy( void ) { return; }
Enemy::Enemy( int hp, std::string const & type ) : _hp(hp), _type(type) { return; }
Enemy::Enemy( Enemy &obj ) {
    *this = obj;
}

Enemy::~Enemy() { return; }

std::string const &Enemy::getType() const { return this->_type; }
int Enemy::getHP() const { return this->_hp; }

void Enemy::takeDamage( int damage) {
    if (damage > this->getHP())
        this->_hp = 0;
    else
        this->_hp -= damage;      
}

Enemy &Enemy::operator = ( Enemy const & obj ) {
    this->_hp = obj.getHP();
    this->_type = obj.getType();

    return *this;
}