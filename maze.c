#include <stdio.h>
#include "maze.h"
//使用递归的方式来求解迷宫问题
void Mark(Maze* m,Point cur)
{
    //走过的地方标记为2
    m->maze[cur.x][cur.y]=2;

}
int Exit(Maze* m,Point pt,Point entry)
{
    (void)m;
    //1当前点是不是入口，若为入口，就不是出口
    if(pt.x==entry.x&&pt.y==entry.y)
    {
        return 0;
    }
    //2.如果当前点在边界上，就是出口
    if(pt.x==0||pt.y==0||pt.x== ROW-1||pt.y==COL-1)
    {
        return 1;
    }
    return 0;
}
int CanStay(Maze* m,Point pt)
{
    //判断pt该点是否能落脚
    //若该点在地图外，则不能落脚
    if(pt.x<0||pt.x>=ROW||pt.y<0||pt.y>=COL)
    {
        return 0;
    }
    //若该点在地图内，位置为1，就能落脚，为0或2都不能落脚
    int value=m->maze[pt.x][pt.y];
    if(value==1)
    {
        return 1;
    }
    return 0;
}


void _GetPath(Maze* m,Point entry,Point cur)
{
    printf("cur:(%d,%d)\n",cur.x,cur.y);
    //每次走到下一个点，都要调用此函数
    //1.判断当前点能否能落脚
    if(!CanStay(m,cur))
    {
        return;
    }
    //2.若能落脚，给当前位置坐标记
    Mark(m,cur);
    //3.若当前点为出口，说明找到了一条出路，探测就结束
    if(Exit(m,cur,entry))
    {
        printf("找到了一条出路\n");
        return;
    }
    //4。若当前点不是出口，按顺时针顺序探测四个方向的相邻点
    
    Point up=cur;
    up.x-=1;
    _GetPath(m,entry,up);

    Point right=cur;
    right.y+=1;
    _GetPath(m,entry,right);

    Point down=cur;
    down.x+=1;
    _GetPath(m,entry,down);

    Point left=cur;
    left.y-=1;
    _GetPath(m,entry,left);
}

void GetPath(Maze* m,Point entry)
{
    if(m==NULL)
    {
        return;
    }
    _GetPath(m,entry,entry);
}
void MazeInit(Maze* m)
{
    if(m==NULL)
    {
        return;
    }
    int arr[ROW][COL]={
        {0,0,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,1,1,1,0},
        {0,0,1,0,1,1},
        {0,0,0,0,0,0}
    };
    int i=0;
    int j=0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            m->maze[i][j]=arr[i][j];
        }
    }
}
void MazePrint(Maze* m)
{
    if(m==NULL)
    {
        return;
    }
    int i=0;
    int j=0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            printf("%lu ",m->maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    Maze maze;
    MazeInit(&maze);
    MazePrint(&maze);
    Point entry={0,2};
    GetPath(&maze,entry);
    MazePrint(&maze);
}
