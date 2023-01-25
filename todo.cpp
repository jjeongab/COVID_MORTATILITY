//submit this file ONLY
//if you need to write your own helper functions, write the functions in this file
//again, do NOT include additional libraries and make sure this todo.cpp can be compiled with the unmodified versions of the other given files in our official compilation environment

#include "given.h"
#include "todo.h"


int getDateCount(char* headerLine)
{
	int count = 0;
	int slash = 0;
	int j = 0;

	for(char* p = headerLine; *(p + j) != '\0'; ++j)
	{

		if(*(p + j) == '/')
		{
			slash++;
			if(slash % 2 == 0)
			{
				count++;
			}
		}


	}


	return count - 1;
}
char** getDates(char *headerLine)
{
	int count = 39;
	int count2 = 39;
	int size = 0;
	char **p = new char*[getDateCount(headerLine)];
	for(int i = 0; i < getDateCount(headerLine); i++)
	{

		while(headerLine[count] != ',' && &headerLine[count] != '\0')
		{
			size++;
			count++;

		}
		p[i] = new char[size + 1];
		for(int k = 0; k <= size; ++k)
		{
			if(k != size)
			{
				p[i][k] = headerLine[count2];
				count2++;
			}
			else if(k == size )
			{
				p[i][k] = '\0';
			}

		}
		count2++;
		size = 0;
		count++;


	}
	return p;


}
int getDay(char** dates, int dateCount, const char* date)
{
	char* day;
	int k;
	for(int i = 0; i < dateCount; i++)
	{
		char* day = new char [1000];
		for(int j = 0; dates[i][j] != '\0'; j++) //create letters;
		{
			day[j] = dates[i][j];
			k = j + 1;
		}
		day[k] = '\0';
		for(int q = 0; q < k; q++) // check if similar letters
		{
			if(day[q] == date[q]) // if same character
			{
				if(q == k -1) // if q is the final letter
				{
					return i + 1;
				}
				else // q is not final letter
				{
					continue;
				}
			}
			else // if having different character, break the loop
			{
				break;
			}
		}
		if(i != dateCount -1 ) // check if end of the dynamic array
		{
			continue;
		}
		else  // not end of the dynamic array but does not have any similarity
		{
			return 0;
		}



	}

}
Place* getPlaces(char** csvLines, int csvLineCount)
{
	Place* q = new Place[csvLineCount];

	char* pt;
	Node* x;
	int j; // starter for country
	int num; // starter for numbers
	int days = 0; // insert days for node
 // insert numbers
	int index = 0; // index of pt for inserting days and nunmbers
	for(int i = 1; i < csvLineCount; i++) // from row to row , i = row
	{
		int comma = 0;
		if(comma == 0) // region
		{
			for(int k = 0; csvLines[i][k] != ','; ++k)
			{
				if(k == 0 && csvLines[i][k] == ',')
				{
					pt = '\0';
					j = k + 1;
					break;
				}
				pt[k] = csvLines[i][k];
				if(csvLines[i][k + 1] == ',')
				{
					pt[k + 1] = '\0';
					j = k + 2;
					comma++;
				}

			}
			q[i - 1].province = pt;

		}
		if(comma == 1) // country
		{
			for(int k = j; csvLines[i][k] != ','; ++k)
			{
				pt[k] = csvLines[i][k];
				if(csvLines[i][k + 1] == ',')
				{
					pt[k + 1] = '\0';
					num = k + 2;
					comma++;
				}


			}
			q[i - 1].region = pt;

		}
		Node* head = nullptr;
		head = x;
		if(comma > 1) // days
		{

			for(int k = num; csvLines[i][k] != '\0'; k++) // go through all the characters in  a row
			{

				if(csvLines[i][k] != ',')
				{
					pt[index] = csvLines[i][k];
					index++;
				}
				if(csvLines[i][k] == ',')
				{


					if(atoi(pt)!= 0)
					{
						x = new Node;
						x->day = days;
						x->number = atoi(pt);
						x->next = nullptr;
						days++;
						index = 0;

					}
					else
					{
						k = k + 2;
						continue;
					}
				}


			}
		}
		q[i - 1].headNode = x;

	}
	return q;


}

