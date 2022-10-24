// mod6repairShopBill.cpp : This file contains the 'main' function.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//function prototypes
//function to calculate the costs of labor and parts; use pointers only for the parameters. This function will also print out the lines on the bill for the labor charge, parts charge, and the subtotal of those items.
void calculateCosts(double, double, double*, double*);
string dollarFormat(string);
string dollarFormat(double);
//function to calculate the shop fee and the tax, using pointers only for the parameters. This function will also print out the lines on the bill for the shop fee, tax, and total
void calculateTax(double, double, double*, double*);
double shopFee, hourlyLaborRate = 50.00, tax;
//labor charge, which is the number of hours of labor entered by the user charged at the rate of $50.00/hour
//shop fee, which is the total of the labor and parts charges times the shop fee rate of 5%
//tax, which is the total of the labor charge, parts charge, and shop fee, times the tax rate of 4%
//total, which is the sum of the labor charge, parts charge, shop fee, and tax
int main()
{
	cout << "Mod. 6 Repair Shop Bill\n\n";
	//Ask the user for the hours of labor and the cost of the parts
	cout << "Enter the hours of labor: ";
	double hoursOfLabor;
	cin >> hoursOfLabor;
	cout << "Enter the parts charge: ";
	double partsCharge;
	cin >> partsCharge;
	calculateCosts(hoursOfLabor, partsCharge, &shopFee, &tax);
	calculateTax(hoursOfLabor, partsCharge, &shopFee, &tax);
	system("pause");
	return 0;
} // end function main

//function to calculate the costs of labor and parts and use pointers only for the parameters. This function will also print out the lines on the bill for the labor charge, parts charge, and the subtotal of those items
void calculateCosts(double hoursOfLabor, double partsCharge, double* laborCharge, double* subtotal)
{
	//labor charge, which is the number of hours of labor entered by the user charged at the rate of $50.00/hour
	*laborCharge = hoursOfLabor * hourlyLaborRate;
	
	//subtotal, which is the sum of the labor charge, parts charge, and shop fee
	*subtotal = *laborCharge + partsCharge + shopFee;
	//total, which is the sum of the labor charge, parts charge, shop fee, and tax
	double total = *subtotal + tax;
	//print out the lines on the bill for the labor charge, parts charge, and the subtotal of those items
	cout << "Parts: " << dollarFormat(partsCharge) << endl;
	cout << "Labor: " << dollarFormat(*laborCharge) << endl;
	cout << "Subtotal: " << dollarFormat(*subtotal) << endl;
} // end function calculateCosts

//function to calculate the shop fee and the tax, using pointers only for the parameters. This function will also print out the lines on the bill for the shop fee, tax, and total
void calculateTax(double shopFeeRate, double taxRate, double* shopFee, double* tax)
{
	//shop fee, which is the total of the labor and parts charges times the shop fee rate of 5%
	*shopFee = shopFeeRate * 0.05;
	//tax, which is the total of the labor charge, parts charge, and shop fee, times the tax rate of 4%
	*tax = taxRate * 0.04;
	//total, which is the sum of the labor charge, parts charge, shop fee, and tax
	double total = *shopFee + *tax;
	//print out the lines on the bill for the shop fee, tax, and total
	cout << "Shop fee: " << dollarFormat(*shopFee) << endl;
	cout << "Tax: " << dollarFormat(*tax) << endl;
	cout << "Total: " << dollarFormat(total) << endl;
} // end function calculateTax

//**************************************************************
// Returns a $-formatted version of the input string.          *
//**************************************************************
string dollarFormat(string original)
{
	string formatted = original; // formatted string to return
	int decimalPos = formatted.find('.'); // position of decimal
	int pos = decimalPos; // position to insert commas

	while (pos > 3) // insert commas until pos is less than 3
	{
		pos -= 3; // move pos back 3 spaces
		formatted.insert(pos, ","); // insert comma
	} // end while loop
	formatted.insert(0, "$"); // insert dollar sign
	return formatted; // return formatted string
} // end dollarFormat


//**************************************************************
// Returns a $-formatted version of the input double.          *
//**************************************************************
string dollarFormat(double value) {

	//creat ostringstream oject
	ostringstream ostr;
	
	//set format flags
	ostr << fixed << setprecision(2);
	
	//insert value into stream
	ostr << value;
	
	//return formatted string
	return dollarFormat(ostr.str());
} // end dollarFormat