/************************************************************
            ___  ___                     __   __   __   ___ 
 |__| |  | |__  |__   |\/|  /\  |\ |    /  ` /  \ |  \ |__  
 |  | \__/ |    |     |  | /~~\ | \|    \__, \__/ |__/ |___ 
                                                           
 [huff_head.h]
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
**********************************************************************************************/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#ifndef huff_head_h
#define huff_head_h

class huffman
{
      private:
              /*** struttura nodo ***/
              class bin_node
              {
                    public:
                           char data;          // info
                           bin_node * left;    // pt figlio sx
                           bin_node * right;   // pt figlio dx
                           /* costruttore bin_node */
                           bin_node (char item)
                           {
                                    data = item;
                                    left = right = 0;
                           }
              }; //-fine class bin_node
              /*** puntatore a strutture nodo ***/
              typedef bin_node * bin_node_LINK; 
              bin_node_LINK root;
      public:
             
             /* funzioni membro: */
             huffman() {root = new bin_node ('*');}  // costruttore
             ~huffman() {delete root;}
             void build_decoding_tree (ifstream & codeIN);  //costruttore albero di decodifica
             void insert (char ch, string node);   // fz. per l'inserimento del codice nell'albero
             void decode (ifstream & msgIN);       // fz. per decodificare il codice
             void write(string word);
             void print_tree (ostream & out, bin_node_LINK root, int indent);   // fz. che visualizza l'albero binario
             void display_decoding_tree (ostream & out) {print_tree( out, root, 0);}  // fz. per visualizzare l'albero di decodifica
};
/* many functions */
string Huffman(char letter);


#endif
