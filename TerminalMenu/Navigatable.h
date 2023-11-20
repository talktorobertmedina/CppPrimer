#pragma once

#include <vector>

class TerminalMenu; // forward declaration

class Navigatable
{
public:
	virtual std::vector<TerminalMenu*> getItems() = 0;
	virtual size_t prompt() const = 0;
	virtual void navigateItem() = 0;
};