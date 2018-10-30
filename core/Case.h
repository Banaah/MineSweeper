//
// Created by Quentin Nouvel on 2018-10-30.
//

#ifndef MINESWEEPER_CASE_H
#define MINESWEEPER_CASE_H

class Case {
private:
	bool m_partyStarted;
	bool m_bomb;
	int m_nbBombAround;
	bool m_open;
public:
	Case();
	int getM_nbBombAround() const;
	bool isBomb()const;

	void setM_open(bool m_open);

	bool isOpen() const;

	void incrM_nbBombAround();
	void setM_bomb(bool m_bomb);
};

#endif //MINESWEEPER_CASE_H
