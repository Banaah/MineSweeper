//
// Created by Quentin Nouvel on 2018-10-30.
//

#include <iostream>
#include <cstdlib>

#include "Plate.h"

Plate::Plate(int m_length, int m_width, int m_nbBomb, std::vector<int> bombPos) : m_length(m_length), m_width(m_width),
																				  m_nbBomb(m_nbBomb) {
	tab = static_cast<Case **>(malloc(sizeof(Case*) * m_length));
	for (int i = 0; i < m_length; ++i) {
		tab[i] = new Case[m_width]();
	}
	if (bombPos.size() != m_nbBomb){
		std::cerr << "Erreur : bombPos length" << std::endl;
		exit(-1);
	}
	int sizeplate = (m_length*m_width)-1;
	int x,y;
	bool top, bot, left, right;
	for (const int &bomb : bombPos) {
		if(bomb > sizeplate){
			std::cerr << "Erreur : bomb out of plate" << std::endl;
			exit(-1);
		}
		x = bomb/m_length;
		y = bomb%m_width;
		tab[x][y].setM_bomb(true);
		top = true;bot = true;left = true;right = true;
		if (x == 0){
			top = false;
		} else if (x == m_length-1){
			bot = false;
		}
		if (y == 0){
			left = false;
		} else if (y == m_width-1){
			right = false;
		}
		if (top) tab[x-1][y].incrM_nbBombAround();
		if (bot) tab[x+1][y].incrM_nbBombAround();
		if (left) tab[x][y-1].incrM_nbBombAround();
		if (right) tab[x][y+1].incrM_nbBombAround();
		if (top && left) tab[x-1][y-1].incrM_nbBombAround();
		if (top && right) tab[x-1][y+1].incrM_nbBombAround();
		if (bot && left) tab[x+1][y-1].incrM_nbBombAround();
		if (bot && right) tab[x+1][y+1].incrM_nbBombAround();
	}
}

Case **Plate::getTab() const {
	return tab;
}

const int Plate::getM_length() const {
	return m_length;
}

const int Plate::getM_width() const {
	return m_width;
}

Plate::~Plate() {
	for (int i = 0; i < m_length; ++i) {
		delete tab[i];
	}
	free(tab);
}

bool Plate::isFinished() const {
	for (int i = 0; i < m_length; ++i) {
		for (int j = 0; j < m_width; ++j) {
			if (!tab[i][j].isOpen()){
				if (!tab[i][j].isBomb()) return false;
			}
		}
	}
	return true;
}

bool Plate::openCase(int x, int y) {
	if (!tab[x][y].isOpen()) {
		if (tab[x][y].isBomb()) return true;
		tab[x][y].setM_open(true);
		if (!tab[x][y].getM_nbBombAround()) openAround(x, y);
	}
	return false;
}

void Plate::openAround(int x, int y) {
	bool top = true, bot = true, left = true, right = true;
	if (x == 0){
		top = false;
	} else if (x == m_length-1){
		bot = false;
	}
	if (y == 0){
		left = false;
	} else if (y == m_width-1){
		right = false;
	}
	if (top) openCase(x-1, y);
	if (bot) openCase(x+1, y);
	if (left) openCase(x, y-1);
	if (right) openCase(x, y+1);
	if (top && left) openCase(x-1, y-1);
	if (top && right) openCase(x-1, y+1);
	if (bot && left) openCase(x+1, y-1);
	if (bot && right) openCase(x+1, y+1);
}
