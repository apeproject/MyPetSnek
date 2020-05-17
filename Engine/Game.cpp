#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
  rng(std::random_device()()),
	snek({2,2}),
	goal(rng,brd,snek)
{}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

//TODO: Draw Title screen until you hit enter
//TODO: Draw Border around board
//TODO: Pad tiles
//TOOD: Make snake segments have color pattern
//TODO: Speed up snek
//TODO: spawn obsticles
//TODO: after eat 2 poop 1
//TODO: moving, color changing(glowing) food snake?
//	grow by how many segments food snek is long

void Game::UpdateModel(){
	if (!gameOver){
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
		if (wnd.kbd.KeyIsPressed(VK_ACCEPT)){
			gameStarted = true;
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
}

void Game::ComposeFrame(){
	// draw snake and test movements
	snek.Draw(brd);
	goal.Draw(brd);
	if(gameOver){
		SpriteCodex::DrawGameOver(gfx.ScreenWidth / 2 - 50, gfx.ScreenHeight / 2 - 50, gfx);
	}
	// add food and draw
	// add colide with food is eaten poo game
	// add poison eat too much food poop kills your face
	

	//std::uniform_int_distribution<int> cellColorDist(0, 255);
	//for (int y = 12; y < brd.GetGridHeight(); y++){ // start with padding up top for score and stuff
	//	for (int x = 6; x < brd.GetGridWidth(); x++){ // space padding left and right without doing math
	//		loc={x,y};
	//		Color c(cellColorDist(rng), cellColorDist(rng), cellColorDist(rng));
	//		brd.DrawCell(loc, c);
	//	}
	//}
}
