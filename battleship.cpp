#include <iostream>
#include <ctime>
using namespace std;
 
const int row = 10;
const int column = 10;
 
int ships = 10,cnt=0;

int field[row][column];
 
void Clear()
{
    for(int i=0; i < row; i++)
    {
        for(int j=0; j < column; j++)
        {
            field[i][j] = 0;
        }
    }
}
 
void Grid()
{
    for(int i=0; i < row; i++)
    {
        for(int j=0; j < column; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

void SetShips()
{
    int ship = 1;
    while(ship <= ships)
    {
        int x = rand() % row;
        int y = rand() % column;
        if(field[x][y] == 1)
            continue;
        ship++;
        field[x][y] = 1;
        
    }
}
 
bool Attack(int x,int y)
{
    if(field[x][y] == 1)
    {
        field[x][y] = -1;
        cnt--;
        return true;
    }
    return false;
}
 
int main()
{
    srand(time(NULL));
    Clear();
    SetShips();
    int a,b,count=0;
    cnt=ships;
    char prompt;
    while((count<65)&&(cnt>0))
    {
        cout << "Please input location(In x-y coordinates): "; 
        cin >> a >> b;
        count++;
        if(Attack(a,b))
           { 
               cout << "Target down. Good job!" << endl; 
               cout << "Number of ships left: " << cnt << endl;
               continue;
           }
        else
             cout << "Target missed!!" << endl;
        cout << "Number of ships left: " << cnt << endl; 
        cout << "Do you accept defeat (y/n)?"; 
        cin >> prompt;
        if(prompt == 'y')
             break;
    }
    
         
    Grid();
    if(cnt==0)
     {
         cout<<"The Battle has been won. But the war is still going on."<<endl;
         cout<<"Do you wish to help us?(y/n)"<<endl;
         cin>>prompt;
         if(prompt == 'y')
            main();
         else
            cout<<"So long, Partner."<<endl; 
     }
     else
         cout << " Game over! " << endl; 
    system("pause");
    return 0;
}