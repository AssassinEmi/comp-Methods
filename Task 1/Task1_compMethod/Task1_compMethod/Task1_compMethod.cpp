// Tasx1_compMethod.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	const char planets[5] = { 'A', 'B', 'G', 'D', 'E' };
	char route[5] = { ' ', ' ', ' ', ' ', ' ' };
	const int distanceMatrix[5][5] = {
		{0,10,15,12,20},
		{10,0,12,25,14},
		{15,12,0,16,28},
		{12,25,16,0,17},
		{20,14,28,17,0}
	};
	int cheapestCost = INT_MAX;
	char cheapestRoute[5] = { ' ', ' ', ' ', ' ', ' ' };
	const int weights[5] = {20,40,70,10,30};
	const int fuelCost = 25;

	
	for(int i = 0; i < 5; i++){
		route[0] = planets[i];

		for(int j = 0; j < 5; j++){
			if (j == i) continue;
			route[1] = planets[j];
			distanceMatrix[i][j];
			int weight1 = weights[i];
			int Cost1 = fuelCost* distanceMatrix[i][j] * weight1;

			for (int x = 0; x < 5; x++){
				if (x == i || x == j) continue;
				route[2] = planets[x];
				distanceMatrix[j][x];
				int weight2 = weights[j];
				int Cost2 = distanceMatrix[j][x] * (weight1+weight2) * fuelCost;

				for (int l = 0; l < 5; l++){
					if (l == i || l == j || l == x) continue;
					route[3] = planets[l];
					distanceMatrix[x][l];
					int weight3 = weights[x];
					int Cost3 = distanceMatrix[x][l] * (weight1 + weight2 + weight3) * fuelCost;


					for (int m = 0; m < 5; m++){
						if (m == i || m == j || m == x || m == l) continue;
						route[4] = planets[m];
						cout << route[0] << route[1] << route[2] << route[3] << route[4]<< '\n';
						distanceMatrix[l][m];
						int weight4 = weights[l];
						int Cost4 = distanceMatrix[l][m] * (weight1 + weight2 + weight3 + weight4) * fuelCost;
						int totalCost = Cost1 + Cost2 + Cost3 + Cost4;
						//cout << "Total Cost : " << totalCost << '\n';
						if (totalCost < cheapestCost){
							cheapestCost = totalCost;
							for (int n = 0; n < 5; n++){
								cheapestRoute[n] = route[n];
							}
							cheapestCost = min(totalCost, cheapestCost);
						}

					}
				}
			}
			
		}
	}
	cout << '\n\n' << "Cheapest Route : " << cheapestRoute[0] << cheapestRoute[1] << cheapestRoute[2] << cheapestRoute[3] << cheapestRoute[4] << '\n'
		<< "Cheapest Cost : " << cheapestCost << '\n';


    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
