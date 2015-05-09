/*
 * SfK.h
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#ifndef SRC_SFK_H_
#define SRC_SFK_H_

#include "Strategie.h"

class SfK: public Strategie {
public:
	void bewerten();
	SfK(KI &ki, SpielBrett &b);
	SfK();
	virtual ~SfK();
};

#endif /* SRC_SFK_H_ */
