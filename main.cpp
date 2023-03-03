#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int matrix1[4][4] = { 1, 0, 3, 2, 3, 2, 1, 0, 0, 2, 1, 3, 3, 1, 3, 2 };
int matrix2[4][4] = { 0, 1, 2, 3, 2, 0, 1, 3, 3, 0, 1, 0, 2, 1, 0, 3 };
struct Keys 
{
	string key1;
	string key2;
};

struct index
{
	int row;
	int col;
};

string populateLeftKey(string key)
{
	string tempKey;
	for (int i = 0; i < key.length() / 2; i++)
	{
		tempKey += key[i];
	}
	return tempKey;
}

string populateRightKey(string key)
{
	string tempKey;
	for (int i = key.length() / 2; i < key.length(); i++)
	{
		tempKey += key[i];
	}
	return tempKey;
}

string P10(string key)
{
	string keyTemp = key;
	key[6] = keyTemp[0];
	key[2] = keyTemp[1];
	key[0] = keyTemp[2];
	key[4] = keyTemp[3];
	key[1] = keyTemp[4];
	key[9] = keyTemp[5];
	key[3] = keyTemp[6];
	key[8] = keyTemp[7];
	key[7] = keyTemp[8];
	key[5] = keyTemp[9];
	return key;
}
string LS_1(string key)
{
	char temp = key[0];
	int j = 0;
	for (int i = 0; i < key.length() - 1; i++)
	{
		key[i] = key[i + 1];
	}
	key[key.length() - 1] = temp;
	return key;
}
 
string LS_2(string key)
{
	char temp1 = key[0];
	char temp2 = key[1];
	for (int i = 0; i < key.length() - 2; i++)
	{
		key[i] = key[i + 2];
	}
	key[key.length() - 2] = temp1;
	key[key.length() - 1] = temp2;
	return key;
}
string P8(string key)
{
	string tempKey;
	tempKey += key[5];
	tempKey += key[2];
	tempKey += key[6];
	tempKey += key[3];
	tempKey += key[7];
	tempKey += key[4];
	tempKey += key[9];
	tempKey += key[8];
	return tempKey;
}

string IP(string key) 
{
	string tempKey;
	tempKey += key[1];
	tempKey += key[5];
	tempKey += key[2];
	tempKey += key[0];
	tempKey += key[3];
	tempKey += key[7];
	tempKey += key[4];
	tempKey += key[6];
	return tempKey;
}

string IP_1(string key)
{
	string tempKey;
	tempKey += key[3];
	tempKey += key[0];
	tempKey += key[2];
	tempKey += key[4];
	tempKey += key[6];
	tempKey += key[1];
	tempKey += key[7];
	tempKey += key[5];
	return tempKey;
}

string EP(string key)
{
	string tempKey;
	tempKey += key[3];
	tempKey += key[0];
	tempKey += key[1];
	tempKey += key[2];
	tempKey += key[1];
	tempKey += key[2];
	tempKey += key[3];
	tempKey += key[0];
	return tempKey;
}

string P4(string key)
{
	string tempKey;
	tempKey += key[1];
	tempKey += key[3];
	tempKey += key[2];
	tempKey += key[0];
	return tempKey;
}

Keys keyGeneration(string key)
{
	Keys k;
	key = P10(key);
	string leftKey = populateLeftKey(key);
	string rightKey = populateRightKey(key);
	leftKey = LS_1(leftKey);
	rightKey = LS_1(rightKey);
	k.key1 = leftKey + rightKey;
	k.key1 = P8(k.key1);
	leftKey = LS_2(leftKey);
	rightKey = LS_2(rightKey);
	k.key2 = leftKey + rightKey;
	k.key2 = P8(k.key2);
	return k;
}

string XOR(string key1, string key2)
{
	if (key1.length() != key2.length())
	{
		cout << "Both keys must have same number of bits " << endl;
		exit(0);
	}
	int length = key1.length();
	string tempKey;
	for (int i = 0; i < length; i++)
	{
		if (key1[i] == key2[i])
		{
			tempKey += '0';
		}
		else
		{
			tempKey += '1';
		}
	}
	return tempKey;
}

index convertIntoDecimal(string binary)
{
	index m;
	int tempNum;
	if (binary[3] == '0')
	{
		tempNum = 0;
	}
	else
	{
		tempNum = 1;
	}
	if (binary[0] == '0')
	{
		tempNum = tempNum + 0;
	}
	else
	{
		tempNum = tempNum + 2;
	}
	m.row = tempNum;
	if (binary[2] == '0')
	{
		tempNum = 0;
	}
	else
	{
		tempNum = 1;
	}
	if (binary[1] == '0')
	{
		tempNum = tempNum + 0;
	}
	else
	{
		tempNum = tempNum + 2;
	}
	m.col = tempNum;
	return m;

}

string convertIntoBinary(int val)
{
	if (val == 0)
	{
		return "00";
	}
	if (val == 1)
	{
		return "01";
	}
	if (val == 2)
	{
		return "10";
	}
	if (val == 3)
	{
		return "11";
	}
}

