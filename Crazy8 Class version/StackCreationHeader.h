#pragma once

//Header file for PlayingCardFactory class.
#ifndef STACKCREATIONHEADER_H
#define STACKCREATIONHEADER_H

#include "StackHeader.h"

class PileFactory 
{
public:
	PileFactory() {}
	virtual ~PileFactory() {}

	enum TYPE {CRAZY8};

	Pile* createPile(PileFactory::TYPE t);
};

#endif