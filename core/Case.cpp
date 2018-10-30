//
// Created by Quentin Nouvel on 2018-10-30.
//

#include "Case.h"


#include "Case.h"

bool Case::isBomb() const{
	return m_bomb;
}

int Case::getM_nbBombAround() const {
	return m_nbBombAround;
}

bool Case::isOpen() const {
	return m_open;
}

Case::Case() {
	m_bomb = false;
	m_open = false;
	m_nbBombAround = 0;
}

void Case::setM_bomb(bool m_bomb) {
	Case::m_bomb = m_bomb;
}

void Case::incrM_nbBombAround() {
	++m_nbBombAround;
}

void Case::setM_open(bool m_open) {
	Case::m_open = m_open;
}
