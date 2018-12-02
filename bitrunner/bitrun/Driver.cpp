#include "Header.h"
#include "Tile.cpp"

//Global Tile Creation
sf::Vector2f DEFAULT_SIZE{ 10.f,10.f };
Tile wall(DEFAULT_SIZE,sf::Color::White,true);
Tile path(DEFAULT_SIZE,sf::Color::Black,false);
Tile player(DEFAULT_SIZE,sf::Color::Blue,false);
vector <vector<Tile>> GRID1{
	// 0     1     2     3     4     5     6     7     8     9
	 {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}, //0
	 {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}, //1
	 {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}, //2
	 {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}, //3
	 {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}, //4
	 {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}, //5
	 {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}, //6
	 {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}, //7
	 {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}, //8
	 {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall} //9
};


sf::RenderWindow window(sf::VideoMode(500, 500), "BITRUN", sf::Style::Close);


//Method Declaration
void drawTile(Tile _tile, sf::Vector2f _position);
void drawGrid(vector <vector <Tile>> _GRID, vector<int>playerLoc);




int main() {

	window.setVerticalSyncEnabled(true);
	vector<int> playerLoc{ 4,4 };
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Escape:
					window.close();
					break;
				case sf::Keyboard::W:
					playerLoc[1]--;
					break;
				case sf::Keyboard::S:
					playerLoc[1]++;
					break;
				case sf::Keyboard::A:
					playerLoc[0]--;
					break;
				case sf::Keyboard::D:
					playerLoc[0]++;
					break;
				}
			}

		}

		window.clear();
		drawGrid(GRID1, playerLoc);
	}

	

	//ReadKey Loop
	do {
		cout << "Press Enter to continue..";
	} while (cin.get() != '\n');
	return 0;
}






void drawTile(Tile _tile, sf::Vector2f _position) {
	sf::RectangleShape rect(sf::Vector2f(_tile.getSize()));
	rect.setFillColor(_tile.getColor());
	rect.setPosition(_position);
	window.draw(rect);
}
void drawGrid(vector <vector <Tile>> _GRID, vector<int> _playerLoc) {
	
	for (int y = 0; y < _GRID.size(); y++) {
		for (int x = 0; x < _GRID.size(); x++) {
			vector <int> loc{ x,y };
			sf::Vector2f position(static_cast <float>(x * 10.f), static_cast<float>(y * 10.f));
			if (loc[0] == _playerLoc[x] && loc[1] == _playerLoc[y] ) {
				drawTile(player, position);
			}
			else {
				drawTile(_GRID[x][y], position);
			}
		}
	}
}