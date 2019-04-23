

#include "maze.h"
#include "os.h"
#include <stdlib.h>
#include <util/delay.h>

int blink(int);
int update_dial(int);
int collect_delta(int);
int check_switches(int);
//my functions
point * makeObstacleTemplate(int startX, int startY, int limit, int change, char c);
point * makeLeftWall();
point * makeRightWall();
point * makeTopWall();
point * makeBottomWall();
point * makeHorizontalLevel1Obstacle1();
point * makeHorizontalLevel1Obstacle2();
point * makeHorizontalLevel2Obstacle1();
point * makeHorizontalLevel3Obstacle1();
point * makeHorizontalLevel3Obstacle2();
point * makeHorizontalLevel4Obstacle1();
point * makeHorizontalLevel4Obstacle2();
point * makeHorizontalLevel5Obstacle1();
point * makeHorizontalLevel5Obstacle2();
point * makeHorizontalLevel6Obstacle1();
point * makeHorizontalLevel6Obstacle2();
point * makeVerticalLevel1Obstacle1();
point * makeVerticalLevel1Obstacle2();
point * makeVerticalLevel1Obstacle3();
point * makeVerticalLevel1Obstacle4();
point * makeVerticalLevel2Obstacle1();
point * makeVerticalLevel2Obstacle2();
point * makeVerticalLevel3Obstacle1();
point * makeVerticalLevel4Obstacle1();
point * makeVerticalLevel5Obstacle1();
point * makeVerticalLevel5Obstacle2();
void printObstacles();
void printingTemplate(point *func, int num, char *str);
void printLeftWall();
void printRightWall();
void printPlayer();
void startNewGame();
void printTopWall();
void printBottomWall();
void printHorizontalLevel1Obstacle1();
void printHorizontalLevel1Obstacle2();
void printHorizontalLevel2Obstacle1();
void printHorizontalLevel3Obstacle1();
void printHorizontalLevel3Obstacle2();
void printHorizontalLevel4Obstacle1();
void printHorizontalLevel4Obstacle2();
void printHorizontalLevel5Obstacle1();
void printHorizontalLevel5Obstacle2();
void printHorizontalLevel6Obstacle1();
void printHorizontalLevel6Obstacle2();
void printVerticalLevel1Obstacle1();
void printVerticalLevel1Obstacle2();
void printVerticalLevel1Obstacle3();
void printVerticalLevel1Obstacle4();
void printVerticalLevel2Obstacle1();
void printVerticalLevel2Obstacle2();
void printVerticalLevel3Obstacle1();
void printVerticalLevel4Obstacle1();
void printVerticalLevel5Obstacle1();
void printVerticalLevel5Obstacle2();

int playerX = 15; // start coordinates
int playerY = 0;
//int grid[300][240]; //check occupied positions

FIL File;                   /* FAT File */

int position = 0;



void main(void) {
    os_init();
    os_add_task( blink,            30, 1);
    os_add_task( collect_delta,   500, 1);
    os_add_task( check_switches,  100, 1);
    sei();

		printObstacles();
		printPlayer();

    for(;;){}

}

void startNewGame(){
  rectangle r = {0, display.width-1, 0, display.height-1};
  fill_rectangle(r, display.background);
  printObstacles();
  playerX = 15;
  playerY = 0;
  printPlayer();
}

void printPlayer(){
  rectangle r;
  r.top = playerY;
  r.bottom = playerY + 3;
  r.left = playerX;
  r.right = playerX + 3;
  fill_rectangle(r,RED);
}

void printObstacles(){
  printTopWall();
  printBottomWall();
  printLeftWall();
	printRightWall();
  printHorizontalLevel1Obstacle1();
  printHorizontalLevel1Obstacle2();
  printHorizontalLevel2Obstacle1();
  printHorizontalLevel3Obstacle1();
  printHorizontalLevel3Obstacle2();
  printHorizontalLevel4Obstacle1();
  printHorizontalLevel4Obstacle2();
  printHorizontalLevel5Obstacle1();
  printHorizontalLevel5Obstacle2();
  printHorizontalLevel6Obstacle1();
  printHorizontalLevel6Obstacle2();
  printVerticalLevel1Obstacle1();
  printVerticalLevel1Obstacle2();
  printVerticalLevel1Obstacle3();
  printVerticalLevel1Obstacle4();
  printVerticalLevel2Obstacle1();
  printVerticalLevel2Obstacle2();
  printVerticalLevel3Obstacle1();
  printVerticalLevel4Obstacle1();
  printVerticalLevel5Obstacle1();
  printVerticalLevel5Obstacle2();
}

