/*
* !!!FIRST DRAFT
* Sample program to navigate between cli items. Example program output
* 
* Initial State:
* 1. MenuItem 1
* 2. MenuItem 2
* 3. MenuItem 3
* 4. Terminate
* Select (1-4) or ESC (back):
* 
* Next State Prime:
* 1. MenuItem 1
* 2. MenuItem 2
* 3. MenuItem 3
* 4. Terminate
* Select (1-4) or ESC (back): 2
*
* MenuItem 2 State:
* 1. MenuItem 2's Option 1
* 2. MenuItem 2's Option 2
* Select (1-2) or ESC (back): ESC
* 
* Revert to Next State Prime:
* <insert Next State Prime text>
* 
* Terminate State:
* ... items listed...
* Select (1-4) or ESC (back): terminate
* 
* END
* 
* Prompts should be case sensitive.
* Prompts should be able to double-confirm.
*/

#include "TerminalMenu.h"
#include <iostream>

int main(int argc, char** argv)
{
	size_t prompt;
	TerminalMenu humanCampaignMenu("Human");
	TerminalMenu orcCampaignMenu("Orc");
	TerminalMenu nightElfCampaignMenu("Night Elf");
	TerminalMenu undeadCampaignMenu("Undead");
	TerminalMenu campaignMenu("Campaign");
	campaignMenu.addItem(&humanCampaignMenu);
	humanCampaignMenu.setParent(&campaignMenu);

	campaignMenu.addItem(&orcCampaignMenu);
	orcCampaignMenu.setParent(&campaignMenu);

	campaignMenu.addItem(&nightElfCampaignMenu);
	nightElfCampaignMenu.setParent(&campaignMenu);

	campaignMenu.addItem(&undeadCampaignMenu);
	undeadCampaignMenu.setParent(&campaignMenu);

	TerminalMenu singlePlayerMenu("Single Player");
	TerminalMenu meleeMenu("Melee");
	TerminalMenu aboutMenu("About");
	TerminalMenu root("");

	root.addItem(&campaignMenu);
	campaignMenu.setParent(&root);

	root.addItem(&singlePlayerMenu);
	singlePlayerMenu.setParent(&root);

	root.addItem(&meleeMenu);
	meleeMenu.setParent(&root);

	root.addItem(&aboutMenu);
	aboutMenu.setParent(&root);

	bool runCondition = true;
	size_t promptResponse = 1;
	TerminalMenu* currentSelection = &root;
	while (runCondition)
	{
		promptResponse = currentSelection->prompt();

		runCondition = !(promptResponse == 0 && currentSelection == &root);
		if (promptResponse == 0)
		{
			currentSelection = currentSelection->getParent();
		}
		else
		{
			currentSelection = currentSelection->getItem(promptResponse - 1);
		}
	}
	return 0;
}
