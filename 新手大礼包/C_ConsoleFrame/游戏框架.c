#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
void Update();
int _game_exit = 1;
int gameFramesCounter = 0;
int getGameFramesCount() { return gameFramesCounter; }
void Awake();
void OnEnable();
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
int _height = 50;
int _width = 100;
void setHeight(int height) { _height = height; }
void setWidth(int width) { _width = width; }
void _updateHandW()
{
	int i;
	char *cmd = (char *)malloc(sizeof(char) * 35);
	int lenth = 0;
	const char *_cmd_1 = "mode con cols=";
	const char *_cmd_2 = " lines=";
	for (i = 0; _cmd_1[i]; i++)
	{
		cmd[lenth++] = _cmd_1[i];
	}
	char temp[10];
	for (i = 0; temp[i]; i++)
	{
		temp[i] = '\0';
	}
	itoa(_width, temp, 10);
	for (i = 0; temp[i]; i++)
	{
		cmd[lenth++] = temp[i];
	}
	for (i = 0; _cmd_2[i]; i++)
	{
		cmd[lenth++] = _cmd_2[i];
	}
	for (i = 0; temp[i]; i++)
	{
		temp[i] = '\0';
	}
	itoa(_height, temp, 10);
	for (i = 0; temp[i]; i++)
	{
		cmd[lenth++] = temp[i];
	}
	cmd[lenth++] = '\0';
	const char *_cmd = cmd;
	system(_cmd);
}
void start()
{
	Awake();
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	OnEnable();
	_updateHandW();
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
/*===============�����ǿ�ܣ����ùܣ������ǿ����һЩ������˵��===============*/
//	void setGameFrames(int gameFrames);		������Ϸ֡��,δ������Ĭ��Ϊ10֡��
//	void setKey(char n);					���ð��������ú��������� n�����֧��12��������
//	int  getKeyDown(char n);				�������˰���������£��������ڸ�֡�ڰ��°��� n���򷵻�1�����򷵻�0�����֧��ͬʱ����12��������
//	void paint(int x,int y,char n);			������Ϊ(x,y)�ĵط����·��� n��
//	int  gotoxy(int x,int y);				�ƶ���굽(x,y)��
//	void clear();							����������ʹ�ûᵼ����Ļ��˸��С��Χ�޸Ľ���ʹ��paint(x,y,' ');���ֶ��������Ա�����Ļ��˸����
//	void exitGame();						�˳���Ϸ��
//	int  getGameFramesCount();				���ص�ǰ���ڵ���֡����
//  void setHeight(int height);				���ô��ڸ߶ȣ�����OnEnable�����е���
//  void setWidth(int width); 				���ô��ڿ��ȣ�����OnEnable�����е���
/*============================================================================*/

/*==================���������뽫��Ҫ��ȫ�ֱ������ڱ�����======================*/
//ȫ�ֱ���

/*============================================================================*/

/**
 * Awake()���Ѻ������ú������ڳ�����س�ִ��һ�Σ� 
 */
void Awake()
{
}

/**
 * OnEnable()���غ������ú�����ִ����Ϸ��ʼ���趨 
 */
void OnEnable()
{
}

/**
 * Start()��ʼ�������ú���������Ϸ��ʼʱִ��һ�Σ� 
 */
void Start()
{
}

/**
 * Update()���к������ú�����ÿһִ֡��һ�Σ� 
 */
void Update()
{
}

/**
 * End()�����������ú�����ִ��exitGame()��ִ��һ�Σ� 
 */
void End()
{
}

int main()
{
	start();
	return 0;
}
