//do NOT modify this file
//do NOT submit this file

#include "given.h"
#include "todo.h"

//feel free to make your own test cases
//testing your own software is an essential software development skill
int main()
{
    cout << "Hi COVID-19 Outbreak Data Analyst!" << endl << endl;
    cout << "=======================================================" << endl;
    int csvLineCount;
    const char* csvFileName = "time_series_covid19_confirmed_global.csv";
    // csvFileName = "test.csv"; //uncomment this to read the other file "test.csv"
    cout << "Reading the CSV file..." << endl;
    char** csvLines = readCSV(csvFileName, csvLineCount);
    if(csvLines == nullptr)
    {
        cout << "Cannot open the file " << csvFileName << "." << endl;
        cout << "For Windows Eclipse, put the csv file under the same folder as your source files." << endl;
        cout << "For other IDEs/OSes, look online and figure out where the input file should be put." << endl;
        return 0;
    }
    cout << "Loaded " << csvLineCount << " lines from " << csvFileName << endl;
    char* csvHeaderLine = csvLines[0];

    cout << "=======================================================" << endl;
    cout << "To warm up, trying getDateCount, getDates, and getDay..." << endl << endl;
    int dateCount = getDateCount(csvHeaderLine);
    cout << "dateCount = " << dateCount << endl;
    cout << endl;
    char** dates = getDates(csvHeaderLine);
    for(int i=0;i<dateCount;i++)
    	cout << "day " << i+1 << ": " << dates[i] << endl;
    cout << endl;
    cout << "Date 1/1/20 is Day " << getDay(dates, dateCount, "1/1/20") << endl;
    cout << "Date 1/22/20 is Day " << getDay(dates, dateCount, "1/22/20") << endl;
    cout << "Date 3/10/20 is Day " << getDay(dates, dateCount, "3/10/20") << endl;
    cout << "Date 3/30/20 is Day " << getDay(dates, dateCount, "3/30/20") << endl;
    cout << "Date 12/30/20 is Day " << getDay(dates, dateCount, "12/30/20") << endl;
    cout << "=======================================================" << endl;
    cout << "Performing getRegions..." << endl << endl;
    Place* regions = getPlaces(csvLines, csvLineCount);
    int regionCount = csvLineCount - 1;
    printPlaces(regions, 10);

}
