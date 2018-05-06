#include "charStats.h"

class charStats {
	
	int lives; //stores how much health a character has
	float posX; //position in x direction
	float posY; //position in y direction
	bool friendlyFire; //check if bullet is from MC or enemy
	float expand; //will represent enemy hit box. Should be big enough to encase enemy but small for MC
	bool dead; //usually is false
	
	public:
	void hit (float x, float y, bool ff) { //run this function on loop to determine of any bullets make contact
		if (posX < (x-expand) && pos > (x+expand)) {
			if (posY < (y-expand) && pos > (y+expand)) {
				lives--;
				if (lives == 0) {
					dead == true;
				}
			}
		}
	}
	
}