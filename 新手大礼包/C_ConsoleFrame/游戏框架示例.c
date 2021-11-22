#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
void Update();
int _game_exit = 1;
int gameFramesCounter = 0;
int getGameFramesCount() { return gameFramesCounter; }
void exitGame() { _game_exit = 0; }
void _checkInput();
void Start();
int gotoxy(int x, int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}
void paint(int x, int y, char n)
{
	gotoxy(x, y);
	printf("%c", n);
}
char key[12];
int _key_number = 0;
void setKey(char n)
{
	if (_key_number < 12)
	{
		key[_key_number] = n;
		_key_number++;
	}
}
int _key_down = 0;
int _the_key[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
void _checkInput()
{
	if (kbhit() != 0)
	{
		char n;
		while (!kbhit() == 0)
		{
			n = getch();
			int i;
			for (i = 0; i < _key_number; i++)
			{
				if (key[i] == n)
				{
					_key_down |= _the_key[i];
				}
			}
		}
	}
}
int getKeyDown(char n)
{
	int i = 0;
	int flag = 0;
	for (; i < _key_number; i++)
	{
		if (key[i] == n)
		{
			flag = 1;
			break;
		}
	}
	return _key_down & _the_key[i] && flag;
}
int gameFrames = 10;
void setGameFrames(int n) { gameFrames = n; }
void clear() { system("cls"); }
void End();
void start()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	Start();
	while (_game_exit)
	{
		_key_down = 0;
		_checkInput();
		Update();
		gameFramesCounter++;
		Sleep(920 / gameFrames);
	}
	End();
}

typedef struct
{
	int x;
	int y;
} Point; //����һ����Ľṹ��

int width = 80, height = 25;											//��Ϸ�߿�
Point snake[2001] = {{12, 20}, {12, 21}, {12, 22}, {12, 23}, {12, 23}}; //�ߵ�����
int length = 4;															//�ߵĳ���
Point direction = {0, -1};												//����ǰ���ķ���
Point tempDirection;													//���´�ǰ������
int score = 0;															//�÷�
Point food;																//ʳ��

void drawTheBorder();		 //�����߿�
void drawSnake();			 //������
void letSnakeGo(int Frames); //����ÿ��һ��֡���˶�һ��
void control();				 //�ٿ�
void generateFood();		 //����ʳ��
void eatFood();				 //��ʳ��
void checkCollision();		 //��ײ���
void drawEndMenu();			 //������������

//�ڸú����������Ϸ��ֵ�Լ�ǰ�ڹ���������趨
void Start()
{
	setKey('w'); //���ð�������
	setKey('s');
	setKey('a');
	setKey('d');
	drawTheBorder();   //����UI
	setGameFrames(40); //������Ϸ֡��
	generateFood();	   //������һ��ʳ��
}

//�ú�����ÿһ֡���е�����
void Update()
{
	drawSnake();   //������ǰ�ߵ�����
	eatFood();	   //�ж����Ƿ����ʳ��
	control();	   //�����ߵķ���
	letSnakeGo(3); //�����Զ�ǰ��
}

//��������Ϸʱ�ĺ���
void End()
{
	drawEndMenu(); //�����˵�
}

int main()
{
	start();
	return 0;
}
/*===========================�����Ǻ�������============================*/
void drawTheBorder()
{
	int i;
	for (i = 0; i < width; i++)
	{ //������ͼ�߿�
		paint(i, 0, '#');
		paint(i, height - 1, '#');
	}
	for (i = 0; i < height; i++)
	{
		paint(width - 1, i, '#');
		paint(0, i, '#');
	}
	gotoxy(100, 12);
	printf("��ĵ÷�:"); //�����÷�
	gotoxy(103, 14);
	printf("%d", score);
}

void drawSnake()
{
	int i;
	for (i = 0; i < length; i++)
	{ //���������黭������
		paint(snake[i].x, snake[i].y, '@');
	}
	paint(snake[length].x, snake[length].y, ' '); //������һ֡�������߲����Ĳ���
	paint(0, 0, '#');
}

void letSnakeGo(int Frames)
{
	if (getGameFramesCount() % Frames == 0)
	{ //ÿ��һ��֡���ƶ�һ����
		if (direction.x)
		{
			if (tempDirection.y)
			{
				direction = tempDirection;
				direction.x = 0;
			}
		}
		else
		{
			if (tempDirection.x)
			{
				direction = tempDirection;
				direction.y = 0;
			}
		}
		int i;
		for (i = length; i > 0; i--)
		{
			snake[i] = snake[i - 1];
		}
		snake[0].x = (snake[0].x + direction.x + width - 3) % (width - 2) + 1; //���ߵ��߽�ʱ��Խ������
		snake[0].y = (snake[0].y + direction.y + height - 3) % (height - 2) + 1;

		checkCollision();
	}
}

void control()
{ //���ƶ����򴢴��� temp��
	Point temp = {0, 0};
	if (getKeyDown('w'))
	{
		temp.y -= 1;
	}
	if (getKeyDown('s'))
	{
		temp.y += 1;
	}
	if (getKeyDown('a'))
	{
		temp.x -= 1;
	}
	if (getKeyDown('d'))
	{
		temp.x += 1;
	}

	if (tempDirection.x)
	{
		if (temp.y)
		{
			tempDirection.x = 0;
			tempDirection.y = temp.y;
		}
	}
	else
	{
		if (temp.x)
		{
			tempDirection.y = 0;
			tempDirection.x = temp.x;
		}
	}
}

void generateFood()
{ // ����ʳ��
	srand((int)time(0));
	food.x = rand() % (width - 2) + 1;
	food.y = rand() % (height - 2) + 1;
	paint(food.x, food.y, '0');
}

void eatFood()
{ //��ʳ��
	int i;
	for (i = 0; i < length; i++)
	{
		if (snake[i].x == food.x && snake[i].y == food.y)
		{
			score++;
			length++;
			setGameFrames(40 + score * 2);
			generateFood();
			gotoxy(103, 14);
			printf("%d", score);
		}
	}
}

void checkCollision()
{ //�����ײ
	int i;
	for (i = 1; i < length; i++)
	{
		if (snake[i].x == snake[0].x && snake[i].y == snake[0].y)
		{
			exitGame();
		}
	}
}

void drawEndMenu()
{ //�����˵�
	gotoxy(30, 11);
	printf("gameover");
	gotoxy(25, 13);
	printf("������յ÷�Ϊ��%d", score);
	gotoxy(0, 26);
}
