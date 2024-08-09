#pragma once

#include <ostream>


class Die
{
private:
    int sides;

public:
    Die(int sides) : sides(sides) {}
    int roll();
    friend std::ostream& operator<<(std::ostream& strm, const Die& obj);
};

