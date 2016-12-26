// LerFich.cpp : Defines the entry point for the console application.
//

#pragma once
#include "stdafx.h"
#include <iostream>
#include <chrono>

//#include"Tree.h"
//********************************
#include <iostream>
#include <fstream>
#include <string>

/*
using namespace std;

int main()
{
	string txt[10];
	string line;

	int i = 0;
	ifstream file("ficheiro.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			txt[i] = line;
			i++;
		}
	}
	file.close();

	for (int j = 0; txt[j] != "\0"; j++)
		cout << txt[j] << endl;

	system("pause");
	return 0;
}

*/

//*****************************
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
ifstream file(argv[1]); // pass file name as argment
string linebuffer;

while (file && getline(file, linebuffer)) {
if (linebuffer.length() == 0)continue;

if (!file) {
cout << "Cannot open input file.\n";
return 1;
}

char str[255];

while (file) {
file.getline(str, 255);  // delim defaults to '\n'
if (file) cout << str << endl;
}
while (file) { // in will be false when eof is reached
file.get(ch);
if (file) cout << ch;
}

file.close();
}
return 0;
}


//********************************************************

/*


using namespace std;

// How to read a text file:
// Use try...catch to deal with a 0 byte file or a non-existant file.
listBox1->Items->Clear();

try
{
String* textFile = String::Concat(windir, (S"\\ficheiro.txt"));
StreamReader *reader = new  StreamReader(textFile);
do
{
listBox1->Items->Add(reader->ReadLine());
} while (reader->Peek() != -1);
}
catch (FileNotFoundException *ex)
{
listBox1->Items->Add(ex);
}

catch (System::Exception *e)
{
listBox1->Items->Add(e);
}


//
// This demonstrates how to create and to write to a text file.
StreamWriter* pwriter = new StreamWriter(S"c:\\KBTest.txt");
pwriter->WriteLine(S"The file was created by using the StreamWriter class.");
pwriter->Close();
listBox1->Items->Clear();
String *filew = new String(S"File written to C:\\KBTest.txt");
listBox1->Items->Add(filew);

//
// This code retrieves file properties. The example uses Notepad.exe.
listBox1->Items->Clear();
String* testfile = String::Concat(windir, (S"\\notepad.exe"));
FileInfo *pFileProps = new FileInfo(testfile);

listBox1->Items->Add(String::Concat(S"File Name = ", (pFileProps->get_FullName())));
listBox1->Items->Add(String::Concat(S"Creation Time = ", (pFileProps->get_CreationTime()).ToString()));
listBox1->Items->Add(String::Concat(S"Last Access Time = ", (pFileProps->get_LastAccessTime()).ToString()));
listBox1->Items->Add(String::Concat(S"Last Write Time = ", (pFileProps->get_LastWriteTime()).ToString()));
listBox1->Items->Add(String::Concat(S"Size = ", (pFileProps->get_Length()).ToString()));


//
// This demonstrates how to obtain a list of disk drives.
listBox1->Items->Clear();
String* drives[] = Directory::GetLogicalDrives();
int numDrives = drives->get_Length();
for (int i = 0; i<numDrives; i++)
{
listBox1->Items->Add(drives[i]);
}


//// This code obtains a list of folders. This example uses the Windows folder.
listBox1->Items->Clear();
String* dirs[] = Directory::GetDirectories(windir);
int numDirs = dirs->get_Length();
for (int i = 0; i<numDirs; i++)
{
listBox1->Items->Add(dirs[i]);
}


//
// This code obtains a list of files. This example uses the Windows folder.
listBox1->Items->Clear();
String* files[] = Directory::GetFiles(this->windir);
int numFiles = files->get_Length();
for (int i = 0; i<numFiles; i++)
{
listBox1->Items->Add(files[i]);
}


//


*/