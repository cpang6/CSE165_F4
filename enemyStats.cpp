#include "charStats.h"

class enemyStats: public charStats {
	
	short int type; //determine what kind of enemies
	
	/*---------
	type = 0: standard enemy
	type = 1: boss
	---------*/
	public:
	
	enemyStats(int t, float posXX, float float posYY) {
		if (t == 0) {
			lives = 3;
			expand = 0.09;
		}
		if (t == 1) {
			lives = 200;
			expand = 0.3;
		}
		type = t;
		posX = posXX;
		posY = posYY;
		
	}
	
}