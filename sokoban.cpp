//author -> Amirreza Eskandarani
//project date is for 2020/06/06
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    //getting map coordinates
    int row, column;
    cout << "Enter number of rows:";
    cin >> row;
    cout << "Enter number of columns:";
    cin >> column;
    char room[row][column];
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++)
            if (i == 1 || j == 1 || i == row || j == column) {
                room[i][j] = '#';
            } else room[i][j] = '.';
    }
    //getting extra wall(s) coordinates
    int number_of_walls, n, m;
    cout << "Enter number of walls:";
    cin >> number_of_walls;
    for (int i = 1; i <= number_of_walls; ++i) {
        cout << "Enter row of wall:";
        cin >> n;
        cout << "Enter column of wall:";
        cin >> m;
        room[n][m] = '#';
    }
    //getting box(es) coordinates
    int number_of_boxes, b1, b2;
    cout << "Enter number of boxes:";
    cin >> number_of_boxes;
    for (int i = 1; i <= number_of_boxes; ++i) {
        cout << "Enter row of box:";
        cin >> b1;
        cout << "Enter column of box:";
        cin >> b2;
        room[b1][b2] = '@';
    }
    //getting destination coordinates
    int d1, d2;
    for (int i = 1; i <= number_of_boxes; ++i) {
        cout << "Enter row of destination:";
        cin >> d1;
        cout << "Enter column of destination:";
        cin >> d2;
        room[d1][d2] = 'T';
    }
    //getting sokoban coordinates
    int s1, s2;
    cout << "Enter row of sokoban:";
    cin >> s1;
    cout << "Enter column of sokoban:";
    cin >> s2;
    room[s1][s2] = 'S';
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= column; ++j)
            cout << room[i][j] << "  ";
        cout << "\n";
    }
    int counter = 0;
    while (true) {
        char k;
        cin >> k;
        //going up with using 'w' character
        if (k == 'w' && room[s1 - 1][s2] != '#') {
            if (room[s1 - 1][s2] == '.') {
                room[s1 - 1][s2] = 'S';
                room[s1][s2] = '.';
                s1--;
            } else if (room[s1 - 1][s2] == '@' && room[s1 - 2][s2] == 'T') {
                room[s1 - 1][s2] = 'S';
                room[s1 - 2][s2] = '@';
                room[s1][s2] = '.';
                counter++;
                s1--;
            } else if (room[s1 - 1][s2] == '@' && room[s1 - 2][s2] != '#' && room[s1 - 2][s2] != '@') {
                room[s1 - 1][s2] = 'S';
                room[s1 - 2][s2] = '@';
                room[s1][s2] = '.';
                s1--;
            }
        }
        //going down with using 's' character
        else if (k == 's' && room[s1 + 1][s2] != '#') {
            if (room[s1 + 1][s2] == '.') {
                room[s1 + 1][s2] = 'S';
                room[s1][s2] = '.';
                s1++;
            } else if (room[s1 + 1][s2] == '@' && room[s1 + 2][s2] == 'T') {
                room[s1 + 1][s2] = 'S';
                room[s1 + 2][s2] = '@';
                room[s1][s2] = '.';
                counter++;
                s1++;
            } else if (room[s1 + 1][s2] == '@' && room[s1 + 2][s2] != '#' && room[s1 + 2][s2] != '@') {
                room[s1 + 1][s2] = 'S';
                room[s1 + 2][s2] = '@';
                room[s1][s2] = '.';
                s1++;
            }
        }
        //going left with using 'a' character
        else if (k == 'a' && room[s1][s2 - 1] != '#') {

            if (room[s1][s2 - 1] == '.') {
                room[s1][s2 - 1] = 'S';
                room[s1][s2] = '.';
                s2--;
            } else if (room[s1][s2 - 1] == '@' && room[s1][s2 - 2] == 'T') {
                room[s1][s2 - 1] = 'S';
                room[s1][s2 - 2] = '@';
                room[s1][s2] = '.';
                counter++;
                s2--;
            } else if (room[s1][s2 - 1] == '@' && room[s1][s2 - 2] != '#' && room[s1][s2 - 2] != '@') {
                room[s1][s2 - 1] = 'S';
                room[s1][s2 - 2] = '@';
                room[s1][s2] = '.';
                s2--;
            }
        }
        //going right with using 'd' character
        else if (k == 'd' && room[s1][s2 + 1] != '#') {

            if (room[s1][s2 + 1] == '.') {
                room[s1][s2 + 1] = 'S';
                room[s1][s2] = '.';
                s2++;
            } else if (room[s1][s2 + 1] == '@' && room[s1][s2 + 2] == 'T') {
                room[s1][s2 + 1] = 'S';
                room[s1][s2 + 2] = '@';
                room[s1][s2] = '.';
                counter++;
                s2++;
            } else if (room[s1][s2 + 1] == '@' && room[s1][s2 + 2] != '#' && room[s1][s2 + 2] != '@') {
                room[s1][s2 + 1] = 'S';
                room[s1][s2 + 2] = '@';
                room[s1][s2] = '.';
                s2++;
            }
        }
        //checking if player wins
        if (counter == number_of_boxes) 
            break;
        
        //checking if player loses
        if (room[2][2] == '@') 
            break;
        
        if (room[row - 1][column - 1] == '@') 
            break;
        
        if (room[2][column - 1] == '@') 
            break;
        
        if (room[row - 1][2] == '@') 
            break;
        
		//when going up
		if(room[s1-3][s2]=='#' && room[s1-2][s2+1]=='#' && room[s1-2][s2]=='@'  )
			break;
		
		if(room[s1-3][s2]=='#' && room[s1-2][s2-1]=='#' && room[s1-2][s2]=='@'  )
			break;
		
		//when going down
		if(room[s1+3][s2]=='#' && room[s1+2][s2+1]=='#' && room[s1+2][s2]=='@'  )
			break;
		
		if(room[s1+3][s2]=='#' && room[s1+2][s2-1]=='#' && room[s1+2][s2]=='@' )
			break;
		
		//when going left
		if(room[s1][s2+3]=='#' && room[s1-1][s2+2]=='#' && room[s1][s2-2]=='@' )
			break;
		
		if(room[s1][s2+3]=='#' && room[s1+1][s2+2]=='#' && room[s1][s2-2]=='@' )
			break;
		
		//when going right
		if(room[s1][s2-3]=='#' && room[s1-1][s2-2]=='#' && room[s1][s2+2]=='@'  )
			break;
		
		if(room[s1][s2-3]=='#' && room[s1+1][s2-2]=='#' && room[s1][s2+2]=='@' )
			break;
		
		//checking if player loses

        //printing map after one move
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= column; ++j)
                cout << room[i][j] << "  ";
            cout << "\n";
        }
    }
    //printing map after player wins or loses
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= column; ++j)
            cout << room[i][j] << "  ";
        cout << "\n";
    }
    //player wins
    if (counter == number_of_boxes) {
        cout << "\n Congraglations you win!";
    }
        //player loses
    else {
        cout << "\n Game over!";
    }
    return 0;
}
