#include<iostream>
#include <cstring> // strlen
#include "AsciiArt.h"
using namespace std;

 // Call a.draw().
ostream &operator<<(ostream &out, const AsciiArt &a)
{
    a.draw(out);
    return out;
};

// optional helper functions
// dynamically allocate a 2D array
char** AsciiArt::makeGrid(int numRows, int numCols)
{
    char** grid = new char*[numRows];
    for(int row=0; row< numRows; row++)
    {
        grid[row] = new char [numCols];
        for(int col=0; col<numCols; col++)
        {
            grid[row][col] = ' ';
        }
    }
    return grid;
};
// delete g[0] etc. and delete g.
void AsciiArt::deleteGrid(char **g, int numRows)
{
    for(int row=0; row<numRows; row++)
    {
        delete g[row];
    }
    delete g;
}; 

void AsciiArt::copyGrid(char **dest, char **source, int numRows, int numCols)
{
    for(int row=0; row<numRows; row++)
    {
        for(int col=0; col<numCols; col++)
        {
            dest[row][col] = source[row][col];
        }
    }
}; 

// Set numRows to max(1,numR), numCols to max(1,numC)
AsciiArt::AsciiArt(int numR, int numC)
{
    numRows = max(1, numR);
    numCols = max(1, numC);
    grid = makeGrid(numRows, numCols);
};
// copy constructor. Make sure to do a deep copy.
AsciiArt::AsciiArt(const AsciiArt &other)
{
    numRows = other.getNumRows();
    numCols = other.getNumCols();
    grid = makeGrid(numRows, numCols);
    copyGrid(grid, other.grid, numRows, numCols);
    
};
// Overloaded assignment operator. Get it right!
AsciiArt& AsciiArt::operator=(const AsciiArt &other)
{
    numRows = other.getNumRows();
    numCols = other.getNumCols();
    deleteGrid(grid, numRows);
    grid = makeGrid(numRows, numCols);
    copyGrid(grid, other.grid, numRows, numCols);
    return *this;
};
 // enlarge, e.g. mult=2 --> "double" each row & column (See output)
AsciiArt& AsciiArt::operator*=(int mult)
{
    int multNumRows = numRows * mult;
    int multNumCols = numCols * mult;
    char** newGrid = makeGrid(multNumRows, multNumCols);
    for(int row=0; row<multNumRows; row++)
    {
        for(int col=0; col<multNumCols; col++)
        {
            newGrid[row][col] = grid[row/mult][col/mult];
        }
    }
    deleteGrid(grid, numRows);
    grid = newGrid;
    numRows = multNumRows;
    numCols = multNumCols;
    return *this;
};
// reduce e.g. div=2 --> keep every other row & columm. (See output)
AsciiArt &AsciiArt::operator/=(int div)
{
    int divNumRows = numRows / div;
    int divNumCols = numCols / div;
    char ** newGrid = makeGrid(divNumRows, divNumCols);
    for(int row=0; row<divNumRows; row++)
    {
        for(int col=0; col<divNumCols; col++)
        {
            newGrid[row][col] = grid[row*div][col*div];
        }
    }
    deleteGrid(grid, numRows);
    grid = newGrid;
    numRows = divNumRows;
    numCols = divNumCols;
    return *this;
};
   // Call *=  
AsciiArt AsciiArt::operator*(int mult)
{
    *this *= mult;
    return *this;
};
//  Call /=
AsciiArt AsciiArt::operator/(int div)
{
    *this/=div;
    return *this;
};
// destructor (Call deleteGrid if you implemented it.)
AsciiArt::~AsciiArt()
{
    deleteGrid(grid, numRows);
};                    

// return true if the *this and other have the same dimensions and the same characters
// return false otherwise
bool AsciiArt::operator==(const AsciiArt &other)
{
    if(numRows != other.numRows || numCols != other.numCols){return false;}
    for(int row=0; row<numRows; row++)
    {
        for(int col=0; col<numCols; col++)
        {
            if(other.grid[row][col] != grid[row][col])
            {
                return false;
            }
        }
    }
    return true;
};
 // call operator==
