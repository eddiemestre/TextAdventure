//
// Main.cpp
//
// Created by Eddie Mestre on 9/12/2021
// Copright © 2021 Eddie Mestre. All rights reserved.
//

#include "TextAdventure.h"
#include <iostream>
#include <string>

int main(int argc, char** argv)
{

	Game instance;

	if (instance.Initialize() == true) {
		instance.RunLoop();
		instance.Shutdown();
	}


	return 0;
}