#include "TerminalMenu.h"
#include <iostream>

TerminalMenu::TerminalMenu() :
	m_displayText(""),
	m_items(std::vector<TerminalMenu*>())
{

}

TerminalMenu::TerminalMenu(std::string displayText) : 
	m_displayText(displayText),
	m_items(std::vector<TerminalMenu*>())
{

}

TerminalMenu::TerminalMenu(std::string displayText, std::vector<TerminalMenu*> children) :
	m_displayText(displayText),
	m_items(children)
{

}

TerminalMenu::~TerminalMenu()
{

}

std::vector<TerminalMenu*> TerminalMenu::getItems()
{
	return std::vector<TerminalMenu*>();
}

TerminalMenu* TerminalMenu::getItem(size_t index) const
{
	if (index < m_items.size())
	{
		return m_items.at(index);
	}
	return NULL;
}

size_t TerminalMenu::prompt() const
{
	std::cout << getDisplayText() << std::endl;
	size_t prompt;

	if (m_items.size() == 0)
	{
		std::cout << "Empty menu. Press 0 to go back: ";
		std::cin >> prompt;
		std::cout << std::endl;
		return 0; // always return 0
	}

	size_t counter = 1;
	for (std::vector<TerminalMenu*>::const_iterator itr = m_items.begin(); itr != m_items.end(); ++itr)
	{
		std::cout << counter << ". " << (*itr)->getDisplayText() << std::endl;
		++counter;
	}
	std::cout << "Select (1-" << counter - 1 << ") or 0 (back): ";
	std::cin >> prompt;
	std::cout << std::endl;
	return prompt;
}

std::string TerminalMenu::getDisplayText() const
{
	return m_displayText;
}

void TerminalMenu::navigateItem()
{

}

void TerminalMenu::addItem(TerminalMenu* item)
{
	m_items.push_back(item);
}

TerminalMenu* TerminalMenu::getParent() const
{
	return m_parent;
}

void TerminalMenu::setParent(TerminalMenu* parent)
{
	m_parent = parent;
}