bool AsciiArt::operator!=(const AsciiArt &other)
{
    return !(*this==other);
};

// Set grid[row][col] to c or do nothing if row or col is out of bounds.
void AsciiArt::setChar(int row, int col, char c)
{
    if(row < 0 || row >= numRows || col < 0 || col >= numCols){return;}
    grid[row][col] = c;
};

// return grid[row][col] or return '\0' if row or col is out of bounds.
char AsciiArt::getChar(int row, int col) const
{
    if(row < 0 || row >= numRows || col < 0 || col >= numCols){return '\0';}
    return grid[row][col];
};

// draw the picture to out.  See sample output as a guide.
void AsciiArt::draw(std::ostream &out) const
{
    for(int row=0; row<numRows; row++)
    {
        for(int col=0; col<numCols; col++)
        {
            out << grid[row][col];
        }
        out << endl;
    }
};

// If row or startCol is out-of-bounds then return without copying anything.
// Otherwise, copy s[0] into grid[row][startCol], s[1] into grid[row][startCol+1] etc.
// If s is "too long to fit", stop copying beyond grid[row][numCols-1].
void AsciiArt::setRow(int row, int startCol, const char s[])
{
    if(row < 0 || row >= numRows || startCol < 0 || startCol >= numCols){return;}
    size_t size = strlen(s);
    for(int i=0; i < size; i++)
    {
        if(startCol+i > numCols-1){return;}
        grid[row][startCol+i] = s[i];
    }

};

// return numRows
int AsciiArt::getNumRows() const
{
    return numRows;
};

// return numCols
int AsciiArt::getNumCols() const
{
    return numCols;
};

// Flip the picture. That means swap the dimensions and
// set each grid[j][i] in the new picture to grid[i][j] from the old picture.
// Avoid memory leaks. Return *this.
AsciiArt& AsciiArt::flip()
{
    int newNumCols = numRows;
    int newNumRows = numCols;
    char** newGrid = makeGrid(newNumRows, newNumCols);
    for(int row=0; row<newNumRows; row++)
    {
        for(int col=0; col<newNumCols; col++)
        {
            newGrid[row][col] = grid[col][row];
        }
    }
    deleteGrid(grid, numRows);
    numRows = newNumRows;
    numCols = newNumCols;
    grid = newGrid;
    return *this;
};

