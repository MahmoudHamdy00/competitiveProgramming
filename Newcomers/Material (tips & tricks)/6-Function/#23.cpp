/*
 * ICPC Assuit Community - Newcomers (Function)
 * Source: https://cutt.ly/SffEVgE
 * Problem Statement :Write a program that will ask the user to enter his/her marks (out of 100). Define a function that will display grades according to the marks entered as below:
 *						Marks			Grade
 * 						(90:100]		AA
 *						(80:90]			AB
 * 						(70:80]			BB
 *						(60:70]			BC
 *  					(50:60]			CD
 * 						(40:50]			DD
 * 						 [0:40]			Fail
 *
 */

#include <iostream>
using namespace std;
string display_grade(double mark) {
	if (mark > 90.0 && mark <= 100.0)
		return "AA";
	if (mark > 80.0)
		return "AB";
	if (mark > 70.0)
		return "BB";
	if (mark > 60.0)
		return "BC";
	if (mark > 50.0)
		return "CD";
	if (mark > 40.0)
		return "DD";
	return "Fail";
}
int main() {
	double mark;
	cin >> mark;

	cout << display_grade(mark);
	return 0;
}
