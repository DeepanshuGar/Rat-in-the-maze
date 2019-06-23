#include <iostream>
using namespace std;

bool RatInMaze(char maze[1000][1000],int sol[][1000],int i,int j,int m,int n)
{
    if(m==i && j==n)
    {
        sol[m][n] = 1;
        //print matrix
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true; 
    }
    if(i>m || j>n)
    {
        return false;
    }
    if(maze[i][j]=='X')
    {
        return false;
    }
    //assume sol exixt in particular cell
    sol[i][j] = 1;
    bool rightSuccess = RatInMaze(maze,sol,i,j+1,m,n);
    bool downSuccess = RatInMaze(maze,sol,i+1,j,m,n);
    
    sol[i][j] = 0;
    if(rightSuccess==true || downSuccess==true)
    {
        return true;
    }
    return false;
}

int main()
{
    int m,n;
    cin>>m>>n;
    
    char maze[1000][1000];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }
    int sol[1000][1000] = {0};
    
    
    RatInMaze(maze,sol,0,0,m-1,n-1);
    return 0;
}

