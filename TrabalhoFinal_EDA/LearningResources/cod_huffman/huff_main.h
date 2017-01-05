/************************************************************
            ___  ___                     __   __   __   ___ 
 |__| |  | |__  |__   |\/|  /\  |\ |    /  ` /  \ |  \ |__  
 |  | \__/ |    |     |  | /~~\ | \|    \__, \__/ |__/ |___ 
                                                           
 [huff_main.cpp]
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

#include <iostream>
#include <fstream>
#include <conio.h>
#include <iterator>
#include <vector>
#include <map>
using namespace std;
#include "huffman.h"
#include "huff_head.h"

ostream& operator<<(ostream& os, vector<bool> vec)
{
  copy(vec.begin(), vec.end(), ostream_iterator<bool>(os, ""));
  return os;
}
 
int main()
{
  /* frequenze codice */
  map<char, double> frequencies;
  frequencies[' '] = 0.141124;
  frequencies['e'] = 0.124167;
  frequencies['a'] = 0.0820011;
  frequencies['t'] = 0.0969225;
  frequencies['i'] = 0.0768052;
  frequencies['n'] = 0.0764055;
  frequencies['o'] = 0.0714095;
  frequencies['s'] = 0.0706768;
  frequencies['r'] = 0.0668132;
  frequencies['l'] = 0.0448308;
  frequencies['d'] = 0.0363709;
  frequencies['h'] = 0.0350386;
  frequencies['c'] = 0.0344391;
  frequencies['u'] = 0.028777;
  frequencies['m'] = 0.0281775;
  frequencies['f'] = 0.0235145;
  frequencies['p'] = 0.0203171;
  frequencies['y'] = 0.0189182;
  frequencies['g'] = 0.0181188;
  frequencies['w'] = 0.0135225;
  frequencies['v'] = 0.0124567;
  frequencies['b'] = 0.0106581;
  frequencies['k'] = 0.00393019;
  frequencies['x'] = 0.00219824;
  frequencies['j'] = 0.0019984;
  frequencies['q'] = 0.0009325;
  frequencies['z'] = 0.000599;
    /* info */
       cout << "\n*  _  _ _  _ ____ ____ _  _ ____ _  _ "
            << "\n*  |__| |  | |___ |___ |\\/| |__| |\\ | "
            << "\n*  |  | |__| |    |    |  | |  | | \\| "
            << "\n*   "
            << "\n***********************************************\n\n";
       char sel1;
       char filename[32];
       huffman h;
    /* ciclo while per il menu */ 
         while (1)
         {
               /* visualizzazione menu: */
                  cout << "\n--- OPERAZIONI DISPONIBILI ---\n\n";
                  cout << "  0) uscire dal programma\n";
                  cout << "  1) visualizza codici ricorrenze\n";
                  cout << "  2) immissione stringa (input) --> codice (output)\n";
                  cout << "  3) lettura stringa (da file) --> codice (output)\n";
                  cout << "  4) visualizza albero ricorrenze <-- codici (prestabiliti)\n";
                  cout << "\n---------------------------------------------------------\n";
               /* lettura selezione: richiede di effettuare la scelta finché la scelta non è valida */
               do{
                  cout << "\n selezione --> ";
                  cin >> sel1;          // lettura selezione
                  cout << endl;
                  /* messaggio di errore in caso di selezione non valida: */
                  if (sel1 != '0' && sel1 != '1' && sel1 != '2' && sel1 != '3' && sel1!= '4') 
                     cout << "*** ERROR: invalid choice!!! try again. . .***\n\n";
               }
               while (sel1 != '0' && sel1 != '1' && sel1 != '2' && sel1 != '3' && sel1 != '4');
               /* switch case */              
               switch (sel1)
               {     
                 /* case 0 */
                 case '0':
                 {
                     /* uscita dal programma */
                         cout << "\n\n";
                         cout << "- produced by.. *3DstyleMaster* -\n";
                         cout << endl;
                         system("pause");
                         return 0;
                 }break;
                 /* case 1  visualizzare codici prestabiliti */
                 case '1':
                 {
                      ofstream wr;
                      wr.open("codenew.txt");
                      Hufftree<char, double> hufftree(frequencies.begin(), frequencies.end());
                      cout << "Codetable for Encoding/Decoding"  << "\n";
                      for (char ch = 'a'; ch <= 'z'; ++ch)
                      {
                           cout << ch << ": " << hufftree.encode(ch) << "\n";
                           wr << ch << " " << hufftree.encode(ch) << "\n";
                      }
                      cout << "Space" << ": " << hufftree.encode(' ') << "\n\n";
                      wr.close();
                      break;
                 }
                 /* case 2: immissione stringa */
                 case '2':
                 {
                      Hufftree<char, double> hufftree(frequencies.begin(), frequencies.end());
                      string word;
                      cout << "\n-- INPUT AND DECODE MSG ACTIVETED ------";
                      cout <<"\nplease, enter your string: ";
                      cin.ignore();
                      getline(cin,word);
                      cout << "string to manipulate is :   " << word << endl << endl;
                      /* calcolo dimensione */
                      cout << "size of input string (in bits): " << (word.size())*8 << endl;
                      cout << "string encoded is :   ";
                      vector<bool> encoded = hufftree.encode(word.begin(), word.end());
                      cout << encoded << "\n\n";
                      cout << "size of encoded string (in bits): " << encoded.size() << endl << endl;
                      cout << "Let's decode the encoded string back ---  " <<"\n" ;
                      cout << "The decoded string is :   " ;
                      string destination;
                      hufftree.decode(encoded, back_inserter(destination));
                      cout << destination << "\n";
                      break;
                 }
                 /* case 3: lettura stringa da file */
                 case '3':
                 {
                      cout<< "\n-- LOOKING FOR THE MESSAGE ------";
                      cout<< "\nname of message file: ";
                      cin >> filename;
                      ifstream message (filename);
                      if (!message.is_open())
                      {
                           cout << "cannot open message file.\n";
                           getch();
                           return 1;
                      }
                      cout<< "\nnow enter name of code file: ";
                      cin >> filename;
                      ifstream code_stream(filename);
                      if (!code_stream.is_open())
                      {
                               cout << "*** WARNING: cannot open code file. ***\n";
                               getch();
                               return 1;
                      }
                      h.build_decoding_tree(code_stream);
                      cout << "\n-- DECODING MESSAGE ACTIVETED ------\n";
                      h.decode(message);
                      break;
                 }
                 case '4':
                 {
                      cout<< "\n-- LOOKING FOR THE SOURCE ------";
                      cout<< "\nenter name of code file: ";
                      cin >> filename;
                      ifstream code_stream(filename);
                      if (!code_stream.is_open())
                      {
                               cout << "*** WARNING: cannot open code file. ***\n";
                               getch();
                               return 1;
                      }
                      h.build_decoding_tree(code_stream);
                      cout << "here is the huffman decoding tree:\n";
                      h.display_decoding_tree(cout);
                      code_stream.close();
                      
                      break;
                 }//fine case-
               }//fine switch-
         }// fine while-
}//fine main.
