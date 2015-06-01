/*
 * SbK.h
 *
 *  Created on: 21.05.2015
 *      Author: franz
 */

#ifndef SRC_H_SBK_H_
#define SRC_H_SBK_H_

#include "Strategie.h"

class SbK: public Strategie {
public:
	virtual void bewerten() override;
	SbK(Team &team, SpielBrett &b);
	virtual ~SbK()=default;
};

#endif /* SRC_H_SBK_H_ */
