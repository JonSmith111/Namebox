#include <iostream>
#include <ncurses.h>

using namespace std;

int win(int len, int wid, int sy, int sx)
{
	int swid, slen, ssx, ssy;

	WINDOW *win;
	WINDOW *sub;

	swid = wid + 2;
	slen = len + 4;
	ssx = sx - 2;
	ssy = sy - 1;


	initscr();

		sub = newwin(wid,len, sy, sx);
		win = newwin(swid, slen, ssy, ssx);

		start_color();
		init_pair(1, COLOR_GREEN, COLOR_WHITE);
		init_pair(2, COLOR_GREEN, COLOR_GREEN);

		wbkgd(win, COLOR_PAIR(2));
		wbkgd(sub, COLOR_PAIR(1));

		wborder(win, '-', '-', '-', '-', '-', '-', '-', '-');

		wprintw(sub, "Hello World");

		mvprintw(0, 0, " ");

		move(len+100, wid+100);

		refresh();
                wrefresh(win);
                wrefresh(sub);

		getch();

	endwin();

	return 0;
}

int main()
{
  string str = "Enter your name: ", name;
  char input[225], c;

  int swid, slen, ssx, ssy;
  int len, wid, sy, sx;

  int col;
  
  WINDOW *win;
  WINDOW *sub;

  cout<<"Enter Color Choice"<<endl
      <<"A: Red"<<endl
      <<"B: Yellow"<<endl
      <<"C: Green"<<endl
      <<"D: Cyan"<<endl
      <<"E: Blue"<<endl
      <<"F: Magenta"<<endl
      <<": ";
  cin>>c;

  switch(c)
    {
    case'a':
    case 'A':
      col = COLOR_RED;
      break;
    case 'b':
    case 'B':
      col = COLOR_YELLOW;
      break;
    case 'C':
    case 'c':
      col = COLOR_GREEN;
      break;
    case 'd':
    case 'D':
      col = COLOR_CYAN;
      break;
    case 'e':
    case 'E':
      col = COLOR_BLUE;
      break;
    case 'F':
    case 'f':
      col = COLOR_MAGENTA;
    }

  len = str.size()+20;
  wid = 1;
  sy = 5;
  sx = 5;
  
  swid = wid + 2;
  slen = len + 4;
  ssx = sx - 2;
  ssy = sy - 1;


  initscr();

  sub = newwin(wid,len, sy, sx);
  win = newwin(swid, slen, ssy, ssx);
  
  start_color();
  init_pair(1, col, COLOR_WHITE);
  init_pair(2, COLOR_WHITE, col);
  
  wbkgd(win, COLOR_PAIR(2));
  wbkgd(sub, COLOR_PAIR(1));
  
  wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
  
  wprintw(sub, str.c_str());
  
  mvprintw(0, 0, " ");
  move(0, str.length());

  refresh();
  wrefresh(win);
  wrefresh(sub);

  wgetstr(sub, input);
  clear();

  name = input;

  str = "Enter Boarder Char: ";
  len = str.size() + 3;
  wid = 1;
  sy = 5;
  sx = 5;
  
  swid = wid + 2;
  slen = len + 4;
  ssx = sx - 2;
  ssy = sy - 1;

  sub = newwin(wid, len, sy, sx);
  win = newwin(swid, slen, ssy, ssx);

  wbkgd(win, COLOR_PAIR(2));
  wbkgd(sub, COLOR_PAIR(1));

  wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
  
  mvprintw(0, 0, " ");
  wprintw(sub, str.c_str());
  move(0, str.length());

  refresh();
  wrefresh(win);
  wrefresh(sub);

  wgetstr(sub, input);
  clear();

  c = input[0];
  len = name.size();
  wid = 1;
  sy = 5;
  sx = 5;
  
  swid = wid + 2;
  slen = len + 4;
  ssx = sx - 2;
  ssy = sy - 1;

  sub = newwin(wid, len, sy, sx);
  win = newwin(swid, slen, ssy, ssx);

  wbkgd(win, COLOR_PAIR(2));
  wbkgd(sub, COLOR_PAIR(1));

  wborder(win, c, c, c, c, c, c, c, c);
  mvprintw(0, 0, " ");
  wprintw(sub, name.c_str());
  curs_set(0);
  
  refresh();
  wrefresh(win);
  wrefresh(sub);

  curs_set(0);
  getch();
  
  endwin();
}
