// Paxton Scott
// This program calculates the employee's Annual Evaluation Report.

#include <iostream>

using namespace std;

int main()

{
    string employee_name,supervisor_name,ID;
    double fall,spring,summer,fw_eval;




    cout<<"What is the name of the employee?";

    cin>>employee_name;


    cout<<"What is the name of the supervisor?";

    cin>>supervisor_name;


    cout<<"What is the employee's ID #?";

    cin>>ID;


    cout<<"What is the employee's evaluation score for the fall?";

    cin>>fall;


    cout<<"What is the employee's evaluation score for the spring?";

    cin>>spring;


    cout<<"What is the employee's evaluation score for the summer?";

    cin>>summer;

    // Calculate the final weighted evaluation score

    fw_eval = fall*0.36 + spring*0.38 + summer*0.26;

	// Display semester + final evaluations,employee name
	// Display supervisor name, employee ID #,  Disclaimer note

	cout <<"Annual Employee Evaluation Report"<< " \n"

	    <<"Name of the Employee:"<<employee_name<<  " \n"
	    <<"Name of the Supervisor:"<<supervisor_name<<" \n"
	    <<"Employee ID#:"<<ID<< " \n"
	    <<"Fall Semester Evaluation:"<<fall<< " \n"
	    <<"Spring Semester Evaluation:"<<spring<< " \n"
	    <<"Summer Semester Evaluation:"<<summer<< " \n"
	    <<"Final Weighted Evaluation:"<<fw_eval<< " \n"
	    <<"Note:This report for" " "<<employee_name<< " " <<"was prepared according to the fair practice of the state."<< " \n"
	    <<"Any discrepancies must be reported by "<<employee_name<<" " "to the supervisor," " "<<supervisor_name<<"."<<



	 endl;




	return 0;
}