void printingTemplate(point *func, int num, char *str){
  point *arr;
  arr = func;
  for(int i=0; i< num; i++){
    point currPoint;
    currPoint = *(arr + i);
    int x = currPoint.x;
    int y = currPoint.y;

    if(x <= 300  && y <= 240){
      display_string_xy(str, x, y);
    }
  }
  free(arr);
}

void printLeftWall(){
  printingTemplate(makeLeftWall(), 34, "|");
}

void printRightWall(){
  printingTemplate(makeRightWall(), 34, "|");
}

void printTopWall(){
  printingTemplate(makeTopWall(), 90, "-");
}

void printBottomWall(){
  printingTemplate(makeBottomWall(), 90, "-");
}

void printHorizontalLevel1Obstacle1(){
  printingTemplate(makeHorizontalLevel1Obstacle1(), 30, "-");
}

void printHorizontalLevel1Obstacle2(){
  printingTemplate(makeHorizontalLevel1Obstacle2(), 30, "-");
}

void printHorizontalLevel2Obstacle1(){
  printingTemplate(makeHorizontalLevel2Obstacle1(), 9, "-");
}

void printHorizontalLevel3Obstacle1(){
  printingTemplate(makeHorizontalLevel3Obstacle1(), 9, "-");
}

void printHorizontalLevel3Obstacle2(){
  printingTemplate(makeHorizontalLevel3Obstacle2(), 9, "-");
}

void printHorizontalLevel4Obstacle1(){
  printingTemplate(makeHorizontalLevel4Obstacle1(), 9, "-");
}

void printHorizontalLevel4Obstacle2(){
  printingTemplate(makeHorizontalLevel4Obstacle2(), 50, "-");
}

void printHorizontalLevel5Obstacle1(){
  printingTemplate(makeHorizontalLevel5Obstacle1(), 62, "-");
}

void printHorizontalLevel5Obstacle2(){
  printingTemplate(makeHorizontalLevel5Obstacle2(), 19, "-");
}

void printHorizontalLevel6Obstacle1(){
  printingTemplate(makeHorizontalLevel6Obstacle1(), 13, "-");
}

void printHorizontalLevel6Obstacle2(){
  printingTemplate(makeHorizontalLevel6Obstacle2(), 13, "-");
}

void printVerticalLevel1Obstacle1(){
  printingTemplate(makeVerticalLevel1Obstacle1(), 9, "|");
}

void printVerticalLevel1Obstacle2(){
  printingTemplate(makeVerticalLevel1Obstacle2(), 14, "|");
}

void printVerticalLevel1Obstacle3(){
  printingTemplate(makeVerticalLevel1Obstacle3(), 10, "|");
}

void printVerticalLevel1Obstacle4(){
  printingTemplate(makeVerticalLevel1Obstacle4(), 10, "|");
}

void printVerticalLevel2Obstacle1(){
  printingTemplate(makeVerticalLevel2Obstacle1(), 4, "|");
}

void printVerticalLevel2Obstacle2(){
  printingTemplate(makeVerticalLevel2Obstacle2(), 9, "|");
}

void printVerticalLevel3Obstacle1(){
  printingTemplate(makeVerticalLevel3Obstacle1(), 12, "|");
}

void printVerticalLevel4Obstacle1(){
  printingTemplate(makeVerticalLevel4Obstacle1(), 5, "|");
}

void printVerticalLevel5Obstacle1(){
  printingTemplate(makeVerticalLevel5Obstacle1(), 5, "|");
}

void printVerticalLevel5Obstacle2(){
  printingTemplate(makeVerticalLevel5Obstacle2(), 5, "|");
}


point * makeObstacleTemplate(int startX, int startY, int limit, int change, char c){
  int currX = startX;
	int currY = startY;
	point *obstacles = malloc(1000 * sizeof(point));

	for(int i=0; i< limit; i++){
		point currPoint;

		currPoint.x = currX;
		currPoint.y = currY;

		*(obstacles + i) = currPoint;
    if (c == 'y') {
      currY += change;
    } else if (c == 'x') {
      currX += change;
    } else {
      point *error=NULL;
      return error;
    }
	}
	return obstacles;
}

point * makeLeftWall(){
  return makeObstacleTemplate(0, 0, 34, 7, 'y');
}

point * makeRightWall(){
  return makeObstacleTemplate(300, 0, 34, 7, 'y');
}

point * makeTopWall(){
  return makeObstacleTemplate(30, 0, 90, 3, 'x');
}

point * makeBottomWall(){
  return makeObstacleTemplate(0, 235, 90, 3, 'x');
}

point * makeHorizontalLevel1Obstacle1(){
  return makeObstacleTemplate(30, 20, 30, 3, 'x');
}

