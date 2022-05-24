#include <iostream>

void begin();
int input(char player, char array[]);
void printarr(char array[]);
bool iswon(char array[]);

int main(){
    begin();
    char array[9];
    for (size_t i = 0; i < (sizeof(array) * sizeof(char)); i++)
    {
        array[i] = ' ';
    }

    char player;
    int pos;
    do
    {
        player = 'X';
        pos = input(player, array);
        array[pos] = player;
        printarr(array);
        if (iswon(array) == true)
        {
            exit(1);
        }
        
        for (size_t i = 0; i < 1; i++)
        {
            player = 'O';
            pos = input(player, array);
            array[pos] = player;
            printarr(array);
            if(iswon(array) == true)
                exit(1);
        }
        
    } while (true);
    

    
}

void begin(){
    std::cout << "############ Welcome to TIC TAC TOE #############" << std::endl; 
    std::cout << "######## Player one: X  -  Player two: O ########" << std::endl;
    int count = 0;
    do
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << "    |    |    " << std::endl;
        }
        if (count == 2)
        {
            break;
        }
        
        std::cout << "--------------" << std::endl;
        count++;
    } while (count < 3);
}

int input(char player, char array[]){
    int pos = 0;

    do
    {
        std::cout << "Player " << player << " choose 1-9" << std::endl;
        std::cin >> pos;
    } while (pos < 1 || pos > 9);

    return pos - 1;
}

void printarr(char array[]){
    system("clear");
    int count = 0, c = 0;
    do
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (j == 1)
            {
                std::cout << " " << array[c] << "  | " << array[c+1] << "  |  " << array[c+2] << std::endl;
                c += 3;
            } else {
                std::cout << "    |    |    " << std::endl;
            }
        }
        if (count == 2)
        {
            break;
        }
        
        std::cout << "--------------" << std::endl;
        count++;
    } while (count < 3);
}

bool iswon(char array[]){
    if ((array[0] == 'X' && array[1] == 'X' && array[2] == 'X') || (array[0] == 'O' && array[1] == 'O' && array[2] == 'O'))
        return true;
    if ((array[3] == 'X' && array[4] == 'X' && array[5] == 'X') || (array[3] == 'O' && array[4] == 'O' && array[5] == 'O'))
        return true;
    if ((array[6] == 'X' && array[7] == 'X' && array[8] == 'X') || (array[6] == 'O' && array[7] == 'O' && array[8] == 'O'))
        return true;

    if ((array[0] == 'X' && array[3] == 'X' && array[6] == 'X') || (array[0] == 'O' && array[3] == 'O' && array[6] == 'O'))
        return true;
    if ((array[1] == 'X' && array[4] == 'X' && array[7] == 'X') || (array[1] == 'O' && array[4] == 'O' && array[7] == 'O'))
        return true;
    if ((array[2] == 'X' && array[5] == 'X' && array[8] == 'X') || (array[2] == 'O' && array[5] == 'O' && array[8] == 'O'))
        return true;

    if ((array[0] == 'X' && array[4] == 'X' && array[8] == 'X') || (array[0] == 'O' && array[4] == 'O' && array[8] == 'O'))
        return true;
    if ((array[2] == 'X' && array[4] == 'X' && array[6] == 'X') || (array[2] == 'O' && array[4] == 'O' && array[6] == 'O'))
        return true;
    return false;
}