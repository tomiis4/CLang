#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void delay(int msDelay) {
	clock_t startTime = clock();

	while (clock() < startTime + msDelay);
}

int getIndex (int xPoint, int yPoint, int boardLength) {
  int index = (boardLength * (yPoint -1)) + (xPoint -1);  
  
  return index;
}

int sign(int x) {
	if (x > 0) {
		return 1;
	} else if (x < 0) {
		return -1;
	} else {
		return 0;
	}
}

int randomInt(int maxValue) {
	int random = (rand() % maxValue) + 1;
	srand(time(NULL));

	return random;
}

int abs(int x) {
	int main;

	if (x < 0) {
		main = x * (-1);
	} else {
		main = x;
	}
	return main;
}


int main() {
	// screen
  char screen[63] = {
    '-', '-', '-', '-', '-', '-', '-', '-', '\n',
    '-', '-', '-', '-', '-', '-', '-', '-', '\n',
    '-', '-', '-', '-', '-', '-', '-', '-', '\n',
    '-', '-', '-', '-', '-', '-', '-', '-', '\n',
    '-', '-', '-', '-', '-', '-', '-', '-', '\n',
    '-', '-', '-', '-', '-', '-', '-', '-', '\n',
    '-', '-', '-', '-', '-', '-', '-', '-', '\n',
  };

	// points
  int startPoint[2] = {randomInt(8), randomInt(7)}; 
  int endPoint[2] = {randomInt(8), randomInt(7)};
	
	// append start point (O) and end point (X)
	screen[getIndex(startPoint[0], startPoint[1], 9)] = 'O';
  screen[getIndex(endPoint[0], endPoint[1], 9)] = 'X';

	/*         GET POINT          */

  // screen x1, y1
	int xPoint = 1;
	int yPoint = 1;
	
	// Loop trough whole screen (7*8)
	for (int i=0; i<56; i++) { // screen size
		// get y point 
		yPoint = i % 7;
		yPoint++;
		
		// get x point
		xPoint = i % 8;
		xPoint++;

		// if point was found
		if (screen[getIndex(xPoint, yPoint, 9)] == 'X') {
			printf("\n Point was found (%d, %d)", xPoint, yPoint);
			break;
		}

		// append & show screen with delay (remove for better spec ;) )
	  screen[getIndex(xPoint, yPoint, 9)] = '-';
		printf("\n%s\n", screen);
		delay(50);
	}

	// append spawn point
	screen[getIndex(startPoint[0], startPoint[1], 9)] = 'O';
  screen[getIndex(endPoint[0], endPoint[1], 9)] = 'X';
	printf("\n%s\n", screen);


	/*  GET SHORTEST PATH   */

	int mainX = startPoint[0];
	int mainY = startPoint[1];

	int x1	= startPoint[0];
	int y1	= startPoint[1];
	int x2	= endPoint[0];
	int y2	= endPoint[1];

	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

	int s1 = sign(x2 - x1);
	int s2 = sign(y2 - y1);

	int change = 0;

	if (dy > dx) {
		int t = dx;

		dx = dy;
		dy = t;

		change = 1;
	} else {
		change = 0;
	}

	int error = 2 * dy - dx;
	int a = 2 * dy;
	int b = 2 * dy - 2 * dx;

	for (int i=0; i < dx; i++) {
		if (error < 0) {
			if (change != 0) {
				mainY += s2; 
			} else {
				mainX += s1;
				error += a; 
			}
		} else {
			mainY += s2;
			mainX += s1;
			error += b;
		}
		screen[getIndex(mainX, mainY, 9)] = '*';
	}

	printf("%s", screen);

	return 0;
}
