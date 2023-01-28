
};

string populateLeftKey(string key)
{
	string tempKey;
	for (int i = 0; i < key.length() / 2; i++)
	{
		tempKey += key[i];
	}