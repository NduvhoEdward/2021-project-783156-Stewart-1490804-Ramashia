#include "Bullet.h"

const auto bullet_SPEED = 15.0;

Bullet::Bullet(){

    bullet.setFillColor(sf::Color::Red);
    bullet.setPosition(Pos.x,Pos.y);
    bullet.scale(1.0f,5.0f);
}

Bullet::~Bullet(){}

void Bullet::Initialize(Blaster *blast, float startPos_x, float startPos_y){

	//set up callback pointer to player
	player = blast;
	//set position
	Pos.x = startPos_x;
	Pos.y = startPos_y;

}

void Bullet::UpdateBullet(){

	//move every frame
	Pos.y -= bullet_SPEED;

	//if the bullet goes off screen, destroy it
//	if (Pos.y <- MainSprite.getTextureRect().height )
//	{
//		MarkForDestroy();
//	}
//
	bullet.setPosition(Pos);
}

void Bullet::DrawBullet(sf::RenderWindow* window){

	for(auto i=0; i<firedBullets.size(); i++){

        window->draw(firedBullets[i]);
	}
}

void Bullet::Destroy(){

}
