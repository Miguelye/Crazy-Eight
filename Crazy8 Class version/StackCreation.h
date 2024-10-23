#pragma once
//Header file for PlayingCardFactory class.
#ifndef STACKCREATION_H
#define STACKCREATION_H

#include "Stack.h"

class StackCreation {
public:
	StackCreation() {}
	virtual ~StackCreation() {}

	enum TYPE {CRAZY8};

	//Create Stack
	Stack* createStack(StackCreation::TYPE t);
};

#endif
