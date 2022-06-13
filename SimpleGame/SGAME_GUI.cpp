#include <windows.h>  
#include "chmat.h"
#include <string>

#define IDI_ICON1 101
#define spaceshipWidth 35
#define spaceshipHeight 35

HINSTANCE hInst;   // current instance
HWND     hWnd, hEdit, HButton1, HButton2, HButton3, Hmainbmp;    //parent window
HANDLE hTimerQueue = NULL;
HANDLE hAlienTimer = NULL;
HANDLE hTimer = NULL;
HANDLE hATimer = NULL;
HANDLE shootHandle;

LPCTSTR lpszAppName = "GEN32";
LPCTSTR lpszTitle = "GENERIC32";
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

struct alienStruct {
	bool ExecutableColor;
	int alienX;
	int alienY;
	int direction;
};


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine, int nCmdShow)
{
	MSG      msg;
	WNDCLASSEX wc;
	HMENU MainMenu;
	MainMenu = CreateMenu();

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszMenuName = lpszAppName;
	wc.lpszClassName = lpszAppName;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hIconSm = (HICON)LoadImage(hInstance, lpszAppName,
		IMAGE_ICON, 16, 16,
		LR_DEFAULTCOLOR);


	if (!RegisterClassEx(&wc))
		return(FALSE);

	hInst = hInstance;
	hWnd = CreateWindowEx(0, lpszAppName,
		lpszTitle,
		WS_OVERLAPPEDWINDOW,
		350, 5,
		652, 820,
		NULL,
		MainMenu,
		hInstance,
		NULL
	);

	if (!hWnd)
		return(FALSE);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return(msg.wParam);
}

CHMAT matrix(620, 770, CHMAT_INT);
alienStruct alien1, alien2;
int spaceshipX = matrix.X / 2 + 17, spaceshipY = 70;
int shootParameter;
bool shift, isGameOver, isPause, isRestart;
int keypressed, score;

void drawGameOver(int x, int y) {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 90; j++)
		{
			if (gameoverpixel[i][j] != 0) {
				matrix.set(x + j * 4, y - i * 4, 0xffffff);
				matrix.set(x + j * 4, (y - i * 4) + 1, 0xffffff);
				matrix.set(x + j * 4, (y - i * 4) + 2, 0xffffff);
				matrix.set(x + j * 4, (y - i * 4) + 3, 0xffffff);
				matrix.set(x + j * 4, (y - i * 4) + 4, 0xffffff);

				matrix.set((x + j * 4) + 1, y - i * 4, 0xffffff);
				matrix.set((x + j * 4) + 1, (y - i * 4) + 1, 0xffffff);
				matrix.set((x + j * 4) + 1, (y - i * 4) + 2, 0xffffff);
				matrix.set((x + j * 4) + 1, (y - i * 4) + 3, 0xffffff);
				matrix.set((x + j * 4) + 1, (y - i * 4) + 4, 0xffffff);

				matrix.set((x + j * 4) + 2, y - i * 4, 0xffffff);
				matrix.set((x + j * 4) + 2, (y - i * 4) + 1, 0xffffff);
				matrix.set((x + j * 4) + 2, (y - i * 4) + 2, 0xffffff);
				matrix.set((x + j * 4) + 2, (y - i * 4) + 3, 0xffffff);
				matrix.set((x + j * 4) + 2, (y - i * 4) + 4, 0xffffff);

				matrix.set((x + j * 4) + 3, y - i * 4, 0xffffff);
				matrix.set((x + j * 4) + 3, (y - i * 4) + 1, 0xffffff);
				matrix.set((x + j * 4) + 3, (y - i * 4) + 2, 0xffffff);
				matrix.set((x + j * 4) + 3, (y - i * 4) + 3, 0xffffff);
				matrix.set((x + j * 4) + 3, (y - i * 4) + 4, 0xffffff);
			}
		}
	}
}

