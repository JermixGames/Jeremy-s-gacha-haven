#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int crystals = 0;


//Funcion del gacha

//HOLA QUE ONDA 

//structs de las stats basicas

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




// personajes 

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
    //creacion de personajes 6 strellas
    

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
            crystals += 500;
            cout << " consigues 500 cristales YEII";
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