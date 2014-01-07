// CrackingCodingChap_1.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;



//Question 1.6:
//
//Given an image represented by an NxN matrix, 
//where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
//

//The class for the question 1.6 
//Contains variables, contructors and membership function for the operation of solving the question
//Assume each pixel of the image is represented by a char

class chap1question6 {

	public:

		int N_rows;		
		int M_Columns;	
		char** originalImage;
		
		//the function to rotate the image
		void rotateImage(char** original) {
			
			// check if the image matrix is legal
			if(N_rows != M_Columns) {
				cout<<" # rows should be equal to # of columns"<<endl;
				return;
			}

			int beginIndex = 0 ;
			int endIndex = 0;
			
			for(int layer = 0 ; layer < M_Columns/2 ; layer++) {

				beginIndex = layer + 1;
				endIndex = M_Columns - beginIndex;

				//for each layer
				for(int j = beginIndex ; j <= endIndex ; j++) {

					char temp_Top = original[layer][j];
					// do swap
					original[layer][j] = original[N_rows - j-1][layer];
					original[N_rows - j-1][layer] = original[N_rows - layer-1][M_Columns-j -1];
					original[N_rows - layer-1][M_Columns-j -1] = original[j][M_Columns -1-layer];
					original[j][M_Columns - 1 - layer] = temp_Top;
					
				}

			}

		}

		//the constructor, initialize the original image
		chap1question6(int n_rows, int m_columns) {

			N_rows = n_rows;
			M_Columns = m_columns;
			originalImage = new char*[N_rows];
			
			for(int i = 0 ; i < N_rows ; i++) {

				originalImage[i] = new char[M_Columns];
			}

			//Assign initial value ('k') to each pixel
			for(int i = 0 ; i < N_rows ; i++) {

				for(int j =0; j < M_Columns ; j++) {
				
					originalImage[i][j] = 'k';
				
				}
			}
			// Assign different valuesto some pixels in order to see the difference before and after rotation
			originalImage[0][0] = 'a';
			originalImage[1][1] = 'p';
			originalImage[0][M_Columns-1] = 'b';
			originalImage[N_rows-1][M_Columns-1] = 'c';
			originalImage[N_rows-2][M_Columns-2] = 'r';
			originalImage[N_rows-1][0] = 'd';
		}

		//the function for doing the actions for solving the problem 
		void operation() {

			// print out the original image
			for(int i = 0 ; i < N_rows ; i++) {

				cout << "original array: ";
				for(int j = 0 ; j < M_Columns ; j++) {

					cout << originalImage[i][j];
				}
				cout << endl;
			}			
			
			//doing the rotation
			rotateImage(originalImage);

			// print out the result
			for(int i = 0 ; i < N_rows ; i++) {
				cout << "changed array: ";

				for(int j =0; j < M_Columns ; j++) {
					cout << originalImage[i][j];
				}
				cout << endl;
			}
			//delete the allocated memory
			for(int i = 0 ; i < N_rows ; i++) {
				delete originalImage[i];
			}
			delete originalImage;
		}
};




int _tmain(int argc, _TCHAR* argv[]) {

	// declare a class of type chap1question6, which indicates the chapter and the question
	//the constructor is given the number of rows and columns
	chap1question6 question6(5,5);

	//
	//by calling the operation member function of each question class, the act of solving the problem will be executed
	question6.operation();
	
	return 0;
}

