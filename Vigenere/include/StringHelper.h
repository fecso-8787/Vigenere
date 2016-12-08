#pragma once

class String
{
public:
	String();
	String(const char* input);
	~String();
	const unsigned int getLenght() const;
	String toUpper()const;
	void RemoveAccents();
	const char* c_str()const;
	String getAcceptableString() const;
	char& operator[] (int x);
private:
	char* m_charArray;
	unsigned int m_length;
	static bool isAcceptedCharacter(const char input);

};