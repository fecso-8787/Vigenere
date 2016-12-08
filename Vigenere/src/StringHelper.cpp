#include "../include/StringHelper.h"

String::String()
{
	m_charArray =new char[1];
	m_charArray = "";
	m_length = 0;
}

String::String(const char * input)
{
	if (input)
	{
		m_length = 0;
		while(input[m_length] && (input[m_length]!='\0' && input[m_length] != '\n'))
		{
			m_length++;
		}
		m_length++;
		m_charArray = new char[m_length+1];
		bool noEnding = input[m_length] != '\0' && input[m_length] != '\n';
		for(unsigned int i=0;i<m_length+1;i++)
		{
			if (i==m_length && noEnding)
			{
				m_charArray[i] = '\0';
			}
			else
			{
				m_charArray[i] = input[i];
			}
			if(m_charArray[i]=='\n')
			{
				m_charArray[i] = '\0';
			}
		}
	}
	else
	{
		m_charArray = "";
		m_length = 0;
	}
}

String::~String()
{

}

const unsigned int String::getLenght() const
{
	return m_length;
}

String String::toUpper() const
{
	String result;
	char* newArray = new char[m_length];
	for(unsigned int i=0;i<m_length;i++)
	{
		if((m_charArray[i]>='a' && m_charArray[i] <= 'z')||(m_charArray[i] >= 'á' && m_charArray[i] <= 'ü'))
		{
			newArray[i] = m_charArray[i] - 32;
		}
		else
		{
			newArray[i] = m_charArray[i];
		}
	}
	result = String(newArray);
	delete[] newArray;
	return result;
}

void String::RemoveAccents()
{
	char accented[] = { 'á', 'é', 'í', 'ó', 'ö', 'õ', 'ú', 'ü', 'û',
		'Á', 'É', 'Í', 'Ó', 'Ö', 'Õ', 'Ú', 'Ü', 'Û' };

	char mask[] = {'a', 'e', 'i', 'o', 'o', 'o', 'u', 'u', 'u',
		'A', 'E', 'I', 'O', 'O', 'O', 'U', 'U', 'U' };

	for(unsigned int i=0;i<m_length;i++)
	{
		for(int j=0;j<18;j++)
		{
			if(accented[j]==m_charArray[i])
			{
				m_charArray[i] = mask[j];
			}
		}
	}
}

const char* String::c_str()const
{
	return m_charArray;
}

bool String::isAcceptedCharacter(const char input)
{
	return (input >= 'A' && input <= 'Z') || input=='\0';
}

String String::getAcceptableString()const
{
	int numCharsToRemove = 0;
	for(unsigned int i=0;i<m_length;i++)
	{
		if(!isAcceptedCharacter(m_charArray[i]))
		{
			numCharsToRemove++;
		}
	}
	char* newString = new char[m_length - numCharsToRemove];
	short index = 0;
	for (unsigned int i = 0; i < m_length; i++)
	{
		if (isAcceptedCharacter(m_charArray[i]))
		{
			newString[index] = m_charArray[i]; 
			index++;
		}
	}
	String result;
	result = String(newString);
	delete[] newString;
	return result;
}

char& String::operator[](int x)
{
	return m_charArray[x];
}
