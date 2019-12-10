#include <stdio.h>
#include <iostream>

using namespace std;

// Our Constants
#define MIN_STORIES 1
#define MAX_STORIES 10

#define MIN_WINDOWS 1
#define MAX_WINDOWS 6

#define MIN_WIN_WIDTH 3
#define MAX_WIN_WIDTH 6

#define MIN_WIN_HEIGHT 3
#define MAX_WIN_HEIGHT 6

#define BASE_SPACE 2	// NOT USING
#define ROOF_SPACE 2	// NOT USING
#define SPACE 2

void getInput(string m, int* loc, int min, int max);
void printLeftSide(int size);
void printRightSide(int size);
void printWindowLines(int win_count, int width);
void fill();
void newLine();
void space();

int main()
{
    // Vars Declaration
    int input_stories, input_windows, input_win_width, input_win_height;
    int b_height, b_width;

    /*  Procedure: taking inputs from user ================================ */
        getInput("Number of stories?",  &input_stories,     MIN_STORIES,    MAX_STORIES);
        getInput("Number of windows?",  &input_windows,     MIN_WINDOWS,    MAX_WINDOWS);
        getInput("Width of window?",    &input_win_width,   MIN_WIN_WIDTH,  MAX_WIN_WIDTH);
        getInput("Height of window?",   &input_win_height,  MIN_WIN_HEIGHT, MAX_WIN_HEIGHT);
    /*  Ends ============================================================== */
        

    //  Building Height Calculation - getting number of rows
        b_height = (SPACE*2) + (input_stories * input_win_height) + (input_stories-1);
    //  Building Width Calculation - getting number of columns
        b_width  = (SPACE*2) + (input_windows * input_win_width) + (input_windows-1);        
        
        int row, col;
        
        //	Roof printing ========================
	        for( int i=0; i<SPACE; i++ ) {
				col = 0;
	            if( i == 0  ) {
	            	
	                while( col++ < b_width ) {
	                	fill();
					}
					
	            } else {
	            	
	            	fill();
	            	while( col++ < b_width-2) {
	            		space();
					}
	            	fill();
	            	
				}	newLine();
	            
	        }
        //	Ends =================================
        
			
		//	Printing Floors ======================
			row = 0;
			while( row++ < input_stories ) {
				//	Printing Single Floor + Windows =========
	        		
					printLeftSide(SPACE);	// Building left side
	        		printWindowLines(input_windows, input_win_width);	
			       	printRightSide(SPACE);  // Building Right side
				
					newLine();
					
					//	Windows inner part ===================
				        for(int i=0; i<input_win_height-2; i++ ) { 
				        	printLeftSide(SPACE);	
				        	for( int a=0; a<input_windows; a++ ) {
				        		
					        	for( int j=0; j<input_win_width; j++ ) {
					        		if( j==0 || j==input_win_width-1 )
					        			fill();
					       			else
					       				space();
								} 
								if(a!=input_windows-1) space();
								
							}	printRightSide(SPACE);
								newLine();
							
						}
					//	Ends ===================================
					
					printLeftSide(SPACE); // Building left side
					printWindowLines(input_windows, input_win_width);
				 	printRightSide(SPACE); // Building right side
				
					newLine();
					
					//	Creating gap between windows ==================
						if( row != input_stories ) {
							printLeftSide(SPACE); // Building left side
							col = 0;
							while(col++ < b_width-(SPACE*2)) {
								space();
							}
							printRightSide(SPACE); // Building right side
							newLine();	
						}
					//	Ends ======================================
						
				//	Ends ====================================
			}
		//	Ends =================================
			        
        //	Base Printing ========================
        for( int i=SPACE-1; i>=0; i-- ) {
        	col = 0;
            if( i == 0  ) {
                while( col++ < b_width ) {
                	fill();
				}
            } else {
            	fill();
            	while( col++ < b_width-2) {
            		printf(" ");
				}
            	fill();
			}
			newLine();
        }
        // Ends ==================================
        
        // cout << b_width << '\n';
        // cout << b_height << '\n';

    return 0;
}

void getInput(string m, int* loc, int min, int max) 
{ 
    int i = 0;
        do {
            if(i++!=0) {
                cout << "Out of range. Range " << min << " to " << max << "\n";
            }
            cout << m << " [" << min << " - " << max << "]: ";
            cin  >> *loc;
            cout << "\n";
        } while (*loc < min || *loc > max);
}

// Building Left Side
void printLeftSide(int size) {
	int col = 0;
	while (col < size) {
		if(col++ == 0) {
			fill();
		} else {
			space();
		}
	}
}
// Building Right Side
void printRightSide(int size) {
	int col = 0;
	while (col < size) {
		if(col++ == size-1) {
			fill();
		} else {
			space();
		}
	}
}
void printWindowLines(int win_count, int width) {
	
	for( int i=0; i<win_count; i++ ) {
			        	
		int col = 0;
		while(col++ < width) {
			fill();
		}
		if(i==win_count-1) {
			break;
		}	space();
		
	}
}
void fill() {
	printf("*");
}
void newLine() {
	printf("\n");
}
void space() {
	printf(" ");
}

  