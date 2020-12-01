#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct triplet
{
	string key;
	string value;
	bool end;

	void Set(string key, string value, bool end)
	{
		this->key = key;
		this->value = value;
		this->end = end;
	}

	string Get_key() { return key; }

	string Get_value() { return value; }

	bool Get_end() { return end; }

	int Get_key_size() { return key.size(); }
};
int i = -1;
triplet search_rules(triplet answer[], string str)
{
	triplet creating;
	string str_sub1, str_sub2;
	i++;

	if (str.find("->.") != string::npos)
	{
		str_sub1 = str.substr(0, str.find("->."));
		str_sub2 = str.substr((str.find("->.") + 3), str.size());
		creating.Set(str_sub1, str_sub2, true);
		answer[i] = creating;
		return *answer;

	}
	if (str.find("->") != string::npos)
	{

		str_sub1 = str.substr(0, str.find("->"));
		str_sub2 = str.substr((str.find("->") + 2), str.size());
		creating.Set(str_sub1, str_sub2, false);
		answer[i] = creating;
		return *answer;
	}

}
void transformation(string str, triplet rules[])
{
	int length = i;
	string str_sub1, str_sub2;
	for (int i = 0; i < length; ++i) {
		if (str.find(rules[i].Get_key()) != string::npos)
		{

			str_sub1 = str.substr(0, str.find(rules[i].Get_key()));
			str_sub2 = str.substr((str.find(rules[i].Get_key()) + rules[i].Get_key_size()), str.size());
			str = str_sub1 + rules[i].Get_value() + str_sub2;
			cout << str << '\n';
			if (rules[i].Get_end() == true) return;
			i = -1;
			continue;
		}
	}
	return;
}
int main()
{
	ifstream file;
	file.open("C:\\test.txt");
	triplet* rules = new triplet[100];
	string buf, str;

	getline(file, str);
	while (!file.eof())
	{
		buf = "";
		getline(file, buf);
		*rules = search_rules(rules, buf);
	}
	cout << str << endl;

	transformation(str, rules);
}