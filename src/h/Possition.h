
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
  bool operator ==(const Possition &p) const{
	  if(p.x==x && p.y == y) return true;
	  return false;
  }
};

#endif // POSSITION_H
