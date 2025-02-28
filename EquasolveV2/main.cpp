#include <iostream> //Bibliothéque de base pour des instruction output simple
#include "C:\Users\grego\Desktop\IUT\PROJET_PERSO\Librairie\TetrasLib\TetrasLib.cpp"

int main()
{

    std::string Equa;
    int IndexEgal;
    int res;
    char Ope;
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
                                /* GUI PART */
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "EquaSolve by Gregoire GIBRAT\n";
    std::cout << "******************************************************************\n";
    std::cout << "Entrez une equation du premier degres :" << '\n' << "   > ";
    std::cin >> Equa;
    ////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////
                                /* SEPARATION BETWEEN MEMBER */
    // Fonction pour déterminée l'index du caractère "="
    IndexEgal = charAt(Equa,'=');
    char TabA[IndexEgal];       // Crée un tableau de caractère qui représente le membre A de l'équation
    int SizeTabA = IndexEgal;   // Retourne sa taille

    char TabB[Equa.length()-(IndexEgal+1)];         // Crée un tableau de caractère qui représente le membre B de l'équation
    int SizeTabB = Equa.length() - (IndexEgal + 1); // Retourne sa taille

    // Remplie le tableau du membre A avec la partie de gauche de l'équation
    for(int i = 0; i<SizeTabA;i++)
    {
        TabA[i]= Equa[i];
    }
    TabA[SizeTabA] = '\0';

    // Remplie le tableau du membre B avec la partie de droite de l'équation
    for(int i = 0; i < SizeTabB;i++)
    {
        TabB[i] = Equa[IndexEgal + 1 + i];
    }
    TabB[SizeTabB] = '\0';
    ////////////////////////////////////////////////////////////////////////////////////////////////
                                /* MEMBER A OR MEMBER B */
    // Détermine quel membre a l'inconnue
    char xPart = 'A';
    for(int i; i<SizeTabB;i++)
    {
        if(TabB[i] == 'x')
        {
            xPart = 'B';
        }
    }

    // Isolation du nombre si x est dans le Membre A
    if(xPart == 'A')
    {  
        int TailleTabEqua = sizeof(TabA)/sizeof(TabA[0]);
        int NbrInt = 0;
        bool NbrNegatif = false;
    
        // Détermine le nombre de nombre dans le membre
        for(int i=0; i< TailleTabEqua ; i++)
        {
            if(charToInt(TabA[i]) >= 0)
            {
                NbrInt++;
            }
        }
     
        // Détermine si le nombre est négatif
        for(int i=0; i< TailleTabEqua ; i++)
        {
            if(TabA[i] == '-')
            {
                if (charToInt(TabA[i+1]) > 0)
                {   
                    NbrNegatif = true;
                }
                
            }
        }
    
        // Crée le tableau du nombre de taille du nombre (1 = 1 ; 23 = 2 ; 789 465 = 6) +1 (Pour le signe negatif '-')
        char NbrEqua[NbrInt + NbrNegatif];
        int TailleNbrEqua = sizeof(NbrEqua)/sizeof(NbrEqua[0]);
    
        int j = 0;
        for(int i = 0; i < TailleTabEqua ; i++)
        {
            if(TabA[i] == '-' && charToInt(TabA[i+1]) > 0 )
            {
                NbrEqua[j] = '-';
                j++;
            }
            else if(charToInt(TabA[i]) >= 0)
            {
                NbrEqua[j] = TabA[i];
                j++;
            }
        }
        j=0;

        int PartA = arrayToInt(NbrEqua,sizeof(NbrEqua)/sizeof(NbrEqua[0]));
        int PartB = arrayToInt(TabB,SizeTabB);

        std::cout << Equa << '\n';
        if(isNegative(PartA))
        {
            std::cout << "x=" << PartB << "+" << (PartA * (-1)) << '\n';
            std::cout << "x=" << PartB + PartA * (-1);
        }
        else
        {
            std::cout << "x=" << PartB << "-" << PartA << '\n';
            std::cout << "x=" << PartB - PartA;
        }
        
    }
    else
    {
        int TailleTabEqua = sizeof(TabB)/sizeof(TabB[0]);
        int NbrInt = 0;
        bool NbrNegatif = false;
    
        // Détermine le nombre de nombre dans le membre
        for(int i=0; i< TailleTabEqua ; i++)
        {
            if(charToInt(TabB[i]) >= 0)
            {
                NbrInt++;
            }
        }
     
        // Détermine si le nombre est négatif
        for(int i=0; i< TailleTabEqua ; i++)
        {
            if(TabB[i] == '-')
            {
                if (charToInt(TabB[i+1]) > 0)
                {   
                    NbrNegatif = true;
                }
                
            }
        }
    
        // Crée le tableau du nombre de taille du nombre (1 = 1 ; 23 = 2 ; 789 465 = 6) +1 (Pour le signe negatif '-')
        char NbrEqua[NbrInt + NbrNegatif];
        int TailleNbrEqua = sizeof(NbrEqua)/sizeof(NbrEqua[0]);
    
        int j = 0;
        for(int i = 0; i < TailleTabEqua ; i++)
        {
            if(TabB[i] == '-' && charToInt(TabB[i+1]) > 0 )
            {
                NbrEqua[j] = '-';
                j++;
            }
            else if(charToInt(TabB[i]) >= 0)
            {
                NbrEqua[j] = TabB[i];
                j++;
            }
        }
        j=0;

        int PartA = arrayToInt(TabA,SizeTabA);
        int PartB = arrayToInt(NbrEqua,sizeof(NbrEqua)/sizeof(NbrEqua[0]));

        std::cout << Equa << '\n';
        if(isNegative(PartB))
        {


            std::cout << PartA << "+" <<(PartB *(-1)) << "=x" << '\n';
            std::cout << PartA + (PartB*(-1)) << "=x" << '\n';
            std::cout << "x=" << PartA + (PartB * (-1));
        }
        else
        {
            std::cout << PartA << "-" << PartB << "=x" <<  '\n';
            std::cout << PartA + (PartB * (-1)) << "=x" << '\n';
            std::cout << "x=" << PartA + (PartB * (-1));
        }

    }

    std::cout << '\n';
    std::cout << "******************************************************************\n";


    return 0;
}
