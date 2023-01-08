#include <stdio.h>
#include <time.h>

void delay(int ms) {
	clock_t startTime = clock();
	while (clock() < startTime + ms);
}

char** getBoard() {
	static char** arr[64];
	
	for (int i=0; i < 64; i++) {
		arr[i] = " ";
	}
	
	return arr;
}

void writeBoard(char** board, int score) {
	printf("\nScore: %d\n", score);
	printf("-----------------\n");
	for (int i=0; i < 64; i++) {
		printf(" %s", board[i]);
		
		if (i % 8 == 7) {
			printf("\n");
		}
	}
	printf("-----------------\n");
}

int getApple() {
	int randomInt = (rand() % 64) +1;
	
	return randomInt;
}

int main() {
	char** board = getBoard();
	int apple = getApple();
	
	int snakeDirection = 1; // 0 left, 1 right, 2 top, 3 bottom;
	int snake[] = {0,1,2};
	int snakeLen = sizeof snake / sizeof snake[0];
	
	
	for (;;) {
		srand(time(0));
		
		// reset board
		board = getBoard();
		
		
		// shift last element (remove first element)
		for (int i=0; i < snakeLen-1; i++) {
			snake[i] = snake[i + 1];
		}
		
		// move snake
		switch (snakeDirection) {
			case 0:
				snake[snakeLen-1] = snake[snakeLen-2] - 1;
				break;
			case 1:
				snake[snakeLen-1] = snake[snakeLen-2] + 1;
				break;
			case 2:
				snake[snakeLen-1] = snake[snakeLen-2] - 8;
				break;
			case 3:
				snake[snakeLen-1] = snake[snakeLen-2] + 8;
				break;
			default: snake; 
		}
		
		
		// append snake
		for (int i=0; i < snakeLen; i++) {
			if (i==snakeLen-1 && snake[i] != 99) {
				board[snake[i]] = "8";
			} else if (snake[i] != 99){
				board[snake[i]] = "%";
			}
		}
		
		// eat apple
		if (apple == snake[snakeLen-1]) {
			apple = getApple();
			
			switch (snakeDirection) {
				case 0:
					snake[snakeLen] = snake[snakeLen-2] - 1;
					break;
				case 1:
					snake[snakeLen] = snake[snakeLen-2] + 1;
					break;
				case 2:
					snake[snakeLen] = snake[snakeLen-2] - 8;
					break;
				case 3:
					snake[snakeLen] = snake[snakeLen-2] + 8;
					break;
				default: snake; 
			}
		}
		
		// append apple
		board[apple] = "O";
		
		// basic loop
		writeBoard(board, snakeLen);
		
		// direction
		printf("Enter direction: W/S/A/D: ");
		char dir;
		scanf("%s", &dir);
		
		switch (dir) {
			case 'w':
				snakeDirection = 2;
				break;
			case 's':
				snakeDirection = 3;
				break;
			case 'a':
				snakeDirection = 0;
				break;
			case 'd':
				snakeDirection = 1;
				break;
			default: dir;
		}
		
		delay(1000);
	}
	
	return 1;
}
