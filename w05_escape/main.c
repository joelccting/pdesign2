#include <stdio.h>
#include <stdbool.h>

//#define DEBUG

#ifdef DEBUG
#define dbg(fmt, ...) printf("[%d] " fmt, __LINE__, ##__VA_ARGS__)
#else
#define dbg(fmt, ...)
#endif

#define SZ (100)

int yMax, xMax, startX, startY;
int tgtX, tgtY;
char map[SZ][SZ];
void print(char map[SZ][SZ], int xMax, int yMax);

bool hasRoad(int x, int y)
{
    if ((0 <= x && x < xMax) && (0 <= y && y < yMax) && (map[x][y] == '.'))
    {
        return true;
    }

    return false;
}

bool result = false;

// The direction for move are: up (x-1, y),
// down (x+1, y), left (x, y-1), and right (x, y+1).
bool maze(int x, int y, int xdes, int ydes)
{
#ifdef DEBUG
    print(map, xMax, yMax);
#endif

    if (x == xdes && y == ydes)
    {
        dbg("Reach!\n");
        result = true;
        return true;
    }
    map[x][y] = 'V';
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (hasRoad(nextX, nextY))
        {
            if (maze(nextX, nextY, xdes, ydes))
            {
                return true;
            }
        }
    }

    return false;
}

void print(char map[SZ][SZ], int xMax, int yMax)
{
    dbg("Print the map:\n");
    for (int i = 0; i < xMax; ++i)
    {
        for (int j = 0; j < yMax; ++j)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

// The origin (0,0) is at the top left corner,
// with x increasing downwards and y increasing to the right.
// The coordinate can be viewed as map[x][y].

int main()
{
    if (2 != scanf("%d %d", &xMax, &yMax))
        return 0;
    scanf("%*[\r\n]");
    scanf("%d %d %d %d", &startX, &startY, &tgtX, &tgtY);
    for (int i = 0; i < xMax; ++i)
    {
        // scanf("%*[\r\n]");
        for (int j = 0; j < yMax; ++j)
        {
            scanf(" %c", &map[i][j]);
        }
    }

#ifdef DEBUG
    print(map, xMax, yMax);
#endif

    // Special case: check if start is already destination
    if (startX == tgtX && startY == tgtY)
    {
        printf("YES");
        return 0;
    }

    if (hasRoad(startX, startY))
    {
        maze(startX, startY, tgtX, tgtY);
    }

    if (result)
        printf("YES");
    else
        printf("NO");

    return 0;
}