void drawScore(int x, int y, int score) {
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 38; j++)
		{
			if (scorepixel[i][j] != 0) {
				matrix.set(x + j * 2, y - i * 2, 0xffffff);
				matrix.set(x + j * 2, (y - i * 2) + 1, 0xffffff);
				matrix.set(x + j * 2, (y - i * 2) + 2, 0xffffff);

				matrix.set((x + j * 2) + 1, y - i * 2, 0xffffff);
				matrix.set((x + j * 2) + 1, (y - i * 2) + 1, 0xffffff);
				matrix.set((x + j * 2) + 1, (y - i * 2) + 2, 0xffffff);
			}
		}
	}
	int a = 80;

	for (int i = x + a; i < 500; i++)
	{
		for (int j = 30; j > 1; j--)
		{
			matrix.set(i, j, 0);
		}

	}
	if (score == 0) {
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (num0[j][i] != 0) {
					matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
					matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
				}
			}
		}
	}

	for (int k = (int)(log10(score)) + 1; k > 0; k--)
	{
		switch ((score / (int)(pow(10, (int)(k - 1)))) % 10)//divide 0
		{
		case 1: {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num1[j][i] != 0) {
						matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
						matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
					}
				}
			}
			a += 15;
		}
			  break;
		case 2: {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num2[j][i] != 0) {
						matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
						matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
					}
				}
			}
			a += 15;

		}
			  break;
		case 3: {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num3[j][i] != 0) {
						matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
						matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
					}
				}
			}
			a += 15;
		}
			  break;
		case 4: {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num4[j][i] != 0) {
						matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
						matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
					}
				}

			}
			a += 15;
		}
			  break;
		case 5: {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num5[j][i] != 0) {
						matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
						matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
					}
				}

			}
			a += 15;
		}
			  break;
		case 6: {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num6[j][i] != 0) {
						matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
						matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
					}
				}

			}
			a += 15;
		}
			  break;
		case 7: {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num7[j][i] != 0) {
						matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
						matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
					}
				}

			}
			a += 15;
		}
			  break;
		case 8: {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num8[j][i] != 0) {
						matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
						matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
					}
				}

			}
			a += 15;
		}
			  break;
		case 9: {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num9[j][i] != 0) {
						matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
						matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
					}
				}

			}
			a += 15;
		}
			  break;
		default: {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num0[j][i] != 0) {
						matrix.set(x + i * 2 + a, y - 10 + j * 2, 0xffffff);
						matrix.set(x + i * 2 + a, y - 10 + j * 2 + 1, 0xffffff);
					}
				}
			}
			a += 15;
		}
			   //draw 0
			   break;
		}
	}
	SendMessage(Hmainbmp, STM_SETIMAGE, 0, (LPARAM)matrix.HBitmap);
}

void drawBullet(int x, int y, int color) {
	if (!isGameOver) {
		if (y >= matrix.Y - 10) {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (bullet[i][j] != 0) {
						matrix.set(x + i, y + j * 2 - 10, 0);
						matrix.set(x + i, y + j * 2 - 9, 0);
					}
				}
			}
		}
		else {
			//delete for animation
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (bullet[i][j] != 0) {
						matrix.set(x + i, y + j * 2 - 10, 0);
						matrix.set(x + i, y + j * 2 - 9, 0);
					}

				}
			}
			//draw bullet
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (bullet[i][j] != 0) {
						matrix.set(x + i, y + j * 2, color);
						matrix.set(x + i, y + j * 2 + 1, color);
					}
				}
			}
		}
	}
	SendMessage(Hmainbmp, STM_SETIMAGE, 0, (LPARAM)matrix.HBitmap);
}

void gameoverFunc() {
	isGameOver = true;
	DeleteTimerQueue(hTimerQueue);
	DeleteTimerQueue(hAlienTimer);
	matrix = 0;
	drawGameOver(140, 381);
	SendMessage(Hmainbmp, STM_SETIMAGE, 0, (LPARAM)matrix.HBitmap);
}

VOID CALLBACK SlidingBox(PVOID lpParam, BOOLEAN TimerOrWaitFired)
{
	for (int i = 0; i < spaceshipWidth; i++)
	{
		for (int j = 0; j < spaceshipHeight; j++)
		{
			matrix.set(spaceshipX + i, spaceshipY - j, 0);
		}
	}
	if (keypressed == 37) {
		if (spaceshipX > 1)
			spaceshipX -= 2;//left
	}
	if (keypressed == 39) {
		if (spaceshipX < matrix.X - 35)
			spaceshipX += 2;//right
	}
	if (keypressed == 38) {
		if (spaceshipY < 350)
			spaceshipY += 2;//up
	}

	if (keypressed == 40) {
		if (spaceshipY > 70)
			spaceshipY -= 2;//down

	}

	for (int i = 0; i < spaceshipWidth; i++)
	{
		for (int j = 0; j < spaceshipHeight; j++)
		{
			if (spaceshippixel[i * spaceshipWidth + j] != 0)
				matrix.set(spaceshipX + i, spaceshipY - j, spaceshippixel[i * spaceshipWidth + j]);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (shift) {
				matrix.set(600 + i, 15 + j * 2, 0xff0000);
				matrix.set(600 + i, 15 + j * 2 + 1, 0xff0000);
			}

			else {
				matrix.set(600 + i, 15 + j * 2, 0x0000ff);
				matrix.set(600 + i, 15 + j * 2 + 1, 0x0000ff);
			}

		}
	}
	SendMessage(Hmainbmp, STM_SETIMAGE, 0, (LPARAM)matrix.HBitmap);
}

