#include<iostream>

#include<iomanip>

#include<fstream>

using namespace std;

#define PLAYERS 10// define the amount of player
#define games 5
bool GetBowlingData(char name[][100], int score[][games], int& n)
{

	ifstream in("BowlingScoresMod.txt");//opening and reading file

	if (!in.fail()) {

		while (!in.eof()) {

			in >> name[n] >> score[n][0] >> score[n][1] >> score[n][2] >> score[n][3] >> score[n][4];//takes in the scores and names

			n++;

		}

		return true;

	}

	return false;

}

void GetAverageScore(int score[][games], double avg_scores[], int n)
{

	for (int i = 0; i < n; i++) //first part of array
	{

		avg_scores[i] = 0;

		for (int j = 0; j < games; j++)
		{//second part of array

			avg_scores[i] += score[i][j];

		}

		avg_scores[i] /= games;

	}

}

void PrettyPrintResults(char name[][100], int score[][games], double avg_scores[], int n)
{

	cout << left << setw(15) << "Name" << "Score1\tScore2\tScore3\tScore4\tScore5\tAvg_Score" << endl;// get the headers set up 

	for (int i = 0; i < n; i++)
	{

		cout << left << setw(15) << name[i] << "\t";//prints names

		for (int j = 0; j < games; j++)

			cout << score[i][j] << "\t";//print score

		cout << avg_scores[i] << endl;//prints average

	}

}

int main() {

	char name[PLAYERS][100];

	int score[PLAYERS][games];

	double avg_scores[PLAYERS];

	int n = 0;

	if (GetBowlingData(name, score, n)) {

		GetAverageScore(score, avg_scores, n);

		PrettyPrintResults(name, score, avg_scores, n);

	}

	return 0;

}

