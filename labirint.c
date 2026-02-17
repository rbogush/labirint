#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define MazeSize 24
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN  "\033[1;32m"
#define BLUE  "\033[1;36m"
#define YELLOW  "\033[1;33m"

void OutputMaze(char Maze[][25],int FloorNum,int I,int Z);
int Move(char Maze[][MazeSize + 1], int I, int Z, char dirMove,char* symbol,int* Icord,int* Zcord);
int Position(int FloorNum,int I, int Z);


int main(void) {
  printf("\033[?25l"); //отключает курсор в терминале
  system("cls"); // очищает терминал
    char SecondFloor[25][25] = {
        "#########################", 
        "#++ + #   #           #^#",
        "#++   # # #           # #", 
        "#     | # # # ######    #", 
        "#+  + | # # #   ####    #", 
        "#    !# #   #   ######  #", 
        "###--#########  ######  #", 
        "#     ## +++ #  ######  #", 
        "#     ##     #  ######  #", 
        "#  #  |    + #  #    #  #", 
        "#  #  |    + #  # ++ #  #", 
        "#  #  ##    *#  #       #", 
        "#  #  ## +++ #  #       #", 
        "#  #  ########  # ++ #  #", 
        "#  #  # + + +#  #    #  #", 
        "#  #  #      #  ######  #", 
        "#  #  ###  ###  #?   #  #", 
        "#  #               ++#  #", 
        "#  #               ++#  #", 
        "#  ####  #####  #  ++#  #", 
        "#    ##  #####  #+   #  #", 
        "#    ##  #####  ######  #", 
        "#-#                     #",
        "#@#                     #", 
        "#########################"  
    };

    char FirstFloor[25][25] = {
        "#########################", 
        "#                     #^#",
        "#                     # #", 
        "#  ####  ## ########    #", 
        "#  ####  #        ?#    #", 
        "#  ####  #############  #", 
        "#  #        ## +++++ #  #", 
        "#  #        ##       #  #", 
        "#  #+          + + + #  #", 
        "#  #+          + + + #  #", 
        "#  #        ##       #  #", 
        "#  #        ## ++    #  #", 
        "#  ####  #########  ##  #", 
        "#  ####  #########  ##  #", 
        "#    ##--##             #", 
        "#     |  ##             #", 
        "###   |  ###########  ###", 
        "#######  ##        #  ###", 
        "##    #  ##        #    #", 
        "##       ##   ###  #    #", 
        "## #     ##---###  ###  #", 
        "## ########   ###  ###  #", 
        "##     *#       #       #",
        "#########       #       #", 
        "############~############"  
    };

    char ThirdFloor[25][25] = {
        "#########################", 
        "#                       #",
        "#                       #", 
        "#  ## ### ### ### ####  #", 
        "#  #   #   #   #   # #  #", 
        "#  #         ?          #", 
        "#  #   #   #   #   # #  #", 
        "#  ## ### ### ### ####  #", 
        "#                   ##  #", 
        "#  ## # #  +++  #####   #", 
        "#  ## # #  +++  #       #", 
        "#  ## # #  +++  #   +   #", 
        "#  ## # #       #+      #", 
        "#               #+      #", 
        "#  ######## #####   +   #", 
        "#  #######      #       #", 
        "#  #######+   ++#    #  #", 
        "#  #+  ++#############  #", 
        "#        #############  #", 
        "#  #   ++##++  +#++     #", 
        "#  ########    *#    #  #", 
        "#   #########-########  #", 
        "#-#                     #",
        "#@#                     #", 
        "#########################"  
    };

    int FloorNum;
    char text1[] = "Где я?.. Холодный металл, странные звуки... Это корабль пришельцев!";
    char text2[] = "Внимание! Вы были похищены. Сейчас вы на корабле пришельцев!";
    char text3[] = "Побег — ваш единственный шанс!";
    int a;

    for (a = 0; a < 10; a++)
      printf("\n");

    for (a = 0; a < 30; a++)
      printf(" ");

    printf("%s", GREEN);

    for (a = 0; text1[a] != '\0'; a++)
    {
    printf("%c", text1[a]);
    fflush(stdout);
    Sleep(40);
    }

    Sleep(300);

    system("cls");
    printf("\033[H");

    for (a = 0; a < 10; a++)
      printf("\n");

    for (a = 0; a < 35; a++)
      printf(" ");

    for (a = 0; text2[a] != '\0'; a++)
    {
    printf("%c", text2[a]);
    fflush(stdout);
    Sleep(40);
    }

    Sleep(300);

    system("cls");
    printf("\033[H");

    printf("%s", RED);

    for (a = 0; a < 10; a++)
      printf("\n");

    for (a = 0; a < 50; a++)
      printf(" ");

    for (a = 0; text3[a] != '\0'; a++)
    {
    printf("%c", text3[a]);
    fflush(stdout);
    Sleep(40);
    }

    Sleep(500);

    printf("%s", RESET);
    system("cls");
    printf("\033[H");

    printf("На каком этаже вы находитесь(номер)?\n");
    printf("1 (Черные стены)\n");
    printf("2 (Зеленые стены)\n");
    printf("3 (Голубые стены)\n");
    printf("Ответ: ");
    scanf("%d", &FloorNum);
    printf("\n");
    char *symbol;
    char space = ' ';
    symbol = &space;
    int I = 1;
    int Z = 1;
    int *Icord = &I;
    int *Zcord = &Z;
    char dirMove;
    int StartPos,Istart,Zstart;
    switch(FloorNum)
      {
      case 1:
        printf("Где вы находитесь?(Введите число)\n");
        printf("1 - Ферма растений\n");
        printf("2 - Спортзал для лунного футбола\n");
        printf("3 - Угол коридора\n");
        printf("4 - Тупик\n");
        printf("Ответ: ");
        scanf("%d", &StartPos);
        printf("\n");
        switch(StartPos)
          {
          case 1: 
            Istart = 10;
            Zstart = 19;
            FirstFloor[Istart][Zstart] = '$';
            break;
          case 2: 
            Istart = 10;
            Zstart = 9;
            FirstFloor[Istart][Zstart] = '$';
            break;
          case 3: 
            Istart = 1;
            Zstart = 1;
            FirstFloor[Istart][Zstart] = '$';
            break;
          case 4: 
            Istart = 14;
            Zstart = 11;
            FirstFloor[Istart][Zstart] = '$';
            break;
          }
        break;
      case 2:
        printf("Где вы находитесь?(Введите число)\n");
        printf("1 - Хранилище\n");
        printf("2 - Центр Безопасности\n");
        printf("3 - Столовая\n");
        printf("4 - Узкий лабиринт\n");
        printf("Ответ: ");
        scanf("%d", &StartPos);
        printf("\n");
        switch(StartPos)
          {
          case 1: 
            Istart = 15;
            Zstart = 10;
            SecondFloor[Istart][Zstart] = '$';
            break;
          case 2: 
            Istart = 20;
            Zstart = 20;
            SecondFloor[Istart][Zstart] = '$';
            break;
          case 3: 
            Istart = 11;
            Zstart = 18;
            SecondFloor[Istart][Zstart] = '$';
            break;
          case 4: 
            Istart = 5;
            Zstart = 9;
            SecondFloor[Istart][Zstart] = '$';
            break;
          }
        break;
      case 3:
        printf("Где вы находитесь?(Введите число)\n");
        printf("1 - Камера заключенных номер 1\n");
        printf("2 - Камера заключенных номер 2\n");
        printf("3 - Обсерватория\n");
        printf("4 - Фонтан\n");
        printf("Ответ: ");
        scanf("%d", &StartPos);
        printf("\n");
        switch(StartPos)
          {
          case 1: 
            Istart = 18;
            Zstart = 5;
            ThirdFloor[Istart][Zstart] = '$';
            break;
          case 2: 
            Istart = 20;
            Zstart = 19;
            ThirdFloor[Istart][Zstart] = '$';
            break;
          case 3: 
            Istart = 15;
            Zstart = 17;
            ThirdFloor[Istart][Zstart] = '$';
            break;
          case 4: 
            Istart = 12;
            Zstart = 12;
            ThirdFloor[Istart][Zstart] = '$';
            break;
          }
          break;
      }
  bool StartOfGame = true;
  while (FloorNum != 0)
    {
    switch(FloorNum)
      {
      case 1:
        if (StartOfGame)
          {
          I = Istart;
          Z = Zstart;
          }
        StartOfGame = false;
        OutputMaze(FirstFloor,FloorNum,I,Z);
        dirMove = _getch();
        Move(FirstFloor,I,Z,dirMove,symbol,Icord,Zcord);
        if (I == 4 && Z == 18)
          {
          *symbol = ' ';
          FirstFloor[14][7] = ' ';
          FirstFloor[14][8] = ' ';
          FirstFloor[15][6] = ' ';
          FirstFloor[16][6] = ' ';
          }
        if (I == 22 && Z == 7)
          {
          *symbol = ' ';
          FirstFloor[20][11] = ' ';
          FirstFloor[20][12] = ' ';
          FirstFloor[20][13] = ' ';
          }
        if (I == 24 && Z == 12)
          FloorNum = 0;
        if (I == 2 && Z == 23)
          {
          FloorNum = 2;
          I = 21;
          Z = 1;
          FirstFloor[2][23] = ' ';
          SecondFloor[I][Z] = '$';
          *symbol = ' ';
          }
        break;
      case 2:
        if (StartOfGame)
          {
          I = Istart;
          Z = Zstart;
          }
        StartOfGame = false;
        OutputMaze(SecondFloor,FloorNum,I,Z);
        dirMove = _getch();
        Move(SecondFloor,I,Z,dirMove,symbol,Icord,Zcord);
        if (I == 16 && Z == 17)
          {
          *symbol = ' ';
          SecondFloor[6][3] = ' ';
          SecondFloor[6][4] = ' ';
          SecondFloor[3][6] = ' ';
          SecondFloor[4][6] = ' ';
          }
        if (I == 5 && Z == 5)
          {
          *symbol = ' ';
          SecondFloor[9][6] = ' ';
          SecondFloor[10][6] = ' ';
          }
        if (I == 11 && Z == 12)
          {
          *symbol = ' ';
          SecondFloor[22][1] = ' ';
          }
        if (I == 22 && Z == 1)
          {
          FloorNum = 1;
          I = 3;
          Z = 23;
          *symbol = ' ';
          SecondFloor[22][1] = ' ';
          FirstFloor[I][Z] = '$';
          }
        if (I == 2 && Z == 23)
          {
          FloorNum = 3;
          I = 21;
          Z = 1;
          *symbol = ' ';
          SecondFloor[2][23] = ' ';
          ThirdFloor[I][Z] = '$';
          }
        break;
      case 3:
        if (StartOfGame)
          {
          I = Istart;
          Z = Zstart;
          }
        StartOfGame = false;
        OutputMaze(ThirdFloor,FloorNum,I,Z);
        dirMove = _getch();
        Move(ThirdFloor,I,Z,dirMove,symbol,Icord,Zcord);
        if (I == 5 && Z == 13)
          {
          *symbol = ' ';
          ThirdFloor[21][13] = ' ';
          }
        if (I == 20 && Z == 15)
          {
          *symbol = ' ';
          ThirdFloor[22][1] = ' ';
          }
        if (I == 22 && Z == 1)
          {
          FloorNum = 2;
          I = 3;
          Z = 23;
          *symbol = ' ';
          ThirdFloor[22][1] = ' ';
          SecondFloor[I][Z] = '$';
          }
        break;
      }
    }
    if (FloorNum == 0)
{
    system("cls");
    
    for (a = 0; a < 10; a++)
        printf("\n");
    

    for (a = 0; a < 50; a++)
        printf(" ");

    printf("%s", GREEN);
    char text[] = "Вы выбрались с корабля пришельцев!";
    for (a = 0; text[a] != '\0'; a++)
    {
        printf("%c", text[a]);
        fflush(stdout);
        Sleep(40);
    }
    
    for (a = 0; a < 15; a++)
        printf("\n");

    printf("%s", RESET);
}
    return 0;
}

