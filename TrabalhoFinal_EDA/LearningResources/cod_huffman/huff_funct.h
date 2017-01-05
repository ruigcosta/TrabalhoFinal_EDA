/*******************************************
            ___  ___                     __   __   __   ___ 
 |__| |  | |__  |__   |\/|  /\  |\ |    /  ` /  \ |  \ |__  
 |  | \__/ |    |     |  | /~~\ | \|    \__, \__/ |__/ |___                                                         
 
 [huff_funct.cpp]
 produced by: *3d_style_master*
 AUTHOR: Irene M. Gironacci

LICENCE:
Permission is granted to anyone to view and modify this program and related documents for 

any purpose, 
provided this copyright notice is retained and prominently displayed, 
along with a note saying that the original programs are available from my web page. 
The programs and documents are distributed without any warranty, expressed or implied. 
The programs and documents were written for research purposes. 
All use of these programs is entirely at the user's own risks. 

CREDITS:
This code was written by Irene M. Gironacci
You need to cite my documents or my name in all pubblications which use this code.

Copyright Irene M. Gironacci - All Rights Reserved
**************************************************************************************/
 
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <conio.h>
using namespace std;
#include "huff_head.h"
#include "huffman.h"

/* definizione di build_decoding_tree */
void huffman::build_decoding_tree (ifstream & codeIN)
{
     char ch;       // carattere
     string code;   // codice del carattere
     
     for (;;)
     {
         codeIN >> ch >> code;
         if (codeIN.eof()) return;
         insert (ch, code);
     }
}

/* definizione di insert() */
void huffman::insert(char ch, string code)
{
     /* puntatore per muoversi nel cammino dalla radice */
     huffman:: bin_node_LINK L = root;
     for (int i = 0; i<code.length(); i++)
     {
         switch (code[i])
         {
                case '0':
                     if (L -> left == 0) L->left = new huffman::bin_node('*');
                     L = L->left;
                     break;
                case '1':
                     if (L -> right == 0) L->right = new huffman::bin_node('*');
                     L = L->right;
                     break;
                default:
                        cerr << "*** illegal character in code ***\n";
                        exit(1);
         }
     }
         L -> data = ch;
}
void huffman::write(string word)
{
     ofstream wr;
     wr.open ("inputMSG.txt");                     
     /* mette le linee in una stringa unica */
     wr << word;
     wr.close(); 
}

/* definizione di decode() */
void huffman::decode (ifstream & msgIN)
{
     char bit;
     huffman::bin_node_LINK L;
     ofstream wr;
     wr.open ("inputMSG2.txt");                     
     for (;;)
     {
         L = root;
         while (L->left != 0 || L-> right != 0)
         {
               msgIN >> bit;
               if (msgIN.eof())return;
               cout << bit;
               wr << bit;
               if (bit == '0') L = L-> left;
               else if (bit == '1') L = L->right;
               else cerr << "illegal bit: " << bit << " -- ignored\n";   
         }
         cout << " <-- " << L->data << endl;
         wr << " " << L->data << endl;
     }
     wr.close();
}

 /* definizione print_tree */
 void huffman::print_tree (ostream & out, huffman::bin_node_LINK root, int indent)
 {
      if (root != 0)
      {
               print_tree (out, root->right, indent +6);
               out << setw(indent) << " " << root-> data << endl;
               print_tree (out, root-> left, indent +6);
      }
}

////////////ENCODE///////////////
string Huffman(char letter)
{//this function takes a letter and produces it's corresponding Huffman encoding
switch(letter){
               // alphabet + ' ' 
case 'a':
case 'A':
     return "1101";
     break;
case 'b':
case 'B':
     return "001101";
     break;
case 'c':
case 'C':
     return "01100";
     break;
case 'd':
case 'D':
     return "0010";
     break;
case 'e':
case 'E':
     return "101";
     break;
case 'f':
case 'F':
     return "111100";
     break;
case 'g':
case 'G':
     return "001110";
     break;
case 'h':
case 'H':
     return "0100";
     break;
case 'i':
case 'I':
     return "1000";
     break;
case 'j':
case 'J':
     return "11111100";
     break;
case 'k':
case 'K':
     return "11111101";
     break;
case 'l':
case 'L':
     return "01111";
     break;
case 'm':
case 'M':
     return "01101";
     break;
case 'n':
case 'N':
     return "1100";
     break;
case 'o':
case 'O':
     return "1110";
     break;
case 'p':
case 'P':
     return "111101";
     break;
case 'q':
case 'Q':
     return "111111100";
     break;
case 'r':
case 'R':
     return "1001";
     break;
case 's':
case 'S':
     return "0101";
     break;
case 't':
case 'T':
     return "000";
     break;
case 'u':
case 'U':
     return "01110";
     break;
case 'v':
case 'V':
     return "001100";
     break;
case 'w':
case 'W':
     return "001111";
     break;
case 'x':
case 'X':
     return "111111101";
     break;
case 'y':
case 'Y':
     return "111110";
     break;
case 'z':
case 'Z':
     return "11111111";
     break;
default:
        cout << " *** ERROR: invalid input!!! ***";
        break;
}
}

