#include <iostream>
#include <cstdio>
using namespace std;
typedef struct
{
  int x;
  int y;
} DIR;
DIR dir_4[] = { {0, 1}, {1, 0}, {0, -1}, { -1, 0}};


int main() {
  cout << "请分别输入行数和列数" << endl;
  int max_x, max_y;
  cin >> max_x >> max_y;
  int value[100][100];  //先存入数组中
  int x = 0, y = 0;
  int di = 0;
  for ( int i = 0; i < max_x * max_y; i++)
  {
    value[x][y] = 65 + i % 26;
    int x1, y1;
    x1 = x + dir_4[di].x; y1 = y + dir_4[di].y;
    if (x1 < 0 || x1 >= max_x || y1 < 0 || y1 >= max_y || value[x1][y1] != 0)
    {
      di++; di %= 4;
    }
    x += dir_4[di].x; y += dir_4[di].y;
  }

  for (int i = 0; i < max_x; ++i) {
    for (int j = 0; j < max_y; ++j) {
      cout << char(value[i][j]) << " ";
    }
    cout << endl;
  }
  return 0;
}

