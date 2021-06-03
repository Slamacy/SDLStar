#pragma once


/*
* An Interactable Element
*/
class IInteractable {
	public:
		virtual void select() = 0;
		virtual void deselect() = 0;
};