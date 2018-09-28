//**************************************************************************
// The program calculates the annual evaluation report of employees
// based on semester evaluations. Also, the program computes a final weighted
// evaluation based on weight given for the individual semesters. Finally,
// the program determines the raise given to an employee by their average
//  weighted evaluation.
//**************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

int main()
{
  // Define Variables and Constants
   const float FWEIGHT = 0.39;
   const float SPWEIGHT = 0.37;
   const float SUWEIGHT = 0.24;
   int n, counter;
   string employee_name,supervisor_name,address,number,employeeid,letter;
   float spe2013,sse2013,fse2013,spe2014,sse2014,fse2014,spe2015,sse2015,fse2015; // all semester variables
   float grade1,grade2,grade3,
   fwe2013,fwe2014,fwe2015,totalfwe,afwe, // final weighted evaluation variables
   salary,raisepercent,raisedollars,salaryraise;



    //Open Input File
    ifstream fin;

	fin.open("input.txt");

    //Open Output File
    ofstream fout;

    fout.open("output.txt");


        cout <<"How many employees are there? \n";
        cin >> n ;

        //Validate The number of employees

     while (n!=3)
    {
        cout <<"Thats the wrong amount of employees";
        cin >> n;

    }

        for (counter = 0; counter < 3; counter++)
        {

        // Get the employee's name

        getline(fin,employee_name);

        if (employee_name.length()>(100) || employee_name.length() <(1))
        {
            cout << "Employee's name not valid";
            continue;
        }

        // Get the supervisor's name

        getline(fin,supervisor_name);

         if (supervisor_name.length()>(100) || supervisor_name.length() <(1))
        {
            cout << "Supervisor's name not valid";
            continue;
        }


        // Get the employee's ID #

        getline(fin,employeeid);

         if (employeeid.length()>(100) || employeeid.length() <(1))
        {
            cout << "Employee's ID # not valid";
            continue;
        }


        //Get the phone number

        getline (fin,number);

         if (number.length()>(100) || number.length() <(1))
        {
            cout << "Employee's phone number not valid";
            continue;
        }


        // Get the address

        getline(fin,address);
         if (address.length()>(100) || address.length() <(1))
        {
            cout << "address not valid";
            continue;
        }


        // Get the employees semester scores and salary

       fin >> spe2013;

       fin >> sse2013;

       fin >> fse2013;

       fin >> spe2014;

       fin >> sse2014;

       fin >> fse2014;

       fin >> spe2015;

       fin >> sse2015;

       fin >> fse2015;

       fin >> salary;

       fin.ignore();

        // Calculate the final weighted evaluations, average final weighted evaluation,and total final weighted evaluation

        fwe2013 = spe2013*SPWEIGHT + sse2013*SUWEIGHT + fse2013*FWEIGHT;
        fwe2014 = spe2014*SPWEIGHT + sse2014*SUWEIGHT + fse2014*FWEIGHT;
        fwe2015 = spe2015*SPWEIGHT + sse2015*SUWEIGHT + fse2015*FWEIGHT;
        totalfwe = fwe2013 + fwe2014 + fwe2015;
        afwe = totalfwe / 3;




    // Create if statements to determine the "raisepercent" variable

    if (afwe <75)
    {
        raisepercent = 0;
    }
    else if (afwe >75 && afwe <=80)
    {
        raisepercent = 1;

    }

    else if (afwe >80 && afwe <=90)
    {
        raisepercent = 3;
    }
   else if (afwe > 90 && afwe <= 100)
    {
     raisepercent = 5;
    }

    else if (afwe > 100)
    {
        raisepercent = 10;
    }


    else
    {
        raisepercent =0;
    }

    // Create if statements to determine the "letter" variable

    if (afwe < 70)
    {
        letter = " Based on your evaluation you might be at risk for losing privileges at this University.";
    }

    else if (afwe >= 95 )
    {
        letter = "Congrats you have a high evaluation!";

    }

    else
    {
    letter = "";
    }

    // Determine "raisedollars" and salaryraise variables

     raisedollars = salary * (raisepercent/100);
     salaryraise = raisedollars + salary;

    // Write Output to File

        fout<<"Texas State University, San Marcos"<< " \n"
	    <<"Annual Employee Evaluation Report From January 1,2013 to December 31,2015"<< " \n\n"

	    <<"Name of the Employee: \t\t\t"<<employee_name<<  " \n"
	    <<"Name of the Supervisor:\t\t\t"<<supervisor_name<<" \n"
	    <<"Employee ID#:\t\t\t\t"<<employeeid<< " \n"
	    <<"Telephone Number:\t\t\t"<<number<<" \n"
	    <<"Address:\t\t\t\t "<<address<<"\n"<<fixed;

            for (int year = 2013; year < 2015; year++)
            {


	    fout<<"Spring Semester Evaluation,"<<year<<":"<<setw(14)<<setprecision(2)<<spe2013<< " \n"
	    <<"Summer Semester Evaluation,"<<year<<":"<<setw(14)<<setprecision(2)<<sse2013<< " \n"
	    <<"Fall Semester Evaluation,"<<year<<":"<<setw(16)<<setprecision(2)<<fse2013<< " \n";


        fout <<"Spring Semester Evaluation,"<<year<<":"<<setw(14)<<setprecision(2)<<spe2014<< " \n"
	    <<"Summer Semester Evaluation,"<<year<<":"<<setw(14)<<setprecision(2)<<sse2014<< " \n"
	    <<"Fall Semester Evaluation,"<<year<<":"<<setw(16)<<setprecision(2)<<fse2014<< " \n";



        fout <<"Spring Semester Evaluation,"<<year<<":"<<setw(14)<<setprecision(2)<<spe2015<< " \n"
	   <<"Summer Semester Evaluation,"<<year<<":"<<setw(14)<<setprecision(2)<<sse2015<< " \n"
	    <<"Fall Semester Evaluation,"<<year<<":"<<setw(16)<<setprecision(2)<<fse2015<< " \n"

	    <<"Final Weighted Evaluation,"<<year<<":"<<setw(15)<<setprecision(2)<<fwe2013<< " \n"
	    <<"Final Weighted Evaluation,"<<year<<":"<<setw(15)<<setprecision(2)<<fwe2014<< " \n"
	    <<"Final Weighted Evaluation,"<<year<<":"<<setw(15)<<setprecision(2)<<fwe2015<< " \n"
	    <<"Total Final Weighted Evaluation:"<<setw(15)<<setprecision(2)<<totalfwe<< " \n"
	    <<"Average Final Weighted Evaluation:"<<setw(12)<<setprecision(2)<<afwe<< " \n"

	    <<"Salary Raise in %: " <<setw(26)<<setprecision(2)<< raisepercent<<"%"<< "\n"
	    <<"Salary Raise in Dollars:" <<setw(18)<<setprecision(2)<< "$"<< raisedollars<< "\n"
	    <<"Salary in Dollars with the raise:" <<setw(9)<<setprecision(2)<<"$"<< salaryraise<< "\n\n"
        <<"Note:This report for "<<employee_name<< " was prepared according to the fair practice of the University.\n"
	    <<"Any discrepancies must be reported by "<<employee_name<<" " "to the supervisor," " "<<supervisor_name<<".\n"
	    <<letter<<"\n"<< endl;
    break;
            }

    }

   //Closing the files
        fin.close();
       fout.close();



cout << "Successfully printed to output file"<<endl;

return 0;
}