string functionk2(Keys k, string key)
{
	string leftKey = populateLeftKey(key);
	string rightKey = populateRightKey(key);
	string dataAfterEP = EP(rightKey);
	string dataAfterXOR_rightKey = XOR(k.key2, dataAfterEP);
	string matrix1Value = populateLeftKey(dataAfterXOR_rightKey);
	string matrix2Value = populateRightKey(dataAfterXOR_rightKey);
	index indexMatrix1 = convertIntoDecimal(matrix1Value);
	index indexMatrix2 = convertIntoDecimal(matrix2Value);
	int valueMatrix1 = matrix1[indexMatrix1.row][indexMatrix1.col];
	int valueMatrix2 = matrix2[indexMatrix2.row][indexMatrix2.col];
	string binaryValueFromMatrix1 = convertIntoBinary(valueMatrix1);
	string binaryValueFromMatrix2 = convertIntoBinary(valueMatrix2);
	string dataAfterMatrixManipulation = binaryValueFromMatrix1 + binaryValueFromMatrix2;
	string dataAfterP4 = P4(dataAfterMatrixManipulation);
	string dataAfterXOR_leftKey = XOR(leftKey, dataAfterP4);
	string overallData = dataAfterXOR_leftKey + rightKey;
	return IP_1(overallData);
}

string mySwitch(string leftKey, string rightKey, string dataAfterXOR_leftKey)
{
	leftKey = rightKey;
	rightKey = dataAfterXOR_leftKey;
	return leftKey + rightKey;
}

string functionk1(Keys k, string key)
{
	string leftKey = populateLeftKey(key);
	string rightKey = populateRightKey(key);
	string dataAfterEP = EP(rightKey);
	string dataAfterXOR_rightKey = XOR(k.key1, dataAfterEP);	
	string matrix1Value = populateLeftKey(dataAfterXOR_rightKey);
	string matrix2Value = populateRightKey(dataAfterXOR_rightKey);
	index indexMatrix1 = convertIntoDecimal(matrix1Value);
	index indexMatrix2 = convertIntoDecimal(matrix2Value);
	int valueMatrix1 = matrix1[indexMatrix1.row][indexMatrix1.col];
	int valueMatrix2 = matrix2[indexMatrix2.row][indexMatrix2.col];
	string binaryValueFromMatrix1 = convertIntoBinary(valueMatrix1);
	string binaryValueFromMatrix2 = convertIntoBinary(valueMatrix2);
	string dataAfterMatrixManipulation = binaryValueFromMatrix1 + binaryValueFromMatrix2;
	string dataAfterP4 = P4(dataAfterMatrixManipulation);
	string dataAfterXOR_leftKey = XOR(leftKey, dataAfterP4);
	string overallData = dataAfterXOR_leftKey + rightKey;
	key = mySwitch(leftKey, rightKey, dataAfterXOR_leftKey);
	return functionk2(k, key);
}

string cipherTextGenerator(string plainText, Keys k)
{
	string ip = IP(plainText);
	return functionk1(k, ip);

}
int main()
{
	bool keyStatus = true;
	string key = "";
	cout << "Enter 10-bit key: ";
	cin >> key;
	while (key.length() != 10)
	{
		cout << "Error! key must be 10 bit, Enter key again: ";
		cin >> key;
	}
	for (int i = 0; i < 10 && keyStatus == true; i++)
	{
		if (key[i] == '0' || key[i] == '1')
		{
			keyStatus = true;
		}
		else
		{
			cout << "key can only contain 0s and 1s! Enter the value of key again: ";
			cin >> key;
			keyStatus = true;
			i = 0;
		}
	}
	Keys k = keyGeneration(key);
	int sizeOfplainText = 8;
	string plainText;
	cout << "Enter plain text: ";
	cin >> plainText;

	bool statusPlainText = true;
	for (int i = 0; i < plainText.length() && statusPlainText == true; i++)
	{
		if (plainText[i] == '0' || plainText[i] == '1')
		{
			statusPlainText = true;
		}
		else
		{
			cout << "Plain text can only contain 0s and 1s! Enter the value of plain text again: ";
			cin >> plainText;
			statusPlainText = true;
			i = 0;
		}
	}
	int numberOfPlainText = plainText.length() / sizeOfplainText;
	int bitsRequired = (plainText.length() % sizeOfplainText);
	
	if (bitsRequired != 0)
	{
		bitsRequired = sizeOfplainText - bitsRequired;
		numberOfPlainText++;
	}
	string temp;
	while (bitsRequired != 0)
	{
		temp += '0';
		bitsRequired--;
	}
	temp += plainText;
	plainText = temp;
	temp = "";
	for (int j = 0; j < plainText.length(); j++)
	{
		temp += plainText[j];
		if (j % (sizeOfplainText - 1) == 0 && j != 0)
		{
			cout << cipherTextGenerator(temp, k) << endl;
			temp = "";
		}
	}
	return 0;
}