void OutputMaze(char Maze[][MazeSize + 1],int FloorNum,int I,int Z)
{
  printf("\033[H"); //Перемещает курсор в начало терминала
  int i,z;

  for (i = 0; i <= MazeSize; i++)
    {
      for (z = 0; z <= MazeSize; z++)
        {
          switch(FloorNum) {
          case 1:
            if (Maze[i][z] == '$')
              printf("%s", YELLOW);
            if (Maze[i][z] == '?' || Maze[i][z] == '!' || Maze[i][z] == '*' || Maze[i][z] == '~' || Maze[i][z] == '@' || Maze[i][z] == '^')
              printf("%s", RED);
            printf("%c ", Maze[i][z]);
            printf("%s", RESET); 
            break;
          case 2:
            if (Maze[i][z] == '$')
              printf("%s", YELLOW);
            if (Maze[i][z] == '#')
              printf("%s", GREEN);
            if (Maze[i][z] == '?' || Maze[i][z] == '!' || Maze[i][z] == '*' || Maze[i][z] == '~' || Maze[i][z] == '@' || Maze[i][z] == '^')
              printf("%s", RED);
            printf("%c ", Maze[i][z]);
            printf("%s", RESET); 
            break;
          case 3:
           if (Maze[i][z] == '$')
              printf("%s", YELLOW);
           if (Maze[i][z] == '#')
              printf("%s", BLUE);
           if (Maze[i][z] == '?' || Maze[i][z] == '!' || Maze[i][z] == '*' || Maze[i][z] == '~' || Maze[i][z] == '@' || Maze[i][z] == '^')
              printf("%s", RED);
            printf("%c ", Maze[i][z]);
            printf("%s", RESET); 
            break;
          }
        }
    printf("\n");
    }
  printf("\n");
  Position(FloorNum,I,Z);
}

