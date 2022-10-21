/**
 * CSC A48 - Intro to Computer Science II, Summer 2020
 * 
 * This is the program file where you will implement your solution for
 * assignment 1. Please make sure you read through this file carefully
 * and that you understand what is provided and what you need to complete.
 * 
 * You will need to have read the handout carefully. Parts where you have to 
 * implement functionality are clearly labeled TODO.
 * 
 * Be sure to test your work thoroughly, our testing will be extensive and will
 * check that your solution is *correct*, not only that it provides 
 * functionality.
 * 
 * Developed by Mustafa Quraish for CSCA48
 * (c) Mustafa Quraish 2020
 */
#include "imgUtils.c"

// This lets the driver code override the image size if it needs to. Make sure 
// you don't hard-code these values anywhere!
#ifndef SIZEX
  #define SIZEX 512
  #define SIZEY 512
#endif 

/*---------------------------------------------------------------------------*/

/**
 * This struct contains one node of the linked list, which represents a single 
 * command to the Turtle. It's field should include:
 * 
 *  - cmd   : A char array of size 10 holding the command name
 * 
 *  - val   : An integer that stores a parameter for the command (like forward,
 *            backward and colour). 
 * 
 *  - next  : A pointer to a struct of the same type, this is used for the 
 *            linked list
 * 
 * TODO: Complete this struct definition
 ****/

typedef struct cmdnode {
    char cmd[10];
    int val;
    struct cmdnode *next;
    struct cmdnode *loop_head;
    
} CmdNode;

/*---------------------------------------------------------------------------*/

void insertCommandLoop(CmdNode *loop_node, CmdNode *new_CmdNode ){
/**
 Add a function called insertCommandLoop(). This function will be used to insert
    a command at the end of the linked list for a 'loop' node. It will take in 2
     parameters, the first will be a pointer to the loop node, and the second will
     be a pointer to the new command node that you have to insert into the loop.
     This function should not return anything, but just update the linked list at
     the loop node.
 */
    
    CmdNode *temp = NULL;
    
    if(loop_node == NULL)
    {
        return;
    }
    else{
        if (loop_node->loop_head == NULL)
        {
            loop_node->loop_head = new_CmdNode;
            return;
        }
        temp = loop_node->loop_head;
        while ( temp->next != NULL)
        {
            temp  = temp -> next;
        }
        temp->next = new_CmdNode;
    }
    
    return;
}


/*---------------------------------------------------------------------------*/

CmdNode *newCmdNode(char cmd[10], int val) {
  /** 
   * This function allocates a new CmdNode struct and initializes it's values 
   * based on the input paramaters given. The next pointer is always 
   * initialized to NULL.
   * 
   * If the 'cmd' parameter is not a correct command, then print
   * "Invalid command.\n" and return NULL.
   * 
   * Note that we will always pass in a value here, even if the 
   * command doesn't need one. In this case, we can just ignore 
   * it. It saves us from having to make separate functions to 
   * deal with this.
   * 
   * TODO: Implement this function
   */
    if((strcmp(cmd, "penup") == 0) || (strcmp(cmd, "pendown") == 0) || (strcmp(cmd, "colour") == 0) || (strcmp(cmd, "forward") == 0) || (strcmp(cmd, "backward") == 0) || (strcmp(cmd, "left") == 0) || (strcmp(cmd, "loop") == 0) || (strcmp(cmd, "right") == 0))
    {
        
        CmdNode *new_node = (CmdNode *) calloc(1, sizeof(CmdNode));
        strcpy(new_node -> cmd, cmd);
        new_node -> val = val;
        new_node -> next = NULL;
        new_node -> loop_head = NULL;
        return new_node;
    }
    else
    {
        printf(" Invaild Command\n");
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

void printCommandList(CmdNode *head) {
  /**
   * This function prints out each command in the linked list one after the 
   * other. Each command MUST also have a line number printed before it, this 
   * is what you will be using to modify / delete them. To do this, initialize 
   * a counter and then increment it for each command.
   * 
   * Depending on whether or not the command needs an additional value 
   * (like forward, backward and colour), use one of the following statements 
   * to print out the information for each node: 
   *            [ The format is "linenumber: command value" ]
   * 
   * printf("%3d: %s %d\n", ... );     [With a value]
   * 
   * printf("%3d: %s\n", ... );        [Without a value]
   * 
   * Obviously, you also need to pass in the correct parameters to the print 
   * function yourself, this is just so you have the correct format.
   * 
   * TODO: Implement this function
   */
    
    int counter = 0;
    CmdNode *temp = NULL;
    temp = head;
    CmdNode *temp2 = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp -> cmd, "forward") == 0 || strcmp(temp -> cmd, "backward") == 0 || strcmp(temp -> cmd, "colour") == 0)
        {
            printf("%3d: %s %d\n", counter, temp -> cmd, temp -> val);
        }
        else if (strcmp(temp -> cmd, "loop") == 0)
        {
            printf("%3d: loop %d\n",counter, temp -> val);
            counter++;
            temp2 = temp -> loop_head;
            while(temp2 != NULL)
            {
                if(temp2 -> val == 0)
                {
                    printf("%3d:  %s\n",counter,temp2 ->cmd);
                }
                else
                {
                    printf("%3d:  %s %d\n",counter,temp2 ->cmd, temp2 -> val);
                }
                temp2 = temp2 -> next;
                counter++;
            }
        }
        else
        {
            printf("%3d: %s\n", counter, temp -> cmd);
        }
        temp = temp -> next;
        counter++;
    }
    return;
}

