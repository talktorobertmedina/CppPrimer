#pragma once

#include "Container.h"

#define INITIAL_SIZE 100
#define RESIZE_THRESHOLD 0.5 // percentage

class Vector: public Container
{
public:
	int size() override;
private:
	int storage[INITIAL_SIZE];
	int size;
};
