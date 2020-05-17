#include "Snake.h"
#include <assert.h>

#pragma region Snek Operatives
Snek::Snek(const Location& loc){ segments[ 0 ].InitHead(loc); }

bool Snek::IsInTileNotEnd(const Location& target) const{
	for (int i = 0; i < nSegments - 1; ++i){
		if (segments[ i ].GetLocation() == target){
			return true;
		}
	}
	return false;
}

bool Snek::IsInTile(const Location& target) const{
	for (int i = 0; i < nSegments; ++i){
		if (segments[ i ].GetLocation() == target){
			return true;
		}
	}
	return false;
}

void Snek::Move(const Location& delta_loc){
	for (int i = nSegments - 1; i > 0; --i){
		segments[ i ].FollowTheLeader(segments[ i - 1 ]);
	}
	segments[ 0 ].Move(delta_loc);
}

Location Snek::GetNextHeadLocation(const Location& delta_loc) const{
	Location l(segments[ 0 ].GetLocation());
	l.UpdateLoc(delta_loc);
	 return l;
}

void Snek::Grow(){ 
	if (nSegments < nSegmentsMax){
		segments[ nSegments ].InitBody();
		++nSegments;
	}
}

void Snek::Draw(Board & brd) const{
	for (int i = 0; i < nSegments; ++i){
		segments[ i ].Draw(brd);
	}
}

void Snek::SnekSegment::InitHead(const Location& hedloc){ //phuck naming same name not working
	loc = hedloc;
	c = HeadColor;
}
#pragma endregion

#pragma region SnekSegment Operatives
void Snek::SnekSegment::InitBody(){ c = BodyColor; }

void Snek::SnekSegment::FollowTheLeader(const SnekSegment& next){ loc = next.loc; }

void Snek::SnekSegment::Move(const Location& delta_loc){ 
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1); // only move 1 cube in x or y direction or break this shit diagnal move?
	loc.UpdateLoc(delta_loc); //loc(x,y) += (delta_loc(x,y);
} 

void Snek::SnekSegment::Draw(Board& brd) const{ brd.DrawCell(loc, c); }
const Location& Snek::SnekSegment::GetLocation() const{
	return loc;
}
#pragma endregion
