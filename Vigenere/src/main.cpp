#include <string>
#include <iostream>
#include "..\include/StringHelper.h"
#include "..\include/Encoder.h"

void writeOutputFile(const String outFile,const String output)
{
	FILE* file;

	fopen_s(&file, outFile.c_str(), "w");
	if (!file)
	{
		printf("Could not open file %s for writing.\n", outFile.c_str());
		return;
	}
	fprintf_s(file, "%s", output.c_str());
	fclose(file);
}

int main()
{
	system("chcp 1250");
	char line[255];

	gets_s(line, 255);

	auto toEncodeString = String(line).toUpper();
	toEncodeString.RemoveAccents();
	toEncodeString = toEncodeString.getAcceptableString();
	puts(toEncodeString.c_str());
	
	Encoder enc = Encoder("Resource\\vtabla.dat");
	enc.Init();
	gets_s(line, 5);
	enc.setKey(line);
	String result = enc.getEncodedString(toEncodeString);
	puts(result.c_str());
	writeOutputFile("kodolt.dat", result);
	getchar();

	return 0;
}