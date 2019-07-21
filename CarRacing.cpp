#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 30;
const int height = 30;
int carx, cary;
//int blockx = 0, blocky = 0;
int numberOfBlocks;
int nblocks = 0;
int blocksX[100], blocksY[100];
enum carDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
carDirecton dir;
int score = 0;
void Setup()
{
    gameOver = false;
    dir = STOP;
    carx = 28;
    cary = 13;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < width+2; i++)
        cout << "_";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width+1; j++)
        {
            if (j == 0)
                cout << "|";
            else if (j%10 == 0)
                cout << "|";
            else if(carx == i && cary == j){
                cout<<"-|O|-";
                j+=4;
            }
            else{
                for(int k=0;k<100;k++){
                    if(blocksX[k] == i && blocksY[k] == j){
                        cout<<"-|X|-";
                        j+=5;
                    }
                }
                cout<<" ";
            }
        }
        cout<<endl;

    }
    for (int i = 0; i < width+2; i++)
        cout << "_";

    cout<<"\nScore is :"<<score;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            cary -= 10;
            if(cary < 0)
            cary = 3;
            break;
        case 'd':
            cary += 10;
            if(cary > 30)
            cary = 23;
            break;
        case 'w':
            carx -= 2;
            break;
        case 's':
            carx += 2;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Block(){
    if(nblocks == 97){
        nblocks = 0;
    }

    numberOfBlocks = rand() % 3;

    if(numberOfBlocks == 1){
        int blockPosition = rand() % 3;
        if(blockPosition == 0){
            blocksX[nblocks] = 2;
            blocksY[nblocks] = 3;

        }
        else if(blockPosition == 1){
            blocksX[nblocks] = 2;
            blocksY[nblocks] = 13;

        }
        else{
            blocksX[nblocks] = 2;
            blocksY[nblocks] = 23;

        }
        nblocks++;
    }

    if(numberOfBlocks == 2){
        int blockPosition = rand() % 3;
        if(blockPosition == 1){
            blocksX[nblocks] = 0;
            blocksY[nblocks] = 3;
            nblocks++;
            blocksX[nblocks] = 0;
            blocksY[nblocks] = 13;

        }
        else if(blockPosition == 2){
            blocksX[nblocks] = 0;
            blocksY[nblocks] = 13;
            nblocks++;
            blocksX[nblocks] = 0;
            blocksY[nblocks] = 33;
            nblocks++;

        }
        else{
            blocksX[nblocks] = 0;
            blocksY[nblocks] = 13;
            nblocks++;
            blocksX[nblocks] = 0;
            blocksY[nblocks] = 23;
            nblocks++;

        }

    }

    for(int i=0;i<nblocks;i++){
        blocksX[i]+= 2;
    }
}

void MoveBlock(){
    for(int i=0;i<nblocks;i++){
        blocksX[i]+= 2;
    }
}

void Logic(){
    for(int i=0;i<nblocks;i++){
        if(blocksX[i] == carx && blocksY[i] == cary){
            gameOver = true;
        }
    }
    score += 1;
}
int main()
{
    Setup();
    int BlockRespawnTimer = 0;
    int MoveBlockTimer = 0;
    while (!gameOver)
    {
        Draw();
        Input();
        Sleep(100); //sleep(10);

        if(BlockRespawnTimer == 1000){
            Block();
            BlockRespawnTimer = 0;
        }
        if(MoveBlockTimer == 500){
            MoveBlock();
            MoveBlockTimer = 0;
        }
        BlockRespawnTimer += 100;
        MoveBlockTimer += 100;
        Logic();
    }
    cout<<"\nGAME OVER!! \n Score is : "<<score;
    return 0;
}
