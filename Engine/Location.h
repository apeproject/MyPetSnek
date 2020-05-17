#pragma once

class Location {
public:
	int x;
	int y;
	bool operator == (const Location& rhs) const{ 
		return x == rhs.x && y == rhs.y; 
	}
	void UpdateLoc(const Location& deltaCoord){
		x += deltaCoord.x;
		y += deltaCoord.y;
	}
};
