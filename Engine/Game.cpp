#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
  rng(std::random_device()()),
	snek({1,1}),
	goal(rng,brd,snek)
{}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

//TODO: Draw Border around board
//TODO: Pad tiles
//TOOD: Make snake segments have color pattern
//TODO: Speed up snek
//TODO: spawn obsticles
//TODO: after eat 2 poop 1
//TODO: moving, color changing(glowing) food snake?
//	grow by how many segments food snek is long

void Game::UpdateModel(){
	if (gameStarted){
		if (!gameOver && gameStarted){
			if (wnd.kbd.KeyIsPressed(VK_UP)){
				delta_loc = {0,-1};
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN)){
				delta_loc = {0,1};
			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT)){
				delta_loc = {-1,0};
			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT)){
				delta_loc = {1,0};
			}
			++snekMoveCounter;
			if (snekMoveCounter >= snekMovePeriod){ // move every 20 count/frames move 1, or 3 times a second at 60 frames a second regulated
				snekMoveCounter = 0;// reset to move again
				const Location next = snek.GetNextHeadLocation(delta_loc);
				if (!brd.inBounds(next) || snek.IsInTileNotEnd(next)){
					//if cheatNoDie == enabled stop move and pick new direction
					gameOver = true;
				} else{
					bool eating = next == goal.GetLocation();
					if (wnd.kbd.KeyIsPressed(VK_CONTROL) || next == goal.GetLocation()){
						snek.Grow();
					}
					snek.Move(delta_loc);
					if (eating){
						goal.Respawn(rng, brd, snek);
					}
				}
			}
		}
	} else{ gameStarted = wnd.kbd.KeyIsPressed(VK_RETURN); }
}

void Game::ComposeFrame(){
	if(!gameStarted){
		brd.DrawBoarder();
		SpriteCodex::DrawTitle(gfx.ScreenWidth / 2 - 107, gfx.ScreenHeight / 2 - 80, gfx); // 213 x 160 dimensions
	}
	if (!gameOver && gameStarted){
		brd.DrawBoarder();
		snek.Draw(brd);
		goal.Draw(brd);
	}
	if(gameOver && gameStarted){
		brd.DrawBoarder();
		snek.Draw(brd);
		goal.Draw(brd);
		SpriteCodex::DrawGameOver(gfx.ScreenWidth / 2 - 42, gfx.ScreenHeight / 2 - 32, gfx); // 83 x 63 dimensions
	}
	// Color Disco Board
	//std::uniform_int_distribution<int> cellColorDist(0, 255);
	//for (int y = 12; y < brd.GetGridHeight(); y++){ // start with padding up top for score and stuff
	//	for (int x = 6; x < brd.GetGridWidth(); x++){ // space padding left and right without doing math
	//		loc={x,y};
	//		Color c(cellColorDist(rng), cellColorDist(rng), cellColorDist(rng));
	//		brd.DrawCell(loc, c);
	//	}
	//}
}
