/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

/*
 * Structs as Parameters:
 * You can pass structs by both copying (direct passing) and also by reference
 * with pointers.
 *
*/

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;

// struct to contain the position of a tile. E.G. tile 4 in a starting 3x3
// matrix will have position row: 1 column: 1
typedef struct position {
    int row;
    int column;
} position;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);
bool find(int tile, position* pos);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
	for(int row = 0, start = (d*d - 1); row < d; row++)
	{
		for(int column = 0; column < d; column++)
		{
			if(start == 0)
				start = '_'; // a char, which can also be interpreted as an int

			board[row][column] = start;
			start--;
		}
	}

    // check whether there are an odd number of tiles (e.g. 4x4 board)
    if(d%2 == 0)
    {
        // switch tiles
        board[d-1][d-3] = 1;
        board[d-1][d-2] = 2;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
	for(int row = 0; row < d; row++)
	{
		for(int column = 0; column < d; column++)
		{
			if(board[row][column] == '_')
				printf("%2c  ", board[row][column]); // print char
			else
				printf("%2i  ", board[row][column]); // print int
		}

		printf("\n\n");
	}
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    /**
     * There are two ways to do this: either (1) create a global
     * variable that remembers the blank space, or (2) check around
     * the tile you want to move to see if the blank space is accessible
     */

/*****************use the find() function and struct position****************

    position pos;

    if(!find(tile, &pos))
        return false;

    // find blank & make sure blank space doesn't go out of the matrix
    // (sequence in && statment matters)
    if(pos.row + 1 < d && board[pos.row + 1][pos.column] == '_')
    {
        board[pos.row + 1][pos.column] = board[pos.row][pos.column];
        board[pos.row][pos.column] = '_';
        return true;
    }
    else if(pos.row - 1 >= 0 && board[pos.row - 1][pos.column] == '_')
    {
        board[pos.row - 1][pos.column] = board[pos.row][pos.column];
        board[pos.row][pos.column] = '_';
        return true;
    }
    else if(pos.column + 1 < d && board[pos.row][pos.column + 1] == '_')
    {
        board[pos.row][pos.column + 1] = board[pos.row][pos.column];
        board[pos.row][pos.column] = '_';
        return true;
    }
    else if(pos.column - 1 >= 0 && board[pos.row][pos.column - 1] == '_')
    {
        board[pos.row][pos.column - 1] = board[pos.row][pos.column];
        board[pos.row][pos.column] = '_';
        return true;
    }
    else
        return false;

******************************************************************************/

    // position of tile
    int row;
    int column;

    // find position of tile
    for(row = 0; row < d; row++)
    {
        for(column = 0; column < d; column++)
        {
            if(board[row][column] == tile)
                goto break_nested_loop;
        }
    }

    break_nested_loop:
    // find blank & make sure blank space doesn't go out of the matrix
    // (sequence in && statment matters)
    if(row + 1 < d && board[row + 1][column] == '_')
    {
        board[row + 1][column] = board[row][column];
        board[row][column] = '_';
        return true;
    }
    else if(row - 1 >= 0 && board[row - 1][column] == '_')
    {
        board[row - 1][column] = board[row][column];
        board[row][column] = '_';
        return true;
    }
    else if(column + 1 < d && board[row][column + 1] == '_')
    {
        board[row][column + 1] = board[row][column];
        board[row][column] = '_';
        return true;
    }
    else if(column - 1 >= 0 && board[row][column - 1] == '_')
    {
        board[row][column - 1] = board[row][column];
        board[row][column] = '_';
        return true;
    }
    else
        return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int counter = 1;

    for(int row = 0; row < d; row++)
    {
        for(int column = 0; column < d; column++)
        {
            if(column == d-1 && row == d-1)
            {
                if(board[row][column] != '_')
                    return false;
            }
            else if(board[row][column] != counter)
                return false;

            counter++;
        }
    }

    return true;
}

/**
 * Find the position of the tile and store it in a struct. Return true
 * if found, false if not.
 */
bool find(int tile, position* pos)
{
    for(int row = 0; row < d; row++)
    {
        for(int column = 0; column < d; column++)
        {
            if(tile == board[row][column])
            {
                // You have a pointer, which is its own 4 bytes of memory. The
                // arrow means dereference pointer to struct, then access element.
                // It is shorthand for (pos*).row
                (*pos).row = row;
                pos->column = column;
                return true;
            }
        }
    }
    return false;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