/*---------------------------------------------------------------------------*/

void queryByCommand(CmdNode *head, char cmd[10]) {
  /**
   * This function looks for commands in the linked list that match the input 
   * query. It prints them out in the same format as the printCommandList() 
   * function.
   * 
   * Make sure that the line number of the commands that match is the same as 
   * the line number that would be printed by the printCommandList() function.
   * 
   * --------------------------------------------------------------------------
   * 
   * For instance, if your printCommandList function outputs
   * 
   *    0: penup
   *    1: forward 200
   *    2: right
   *    3: forward 50
   * 
   * Then, if this function is called with the same list and cmd = "forward", 
   * then your output here should be
   * 
   *    1: forward 200
   *    3: forward 50
   * 
   * TODO: Implement this function
   */

    int counter = 0;
    CmdNode *temp = NULL;
    temp = head;
    CmdNode *temp2 = NULL;
    
    while (temp != NULL) {
        if (strcmp(temp -> cmd, cmd) == 0) {
            
            if (strcmp(temp -> cmd, "forward") == 0 || strcmp(temp -> cmd, "backward") == 0 || strcmp(temp -> cmd, "colour") == 0 || strcmp(temp -> cmd, "loop") == 0) {
                printf("%d: %s %d\n", counter, temp -> cmd, temp -> val);
            }
            
            else {
                printf("%d: %s\n", counter, temp -> cmd);
            }
        }
        counter++;
        if (strcmp(temp -> cmd, "loop") == 0) {
            temp2 = temp -> loop_head;
            
            while (temp2 != NULL) {
                if (strcmp(temp2 -> cmd, cmd) == 0) {
                    
                    if (strcmp(temp2 -> cmd, "forward") == 0 || strcmp(temp2 -> cmd, "backward") == 0 || strcmp(temp2 -> cmd, "colour") == 0) {
                        printf("%d: %s %d\n", counter, temp2 -> cmd, temp2 -> val);
                    }
                    
                    else {
                        printf("%d: %s\n", counter, temp2 -> cmd);
                    }
                }
                counter++;
                temp2 = temp2->next;
            }
        }
        temp=temp->next;
    }
    
    return;
}

/*---------------------------------------------------------------------------*/

int countCommands(CmdNode *head) {
    /**
     * This function counts and returns the length of the linked list. It
     * requires list traversal.
     *
     * TODO: Implement this function
     *     if (loop_node->loop_head == NULL)
     {
         loop_node->loop_head = new_CmdNode;
         return;
     }
     temp = loop_node->loop_head;
     while ( temp->next != NULL)
         {
             temp  = temp -> next;
         }
     temp->next = new_CmdNode;
     
     return;
 }
     */
    
    int counter = 0;
    CmdNode *temp = NULL;
    CmdNode *temp2 = NULL;
    temp = head;
    
    while(temp != NULL)
    {
        counter++;
        
        if (temp->loop_head != NULL) {
            temp2 = temp->loop_head;
            while (temp2 != NULL) {
                counter++;
                temp2 = temp2->next;
                
            }
        }
        temp = temp -> next;
    }
    
return counter;
}
/*---------------------------------------------------------------------------*/