VOID* Shoot(LPVOID vv)
{
	struct alienStruct* alien = (struct alienStruct*)vv;
	int locx, locy;
	shootParameter = 0;
	drawScore(2, 20, score);
	locx = spaceshipX + 15;
	locy = spaceshipY + 5;
	bool shotflag = true;

	for (int j = locy; j < matrix.Y; j++)
	{

		if (alien->ExecutableColor)
			drawBullet(locx, j, 0xff0000);
		else
			drawBullet(locx, j, 0x0000ff);
		Sleep(1);

		if (locx >= alien->alienX - 4 && locx <= (alien->alienX + 39) && j >= alien->alienY - 35 && j <= (alien->alienY) && shotflag)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int k = 0; k < 5; k++)
				{
					
						matrix.set(locx + i, j + k * 2 - 10, 0);
						matrix.set(locx + i, j + k * 2 - 9, 0);
				
				}
			}

			for (int i = 0; i < spaceshipWidth; i++)
			{
				for (int j = 0; j < spaceshipHeight; j++)
				{
					matrix.set(alien->alienX + i, alien->alienY - j, 0);
				}
			}
			alien->alienY = 700;
			alien->direction *= -1;
			shotflag = false;
			score += 100;
		}
	}
	SendMessage(Hmainbmp, STM_SETIMAGE, 0, (LPARAM)matrix.HBitmap);
	return(0);
}

VOID CALLBACK Alien(PVOID lpParam, BOOLEAN TimerOrWaitFired)
{
	struct alienStruct* alien = (struct alienStruct*)lpParam;
	int speed = 1;
	if (score > 1000) speed = 2;
	if (score > 10000) speed = 3;
	drawScore(2, 20, score);
	//delete for animation
	for (int i = 0; i < spaceshipWidth; i++)
	{
		for (int j = 0; j < spaceshipHeight; j++)
		{
			matrix.set(alien->alienX + i, alien->alienY - j, 0);
		}
	}
	alien->alienY -= speed;
	alien->alienX += alien->direction;

	DWORD dw;
	if (alien->alienY < 70) {
		gameoverFunc();
		for (int i = 0; i < spaceshipWidth; i++)
		{
			for (int j = 0; j < spaceshipHeight; j++)
			{
				matrix.set(alien->alienX + i, alien->alienY - j, 0);
			}
		}
		return;
	}

	else {
		//draw alien
		if (alien->alienX == 1 && alien->direction == -1)alien->direction = 1;
		if (alien->alienX == matrix.X - spaceshipWidth && alien->direction == 1)alien->direction = -1;
		for (int i = 0; i < spaceshipWidth; i++)
		{
			for (int j = 0; j < spaceshipHeight; j++)
			{
				if (alien->ExecutableColor)
					matrix.set(alien->alienX + i, alien->alienY - j, 0xff0000);
				else
					matrix.set(alien->alienX + i, alien->alienY - j, 0x0000ff);
			}
		}
	}
	SendMessage(Hmainbmp, STM_SETIMAGE, 0, (LPARAM)matrix.HBitmap);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_CREATE:
	{
		hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "Edit", "", WS_CHILD | WS_VISIBLE |
			ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN | WS_VSCROLL, 735, 5, 150, 100, hWnd, NULL, hInst, NULL);
		Hmainbmp = CreateWindowEx(NULL, "STATIC", "", WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_THICKFRAME, 1, 1, 660, 700, hWnd, NULL, hInst, NULL);
		score = 0;
		drawScore(2, 20, score);
		shift = true;
		isGameOver = false;

		alien1.alienX = matrix.X - spaceshipWidth;
		alien1.alienY = matrix.Y;
		alien1.direction = -1;
		alien1.ExecutableColor = true;//red

		alien2.alienX = 0;
		alien2.alienY = 770;
		alien2.direction = 1;
		alien2.ExecutableColor = false;//blue


		hTimerQueue = CreateTimerQueue();
		if (NULL == hTimerQueue)
		{
			break;
		}
		//starts 1000 ms later calls thread every 30 ms
		CreateTimerQueueTimer(&hTimer, hTimerQueue, (WAITORTIMERCALLBACK)SlidingBox, NULL, 0, 25, WT_EXECUTEONLYONCE);
		//----------------------Alien Timer -------------------------


		hAlienTimer = CreateTimerQueue();
		if (NULL == hAlienTimer)
		{
			break;
		}
		CreateTimerQueueTimer(&hATimer, hAlienTimer, (WAITORTIMERCALLBACK)Alien, &alien1, 100, 30, WT_EXECUTEONLYONCE);
		CreateTimerQueueTimer(&hATimer, hAlienTimer, (WAITORTIMERCALLBACK)Alien, &alien2, 4000, 30, WT_EXECUTEONLYONCE);
	}
	break;
	case WM_KEYDOWN:
	{
		static int t;
		static DWORD dw, dw2;
		t = (int)wParam;
		if (t == 32) {
			if (lParam & (1 << 30))
			{
				break;
			}
			else
			{
				if (score >= 10) {
					score -= 10;
				}
				shootParameter = 1;
				if (shift)
					CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Shoot, &alien1, 0, &dw);
				else
					CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Shoot, &alien2, 0, &dw2);
			}
		}
		if (t > 36 && t < 41) keypressed = t;
		if (t == 16) shift = !shift;
	}
	break;
	case WM_DESTROY:
		DeleteTimerQueue(hTimerQueue);
		DeleteTimerQueue(hAlienTimer);
		PostQuitMessage(0);
		break;
	default:
		return(DefWindowProc(hWnd, uMsg, wParam, lParam));
	}
	return(0L);
}

