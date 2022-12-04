#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int crystals = 0;


//juego de alto bajo para ganar Crystrales   
void alto_bajo()
{
    int submenu;
    int X;
    int resp;
    int attemps;
    int Cwon;


    //submenu 
    cout << "Seleccion de dificultad\n";
    cout << "1. Normal: recompensa maxima de 2500 crystals.\n";
        cout << "2. Dificil: recompensa maxima de 10 000 crystals.\n";

        cin >> submenu;

    //Normal difficult 
    if (submenu == 1)
    {
        cout << "Alto bajo en dificultad Normal\n";
        cout << "Prueba con numeros del 1 al 20 !!\n";
        system("pause");



        X = (rand() % 21);

        attemps = 5;

        do
        {
            system("cls");
            cout << "Te restan: " << attemps  << " intentos \n";
            cin >> resp;
            if (resp == X)
            {
                cout << "Has acertado!!!\n";
                system("pause");
            }
            else if (resp < X && attemps != 0)
            {
                cout << " BAJO!! \n";
                attemps--;
                system("pause");

            }
            else if (resp > X && attemps != 0)
            {
                cout << " ALTO!! \n";
                attemps--;
                system("pause");

            }
            else if (attemps == 0)
            {
                cout << " Buen intento, suerte para la proxima \n";
                system("pause");
                attemps = 0;
            }
        } while (resp != X && attemps != 0);
        system("cls");
        Cwon = attemps * 500;
        cout << "HAS GANADO " << Cwon << " Crystals\n";
        crystals += Cwon;
        system("pause");

        
       
    }
    //Hard difficult
    if (submenu == 2)
    {
        cout << "Alto bajo en dificultad Dificil\n";
        cout << "Prueba con numeros del 1 al 100 !!\n";
        system("pause");



        X = (rand() % 101);

        attemps = 10;

        do
        {
            system("cls");
            cout << "Te restan: " << attemps << " intentos \n";
            cin >> resp;
            if (resp == X)
            {
                cout << "Has acertado!!!\n";
                system("pause");
            }
            else if (resp < X && attemps != 0)
            {
                cout << " BAJO!! \n";
                attemps--;
                system("pause");

            }
            else if (resp > X && attemps != 0)
            {
                cout << " ALTO!! \n";
                attemps--;
                system("pause");

            }
            else if (attemps == 0)
            {
                cout << " Buen intento, suerte para la proxima \n";
                system("pause");
                attemps = 0;
            }
        } while (resp != X && attemps != 0);
        system("cls");
        Cwon = attemps * 1000;
        cout << "HAS GANADO " << Cwon << " Crystals\n";
        crystals += Cwon;
        system("pause");



    }
 }

//structs importantes UwU
struct PJ
{
    string name;
    string element;
    int HP;
    int ATK;
    int lvl;
    int stars;

    void SetStats(string n, string e, int a, int b, int c)
    {
        name = n;
        element = e;
        HP = a;
        ATK = b;
        stars = c;
        lvl = 0;
    }
};
struct Mob
{
    string name;
    string element;
    int HP;
    int ATK;
    int lvl;
};




//funcion del gacha  
int Gacha()
{
    int x = 0;
    int S = (rand() % 501);
    if (S >= 300)
    {
        x = 2 + rand() % 4;
     
        return x;

    }
    if (S <= 299)
    {
        x = rand() % 2;
       
        return x;

    }
    return 0;

}

//menu 
int DMenu( int M )
{
    system("cls");
    std::cout << R"(
       _                               _        _____            _             _                           
      | |                             ( )      / ____|          | |           | |                          
      | | ___ _ __ ___ _ __ ___  _   _|/ ___  | |  __  __ _  ___| |__   __ _  | |__   __ ___   _____ _ __  
  _   | |/ _ \ '__/ _ \ '_ ` _ \| | | | / __| | | |_ |/ _` |/ __| '_ \ / _` | | '_ \ / _` \ \ / / _ \ '_ \ 
 | |__| |  __/ | |  __/ | | | | | |_| | \__ \ | |__| | (_| | (__| | | | (_| | | | | | (_| |\ V /  __/ | | |
  \____/ \___|_|  \___|_| |_| |_|\__, | |___/  \_____|\__,_|\___|_| |_|\__,_| |_| |_|\__,_| \_/ \___|_| |_|
                                  __/ |                                                                    
                                 |___/                                                                     	
)" << '\n';

    cout << "You have " << crystals << " crystals!\n" << endl;
    cout << "0) Status of three characters.\n";
    cout << "1) Roll Character for 500 crystals?\n";
    cout << "2) Guarantee a 5 star character by rolling for 1500 crystals.\n";
    cout << "3) Train character for 1000 crystals.\n";
    cout << "4) Battle the next enemy (Name: XXXX, Element: XXXX, Level: XXXX)\n";
    cout << "5) Play Alto-Bajo to farm crystals.\n";
    cout << "6) Exit the game.\n";
    cin >> M;

    return M;
  
}

int main()
{

    srand((unsigned)time(0));

    crystals += 500;
    int menu = 0;


    //Creacion de todos los personajes
    PJ personaje[7];
    personaje[0].SetStats("Nahida", "Dendro", 500, 250, 6);
    personaje[1].SetStats("Ember", "Pyro", 500, 250, 6);
    personaje[2].SetStats("Gaia", "Dendro", 150, 100, 5);
    personaje[3].SetStats("Blaze", "Pyro", 150, 100, 5);
    personaje[4].SetStats("Haru", "Dendro", 150, 100, 5);
    personaje[5].SetStats("Hestia", "Pyro", 150, 100, 5);

    PJ mipj;
    

 


    do
    {
        


        switch (DMenu(menu))
        {
        case 0:


            break;
        case 1:
            if (crystals >= 500) {
                crystals -= 500;
                mipj = personaje[Gacha()];

                cout << "te ha tocado " << mipj.name <<endl;
                system("pause");

            }
            else
            {
                cout << " no hay plata \n";
                system("pause");

            }

            break;

        case 2:  
           
            break;

        case 3:

            break;

        case 4:

            break;

        case 5:
            alto_bajo();
            break;
        case 6:
            system("cls");
            std::cout << R"(


       _                 _                ___                     _              _             
   _  | |               | |              / __)                   | |            (_)            
 _| |_| |__  _____ ____ | |  _  ___    _| |__ ___   ____    ____ | | _____ _   _ _ ____   ____ 
(_   _)  _ \(____ |  _ \| |_/ )/___)  (_   __) _ \ / ___)  |  _ \| |(____ | | | | |  _ \ / _  |
  | |_| | | / ___ | | | |  _ (|___ |    | | | |_| | |      | |_| | |/ ___ | |_| | | | | ( (_| |
   \__)_| |_\_____|_| |_|_| \_|___/     |_|  \___/|_|      |  __/ \_)_____|\__  |_|_| |_|\___ |
                                                           |_|            (____/        (_____|
)" << '\n';


            menu = 6;  
            system("pause");
            break;

        default:

            DMenu(menu);
        }
    } while (menu != 6);

    return 0;
}