CmdNode *insertCommand(CmdNode *head, CmdNode *new_CmdNode) {
  /**
   * This function inserts the node new_CmdNode *at the tail* of the linked 
   * list. (You are adding a command at the end).
   * 
   * If head == NULL, then the linked list is still empty.
   * 
   * It returns a pointer to the head of the linked list with the new node 
   * added into it.
   * 
   * TODO: Implement this function
   */
    CmdNode *temp = NULL;
    temp = head;
    if( head == NULL)
    {
        head = new_CmdNode;
    }
    else
    {
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = new_CmdNode;
        
    }
  return head;
}

/*---------------------------------------------------------------------------*/


CmdNode *deleteCommandList(CmdNode *head) {
  /**
   * This function deletes the linked list of commands, releasing all the 
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   * 
   * TODO: Implement this function
   */
    
    if (head == NULL) {
        return NULL;
    }
    
    CmdNode *pointer = NULL;
    CmdNode *trail = NULL;
    trail = head;
    pointer = head->next;
    
    CmdNode *pointer_loop = NULL;
    CmdNode *trail_loop = NULL;
    
    while (pointer != NULL)
    {
        if (strcmp(pointer->cmd, "loop") == 0) {
            trail_loop = pointer->loop_head;
            pointer_loop = pointer->loop_head->next;

            while (pointer_loop != NULL) {
                free(trail_loop);
                trail_loop = NULL;
                trail_loop = pointer_loop;
                pointer_loop = pointer_loop->next;
            }
        }

        free(trail);
        trail = NULL;
        trail = pointer;
        pointer = pointer->next;
    }
 
    return NULL;
}

/*---------------------------------------------------------------------------*/
// helper fxn

void changeDirection (int *ptr, char direction[10])// 0 for right (default), 1 for down, 2 for left, 3 for up
{
    if (*ptr == 0)
    {
        if (strcmp("left", direction) == 0)
        {
            *ptr = 3;
        }
        else if (strcmp("right", direction) == 0)
        {
            *ptr = 1;
        }
    }
    else if(*ptr == 1)
    {
        if (strcmp("left", direction) == 0)
        {
            *ptr = 0;
        }
        else if (strcmp("right", direction) == 0)
        {
            *ptr =2 ;
        }
    }
    else if(*ptr == 2)
    {
        if (strcmp("left", direction) == 0)
        {
            *ptr = 1;
        }
        else if (strcmp("right", direction) == 0)
        {
            *ptr =3 ;
        }
    }
    else if(*ptr == 3)
    {
        if (strcmp("left", direction) == 0)
        {
            *ptr = 2;
        }
        else if (strcmp("right", direction) == 0)
        {
            *ptr =0 ;
        }
    }
}

