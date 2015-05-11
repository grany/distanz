/*
 * SfK.cpp
 *
 *  Created on: 09.05.2015
 *      Author: franz
 */

#include "../h/SfK.h"
#include <cmath>
#include <algorithm>
#include "../h/zug.h"
#include <iostream>

void SfK::bewerten(){
	aZuege.clear();
	getmZuege(aZuege);
	mZuege=aZuege;
	Possition gk = team.getGegner()->getStein(4).getOrt()->getPos();//Possition des Gegnerischen Königs
	for(std::vector<zug>::iterator it=aZuege.begin(); it!=aZuege.end(); ++it){
		(*it).wert=std::abs((*it).zpos.x-gk.x)+std::abs((*it).zpos.y-gk.y);
		//std::cout<<"Sfk::bewerten Wertigkeiten s_id:"<<(*it).stein->getid()<<" zpos: "<<(*it).zpos.x<<":"<<(*it).zpos.y<<" wert:"<<(*it).wert<<std::endl;
	}

	std::sort(aZuege.begin(),aZuege.end());
	if(!aZuege.size()) std::cerr<<"Error SfK::bewerten :Keine Züge"<<std::endl;
	nZug=aZuege[0];
	/*
	int arr[6];
	nZug.stein->getMteam()->distanzen(*nZug.stein, arr);
	for(int i =0 ;i<6;i=i+2){
		std::cout<<arr[i]<<":"<<arr[i+1]<<std::endl;
	}

	*/
}

SfK::SfK(Team &team, SpielBrett &b): Strategie(team, b){}

SfK::~SfK() {}

