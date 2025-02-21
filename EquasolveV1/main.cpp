#include <iostream> //Bibliothéque de base pour des instruction output simple
#include "TetrasLib.cpp"

int main()
{

    std::string Equa;
    int IndexEgal;
    int res;
    

    std::cout << '\n';
    std::cout << '\n';
    std::cout << "EquaSolve by Gregoire GIBRAT\n";
    std::cout << "******************************************************************\n";
    std::cout << "Entrez une equation du premier degres :" << '\n' << "   > ";
    std::cin >> Equa;
    std::cout << '\n';

    IndexEgal = charAt(Equa,'=');
    char TabX[IndexEgal]; 
    int SizeTabX = IndexEgal;

    char TabY[Equa.length()-(IndexEgal+1)]; 
    int SizeTabY = Equa.length() - (IndexEgal + 1); 


    for(int i = 0; i<SizeTabX;i++)
    {
        TabX[i]= Equa[i];
    }
    TabX[SizeTabX] = '\0';

    for(int i = 0; i < SizeTabY;i++)
    {
        TabY[i] = Equa[IndexEgal + 1 + i];
    }
    TabY[SizeTabY] = '\0';

    int PartX = arrayToInt(TabX,SizeTabX);
    int PartY = arrayToInt(TabY,SizeTabY);

    
    std::cout << "******************************************************************\n";


    return 0;
}
