
#ifndef POSSITION_H	//Position
#define POSSITION_H	//Position

/**
  * struct Position
  * 
  */

struct Possition	//Position
{
  short int x;
  short int y;
  Possition(short int x, short int y): x(x), y(y){}	//Position
  Possition(): x(-1),y(-1){}				//Position
  bool operator ==(const Possition &p) const{		//Position
	  if(p.x==x && p.y == y) return true;
	  return false;
  }
};

#endif // POSSITION_H					//Position ;) :b
