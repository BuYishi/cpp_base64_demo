#include <iostream>
#include <fstream>
#include "Base64Encoder.h"
#include "Base64Decoder.h"
using namespace std;
void encodeDemo();
void decodeDemo();
int main()
{
	encodeDemo();
	decodeDemo();
	system("pause");
	return 0;
}
void encodeDemo()
{
	const char *text = "John Rambo";
	Base64Encoder encoder;
	const string &encodedText = encoder.encode(text);
	cout << encodedText << endl;
	string inputFilename("E:/Packages/Java/jdk-8u144-windows-x64.exe");
	ifstream ifs(inputFilename, ifstream::binary);
	if (ifs)
	{
		string encodedFilename(inputFilename + ".txt");
		ofstream ofs(encodedFilename, ofstream::binary);
		if (ofs)
		{
			streamsize numberOfBytesRead;
			int numberOfBytesEncoded;
			constexpr int inputBufferSize = 10 * 1024;
			char inputBuffer[inputBufferSize];
			char encodedBuffer[inputBufferSize * 2];
			while (!ifs.eof())
			{
				numberOfBytesRead = ifs.read(inputBuffer, inputBufferSize).gcount();
				numberOfBytesEncoded = encoder.encode(inputBuffer, numberOfBytesRead, encodedBuffer);
				ofs.write(encodedBuffer, numberOfBytesEncoded);
			}
			numberOfBytesEncoded = encoder.encodeEnd(encodedBuffer);
			ofs.write(encodedBuffer, numberOfBytesEncoded);
		}
		else
			cout << "Cannot open file: " << encodedFilename << endl;;
	}
	else
		cout << "Cannot open file: " << inputFilename << endl;
}
void decodeDemo()
{
	Base64Decoder decoder;
	const string &decodedText = decoder.decode("QWxsIGlzIHdlbGwh");
	cout << decodedText << endl;
	string filename("E:/Packages/Android/docs-24_r01.zip.txt");
	ifstream ifs(filename, ifstream::binary);
	if (ifs)
	{
		filename = "android_docoment";
		ofstream ofs(filename, ofstream::out | ofstream::binary);
		if (ofs)
		{
			streamsize numberOfBytesRead;
			int numberOfBytesDecoded;
			constexpr int bufferSize = 10 * 1024;
			char inputBuffer[bufferSize];
			char decodedBuffer[bufferSize];
			while (!ifs.eof())
			{
				numberOfBytesRead = ifs.read(inputBuffer, 1024).gcount();
				numberOfBytesDecoded = decoder.decode(inputBuffer, numberOfBytesRead, decodedBuffer);
				ofs.write(decodedBuffer, numberOfBytesDecoded);
			}
		}
		else
			cout << "Cannot open file: " << filename << endl;
	}
	else
		cout << "Cannot open file: " << filename << endl;
}