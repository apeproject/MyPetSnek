#pragma once

struct Location {
public:
	int x;
	int y;
	void UpdateLoc(const Location& deltaCoord){
		x += deltaCoord.x;
		y += deltaCoord.y;
	}
};