int Move(char Maze[][MazeSize + 1], int I, int Z, char dirMove,char* symbol,int* Icord,int* Zcord)
{

  switch(dirMove)
  {
    case 'w':
      if (Maze[I - 1][Z] != '#' && Maze[I - 1][Z] != '+' && Maze[I - 1][Z] != '-' && Maze[I - 1][Z] != '|' && Maze[I - 1][Z] != '+')
        {
        Maze[I][Z] = *symbol;
        *symbol = Maze[I - 1][Z];
        Maze[I - 1][Z] = '$';
        *Icord = *Icord - 1;
        }
      return 0;
    case 's':
      if (Maze[I + 1][Z] != '#' && Maze[I + 1][Z] != '+' && Maze[I + 1][Z] != '-' && Maze[I + 1][Z] != '|' && Maze[I + 1][Z] != '+')
        {
        Maze[I][Z] = *symbol;
        *symbol = Maze[I + 1][Z];
        Maze[I + 1][Z] = '$'; 
        *Icord = *Icord + 1; 
        }
      return 0;
    case 'a':
      if (Maze[I][Z - 1] != '#' && Maze[I][Z - 1] != '+' && Maze[I][Z - 1] != '-' && Maze[I][Z - 1] != '|' && Maze[I][Z - 1] != '+')
        {
        Maze[I][Z] = *symbol;
        *symbol = Maze[I][Z - 1];
        Maze[I][Z - 1] = '$';  
        *Zcord = *Zcord - 1;
        }
      return 0;
    case 'd':
      if (Maze[I][Z + 1] != '#' && Maze[I][Z + 1] != '+' && Maze[I][Z + 1] != '-' && Maze[I][Z + 1] != '|' && Maze[I][Z + 1] != '+')
        {
        Maze[I][Z] = *symbol;
        *symbol = Maze[I][Z + 1];
        Maze[I][Z + 1] = '$';  
        *Zcord = *Zcord + 1;
        }
      return 0; 
  }
}

