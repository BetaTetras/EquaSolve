#include <iostream> //Bibliothéque de base pour des instruction output simple



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* 
Check if an input from the user is conform to the available choice or in the opposite case, display an error ask the 
user to enter a new input

Syntaxe:

*Input to check* = IntegerVerifier(*from*,*to*,*Input to check*);
Input = IntegerVerifier(1,10,Input);
        => Verifie if Input is a integer and if it's between 1 and 10 
*/

int IntegerVerifier(int x,int y,int input)
{
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        std::cout << '\n';
        std::cout << "  ERROR : INVALIDE INPUT" << '\n';
        std::cout << "  Input should be Integer (ex : 1,50,-10) " <<'\n';
        std::cout << "      > ";
        std::cin >> input;
        std::cout << '\n'; 
    }

    while (input < x || input >y)
    {
        std::cout << '\n';
        std::cout << "  ERROR : INVALIDE INPUT" << '\n';
        std::cout << "  Input should be between " << x << " and " << y << " ." << '\n';
        std::cout << "      > ";
        std::cin >> input;
        std::cout << '\n'; 
    }



    return input;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Search in a string a certain caractere and return is index , return -1 if it's not found

Syntaxe:

*Varible*=charAt(*String*,*Character*);
IndexOfEqual=charAt(Equation,'=');
    => Give the index of the character '=' in the string "Equation"
*/


int charAt(std::string String,char Car)
{
    int TailleEqua = String.length();
    int i = 0;
    while(i<TailleEqua)
    {
        if(String[i] == Car)
        {
            return i;
        }
        i++;
    }
    return -1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Convert a character number into his integer number thanks to the ASCII table :
    • '0' = 48
    • '1' = 49
    • '2' = 50
    • '3' = 51
    • '4' = 52
    • '5' = 53
    • '6' = 54
    • '7' = 55
    • '8' = 56
    • '9' = 57

or return -1 if the input is wrong

Syntaxe:
*Integer variable* = charToInt(*character*);
Nbr=charToInt('9');
    => Converts the character '9' to its corresponding decimal value using the ASCII table (57) 
       and subtracts 48 (ASCII value of '0') to get the correct integer.    
*/ 

int charToInt(char car)
{
    int nbr = car;

    if(nbr >= 48 && nbr <=57)
    {
        return nbr - 48;
    }

    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int arrayToInt(char Tab[],int Size_Tab)
{
    int nbrNonEntier = 0;

    for(int i = 0;i< Size_Tab;i++)
    {
        if(charToInt(Tab[i])<0)
        {
            nbrNonEntier ++;
        }
    }

    Size_Tab = Size_Tab -nbrNonEntier;
    int TabNbr[Size_Tab];
    
    int nbr = 0;
    int multi = 1;

    for(int i = 0 ; i< Size_Tab ; i++)
    {
        if(charToInt(Tab[i]) != -1)
        {
            TabNbr[i] = charToInt(Tab[i]);
        }
    }

    for(int i = sizeof(TabNbr)/sizeof(TabNbr[0])-1 ; i >= 0 ; i--)
    {
        nbr = nbr +(TabNbr[i] * multi);
        multi = multi*10;
    }
    multi = 0;

    return nbr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char arrayToOpe(char Tab[],int Size)
{
    char Ope;
    int res;


    for(int i = 0; i<Size;i++)
    {
        if(Tab[i] == '+')
        {
            return '+';
        }
        else if(Tab[i] == '-')
        {
            return '-';
        }
        else if(Tab[i] == '*')
        {
            return '+';
        }
        else if(Tab[i] == '/')
        {
            return '-';
        }
    }

    return '!';
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool isNegative(int Nbr)
{
    if(Nbr < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}