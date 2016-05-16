//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400
#define PADDLE_HEIGHT 15
#define PADDLE_WIDTH 60
#define PADDLE_PADDING 50
#define BRICK_WIDTH ((WIDTH/10) - 5)

// width of brick plus padding (for space) plus an initial differential to space from wall
#define BRICK_X_POSITION (BRICK_WIDTH + 4.5) + 5

// height of brick plus padding (for space) plus an initial differential to space from ceiling
#define BRICK_Y_POSITION (PADDLE_HEIGHT + 5) + 20
#define BALL_SIZE 20

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);
void centerLabel(GWindow window, GLabel label);
double randomSpeed(void);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // vertical velocity
    double y_velocity = 2.0;

    // horizontal velocity
    double x_velocity = randomSpeed();

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        GEvent event = getNextEvent(MOUSE_EVENT);

        // check for mouse movements
        if(event != NULL)
        {
            if(getEventType(event) == MOUSE_MOVED)
            {
                double x = getX(event) - getWidth(paddle)/2;
                double y = getY(paddle);
                setLocation(paddle, x, y);
            }
        }

        // move the ball
        move(ball, x_velocity, y_velocity);

        // check if ball hit the right side of the screen
        if(getX(ball) + getWidth(ball) >= getWidth(window))
        {
            x_velocity = -x_velocity;
        }

        // if ball hits left side bounce
        if(getX(ball) <= 0)
        {
            x_velocity = -x_velocity;
        }

        // if ball hits top of window, bounce
        if(getY(ball) <= 0)
        {
            y_velocity = -y_velocity;
        }

        // if ball hits the bottom window
        if(getY(ball) >= getHeight(window))
        {
            // decrement lives
            lives--;

            // place the ball
            setLocation(ball, (WIDTH + BALL_SIZE)/2, (HEIGHT + BALL_SIZE)/2);

            x_velocity = randomSpeed();

            // wait for click
            waitForClick();
        }

        // pause so we can actually see stuff
        pause(10);

        GObject collision = detectCollision(window, ball);

        if (collision != NULL)
        {
            // if ball hits paddle, bounce
            if (collision == paddle || (strcmp(getType(collision), "GRect") == 0))
            {
                y_velocity = -y_velocity;
            }

            // if collision with a brick (not paddle), then remove
            if(collision != paddle && (strcmp(getType(collision), "GRect") == 0))
            {
                // increment points
                points++;

                // decrement bricks
                bricks--;

                // update scoreboard
                updateScoreboard(window, label, points);

                // remove tile
                removeGWindow(window, collision);
            }
        }
    }

    if(bricks == 0)
    {
        setLabel(label, "You win!");
        centerLabel(window, label);
    }
     else
    {
        setLabel(label, "You lose!");
        centerLabel(window, label);
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/*
 * Randomize Speed
 */
double randomSpeed(void)
{
    // seed random int generator
    srand48((long int) time(NULL));

    // randomized horizontal velocity
    double x_velocity = 5.0 * drand48();

    return x_velocity;
}

/*
 * Center label
 */
void centerLabel(GWindow window, GLabel label)
{
    // set location of label
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // color array
    char* array[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE"};

    for(int l = 0; l < ROWS; l++)
    {
        for(int h = 0; h < COLS; h++)
        {
            // place tiles
            GRect tile = newGRect(h * BRICK_X_POSITION, l * BRICK_Y_POSITION, BRICK_WIDTH, PADDLE_HEIGHT);

            // rainbow color
            setColor(tile, array[l]);
            setFilled(tile, true);

            // add to window
            add(window, tile);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // instantiate a new ball
    GOval ball = newGOval((WIDTH + BALL_SIZE)/2, (HEIGHT + BALL_SIZE)/2, BALL_SIZE, BALL_SIZE);

    // set color to black
    setColor(ball, "BLACK");

    // fill it
    setFilled(ball, true);

    // add ball to window
    add(window, ball);

    // return it
    return ball;

}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // create a new paddle
    GRect paddle = newGRect((WIDTH - PADDLE_WIDTH)/2, HEIGHT - PADDLE_PADDING, PADDLE_WIDTH, PADDLE_HEIGHT);

    // set color
    setColor(paddle, "BLACK");

    // fill in color
    setFilled(paddle, true);

    // add to window
    add(window, paddle);

    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel score = newGLabel("0");

    add(window, score);

    // set location of label
    double x = (getWidth(window) - getWidth(score)) / 2;
    double y = (getHeight(window) - getHeight(score)) / 2;
    setLocation(score, x, y);

    // set font
    setFont(score, "SanSerif-30");

    setColor(score, "LIGHT_GRAY");

    return score;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