point * makeHorizontalLevel1Obstacle2(){
  return makeObstacleTemplate(208, 20, 30, 3, 'x');
}

point * makeHorizontalLevel2Obstacle1(){
  return makeObstacleTemplate(3, 60, 9, 3, 'x');
}

point * makeHorizontalLevel3Obstacle1(){
  return makeObstacleTemplate(30, 90, 9, 3, 'x');
}

point * makeHorizontalLevel3Obstacle2(){
  return makeObstacleTemplate(178, 90, 9, 3, 'x');
}

point * makeHorizontalLevel4Obstacle1(){
  return makeObstacleTemplate(30, 120, 9, 3, 'x');
}

point * makeHorizontalLevel4Obstacle2(){
  return makeObstacleTemplate(117, 120, 50, 3, 'x');
}

point * makeHorizontalLevel5Obstacle1(){
  return makeObstacleTemplate(3, 170, 62, 3, 'x');
}

point * makeHorizontalLevel5Obstacle2(){
  return makeObstacleTemplate(240, 170, 19, 3, 'x');
}

point * makeHorizontalLevel6Obstacle1(){
  return makeObstacleTemplate(120, 210, 13, 3, 'x');
}

point * makeHorizontalLevel6Obstacle2(){
  return makeObstacleTemplate(200, 210, 13, 3, 'x');
}

point * makeVerticalLevel1Obstacle1(){
  return makeObstacleTemplate(50, 27, 9, 7, 'y');
}

point * makeVerticalLevel1Obstacle2(){
  return makeObstacleTemplate(117, 23, 14, 7, 'y');
}

point * makeVerticalLevel1Obstacle3(){
  return makeObstacleTemplate(178, 23, 10, 7, 'y');
}

point * makeVerticalLevel1Obstacle4(){
  return makeObstacleTemplate(208, 23, 10, 7, 'y');
}

point * makeVerticalLevel2Obstacle1(){
  return makeObstacleTemplate(28, 95, 4, 7, 'y');
}

point * makeVerticalLevel2Obstacle2(){
  return makeObstacleTemplate(270, 60, 9, 7, 'y');
}

point * makeVerticalLevel3Obstacle1(){
  return makeObstacleTemplate(240, 127, 12, 7, 'y');
}

point * makeVerticalLevel4Obstacle1(){
  return makeObstacleTemplate(160, 177, 5, 7, 'y');
}

point * makeVerticalLevel5Obstacle1(){
  return makeObstacleTemplate(30, 210, 5, 7, 'y');
}

point * makeVerticalLevel5Obstacle2(){
  return makeObstacleTemplate(270, 210, 5, 7, 'y');
}

// end of my functions

int collect_delta(int state) {
	position += os_enc_delta();
	return state;
}

int check_switches(int state) {

	if (get_switch_press(_BV(SWN))) {
			playerY -= 3;
      printPlayer();
	}

	if (get_switch_press(_BV(SWE))) {
			playerX += 3;
      printPlayer();
	}

	if (get_switch_press(_BV(SWS))) {
			playerY += 3;
      printPlayer();
	}

	if (get_switch_press(_BV(SWW))) {
			playerX -= 3;
      printPlayer();
	}

	if (get_switch_long(_BV(SWC))) {
    startNewGame();
	}

	if (get_switch_short(_BV(SWC))) {
    startNewGame();
	}

	if (get_switch_rpt(_BV(SWN))) {
    playerY -= 3;
    printPlayer();
	}

	if (get_switch_rpt(_BV(SWE))) {
    playerX += 3;
    printPlayer();
	}

	if (get_switch_rpt(_BV(SWS))) {
    playerY += 3;
    printPlayer();
	}

	if (get_switch_rpt(_BV(SWW))) {
    playerX -= 3;
    printPlayer();
	}

	if (get_switch_rpt(SWN)) {

	}


	if (get_switch_long(_BV(OS_CD))) {

	}

	return state;
}




int blink(int state) {
	static int light = 0;
	uint8_t level;

	if (light < -120) {
		state = 1;
	} else if (light > 254) {
		state = -20;
	}


	/* Compensate somewhat for nonlinear LED
           output and eye sensitivity:
        */
	if (state > 0) {
		if (light > 40) {
			state = 2;
		}
		if (light > 100) {
			state = 5;
		}
	} else {
		if (light < 180) {
			state = -10;
		}
		if (light < 30) {
			state = -5;
		}
	}
	light += state;

	if (light < 0) {
		level = 0;
	} else if (light > 255) {
		level = 255;
	} else {
		level = light;
	}

	os_led_brightness(level);
	return state;
}
