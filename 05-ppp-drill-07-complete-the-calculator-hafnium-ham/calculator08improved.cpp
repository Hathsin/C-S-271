/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 1 bug that the compiler will catch, 4 runtime bugs that it won't, 1 missing operation, and 1 style bug that could lead to serious problems down the line!
*/

#include "std_lib_facilities.h"

struct Token
{
	char kind;          //token struct, holds a token character for math or value and a string
	double value;
	string name;  //confusing(1) var name same
	Token(char ch) : kind(ch), value(0) {}   //for a char read it in and set val to 0
	Token(char ch, double val) : kind(ch), value(val) {}  //set char and val
    Token(char ch, string str) : kind(ch), name(str) {}   //for variables                         added in IFIXED
};

class Token_stream
{
	bool full;          //the token stream, defines full and buffer
	Token buffer;

public:
	Token_stream() : full(0), buffer(0) {}    //calls the stream and sets all to 0

	Token get();
	void unget(Token t)   //puts token that we got into buffer, so the full token can be taken
	{
		buffer = t;
		full = true;
	}

	void ignore(char);
};

const char let = 'L';
const char square = 'S';
const char power = 'P';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';  //confusing(2) var name same

Token Token_stream::get()  //getting a token process
{
	if (full)   //if it is full = true. set full false and return buffer
	{
		full = false;
		return buffer;
	}
	char ch;     //else read a char
	cin >> ch;
	switch (ch)
	{
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);   // if char is operation, return
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{ 
		cin.unget();        //if char is num or decimal, put it back and read a double
		double val;         //store double with char that says it is num
		cin >> val;
		return Token(number, val);
	}
    case '#':               //the new let
    {
        return Token(let);
    }
	default:
		if (isalpha(ch))     //is neither operation or num and is char
		{
			string s;       //make string
			s += ch;        //string adds char
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) //if it isnt op/num and is char or digit, set as string
				s += ch;             													//		I FIXED
			cin.unget();
			if (s == "exit") //if string is exit, return a   is eval later                      I FIXED
				return Token(quit);
			if (s == "sqrt")
				return Token(square);
			if (s == "pow")
				return Token(power);
			return Token(name, s);  //sets token as a name and store string in double
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) //if buffer has something and c is kind in buffer, delete buffer and ret
	{
		full = false;
		return;
	}
	full = false;        //if c is not kind, ensure buffer is clear

	char ch;
	while (cin >> ch)  //ignores all until c
		if (ch == c)
			return;
}



struct Variable
{
	string name;      //a variable struct
	double value;
	Variable(string n, double v) : name(n), value(v) {}
	
};

vector<Variable> names;

double get_value(string s)  //response to name
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s)     //looks for var with this name, else says is undefined
			return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)  //change a vars value                  could replace error on line 233
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s)
		{
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i) //checks if name exists in vector of previous vars
		if (names[i].name == s)
			return true;
	return false;
}

Token_stream ts;

double expression();

double square_root()
{
	Token t = ts.get();        //ensures order of operations
	if(t.kind =='(')               //start with paraenthesis
	{
		double d = expression();   //ensures oop, check more P, MD, AS
		t = ts.get();
		if (t.kind != ')')          //not number or operation, must be close para.
			error("')' expected");
		else if(d < 0){
			error("cannot take square root of a negative number");
		}
		else{									//close para							I FIXED
			return sqrt(d);
		}
	}
	else{
		error("'(' expected");
	}
}

double power_func()
{
	Token t = ts.get();        //ensures order of operations
	if(t.kind =='(')               //start with paraenthesis
	{
		double d;   //reads in power stuff and ensures only ints. 
		double p;
		char c;
		cin >> d >> c >> p;
		int i1 = narrow_cast<int>(p);
		t = ts.get();
		if (t.kind != ')')          //not number or operation, must be close para.
			error("')' expected");
		else{									//close para							I FIXED
			return pow(d, i1);
		}
	}
	else{
		error("'(' expected");
	}
}

double primary()       
{
	Token t = ts.get();        //ensures order of operations
	switch (t.kind)
	{
	case '(':               //start with paraenthesis
	{
		double d = expression();   //ensures oop, check more P, MD, AS
		t = ts.get();
		if (t.kind != ')')          //not number or operation, must be close para.
			error("')' expected");
		else{									//close para							I FIXED
			return d;
		}
	}
	case '-':                   //a minus without num before is negative number
		return -primary();     //ret negative num
	case number:                //if it is char 8, means its a num, so retun a value
		return t.value;
	case name:                  //if it is char a, it is a variable, so it gets val
		return get_value(t.name);
	case square:				//if char S, take root
		return square_root();
	case power:					//if char P, do power
		return power_func();
	default:
		error("primary expected");
	}
}



double term()
{
	double left = primary(); //ensures order of operations
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '*':                //if multiplication then multiply
			left *= primary();
			break;
		case '/':                //if divide, divide, but not by 0
		{
			double d = primary();
			if (d == 0)
				error("divide by zero");
			left /= d;
			break;
		}
		case '%':   
		{               //if mod do mod stuff 
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(primary());
			if (i2==0) error("%: divide by zero");
			left = i1 % i2;
			break;
		}
		default:
			ts.unget(t);         //return result
			return left;
		}
	}
}

double expression()
{
	double left = term();  //ensures order of operations
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '+':          //token is + then add
			left += term();
			break;
		case '-':           //token is - then subtract
			left -= term();
			break;
		default:
			ts.unget(t);    //if neither, return
			return left;
		}
	}
}

double declaration()  ///creates var
{
	Token t = ts.get();
	if (t.kind != 'a')  //checks that it is var
		error("name expected in declaration");
	string name = t.name;
	if (is_declared(name))  //prevents dupes
		error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') //must have = after name
		error("= missing in declaration of ", name);
	double d = expression(); //evaluates equation/takes in num
	names.push_back(Variable(name, d)); //adds var to names vector(list of names)
	return d;
}

double statement()  //starts equation or sets var
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let: //create var
		return declaration();   //if it is l, sets var to value
	default:
		ts.unget(t);  
		return expression();    //returns solved equation
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true)
		try
		{
			cout << prompt;      //ask for user prompt
			Token t = ts.get();  //load first char in token
			while (t.kind == print)  //waits for ; and will print
				t = ts.get();
			if (t.kind == quit)      //waits for Q and will stop
				return;    
			ts.unget(t);         //places token back to be read
			cout << result << statement() << endl;   //returns ans and 
		}
		catch (runtime_error &e)
		{
			cerr << e.what() << endl;
			clean_up_mess();
		}
}

int main()

try
{
    names.push_back(Variable("k", 1000));
	calculate();    //first, calculate
	return 0;       //then end prg
}
catch (exception &e)
{
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';')
		;
	return 1;
}
catch (...)
{
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';')
		;
	return 2;
}
