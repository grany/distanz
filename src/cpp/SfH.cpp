/*
 * SfH.cpp
 *
 *  Created on: 12.05.2015
 *      Author: franz
 */

#include "../h/SfH.h"
#include <algorithm>

void SfH::bewerten(){
	aZuege.clear();
	getmZuege(aZuege);
	mZuege=aZuege;
	for(std::vector<zug>::iterator it=aZuege.begin(); it!=aZuege.end(); ++it){
		(*it).wert=((*it).zpos==team.getGegner()->getStein(1).getOrt()->getPos() \
				||(*it).zpos==team.getGegner()->getStein(2).getOrt()->getPos() \
				|| (*it).zpos==team.getGegner()->getStein(3).getOrt()->getPos())\
						?20:(*it).wert+1;
	}

	std::sort(aZuege.begin(),aZuege.end());
	nZug=aZuege[0];
	this->wert=nZug.wert;

	/*
	int arr[6];
	nZug.stein->getMteam()->distanzen(*nZug.stein, arr);
	for(int i =0 ;i<6;i=i+2){
		std::cout<<arr[i]<<":"<<arr[i+1]<<std::endl;
	}

	*/
}
SfH::SfH(Team &team, SpielBrett &b): Strategie(team, b) {
	// TODO Auto-generated constructor stub

}

SfH::~SfH() {
	// TODO Auto-generated destructor stub
}

