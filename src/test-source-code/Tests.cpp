#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Game.h"

TEST_CASE("Testing Centipede Move")
{
  Centipede centi;
  float x1=0, x2=0;
  x1 = centi.centipede_getPosX();
  centi.move_centipede();
  x2 =centi.centipede_getPosX();

  CHECK(x1!=x2);

}

TEST_CASE("Testing Centipede Move")
{
  Centipede centi;
  float x1=0, x2=0;
  x1 = centi.centipede_getPosX();
  centi.move_centipede();
  x2 =centi.centipede_getPosX();

  CHECK(x1!=x2);

}

TEST_CASE("Testing Bullet Move")
{
  Blaster bull;
  float y1=0, y2=0;
  y1 = bull.blaster_getPosY();
  bull.move_blaster();
  y2 =bull.blaster_getPosY();

  CHECK(y1!=y2);

}

TEST_CASE("Testing Bullet Starting Position")
{
  Blaster bull;
  float y1=10, y2=10;
  bull.set_blaster(y1,y2);
  float A = bull.blaster_getPosY();
  float B = bull.blaster_getPosY();

  CHECK(y1==A);
  CHECK(y2==B);
}

TEST_CASE("Testing Player Fire Bullet")
{
   Player play;
   auto ptr =play.fire_bullet();
   CHECK(ptr== nullptr);

}
