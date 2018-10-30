//
// Created by Quentin Nouvel on 2018-10-30.
//

#ifndef MINESWEEPER_PLATE_H
#define MINESWEEPER_PLATE_H


#include <vector>

#include "Case.h"

class Plate {
private:
	int const m_length, m_width;
	int const m_nbBomb;
	Case **tab;

	void openAround(int x, int y);
public:
	virtual ~Plate(); // destructor
	Case **getTab() const ;
	const int getM_length() const;
	const int getM_width() const;
	Plate(int m_length,int m_width,int m_nbBomb, std::vector<int> bombPos);
	bool isFinished() const;
	bool openCase(int x, int y);

};


#endif //MINESWEEPER_PLATE_H
