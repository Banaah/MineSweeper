//
// Created by Quentin Nouvel on 2018-10-30.
//
#include <iostream>

#include "game.h"

void game(){
	std::vector<int> bomb;
	bomb.push_back(4);
	bomb.push_back(6);
	bomb.push_back(8);
	bomb.push_back(14);
	bomb.push_back(34);
	bomb.push_back(42);
	bomb.push_back(53);
	bomb.push_back(58);
	bomb.push_back(66);
	bomb.push_back(76);
	Plate p = Plate(9, 9, 10, bomb);
	afficher_plateau(p);
	int x, y;
	while (!p.isFinished()){
		std::cin >> x >> y;
		if (p.openCase(x-1, y-1)) break;
		afficher_plateau(p);
	}
	if(!p.isFinished()){
		afficher_plateau_loose(p);
	} else afficher_plateau(p);
}