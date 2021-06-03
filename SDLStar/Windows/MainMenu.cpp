#pragma once

#include "../GUI/GUI_Library.h"

class MainMenuWindow : public GUI_Window {
	public:
		MainMenuWindow() {
			addElement(new GUI_Label("SingParty"));
		}
};