#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n_course, credit_hours, total_credit_hours=0;
	float total_grade_points=0.0;
	string grade;
	cout << "Enter number of courses = ";
	cin >> n_course;
	for (int i = 0; i < n_course; i++)
	{
		cout << "Enter credit hours for course " << i + 1<<"= ";
		cin >> credit_hours;
		total_credit_hours += credit_hours;
		cout << "Enter Grade of course " << i + 1 << "= ";
		cin >> grade;
		if (grade == "A" || grade == "A+")
		{
			total_grade_points = total_grade_points + (4.0 * credit_hours);
		}
		else if (grade == "A-")
		{
			total_grade_points = total_grade_points + (3.7 * credit_hours);
		}
		else if (grade == "B+")
		{
			total_grade_points = total_grade_points + (3.3 * credit_hours);
		}
		else if (grade == "B")
		{
			total_grade_points = total_grade_points + (3.0 * credit_hours);
		}
		else if (grade == "B-")
		{
			total_grade_points = total_grade_points + (2.7 * credit_hours);
		}
		else if (grade == "C+")
		{
			total_grade_points = total_grade_points + (2.3 * credit_hours);
		}
		else if (grade == "C")
		{
			total_grade_points = total_grade_points + (2.0 * credit_hours);
		}
		else if (grade == "C-")
		{
			total_grade_points = total_grade_points + (1.7 * credit_hours);
		}
		else if (grade == "D+")
		{
			total_grade_points = total_grade_points + (1.3 * credit_hours);
		}
		else if (grade == "D")
		{
			total_grade_points = total_grade_points + (1.0 * credit_hours);
		}
		else if (grade == "D-")
		{
			total_grade_points = total_grade_points + (0.7 * credit_hours);
		}
		else
		{
			total_grade_points = total_grade_points + (0 * credit_hours);
		}
	}
	float GPA = (total_grade_points / total_credit_hours);
	float previous_CGPA, CGPA;
	int sem;
	cout << "Enter semester number = ";
	cin >> sem;
	cout << "Enter previous CGPA = ";
	cin >> previous_CGPA;
	CGPA = ((previous_CGPA * sem - 1) + GPA) / sem;
	cout << "CGPA = " << CGPA;
	return 0;
}