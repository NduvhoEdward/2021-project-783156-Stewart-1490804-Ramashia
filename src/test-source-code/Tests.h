#ifndef TESTS_H
#define TESTS_H
#include "Game.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("testing centipede Move")
{

}

class Tests
{
    public:
        Tests();
        virtual ~Tests();
        bool test_centipede_move();
        bool test_bullet_move();
        bool test_player_move();
        bool test_bullet_hit();
        bool test_centipede_eat();



    protected:

    private:
        Game game;
};

#endif // TESTS_H