/*---------------------------------------------------------------------------*/
void main_run(Image *im, CmdNode *pointer, int *endX, int *endY, int *colour, int *pen, int *direction, int *initial_x, int *initial_y, int *final_x, int *final_y) {

    if (strcmp (pointer -> cmd, "colour") == 0) // check for colour of pen
    {
        if( pointer -> val > 255) // check if more than threshold
        {
            *colour = 255;
        }
        else if (pointer -> val < 0)// check if less than threshold
        {
            *colour = 0;
        }
        else
        {
            *colour = pointer -> val;
        }
    }
    else if (strcmp(pointer ->cmd, "pendown") == 0) // draw on
    {
        *pen = 0;
    }
    else if (strcmp(pointer -> cmd, "penup") == 0) // draw off
    {
        *pen = 1;
    }
    else if (strcmp ("right", pointer -> cmd) == 0)
    {
        changeDirection(direction, "right");
    }
    else if (strcmp ("left", pointer -> cmd) == 0)
    {
        changeDirection(direction, "left");
    }
    else if (strcmp("forward", pointer -> cmd) == 0)
    {
        if (*direction == 0) // right
        {
            {
                *final_x = *initial_x + (pointer -> val);
                if (*final_x > SIZEX-1)
                {
                    *final_x = SIZEX-1; //bound final x
                }
                else if (*final_x < 0)
                {
                    *final_x = 0;
                }
                if (*pen == 0)
                {
                    drawLine(im,*initial_x, *initial_y, *final_x, *final_y, *colour); //draw the line
                    
                }
            }
        }
        else if(*direction == 1) // down
        {
            {
                *final_y = *initial_y + (pointer -> val);
                if (*final_y > SIZEY - 1)
                {
                    *final_y = SIZEY - 1; //bound final y
                }
                else if (*final_y < 0)
                {
                    *final_y = 0;
                }
                if (*pen == 0)
                {
                    drawLine(im,*initial_x, *initial_y, *final_x, *final_y, *colour); //draw the line
                    
                }
                
            }
        }
        else if(*direction == 2) // LEFT
        {
            {
                *final_x = *initial_x - (pointer -> val);
                if (*final_x < 0)
                {
                    *final_x = 0; //bound final x
                }
                else if (*final_x > SIZEX - 1)
                {
                    *final_x = SIZEX - 1;
                }
                if (*pen == 0)
                {
                    drawLine(im,*initial_x, *initial_y, *final_x, *final_y, *colour); //draw the line
                    
                }
                
            }
        }
        else if(*direction == 3) // UP
        {
            {
                *final_y = *initial_y - (pointer -> val);
                if (*final_y < 0)
                {
                    *final_y = 0; //bound final y
                }
                else if (*final_y > SIZEY-1)
                {
                    *final_y = SIZEY-1;
                }
                if (*pen == 0)
                {
                    drawLine(im,*initial_x, *initial_y, *final_x, *final_y, *colour); //draw the line
                    
                }
                
            }
        }
    }
    else if (strcmp("backward", pointer -> cmd) == 0)
    {
        if (*direction == 0) // right
        {
            {
                *final_x = *initial_x - (pointer -> val);
                if (*final_x < 0)
                {
                    *final_x = 0; // bound to the edge of the screen
                }
                else if (*final_x > SIZEX-1)
                {
                    *final_x = SIZEX-1;
                }
                if (*pen == 0)
                {
                    drawLine(im,*initial_x, *initial_y, *final_x, *final_y, *colour); //draw the line
                    
                }
                
            }
        }
        else if(*direction == 1) // down
        {
            {
                *final_y = *initial_y - (pointer -> val);
                if (*final_y < 0)
                {
                    *final_y = 0; // bound to the edge of the screen
                }
                else if (*final_y > SIZEY-1)
                {
                    *final_y = SIZEY-1;
                }
                if (*pen == 0)
                {
                    drawLine(im,*initial_x, *initial_y, *final_x, *final_y, *colour); //draw the line
                    
                }
                
            }
        }
        else if(*direction == 2) // left
        {
            {
                *final_x = *initial_x + (pointer -> val);
                if (*final_x > SIZEX - 1)
                {
                    *final_x = SIZEX - 1; // bound to the edge of the screen
                }
                else if (*final_x < 0)
                {
                    *final_x = 0;
                }
                if (*pen == 0)
                {
                    drawLine(im,*initial_x, *initial_y, *final_x, *final_y, *colour); //draw the line
                    
                }
                
            }
        }
        else if(*direction == 3) // UP
        {
            {
                *final_y = *initial_y + (pointer -> val);
                if (*final_y > SIZEY - 1)
                {
                    *final_y = SIZEY - 1; // bound to the edge of the screen
                }
                else if (*final_y < 0)
                {
                    *final_y = 0;
                }
                if (*pen == 0)
                {
                    drawLine(im,*initial_x, *initial_y, *final_x, *final_y, *colour); //draw the line
                    
                }
                
            }
        }
    }
    
}
/*---------------------------------------------------------------------------*/


