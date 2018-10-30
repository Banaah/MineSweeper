//
// Created by Quentin Nouvel on 2018-10-30.
//
#include <iostream>

#include "console.h"

using namespace std;

void afficher_plateau(Plate &p){
	Case **plateau = p.getTab();
	for (int i = 0; i < p.getM_length(); ++i) {
		for (int j = 0; j < p.getM_width(); ++j) {
			if (plateau[i][j].isOpen()){
				if (plateau[i][j].getM_nbBombAround()) cout << '|' << plateau[i][j].getM_nbBombAround();
				else cout << "| ";
			} else cout << "|#";
		}
		cout << '|' << endl;
	}
}

void afficher_plateau_loose(Plate &p){
	Case **plateau = p.getTab();
	for (int i = 0; i < p.getM_length(); ++i) {
		for (int j = 0; j < p.getM_width(); ++j) {
			if (plateau[i][j].isBomb())cout << '|' << 'X';
			else if (plateau[i][j].isOpen()){
				if (plateau[i][j].getM_nbBombAround()) cout << '|' << plateau[i][j].getM_nbBombAround();
				else cout << "| ";
			} else cout << "|#";
		}
		cout << '|' << endl;
	}
}