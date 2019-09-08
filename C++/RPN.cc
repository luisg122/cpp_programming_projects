#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct NODE
{
       float num;
       NODE *next;
};

class stack
{
    private:
      NODE *head;

    public:
      stack();
      void push(float);
      float pop();
      int nElements();
      float display();
};

class RPN: public stack
{
    public:
      void add();
      void subtract();
      void multiply();
      void divide();
};


stack::stack()
{
     head = NULL;
}

void stack::push(float a_number)
{
     NODE *temp = new NODE;
     if (temp)
	 {
        temp->num = a_number;
        temp->next = head;
        head = temp;
     }
}

float stack::pop()
{
	float number = 0;


    if (!head)
      {
         return 0;
      }
      else
      {
           NODE *temp = head;
           number = head->num;
           head = temp->next;
           delete temp;
      }
      return number;
}

int stack::nElements()
{
    int counter=0;
    for (NODE *node = head; node; node=node->next)
    {
        counter++;
    }
    return counter;
}

float stack::display()
{

	

	 //ERROR CHECKING TOO MANY OPERANDS???       PRINTING TOO MANY OPERANDS FOR :   100 10 50 25 / * - -2 / =	, but still giving correct output && WILL NOT ALLOW ME TO DO A SECOND CALCULATAION , OUTPUT WILL BE TOO MANY OPERANDS

	   if(nElements() !=1)
	  {
		   cout << "Error: too many operands" << endl;
			return 1;
	  }

	   /*
		//   if( nElements() < 2 )
			{
				cout << "Error: too many operators" << endl;
				return 1;
			}
*/



			   else //(nElements() > 0)
			   {
				 float temp = pop();
				 cout << temp << endl;
				 push(temp);

				 return temp;

			   }
	 

      
}


void RPN::add()
{
     if (nElements()>=2)
     {
        push(pop() + pop());
     }
}

void RPN::subtract()
{
     if (nElements()>=2)
     {
        push(0 - pop() + pop());
     }
}

void RPN::multiply()
{
     if (nElements()>=2)
     {
        push(pop() * pop());
     }
}

void RPN::divide()
{
     if (nElements()>=2)
     {
		 //if(pop() * pop() == 0)
		// {
			 //cout << "Error: Divide by 0.\n";
		// }
		
			 push(1 / pop() * pop());	
     }


	 //else if( nElements()>=2)
		// {
    	//	 cout << "Error: Divide by 0.\n";						//??????
		 //}
		
}

//Function prototype for isOperator
bool isOperator(const string& input);

//Function prototype for perforOperation
int performOperation(const string& input, RPN& calculator);

int main(){

    RPN calculator;
    string input;
	
     float num;

    cout << "RPN Calculator: " << endl;
    cout << "Input\n";


    while(input != "0")
           {
               //Terminate program when 0 is entered by user
               while(true)
               {

               // get input
               cin >> input;

               // check for being numeric value

                   if(istringstream(input) >> num)
                   {
                       //use push function
                	   calculator.push(num);
                   }

                   // check for operator
                   else if(isOperator(input))
                   {
                       performOperation(input, calculator);
                   }

                   // If user enters 0 on a line followed by a new line, the program exits     ????????????
                   else if(input == "0\n")
                   {
                       return -1;
                   }


               }
               }
   }

bool isOperator(const string& input)
{
    static const string operators ="-+*/";
    if (input.length() == 1) // right size to be an operator.
    {
        return operators.find_first_of(input[0]) != string::npos;
        // look in the operator string for the first (and only) character in input
    }
    return false;
}



int performOperation(const string& input, RPN& calculator)
{
    //double firstOperand = 0;
    //double secondOperand = 0;
    //double result;



    /*
    if( calculator.size() > 2 )                      //Error check gives a false error for last input ???
    {
        cout << "Error: too many operands" << endl;
        return 1;
    }

    //Error chceck for too many operators           ////STILL PRINT OUTPUT???
    if( calculator.size() < 2 )
        {
            cout << "Error: too many operators" << endl;
            return 1;
        }
*/


    switch (input[0])
    {
    case '+': calculator.add();
              calculator.display();
              break;
    case '-': calculator.subtract();
              calculator.display();
              break;
    case '*': calculator.multiply();
              calculator.display();
              break;
    case '/':  calculator.divide();

				//if (firstOperand / 0) 
				//{
				//	cout << "Error: Divide by 0.\n";
				//}
    		   calculator.display();
    		  break;
    }
                        	/*
                        	if (secondOperand == 0)
                        	            { // moved this test to here because it's the only place it matters.
                        	                cout << "Error: Division by 0.\n";
                        	                return -1;
                        	            }
*/





return 0;

}
