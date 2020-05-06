#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
  rng(std::random_device()()),
	slither({50,50})
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(){
	if (wnd.kbd.KeyIsPressed(VK_UP)){
		delta_loc = {0,1};
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)){
		delta_loc = {0,-1};
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)){
		delta_loc = {-1,0};
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)){
		delta_loc = {1,0};
	}


}

void Game::ComposeFrame(){
	// draw snake and test movements
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
