// CrackingCodingChap_1.cpp : Defines the entry point for the console application. /// - remove following unused line

#include "stdafx.h"
#include <iostream>
#include <string>
/// + add empty line for readibility
using namespace std;
/// + add empty line for readibility
// Question 1 : write a program to judge if the string contains unique characters
class chap1question1 { /// add space between class name and left brace /// - remove follwing redundant comment

public:
	string targetString; /// - remove follwing redundant comment

	// function1 : use addtitonal datastructure;
	bool isStringUnique(string target) { /// add space between paranthese and brace
		/// + add empty line
		int table[256] = {0}; /// you can use boolean instead of integer, will save you on memory usage
		/// + add empty line
		for(int i = 0; i < target.length(); i++) { /// re-arrange use of spaces in for-statement
			if(table[(int)target[i]] != 0) { /// re-arrange use of spaces in if-statement /// + always use braces
				return false;
			}
			table[(int)target[i]]++;
		}
		return true;
	}

	// function2 : no extra data structure used /// people knew it's `here`...
	bool isStringUniqueEfficient(string target) { /// naming needs to be clear and meaningful
		/// + add empty line for readibility
		int bitMapTable = 0;
		int tempStorage = 0;
		/// + add empty line for readibility
		for(int i = 0; i < target.length(); i++) { /// re-arrange spaces
			tempStorage = 1 << (int)target[i];
		
			if((bitMapTable & tempStorage) != 0){ /// re-arrange spaces
				return false;
			} else { /// re-arrange spaces
				bitMapTable = bitMapTable | tempStorage;
			}

		}
		return true; /// - remove following unused line
	}
	/// - remove meaningless comment
	void operationQ_1(){
		cout<<"please string you would like to judge!"<<endl; /// re-arrange spaces
		cin>>targetString;

		if(isStringUnique(targetString)) { /// re-arrange spaces
			cout<< "The string is unique, all characters are identical" << endl;
		} else { /// re-arrange spaces
			cout<<"The string is 'not' unique (use additional data structure)"<<endl;
		}
		/// + add empty line for readibility
		if(isStringUniqueNoAddStructure(targetString)) { /// re-arrange spaces
			cout<< "The string is unique, all characters are identical (no additional data structure used)" << endl;
		} else { /// re-arrange spaces
			cout << " The string is 'not' unique! (no additional data structure used)" << endl; /// moved right brace to next line to keep code style cosistent
		} ///
	}
	
};
/// - remove following unused line
// Question 2: Write code to reverse a C-Style String.
//(C-String means that ��abcd�� is represented as five characters, including the null character.) /// can't understand what's this, do you?

class chap1question2 { /// re-arrange spaces /// - remove following unused line and code

private: /// always use access control to be more clear
	char* reverseCstyleString(char* target) { /// re-arrange spaces
		char tempChar;
		int index = 0;
		int front = 0;
		int rear = 0;
		/// + add empty line for readibility
		while(target[index] != NULL) { /// re-arrange spaces
			index++;
		}
		/// + add empty line for readibility
		rear = --index;
		while(front < rear){ /// re-arrange spaces
			tempChar = target[rear];
			target[rear] = target[front];
			target[front] =tempChar;
			rear--;
			front++;
		} /// - remove following unused code

		return target; 
	} 
	/// - remove meaningless comment
public: /// edit indentation for consisent style
	void operationQ_2(){ /// - remove following unused code

		char targetCString[] = "asdfghjklo";
		int stringIndex = 0;
		cout<<"original string: "<<endl;
		/// + add empty line for readibility
		while(targetCString[stringIndex]) { /// moved the brace here to keep code style consistent
			cout<<targetCString[stringIndex]; /// remove space to keep code style consistent
			stringIndex++;
		}
		cout<<endl;
		/// + add empty line for readibility
		reverseCstyleString(targetCString);
		cout<<"reversed string!"<<endl;
		/// + add empty line for readibility
		stringIndex = 0;
		while(targetCString[stringIndex]) { /// moved the brace here to keep code style consistent
			cout << targetCString[stringIndex];
			stringIndex++;
		}
	}

};

