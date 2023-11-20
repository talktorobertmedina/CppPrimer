#pragma once

#include <vector>
#include <string>
#include "Navigatable.h"

class TerminalMenu: Navigatable
{
public:
	TerminalMenu();
	TerminalMenu(std::string displayText);
	TerminalMenu(std::string displayText, std::vector<TerminalMenu*> children);
	~TerminalMenu();
	std::vector<TerminalMenu*> getItems();
	TerminalMenu* getItem(size_t index) const;
	size_t prompt() const;
	void navigateItem();
	void addItem(TerminalMenu* item);
	std::string getDisplayText() const;
	TerminalMenu* getParent() const;
	void setParent(TerminalMenu* parent);
protected:
private:
	std::string                  m_displayText;
	std::vector<TerminalMenu*>   m_items;
	TerminalMenu*                m_parent;
};
