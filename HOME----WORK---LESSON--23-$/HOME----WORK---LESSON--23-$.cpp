#include <iostream>
#include <conio.h> 

using namespace std;

const unsigned int Number = 8;
int chess[Number][Number];
int move_x[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int move_y[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Function

void SonsuzDovr() {
    char trueFalse;
    while (true) {
        trueFalse = _getch();

        if (trueFalse >= '0' && trueFalse <= '9') {
            _putch(' ');
        }
        else {
            _putch(trueFalse);
        }
    }
}

void bigSmall()
{
    char BigSmall;
    while (true)
    {
        BigSmall = _getch();


        if (BigSmall >= 'A' && BigSmall <= 'Z') 
        {
            _putch(BigSmall - 'A' + 'a');
        }

        else if (BigSmall >= 'a' && BigSmall <= 'z') 
        {
            _putch(BigSmall - 'a' + 'A');
        }

        else 
        {
            _putch(BigSmall);
        }
    }
}

bool chess_board(int x, int y)
{
    return (x >= 0 && x < Number && y >= 0 && y < Number && chess[x][y] == -1);
}


bool solveKTUtil(int x, int y, int N)
{
    if (N == Number * Number)
    {
        return true; 
    }

    for (int k = 0; k < 8; k++)
    {
        int new_x = x + move_x[k];
        int new_y = y + move_y[k];
        if (chess_board(new_x, new_y))
        {
            chess[new_x][new_y] = N;
            if (solveKTUtil(new_x, new_y, N + 1))
            {
                return true;
            }
            chess[new_x][new_y] = -1;
        }
    }
    return false;
}
 
void printSolution()
{
    for (int i = 0; i < Number; i++)
    {
        for (int j = 0; j < Number; j++)
        {
            cout << chess[i][j] << "\t";
        }
        cout << endl;
    }
}


void solveKT(int start_x, int start_y)
{
    for (int i = 0; i < Number; i++)
    {
        for (int j = 0; j < Number; j++)
        {
            chess[i][j] = -1;
        }
    }

    chess[start_x][start_y] = 0; 
    if (solveKTUtil(start_x, start_y, 1))
    {
        printSolution();
    }
    else
    {
        cout << "Çözüm tapılmadı! At bütün xanalardan keçə bilmədi." << endl;
    }
}


int main()
{
    cout << "=======================================";
    cout << "\n\n";
    cout << "Tap - 1";
    cout << "\n\n\n\n";

    //cout << "Enter number or letter : ";
    //SonsuzDovr();


    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "=======================================";
    cout << "\n\n";
    cout << "Tap - 2";
    cout << "\n\n\n\n";

    //cout << "Enter letter : ";
    //bigSmall();

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "=======================================";
    cout << "\n\n";
    cout << "Tap - 3";
    cout << "\n\n\n\n";

    int X_1, Y_1;

    cout << "Başlanğıc koordinatlarını daxil edin (x y): ";
    cin >> X_1 >> Y_1;

    if (X_1 < 0 || X_1 >= Number || Y_1 < 0 || Y_1 >= Number) {
        cout << "Səhv koordinatlar! Koordinatlar 0 ilə 7 arasında olmalıdır." << endl;
        return 1;
    }

    solveKT(X_1, Y_1);

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "=======================================";
}