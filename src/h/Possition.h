
#ifndef POSSITION_H
#define POSSITION_H

/**
  * struct Possition
  * 
  */

struct Possition
{
  short int x;
  short int y;
  Possition(short int x, short int y): x(x), y(y){}
  Possition(): x(-1),y(-1){}
};

#endif // POSSITION_H