/*
clang: warning: treating 'c-header' input as 'c++-header' when in C++ mode, this behavior is deprecated [-Wdeprecated]
HERE IS A PICTURE!
*
**
***
****
*****
******
*******
********
ZZZZZZZZZZZZZZZZZZZZZZZZ
  ZZZZZZZZZZZZZZZZZZZZ  
     ZZZZZZZZZZZZZZ     
         ZZZZZZ         
           ZZ           

Z    
HZ    
EZZ   
RZZ   
EZZ   
 ZZZ  
IZZZ  
SZZZ  
 ZZZ  
AZZZZ 
 ZZZZ 
PZZZZZ
IZZZZZ
CZZZZ 
TZZZZ 
UZZZ  
R*ZZZ  
E**ZZZ  
!***ZZZ  
****ZZ   
*****ZZ   
******ZZ   
*******Z    
********Z    


Z    
HZ    
EZZ   
RZZ   
EZZ   
 ZZZ  
IZZZ  
SZZZ  
 ZZZ  
AZZZZ 
 ZZZZ 
PZZZZZ
IZZZZZ
CZZZZ 
TZZZZ 
UZZZ  
R*ZZZ  
E**ZZZ  
!***ZZZ  
****ZZ   
*****ZZ   
******ZZ   
*******Z    
********Z    
ZZ        
ZZ        
HHZZ        
HHZZ        
EEZZZZ      
EEZZZZ      
RRZZZZ      
RRZZZZ      
EEZZZZ      
EEZZZZ      
  ZZZZZZ    
  ZZZZZZ    
IIZZZZZZ    
IIZZZZZZ    
SSZZZZZZ    
SSZZZZZZ    
  ZZZZZZ    
  ZZZZZZ    
AAZZZZZZZZ  
AAZZZZZZZZ  
  ZZZZZZZZ  
  ZZZZZZZZ  
PPZZZZZZZZZZ
PPZZZZZZZZZZ
IIZZZZZZZZZZ
IIZZZZZZZZZZ
CCZZZZZZZZ  
CCZZZZZZZZ  
TTZZZZZZZZ  
TTZZZZZZZZ  
UUZZZZZZ    
UUZZZZZZ    
RR**ZZZZZZ    
RR**ZZZZZZ    
EE****ZZZZZZ    
EE****ZZZZZZ    
!!******ZZZZZZ    
!!******ZZZZZZ    
********ZZZZ      
********ZZZZ      
**********ZZZZ      
**********ZZZZ      
************ZZZZ      
************ZZZZ      
**************ZZ        
**************ZZ        
****************ZZ        
****************ZZ        

HHEERREE  IISS  AA  PPIICCTTUURREE!!
HHEERREE  IISS  AA  PPIICCTTUURREE!!
**
**
****
****
******
******
********
********
**********
**********
************
************
**************
**************
****************
****************
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ    
    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ    
          ZZZZZZZZZZZZZZZZZZZZZZZZZZZZ          
          ZZZZZZZZZZZZZZZZZZZZZZZZZZZZ          
                  ZZZZZZZZZZZZ                  
                  ZZZZZZZZZZZZ                  
                      ZZZZ                      
                      ZZZZ                      


HERE IS A PICTURE!
*
**
***
****
*****
******
*******
********
ZZZZZZZZZZZZZZZZZZZZZZZZ
  ZZZZZZZZZZZZZZZZZZZZ  
     ZZZZZZZZZZZZZZ     
         ZZZZZZ         
           ZZ           

ZZZZZZ                        
ZZZZZZ                        
ZZZZZZ                        
ZZZZZZ                        
ZZZZZZ                        
ZZZZZZ                        
HHHHHHZZZZZZ                        
HHHHHHZZZZZZ                        
HHHHHHZZZZZZ                        
HHHHHHZZZZZZ                        
HHHHHHZZZZZZ                        
HHHHHHZZZZZZ                        
EEEEEEZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
RRRRRRZZZZZZZZZZZZ                  
RRRRRRZZZZZZZZZZZZ                  
RRRRRRZZZZZZZZZZZZ                  
RRRRRRZZZZZZZZZZZZ                  
RRRRRRZZZZZZZZZZZZ                  
RRRRRRZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
EEEEEEZZZZZZZZZZZZ                  
      ZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
IIIIIIZZZZZZZZZZZZZZZZZZ            
IIIIIIZZZZZZZZZZZZZZZZZZ            
IIIIIIZZZZZZZZZZZZZZZZZZ            
IIIIIIZZZZZZZZZZZZZZZZZZ            
IIIIIIZZZZZZZZZZZZZZZZZZ            
IIIIIIZZZZZZZZZZZZZZZZZZ            
SSSSSSZZZZZZZZZZZZZZZZZZ            
SSSSSSZZZZZZZZZZZZZZZZZZ            
SSSSSSZZZZZZZZZZZZZZZZZZ            
SSSSSSZZZZZZZZZZZZZZZZZZ            
SSSSSSZZZZZZZZZZZZZZZZZZ            
SSSSSSZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
      ZZZZZZZZZZZZZZZZZZ            
AAAAAAZZZZZZZZZZZZZZZZZZZZZZZZ      
AAAAAAZZZZZZZZZZZZZZZZZZZZZZZZ      
AAAAAAZZZZZZZZZZZZZZZZZZZZZZZZ      
AAAAAAZZZZZZZZZZZZZZZZZZZZZZZZ      
AAAAAAZZZZZZZZZZZZZZZZZZZZZZZZ      
AAAAAAZZZZZZZZZZZZZZZZZZZZZZZZ      
      ZZZZZZZZZZZZZZZZZZZZZZZZ      
      ZZZZZZZZZZZZZZZZZZZZZZZZ      
      ZZZZZZZZZZZZZZZZZZZZZZZZ      
      ZZZZZZZZZZZZZZZZZZZZZZZZ      
      ZZZZZZZZZZZZZZZZZZZZZZZZ      
      ZZZZZZZZZZZZZZZZZZZZZZZZ      
PPPPPPZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
PPPPPPZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
PPPPPPZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
PPPPPPZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
PPPPPPZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
PPPPPPZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
IIIIIIZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
IIIIIIZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
IIIIIIZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
IIIIIIZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
IIIIIIZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
IIIIIIZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
CCCCCCZZZZZZZZZZZZZZZZZZZZZZZZ      
CCCCCCZZZZZZZZZZZZZZZZZZZZZZZZ      
CCCCCCZZZZZZZZZZZZZZZZZZZZZZZZ      
CCCCCCZZZZZZZZZZZZZZZZZZZZZZZZ      
CCCCCCZZZZZZZZZZZZZZZZZZZZZZZZ      
CCCCCCZZZZZZZZZZZZZZZZZZZZZZZZ      
TTTTTTZZZZZZZZZZZZZZZZZZZZZZZZ      
TTTTTTZZZZZZZZZZZZZZZZZZZZZZZZ      
TTTTTTZZZZZZZZZZZZZZZZZZZZZZZZ      
TTTTTTZZZZZZZZZZZZZZZZZZZZZZZZ      
TTTTTTZZZZZZZZZZZZZZZZZZZZZZZZ      
TTTTTTZZZZZZZZZZZZZZZZZZZZZZZZ      
UUUUUUZZZZZZZZZZZZZZZZZZ            
UUUUUUZZZZZZZZZZZZZZZZZZ            
UUUUUUZZZZZZZZZZZZZZZZZZ            
UUUUUUZZZZZZZZZZZZZZZZZZ            
UUUUUUZZZZZZZZZZZZZZZZZZ            
UUUUUUZZZZZZZZZZZZZZZZZZ            
RRRRRR******ZZZZZZZZZZZZZZZZZZ            
RRRRRR******ZZZZZZZZZZZZZZZZZZ            
RRRRRR******ZZZZZZZZZZZZZZZZZZ            
RRRRRR******ZZZZZZZZZZZZZZZZZZ            
RRRRRR******ZZZZZZZZZZZZZZZZZZ            
RRRRRR******ZZZZZZZZZZZZZZZZZZ            
EEEEEE************ZZZZZZZZZZZZZZZZZZ            
EEEEEE************ZZZZZZZZZZZZZZZZZZ            
EEEEEE************ZZZZZZZZZZZZZZZZZZ            
EEEEEE************ZZZZZZZZZZZZZZZZZZ            
EEEEEE************ZZZZZZZZZZZZZZZZZZ            
EEEEEE************ZZZZZZZZZZZZZZZZZZ            
!!!!!!******************ZZZZZZZZZZZZZZZZZZ            
!!!!!!******************ZZZZZZZZZZZZZZZZZZ            
!!!!!!******************ZZZZZZZZZZZZZZZZZZ            
!!!!!!******************ZZZZZZZZZZZZZZZZZZ            
!!!!!!******************ZZZZZZZZZZZZZZZZZZ            
!!!!!!******************ZZZZZZZZZZZZZZZZZZ            
************************ZZZZZZZZZZZZ                  
************************ZZZZZZZZZZZZ                  
************************ZZZZZZZZZZZZ                  
************************ZZZZZZZZZZZZ                  
************************ZZZZZZZZZZZZ                  
************************ZZZZZZZZZZZZ                  
******************************ZZZZZZZZZZZZ                  
******************************ZZZZZZZZZZZZ                  
******************************ZZZZZZZZZZZZ                  
******************************ZZZZZZZZZZZZ                  
******************************ZZZZZZZZZZZZ                  
******************************ZZZZZZZZZZZZ                  
************************************ZZZZZZZZZZZZ                  
************************************ZZZZZZZZZZZZ                  
************************************ZZZZZZZZZZZZ                  
************************************ZZZZZZZZZZZZ                  
************************************ZZZZZZZZZZZZ                  
************************************ZZZZZZZZZZZZ                  
******************************************ZZZZZZ                        
******************************************ZZZZZZ                        
******************************************ZZZZZZ                        
******************************************ZZZZZZ                        
******************************************ZZZZZZ                        
******************************************ZZZZZZ                        
************************************************ZZZZZZ                        
************************************************ZZZZZZ                        
************************************************ZZZZZZ                        
************************************************ZZZZZZ                        
************************************************ZZZZZZ                        
************************************************ZZZZZZ                        

HHHHHHEEEEEERRRRRREEEEEE      IIIIIISSSSSS      AAAAAA      PPPPPPIIIIIICCCCCCTTTTTTUUUUUURRRRRREEEEEE!!!!!!
HHHHHHEEEEEERRRRRREEEEEE      IIIIIISSSSSS      AAAAAA      PPPPPPIIIIIICCCCCCTTTTTTUUUUUURRRRRREEEEEE!!!!!!
HHHHHHEEEEEERRRRRREEEEEE      IIIIIISSSSSS      AAAAAA      PPPPPPIIIIIICCCCCCTTTTTTUUUUUURRRRRREEEEEE!!!!!!
HHHHHHEEEEEERRRRRREEEEEE      IIIIIISSSSSS      AAAAAA      PPPPPPIIIIIICCCCCCTTTTTTUUUUUURRRRRREEEEEE!!!!!!
HHHHHHEEEEEERRRRRREEEEEE      IIIIIISSSSSS      AAAAAA      PPPPPPIIIIIICCCCCCTTTTTTUUUUUURRRRRREEEEEE!!!!!!
HHHHHHEEEEEERRRRRREEEEEE      IIIIIISSSSSS      AAAAAA      PPPPPPIIIIIICCCCCCTTTTTTUUUUUURRRRRREEEEEE!!!!!!
******
******
******
******
******
******
************
************
************
************
************
************
******************
******************
******************
******************
******************
******************
************************
************************
************************
************************
************************
************************
******************************
******************************
******************************
******************************
******************************
******************************
************************************
************************************
************************************
************************************
************************************
************************************
******************************************
******************************************
******************************************
******************************************
******************************************
******************************************
************************************************
************************************************
************************************************
************************************************
************************************************
************************************************
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
            ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ            
            ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ            
            ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ            
            ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ            
            ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ            
            ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ            
                              ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                              
                              ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                              
                              ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                              
                              ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                              
                              ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                              
                              ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                              
                                                      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                                      
                                                      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                                      
                                                      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                                      
                                                      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                                      
                                                      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                                      
                                                      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                                      
                                                                  ZZZZZZZZZZZZ                                                                  
                                                                  ZZZZZZZZZZZZ                                                                  
                                                                  ZZZZZZZZZZZZ                                                                  
                                                                  ZZZZZZZZZZZZ                                                                  
                                                                  ZZZZZZZZZZZZ                                                                  
                                                                  ZZZZZZZZZZZZ                                                                  

HHEERREE  IISS  AA  PPIICCTTUURREE!!
HHEERREE  IISS  AA  PPIICCTTUURREE!!
**
**
****
****
******
******
********
********
**********
**********
************
************
**************
**************
****************
****************
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ    
    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ    
          ZZZZZZZZZZZZZZZZZZZZZZZZZZZZ          
          ZZZZZZZZZZZZZZZZZZZZZZZZZZZZ          
                  ZZZZZZZZZZZZ                  
                  ZZZZZZZZZZZZ                  
                      ZZZZ                      
                      ZZZZ                      

HERE IS A PICTURE!
*
**
***
****
*****
******
*******
********
ZZZZZZZZZZZZZZZZZZZZZZZZ
  ZZZZZZZZZZZZZZZZZZZZ  
     ZZZZZZZZZZZZZZ     
         ZZZZZZ         
           ZZ           

EEI  ITR!
*
**
***
****
 ZZZZZZZZZZ 
     ZZZ    

EEEEII    IITTRR!!
EEEEII    IITTRR!!
**
**
****
****
******
******
********
********
  ZZZZZZZZZZZZZZZZZZZZ  
  ZZZZZZZZZZZZZZZZZZZZ  
          ZZZZZZ        
          ZZZZZZ        
*/