// Question 3: Design an algorithm and write code to remove the duplicate characters in a string without using any 
//additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.

class chap1question3{
	string targetString;

	void removeDuplicate(string& target){
		int tempIndex = 0;
		int tableBitMap = 0;
		for(int i = 0 ; i < target.length() ; i++){ 
			if( (tableBitMap & (1<< (int)target[i])) == 0 ){
				tableBitMap =  tableBitMap | 1 << (int)target[i];
				//target[tempIndex] = target[i];
				//tempIndex ++ ; 
			}else{
				target.erase(i,1);
				i--;
			}

		}


	}
public:
	void operationQ_3(){
		cout<< "please enter the string you want to operate: " << endl;
		cin>> targetString;
		cout<< endl << "original string: " << targetString<<endl;
		removeDuplicate(targetString);
		cout<< "resault string: "<<endl << targetString<<endl;
	
	}


};

// Question 4:Write a method to decide if two strings are anagrams or not.

class chap1question4{
	string string1;
	string string2;

 
	bool isAnagrams(char str1[],char str2[]){
		int table[256] = {0};
		int indexStr1 = 0;
		int indexStr2 = 0;
		while(str1[indexStr1] != NULL){  //O(n)
			table[(int)str1[indexStr1]]++;
			indexStr1++;
		}
		while(str2[indexStr2] != NULL){//O(n)
			table[(int)str2[indexStr2]]--;
			indexStr2++;
		}
		if(indexStr1 != indexStr2)
			return false;
		else{

			for(int i = 0 ; i<256; i++){//O(1)
				if(table[i] != 0)
					return false;
			}
			return true;
		}

		return false;	
	}
public:
	void operation(){
		cout<<"Please enter the first string: " <<endl;
		cin >> string1;
		cout<<"Please enter the second string: " <<endl;
		cin>>string2;

		bool isAnagram = isAnagrams(&string1[0], &string2[0]);
		if(isAnagram)
			cout<< "these two strings are anagrams"<<endl;
		else 
			cout << "these two strings are 'not' anagrams"<<endl;
	}



};

// Question 5: Write a method to replace all spaces in a string with ��%20��.

class chap1question5{
	char targetString[];

	char* replaceSpace(char* target){
		int newIndex = 0;
		int oldIndex = 0;
		int length =0;
		while (target[length]!=NULL) // O(n)
		{
			length++;
		}
		char* newString = (char*) malloc((length)*sizeof(char)*3+1);
		while(target[oldIndex] != NULL){
			if(target[oldIndex] == ' '){
				newString[newIndex] = '%';
				newString[newIndex+1] = '2';
				newString[newIndex+2] = '0';
				newIndex += 3;
			}else{
				newString[newIndex] = target[oldIndex];
				newIndex++;
			}
			oldIndex++;
		}
		newString[newIndex] = NULL;
		return newString;
	}
public:
	void operation(){
	 char originalString[] = "uerl://th i s.c o m !"; // C-Style
	 char* newString;
	 newString = replaceSpace(originalString);
		int index = 0;	
	 while(newString[index]!=NULL){
		cout<<newString[index];
		index++;
	 }
	
	}

};