int Position(int FloorNum, int I, int Z)
{
  switch(FloorNum)
  {
  case 1:
    if ((I >= 6 && I <= 11) && (Z >= 14 && Z <= 20))
      printf("                 ФЕРМА РАСТЕНИЙ                \n");
    else if ((I == 4) && (Z >= 10 && Z <= 18))
      printf("         ТАЙНИК С КЛЮЧОМ ОТ ОРУЖЕЙНОЙ         \n");
    else if ((I >= 6 && I <= 11) && (Z >= 4 && Z <= 11))
      printf("          СПОРТЗАЛ ДЛЯ ЛУННОГО ФУТБОЛА        \n");
    else if ((I == 22) && (Z >= 2 && Z <= 7))
      printf("                   ОРУЖЕЙНАЯ                  \n");
    else if ((I >= 22 && I <= 23) && (Z >= 9 && Z <= 15))
      printf("                     ВЫХОД                     \n");
    else 
      printf("                    КОРИДОР                    \n");
    return 0;
  case 2:
    if ((I >= 1 && I <= 5) && (Z >= 1 && Z <= 5))
      printf("              ПУНКТ УПРАВЛЕНИЯ               \n"); 
    else if ((I >= 7 && I <= 12) && (Z >= 8 && Z <= 12))
      printf("                 ЛАБОРАТОРИЯ                 \n");
    else if ((I >= 14 && I <= 15) && (Z >= 7 && Z <= 12))
      printf("                  ХРАНИЛИЩЕ                  \n");
    else if ((I >= 16 && I <= 20) && (Z >= 17 && Z <= 20))
      printf("            ЦЕНТР БЕЗОПАСНОСТИ              \n");
    else if ((I >= 9 && I <= 14) && (Z >= 17 && Z <= 20))
      printf("                  СТОЛОВАЯ                   \n");
    else 
      printf("                    КОРИДОР                    \n");
    return 0;
 case 3:
    if ((I >= 4 && I <= 6) && (Z >= 4 && Z <= 20))
      printf("                  БИБЛИОТЕКА                  \n"); 
    else if ((I >= 8 && I <= 13) && (Z >= 9 && Z <= 15))
      printf("                    ФОНТАН                    \n"); 
    else if ((I >= 10 && I <= 16) && (Z >= 17 && Z <= 23))
      printf("                 ОБСЕРВАТОРИЯ                 \n"); 
    else if ((I >= 15 && I <= 16) && (Z >= 10 && Z <= 15))
      printf("          КАМЕРА ЗАКЛЮЧЕННЫХ №4              \n"); 
    else if ((I >= 17 && I <= 19) && (Z >= 4 && Z <= 8))
      printf("          КАМЕРА ЗАКЛЮЧЕННЫХ №1              \n");
    else if ((I >= 19 && I <= 20) && (Z >= 11 && Z <= 15)) 
      printf("          КАМЕРА ЗАКЛЮЧЕННЫХ №2              \n");
    else if ((I >= 19 && I <= 20 ) && (Z >= 17 && Z <= 20))
      printf("          КАМЕРА ЗАКЛЮЧЕННЫХ №3              \n");
    else 
      printf("                    КОРИДОР                    \n");
    return 0; 
  }
}
      