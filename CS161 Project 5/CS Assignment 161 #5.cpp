// Program : CS161 HW #5
// Name    : Brandan Tyler Lasley
// Date    : 10/26/2013 19:48
// Description: Uses mathmatics to find the average of data
// Sources : none

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <array>

using namespace std;

int main(){

	string filename;
	ifstream data;
	string result;
	int results[36] = {0, 0, 0, 0};
	double totalsSeen[2] = {0, 0};
	double totalsNotseen[2] = {0, 0};

	// Lazy way to set vars for echo.
	string echo;
	string echo1;
	string echo2;
	string echo3;
	string dummy;

	// Prompt & Open File
    cout << "Please, enter the full pathname to the data file on disk: " << endl;
    cin >> filename;
    data.open(filename);

	// Exit on I/O error
	 if (!data.is_open()) {
		 cout << "Failed to open file, press enter to exit";
		 getchar();
		 getchar();
		return 0x01;
	 }

	// Echo/print to screen
	cout << endl << left << setw(15) << "Name: " << setw(10) << "Seen AD?: " << setw(5) << "Age: " << setw(7) << "Score: " << endl;
	while (!data.eof()){
		data >> echo >> echo1 >> echo2 >> echo3;
		cout << left << setw(15) << echo << setw(10) << echo1 << setw(5) << echo2 << setw(7) << echo3 << endl;
	}

	// Refresh buffer line thing
	data.seekg(0);

	 // Read Data
	 int i = 0;
     while(!data.eof()) {
		data >> dummy>> result >> results[(i + 1)] >>  results[(i + 2)];

	   // Convert Y/N to INT
	   if (result == "Y") {
		   results[i] = 1;
	   } else {
		   results[i] = 0;
	   }
	   i = i + 3;
     }

	// Closing file, we dont need it anymore.
	 data.close();


	// Totals Array infomation

	// TotalsSeen
	// 0 = Subjects over 18, who have seen the ad.
	// 1 = Sbjects under 18, who have seen the ad.

	// TotalNotseen
	// 0 = Subjects over 18, who have NOT seen the ad.
	// 1 = Sbjects under 18, who have NOT seen the ad.
	 
	// Division (count) Array Infomation
	// 0 = Persons over 18, seen
	// 1 = Persons over 1 not seen
	// 2 = Under 18 seen
	// 3 = Under 18 not seen

	int count[4] = {0, 0, 0, 0};

	 // Totals Calculation
	 for ( i = 0; i <36;) {
		 if (results[ i + 1 ] > 18) {
			 if (results[ i ] == 1) {
				 totalsSeen[1] += (double)results[ i + 2];
				 count[0]++;
			 } else {
				 totalsNotseen[1] += (double)results[ i + 2];
				 count[1]++;
			}
		 }  else if (results[ i + 1 ] < 18) {
			 if (results[ i ] == 1) {
				 totalsSeen[0] += (double)results[ i + 2];
				 count[2]++;
			 } else {
				 totalsNotseen[0] += (double)results[ i + 2];
				 count[3]++;
			}
		 }
		 i = i + 3;
	 }

	// Calculate Average and output finals.
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Average Score for 18>, Seen Advert     :  " << (totalsSeen[1] / count[0]) << endl;
    cout << "Average Score for 18>, Not Seen Advert :  " << (totalsNotseen[1] / count[1]) << endl;
    cout << "Average Score for 18<, Seen Advert     :  " << (totalsSeen[0] / count[2]) << endl;
    cout << "Average Score for 18<, Not Seen Advert :  " << (totalsNotseen[0] / count[3]) << endl;

	// Calculate Total Average Score
	double total = 0; 
	for ( i = 0; i < 36;) { 
		total += results[i + 2];
		i = i + 3; 
	}
	// Output Global Average
	cout << "Average Global Score                   :  " << (total / 12) << endl;

	// Exit Footer
	getchar();
	getchar();
	return 0;
}