class chap1question6{
	public:
		int N_rows; // for the image
		int M_Columns; // for the image
		char** originalImage;
		void rotateImage(char** original){
			if(N_rows != M_Columns){
				cout<<" # rows should be equal to # of columns"<<endl;
				return;
			}
			int beginIndex = 0 ;
			int endIndex = 0;
			//*(original+1)[0] = 'k';
			for(int layer = 0 ; layer < M_Columns/2 ; layer++){
				beginIndex = layer+1;
				endIndex = M_Columns -beginIndex;
				//for each layer
				for(int j = beginIndex ; j<=endIndex ; j++){
					char temp_Top = original[layer][j];
					// do swap
					original[layer][j] = original[N_rows - j-1][layer];
					original[N_rows - j-1][layer] = original[N_rows - layer-1][M_Columns-j -1];
					original[N_rows - layer-1][M_Columns-j -1] = original[j][M_Columns -1-layer];
					original[j][M_Columns - 1 - layer] = temp_Top;
					
				}

			}

		}
		chap1question6(int n_rows, int m_columns){
			N_rows = n_rows;
			M_Columns = m_columns;
			originalImage = new char*[N_rows];
			for(int i = 0 ; i< N_rows ; i++){
				originalImage[i] = new char[M_Columns];
			}
			int indexCount = 0;
			//initialize the original image
			for(int i = 0 ; i < N_rows ; i++){
				for(int j =0; j< M_Columns ; j++){
					originalImage[i][j] = 'k';
					indexCount++;
				}
			}
			originalImage[0][0] = 'a';
			originalImage[1][1] = 'p';
			originalImage[0][M_Columns-1] = 'b';
			originalImage[N_rows-1][M_Columns-1] = 'c';
			originalImage[N_rows-2][M_Columns-2] = 'r';
			originalImage[N_rows-1][0] = 'd';
		}
		void operation(){

			for(int i = 0 ; i < N_rows ; i++){
				cout<< "original array: ";
				for(int j =0; j< M_Columns ; j++){
					cout<<originalImage[i][j];
				}
				cout<<endl;
			}			
			//rotate!!
			rotateImage(originalImage);

			for(int i = 0 ; i < N_rows ; i++){
				cout<< "changed array: ";
				for(int j =0; j< M_Columns ; j++){
					cout<<originalImage[i][j];
				}
				cout<<endl;
			}
			//delete the allocated memory
			for(int i = 0 ; i< N_rows ; i++){
				delete originalImage[i];
			}
			delete originalImage;
		}


};

class Chap1Question7{
		int M_Columns;
		int N_Rows;

	public:
		int** originalMatrix;
		int* zeroRows;
		int* zeroColumns;

		Chap1Question7(int numberRows, int numberColumns){
			M_Columns = numberColumns;
			N_Rows = numberRows;
			zeroRows = new int[N_Rows];
			zeroColumns = new int[M_Columns];
			originalMatrix = new int*[N_Rows];
			for(int i = 0 ; i < N_Rows ; i ++){
				originalMatrix[i] = new int[M_Columns];
			}
			for(int i = 0 ; i < N_Rows ; i++){
				for(int j = 0 ; j< M_Columns ; j++){
					originalMatrix[i][j] = 1;
				}
			}
			originalMatrix[1][1] = 0;

		}
		void SenseZero(){
			for(int i = 0 ; i< N_Rows ; i++){
				for(int j = 0 ; j < M_Columns ; j++){
					if(originalMatrix[i][j] == 0 ){
						zeroRows[i] = 1;
						zeroColumns[j] = 1;
					}

				}
			}
		}
		void SetZero(){
			for(int i =0; i <N_Rows ; i++){
				for(int j =0 ; j<M_Columns; j++){
					if(zeroRows[i] ==1)
						originalMatrix[i][j] = 0;
					if(zeroColumns[j] ==1)
						originalMatrix[i][j] = 0;

				}
			}
		}
		void operation(){
			for(int i = 0 ; i < N_Rows ; i++){
				cout<< "original Matrix: ";
				for(int j =0; j< M_Columns ; j++){
					cout<<originalMatrix[i][j];
				}
				cout<<endl;
			}
			cout<<endl;
			SenseZero();
			SetZero();
			for(int i = 0 ; i<N_Rows ; i++){
				cout << "Modified Matrix: ";
				for(int j = 0 ; j <M_Columns ; j++){
				 cout<<originalMatrix[i][j];
				}
				cout<<endl;
			}

						


		}

};



int _tmain(int argc, _TCHAR* argv[])
{
	chap1question1 question1;
	chap1question2 question2;
	chap1question3 question3;
	chap1question4 question4;
	chap1question5 question5;
	chap1question6 question6(5,5);
	Chap1Question7 question7(4,7);
	//question1.operationQ_1();
	//question2.operationQ_2();
	//question3.operationQ_3();
	//question4.operation();
	//question6.operation();
	question7.operation();
	return 0;
}