void run(Image *im, CmdNode *head, int *endX, int *endY) {
  /**
   * This function runs the list of commands to move the turtle around and draw 
   * the image, and returns the final position of the turtle in the variables 
   * endX and endY.
   * 
   * --------------------------------------------------------------------------
   * 
   * NOTE: In the image we work with, the top-left pixel is (0,0),
   *       - x increases as you go right, up till SIZEX-1
   *       - y increases as you go down, up till SIZEY-1
   * 
   *                 (0,0)                 (SIZEX-1, 0)
   *                   x------------------------x
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |          IMAGE         |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   |                        |
   *                   x------------------------x
   *             (0, SIZEY-1)            (SIZEX-1, SIZEY-1)
   * 
   * The image is in grayscale (black and white), so the colours are numbers 
   * from [0-255] where 0 is black, 255 is white, and the values in between 
   * are varying levels of gray.
   * 
   * You need to understand how the (x,y) values are stored so you know how 
   * they should be updated when you move (down means y increases, etc). You do 
   * not need to use the 'im' variable for anything other than passing it into 
   * the drawLine() function described below.
   * 
   * --------------------------------------------------------------------------
   * 
   * Here's the setup - There is a turtle (with a pen) that walks along the 
   * image. When the pen is down (on the paper), it draws a line along the path 
   * that it walks on. (If you want to play around with this, consider looking 
   * at the `turtle` library in python!)
   * 
   * The turtle initially starts at pixel (0, 0) [at the top left], 
   * facing right (in the positive x direction). The pen starts off
   * as `down`, with the default colour being black (0).
   * 
   * You need to go through the linked list and 'run' the commands to keep 
   * track of the turtles position, and draw the appropriate lines. Here is 
   * what each command should do:
   * 
   *  - penup          : Put the pen up (stop drawing)
   *  - pendown        : Put the pen down (start / continue drawing)
   *  - colour <val>   : Draw lines in colour <val> from now on
   *  - forward <val>  : Move the turtle forward <val> steps (pixels) 
   *                     in the direction it is facing.
   *  - backward <val> : Same as above, except move backwards
   *  - right          : Turn the turtle to the right by 90 degrees
   *  - left           : Turn the turtle to the left by 90 degrees
   * 
   * NOTE: Make sure that you do *not* go outside the image. For this, set the 
   * maximum and minimum values of x and y to be 0 and SIZEX-1 / SIZEY-1 
   * respectively.
   * 
   * For instance, if the turtle is at (0,0) facing right, and your command is
   * `forward 100000`, it will only go forward till (SIZEX-1, 0), and end 
   * up at the rightmost pixel in that row.
   * 
   * IMPORTANT: Once you are done with all the commands, make sure you save the 
   * final (x,y) location of the turtle into the variables endX and endY.
   * 
   * --------------------------------------------------------------------------
   * 
   * We have already implemented a drawLine() function (in imgUtils.c) which 
   * you should use to actually draw the lines. It takes in the following:
   * 
   *      - a pointer to an image struct (use 'im')
   *      - (x,y) location of start point
   *      - (x,y) location of end point
   *      - a colour to draw the line in [0-255]
   *          
   * Note that this function only draws horizontal and vertical lines, so 
   * either the x values or the y values of both points must be the same. 
   * Both these points *must* also be within the image. 
   *          [ 0 <= x < SIZEX,  0 <= y < SIZEY ]
   * 
   * 
   * TODO: Implement this function
   */
    
    if (head == NULL)
    {
        return ;
    }
    
    int colour = 0;
    int pen = 0; // 0 for down (default) and 1 for up
    int direction = 0; // 0 for right (default), 1 for down, 2 for left, 3 for up
    int initial_x = 0;
    int initial_y = 0;
    int final_x = 0;
    int final_y = 0;
    CmdNode *pointer = NULL;
    pointer = head;
    CmdNode *loop_pointer = NULL;

    
    while (pointer != NULL)
    {
        main_run(im, pointer, endX, endY, &colour, &pen, &direction, &initial_x, &initial_y, &final_x, &final_y);
        
        if (strcmp(pointer->cmd, "loop") == 0) {

            for (int i = 1; i <= pointer->val; i++) {
                loop_pointer = pointer->loop_head;

                while (loop_pointer != NULL) {
                    main_run(im, loop_pointer, endX, endY, &colour, &pen, &direction, &initial_x, &initial_y, &final_x, &final_y);

                    initial_x = final_x;
                    initial_y = final_y;
                    loop_pointer = loop_pointer -> next;
                }
            }
        }

        initial_x = final_x;
        initial_y = final_y;
        pointer = pointer -> next;
    }
    *(endX) = final_x;
    *(endY) = final_y;
    return;
}

/*---------------------------------------------------------------------------*/
// All done!

