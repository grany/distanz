/*
 * KI.h
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#ifndef SRC_H_KI_H_
#define SRC_H_KI_H_

#include "Team.h"

class KI {
private:
	Team &t;
public:
	KI(Team &t);
	Team& getTeam();
	virtual ~KI();
};

#endif /* SRC_H_KI_H_ */
