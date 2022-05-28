#include <iostream>
#include <stdlib.h>

using namespace std;
void kontrola_menu(int msc)
{
    if (msc<1 || msc>9)
    {
        exit(0);
    }
}
void kontrola_miejsca(char *plansza, int msc)
{
    if ((msc<1||msc>9) || plansza[msc-1]=='0' || plansza[msc-1]=='X' )
    {
        exit(0);
    }
}

void wstaw_symbol(char *plansza, int miejsce)
{
    plansza[miejsce-1]='0';
}

void rysuj_plansze(char *plansza)
{
     cout <<endl;
        cout << " "<< plansza[0] <<" | "<<plansza[1]<<" | "<<plansza[2]<<endl;
        cout << "   |   |   "<<endl;
        cout << "-----------"<<endl;
        cout << " "<<plansza[3] <<" | "<<plansza[4]<<" | "<<plansza[5]<<endl;
        cout << "   |   |   "<<endl;
        cout << "-----------"<<endl;;
        cout << " "<< plansza[6] <<" | "<<plansza[7]<<" | "<<plansza[8]<<endl;
        cout << "   |   |   "<<endl;
        cout <<endl;
}
int wybor_miejsca(char *plansza)
{
    int _miejsce=0;
    cout<<"Wybierz pole ";
    cin>>_miejsce;
    if ((_miejsce<1||_miejsce>9) || plansza[_miejsce-1]=='0' || plansza[_miejsce-1]=='X' )
    {
        exit(0);
    }

    else
    {
    wstaw_symbol(plansza, _miejsce);
    rysuj_plansze(plansza);
    return _miejsce;
    }
}
void test_wygranej(char *plansza)
{
    if ((plansza[0]=='0' && plansza[1]=='0' && plansza[2]=='0') || (plansza[3]=='0' && plansza[4]=='0' && plansza[5]=='0') || (plansza[6]=='0' && plansza[7]=='0' \
        && plansza[8]=='0') || (plansza[6]=='0' && plansza[7]=='0' && plansza[8]=='0') || (plansza[0]=='0' && plansza[3]=='0' && plansza[6]=='0') || (plansza[1]=='0' && plansza[4]=='0' && plansza[7]=='0') \
        || (plansza[2]=='0' && plansza[5]=='0' && plansza[8]=='0') || (plansza[0]=='0' && plansza[4]=='0' && plansza[8]=='0') || (plansza[2]=='0' && plansza[4]=='0' && plansza[6]=='0'))
    {
        cout<<"Wygrales"<<endl;
    }

    else if ((plansza[0]=='X' && plansza[1]=='X' && plansza[2]=='X') || (plansza[3]=='X' && plansza[4]=='X' && plansza[5]=='X') || (plansza[6]=='X' && plansza[7]=='X' \
        && plansza[8]=='X') || (plansza[6]=='X' && plansza[7]=='X' && plansza[8]=='X') || (plansza[0]=='X' && plansza[3]=='X' && plansza[6]=='X') || (plansza[1]=='X' && plansza[4]=='X' && plansza[7]=='X') \
        || (plansza[2]=='X' && plansza[5]=='X' && plansza[8]=='X') || (plansza[0]=='X' && plansza[4]=='X' && plansza[8]=='X') || (plansza[2]=='X' && plansza[4]=='X' && plansza[6]=='X'))
    {
        cout<<"Przegrales"<<endl;
    }
}
bool test_remisu(char *plansza)
{
    if(!((plansza[0]=='0' && plansza[1]=='0' && plansza[2]=='0') || (plansza[3]=='0' && plansza[4]=='0' && plansza[5]=='0') || (plansza[6]=='0' && plansza[7]=='0' \
        && plansza[8]=='0') || (plansza[6]=='0' && plansza[7]=='0' && plansza[8]=='0') || (plansza[0]=='0' && plansza[3]=='0' && plansza[6]=='0') || (plansza[1]=='0' && plansza[4]=='0' && plansza[7]=='0') \
        || (plansza[2]=='0' && plansza[5]=='0' && plansza[8]=='0') || (plansza[0]=='0' && plansza[4]=='0' && plansza[8]=='0') || (plansza[2]=='0' && plansza[4]=='0' && plansza[6]=='0')|| (plansza[0]=='X' && plansza[1]=='X' && plansza[2]=='X') || (plansza[3]=='X' && plansza[4]=='X' && plansza[5]=='X') || (plansza[6]=='X' && plansza[7]=='X' \
        && plansza[8]=='X') || (plansza[6]=='X' && plansza[7]=='X' && plansza[8]=='X') || (plansza[0]=='X' && plansza[3]=='X' && plansza[6]=='X') || (plansza[1]=='X' && plansza[4]=='X' && plansza[7]=='X') \
        || (plansza[2]=='X' && plansza[5]=='X' && plansza[8]=='X') || (plansza[0]=='X' && plansza[4]=='X' && plansza[8]=='X') || (plansza[2]=='X' && plansza[4]=='X' && plansza[6]=='X')))
        {
            cout<<"Remis"<<endl;
            return true;
        }
    else
    {
        return false;
    }
}

void wstaw_symbol_komputer(char *plansza, int miejsce_komputer)
{
    plansza[miejsce_komputer-1]='X';
    rysuj_plansze(plansza);
}
void algorytm(int a, int b, int c, int d, int e, char *plansza, int miejsce)
{
                    wstaw_symbol_komputer(plansza, a);
                    miejsce=wybor_miejsca(plansza);
                        if (miejsce!=b)
                        {
                           wstaw_symbol_komputer(plansza, b);
                            test_wygranej(plansza);
                        }
                        else
                        {
                            wstaw_symbol_komputer(plansza, c);
                            test_wygranej(plansza);
                            miejsce=wybor_miejsca(plansza);
                                if (miejsce!=d)
                                {
                                wstaw_symbol_komputer(plansza, d);
                                test_remisu(plansza);
                                test_wygranej(plansza);
                                }
                                else
                                {
                                    wstaw_symbol_komputer(plansza, e);
                                    test_remisu(plansza);
                                    test_wygranej(plansza);
                                }
                        }
}
void algorytm_srodek(int a, int b, int c, int d, int e, char *plansza, int miejsce)
{
                    wstaw_symbol_komputer(plansza, a);
                    miejsce=wybor_miejsca(plansza);
                        if (miejsce!=b)
                        {
                           wstaw_symbol_komputer(plansza, b);
                            test_wygranej(plansza);
                        }
                        else
                        {
                            wstaw_symbol_komputer(plansza, c);
                            test_wygranej(plansza);
                            miejsce=wybor_miejsca(plansza);
                                if (miejsce==d)
                                {
                                wstaw_symbol_komputer(plansza, e);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                                }
                                else if (miejsce==e)
                                {
                                wstaw_symbol_komputer(plansza, d);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                                }
                                else
                                {
                                    wstaw_symbol_komputer(plansza, d);
                                    test_remisu(plansza);
                                    test_wygranej(plansza);
                                }
                        }
}
void algorytm2(int a, int b, int c, int d, int e, char *plansza, int miejsce )
{
        wstaw_symbol_komputer(plansza,a);
        miejsce=wybor_miejsca(plansza);
        if (miejsce!=b)
        {
            wstaw_symbol_komputer(plansza,b);
            test_wygranej(plansza);
        }
        else
        {
            wstaw_symbol_komputer(plansza, c);
            miejsce=wybor_miejsca(plansza);
            if (miejsce==d)
            {
            wstaw_symbol_komputer(plansza, e);
            test_wygranej(plansza);
            }
            else
            {
                wstaw_symbol_komputer(plansza, d);
                test_wygranej(plansza);
            }
        }
}

int main()
{
    int wybor=0;
    int miejsce=0;
    int miejsce_komputer=0;
    char plansza[9]={'\0'};
    cout<<"Kto ma zaczac gre?\nGracz - wybierz 1\nKomputer - wybierz 2\n";
    cin>>wybor;
    kontrola_menu(wybor);
    switch (wybor)
    {
    case 1:
        rysuj_plansze(plansza);
        miejsce=wybor_miejsca(plansza);
            if (miejsce==1)
            {
                 wstaw_symbol_komputer(plansza, 5);
                miejsce=wybor_miejsca(plansza);
                //BLOK GDY GRACZ WYBIERZE POLE 4
                if (miejsce==4)
                {
                    algorytm(7,3,2,8,6, plansza, miejsce);
                }


                //BLOK GDY GRACZ WYBIERZE POLE 2
                else if (miejsce==2)
                {
                    algorytm(3,7,4,6,9, plansza, miejsce);
                }

                //BLOK GDY GRACZ WYBIERZE POLE 3
                else if (miejsce==3)
                {
                    algorytm(2,8,4,6,9, plansza, miejsce);
                }


                //BLOK GDY GRACZ WYBIERZE POLE 6
                else if (miejsce==7)
                {
                    algorytm(4,6,8,2,3, plansza, miejsce);
                }

                 //BLOK GDY GRACZ WYBIERZE POLE 7
                else if (miejsce==7)
                {
                    algorytm(2,8,4,6,9, plansza, miejsce);
                }


                 //BLOK GDY GRACZ WYBIERZE POLE 8
                else if (miejsce==8)
                {
                    algorytm(3,5,8,6,4, plansza, miejsce);
                }



                 //BLOK GDY GRACZ WYBIERZE POLE 9
                else if (miejsce==9)
                {
                    algorytm(6,4,7,3,2, plansza, miejsce);
                }

            }




            else if (miejsce==3)
            {
                wstaw_symbol_komputer(plansza, 5);
                miejsce=wybor_miejsca(plansza);
                //BLOK GDY GRACZ WYBIERZE POLE 1
                if (miejsce==1)
                {
                    algorytm(2,8,4,6,9, plansza, miejsce);
                }

                //BLOK GDY GRACZ WYBIERZE POLE 2
                else if (miejsce==2)
                {
                   algorytm(1,9,6,4,7, plansza, miejsce);
                }

                //BLOK GDY GRACZ WYBIERZE POLE 4
                else if (miejsce==4)
                {
                    algorytm(2,8,9,1,7, plansza, miejsce);
                }


                //BLOK GDY GRACZ WYBIERZE POLE 6
                else if (miejsce==6)
                {
                    algorytm(9,1,2,8,4, plansza, miejsce);
                }

                 //BLOK GDY GRACZ WYBIERZE POLE 7
                else if (miejsce==7)
                {
                    algorytm(4,6,9,1,2, plansza, miejsce);
                }


                 //BLOK GDY GRACZ WYBIERZE POLE 8
                else if (miejsce==8)
                {
                    algorytm(6,4,1,9,7, plansza, miejsce);
                }



                 //BLOK GDY GRACZ WYBIERZE POLE 9
                else if (miejsce==9)
                {
                    algorytm(6,4,8,2,1,plansza, miejsce);
                }

            }

            else if (miejsce==7)
            {
                wstaw_symbol_komputer(plansza, 5);
                miejsce=wybor_miejsca(plansza);
                //BLOK GDY GRACZ WYBIERZE POLE 1
                if (miejsce==1)
                {
                    algorytm(4,6,2,8,9, plansza, miejsce);
                }

                //BLOK GDY GRACZ WYBIERZE POLE 2
                else if (miejsce==2)
                {
                   algorytm(6,4,1,9,8, plansza, miejsce);
                }

                //BLOK GDY GRACZ WYBIERZE POLE 3
                else if (miejsce==3)
                {
                    algorytm(4,6,9,1,2, plansza, miejsce);
                }


                //BLOK GDY GRACZ WYBIERZE POLE 4
                else if (miejsce==4)
                {
                    algorytm(1,9,8,2,3, plansza, miejsce);
                }

                 //BLOK GDY GRACZ WYBIERZE POLE 6
                else if (miejsce==6)
                {
                    algorytm(8,2,1,9,3, plansza, miejsce);
                }


                 //BLOK GDY GRACZ WYBIERZE POLE 8
                else if (miejsce==8)
                {
                    algorytm(6,4,1,9,7, plansza, miejsce);
                }



                 //BLOK GDY GRACZ WYBIERZE POLE 9
                else if (miejsce==9)
                {
                    algorytm(6,4,8,2,1,plansza, miejsce);
                }

            }


            else if (miejsce==9)
            {
                wstaw_symbol_komputer(plansza, 5);
                miejsce=wybor_miejsca(plansza);
                //BLOK GDY GRACZ WYBIERZE POLE 1
                if (miejsce==1)
                {
                    algorytm(2,8,7,3,6, plansza, miejsce);
                }

                //BLOK GDY GRACZ WYBIERZE POLE 2
                else if (miejsce==2)
                {
                   algorytm(6,4,7,3,1, plansza, miejsce);
                }

                //BLOK GDY GRACZ WYBIERZE POLE 3
                else if (miejsce==3)
                {
                    algorytm(6,4,2,8,1, plansza, miejsce);
                }


                //BLOK GDY GRACZ WYBIERZE POLE 4
                else if (miejsce==4)
                {
                    algorytm(8,2,3,7,1, plansza, miejsce);
                }

                 //BLOK GDY GRACZ WYBIERZE POLE 6
                else if (miejsce==6)
                {
                    algorytm(3,7,8,2,1, plansza, miejsce);
                }


                 //BLOK GDY GRACZ WYBIERZE POLE 7
                else if (miejsce==7)
                {
                    algorytm(8,2,4,6,3, plansza, miejsce);
                }



                 //BLOK GDY GRACZ WYBIERZE POLE 8
                else if (miejsce==8)
                {
                    algorytm(7,3,6,4,1,plansza, miejsce);
                }

            }
            else if (miejsce==2)
            {
                wstaw_symbol_komputer(plansza, 5);
                miejsce=wybor_miejsca(plansza);
                if (miejsce==1)
                {
                    algorytm(3,7,4,6,8,plansza, miejsce);
                }
                else if (miejsce==3)
                {
                    algorytm(1,9,6,4,8,plansza, miejsce);
                }
                else if (miejsce==4)
                {
                    algorytm(1,9,3,7,8,plansza, miejsce);
                }
                else if (miejsce==6)
                {
                    algorytm(3,7,9,1,4,plansza, miejsce);
                }
                else if (miejsce==7)
                {
                    algorytm(9,1,4,6,3,plansza, miejsce);
                }
                else if (miejsce==8)
                {
                    algorytm(1,9,7,3,4,plansza, miejsce);
                }
                else if (miejsce==9)
                {
                    algorytm(4,6,3,7,8,plansza, miejsce);
                }
            }

            else if (miejsce==4)
            {
                wstaw_symbol_komputer(plansza, 5);
                miejsce=wybor_miejsca(plansza);
                if (miejsce==1)
                {
                    algorytm(7,3,2,8,9,plansza, miejsce);
                }
                else if (miejsce==2)
                {
                    algorytm(1,9,7,3,6,plansza, miejsce);
                }
                else if (miejsce==3)
                {
                    algorytm(2,8,1,9,6,plansza, miejsce);
                }
                else if (miejsce==6)
                {
                    algorytm(3,7,1,9,8,plansza, miejsce);
                }
                else if (miejsce==7)
                {
                    algorytm(1,9,8,2,3,plansza, miejsce);
                }
                else if (miejsce==8)
                {
                    algorytm(7,3,1,9,6,plansza, miejsce);
                }
                else if (miejsce==9)
                {
                    algorytm(8,2,3,7,1,plansza, miejsce);
                }
            }
                else if (miejsce==6)
            {
                wstaw_symbol_komputer(plansza, 5);
                miejsce=wybor_miejsca(plansza);
                if (miejsce==1)
                {
                    algorytm(2,8,3,7,4,plansza, miejsce);
                }
                else if (miejsce==2)
                {
                    algorytm(3,7,1,9,8,plansza, miejsce);
                }
                else if (miejsce==3)
                {
                    algorytm(9,1,2,8,7,plansza, miejsce);
                }
                else if (miejsce==4)
                {
                    algorytm(1,9,3,2,7,plansza, miejsce);
                }
                else if (miejsce==7)
                {
                    algorytm(1,9,8,2,3,plansza, miejsce);
                }
                else if (miejsce==8)
                {
                    algorytm(3,7,9,1,4,plansza, miejsce);
                }
                else if (miejsce==9)
                {
                    algorytm(3,7,8,2,1,plansza, miejsce);
                }
            }

            else if (miejsce==8)
            {
                wstaw_symbol_komputer(plansza, 5);
                miejsce=wybor_miejsca(plansza);
                if (miejsce==1)
                {
                    algorytm(4,6,3,7,9,plansza, miejsce);
                }
                else if (miejsce==2)
                {
                    algorytm(9,1,3,6,7,plansza, miejsce);
                }
                else if (miejsce==3)
                {
                    algorytm(6,4,1,9,7,plansza, miejsce);
                }
                else if (miejsce==4)
                {
                    algorytm(7,3,1,9,6,plansza, miejsce);
                }
                else if (miejsce==6)
                {
                    algorytm(9,1,3,7,4,plansza, miejsce);
                }
                else if (miejsce==7)
                {
                    algorytm(9,1,4,6,3,plansza, miejsce);
                }
                else if (miejsce==9)
                {
                    algorytm(7,3,6,4,1,plansza, miejsce);
                }
            }

//////////////////////NA SRODKU
            else if (miejsce==5)
            {
                wstaw_symbol_komputer(plansza,9);
                miejsce=wybor_miejsca(plansza);
                if (miejsce==1)
                {
                    algorytm(6,3,7,8,2,plansza, miejsce);
                }
                else if (miejsce==2)
                {
                    algorytm(8,7,3,6,4,plansza, miejsce);
                }
                else if (miejsce==3)
                {
                    algorytm_srodek(7,8,2,4,6,plansza, miejsce);
                }
                else if (miejsce==4)
                {
                    algorytm(6,3,7,8,2,plansza, miejsce);
                }
                else if (miejsce==6)
                {
                    wstaw_symbol_komputer(plansza, 4);
                    miejsce=wybor_miejsca(plansza);
                        if (miejsce==2)////////////////////////////////////////////////////////DORBRZE
                        {
                           wstaw_symbol_komputer(plansza, 8);
                            test_wygranej(plansza);
                            miejsce=wybor_miejsca(plansza);
                            test_wygranej(plansza);
                            if(miejsce!=7)
                            {
                                wstaw_symbol_komputer(plansza, 7);
                                test_wygranej(plansza);
                            }
                            else
                            {
                                wstaw_symbol_komputer(plansza, 3);
                                test_remisu(plansza);
                            }
                        }
                        else if (miejsce==3)/////////////////////////////////////////////////DOBRZE
                        {
                           wstaw_symbol_komputer(plansza, 7);
                            test_wygranej(plansza);
                            miejsce=wybor_miejsca(plansza);
                            test_wygranej(plansza);
                            if(miejsce!=8)
                            {
                                wstaw_symbol_komputer(plansza, 8);
                                test_wygranej(plansza);
                            }
                            else
                            {
                                wstaw_symbol_komputer(plansza, 2);
                                test_remisu(plansza);
                            }
                        }
                        else if (miejsce==4)//DOBRZE
                        {
                               wstaw_symbol_komputer(plansza, 6);
                                test_wygranej(plansza);
                                miejsce=wybor_miejsca(plansza);
                                if(miejsce!=3)
                                {
                                    wstaw_symbol_komputer(plansza, 3);
                                    test_wygranej(plansza);
                                    test_remisu(plansza);
                                }
                                else
                                {
                                    wstaw_symbol_komputer(plansza, 7);
                                    test_wygranej(plansza);
                                    test_remisu(plansza);
                                    miejsce=wybor_miejsca(plansza);
                                    if (miejsce!=8)
                                    {
                                        wstaw_symbol_komputer(plansza, 8);
                                        test_wygranej(plansza);
                                    }
                                    else if(miejsce==8)
                                    {
                                        wstaw_symbol_komputer(plansza, 2);
                                        test_remisu(plansza);
                                    }
                                }
                        }

                            else if(miejsce==7)///////////////////////////////////////////////////
                            {
                                wstaw_symbol_komputer(plansza, 3);
                                miejsce=wybor_miejsca(plansza);
                                if (miejsce==2)
                                {
                                     wstaw_symbol_komputer(plansza, 8);
                                     test_remisu(plansza);
                                }
                                else if (miejsce==8)
                                {
                                     wstaw_symbol_komputer(plansza, 2);
                                     test_remisu(plansza);
                                }
                                else
                                {
                                    wstaw_symbol_komputer(plansza, 2);
                                    test_remisu(plansza);
                                }


                            }
                            else if(miejsce==8)
                            {
                                wstaw_symbol_komputer(plansza, 2);
                                miejsce=wybor_miejsca(plansza);
                                if (miejsce==3)
                                {
                                    wstaw_symbol_komputer(plansza, 7);
                                    test_remisu(plansza);
                                }
                                else if(miejsce==7)
                                {
                                    wstaw_symbol_komputer(plansza, 3);
                                    test_remisu(plansza);
                                }
                                else
                                {
                                    wstaw_symbol_komputer(plansza, 3);
                                    test_remisu(plansza);
                                }
                            }
                        }


                else if (miejsce==7)
                {
                    algorytm_srodek(3,6,4,2,8,plansza, miejsce);
                }
                else if (miejsce==8)
                {
                    wstaw_symbol_komputer(plansza, 2);
                    miejsce=wybor_miejsca(plansza);
                        if (miejsce==1)
                        {
                           wstaw_symbol_komputer(plansza, 3);
                            test_wygranej(plansza);
                            miejsce=wybor_miejsca(plansza);
                            test_wygranej(plansza);
                            if(miejsce!=6)
                            {
                                wstaw_symbol_komputer(plansza, 6);
                                test_wygranej(plansza);
                            }
                            else
                            {
                                wstaw_symbol_komputer(plansza, 4);
                                test_remisu(plansza);
                            }
                        }
                        else if (miejsce==3)
                        {
                           wstaw_symbol_komputer(plansza, 7);
                            test_wygranej(plansza);
                            miejsce=wybor_miejsca(plansza);
                            if(miejsce==4)
                            {
                                wstaw_symbol_komputer(plansza, 6);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                            else if(miejsce==6)
                            {
                                wstaw_symbol_komputer(plansza, 4);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                            else
                            {
                                wstaw_symbol_komputer(plansza, 4);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                        }
                        else if (miejsce==4)
                        {
                           wstaw_symbol_komputer(plansza, 6);
                            test_wygranej(plansza);
                            miejsce=wybor_miejsca(plansza);
                            if(miejsce!=3)
                            {
                                wstaw_symbol_komputer(plansza, 3);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                            else
                            {
                                wstaw_symbol_komputer(plansza, 7);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                        }
                        else if (miejsce==6)
                        {
                           wstaw_symbol_komputer(plansza, 4);
                            test_wygranej(plansza);
                            miejsce=wybor_miejsca(plansza);
                            if(miejsce==3)
                            {
                                wstaw_symbol_komputer(plansza, 7);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                            else if(miejsce==7)
                            {
                                wstaw_symbol_komputer(plansza, 3);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                            else
                            {
                                wstaw_symbol_komputer(plansza, 3);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                        }

                        else if (miejsce==7)
                        {
                           wstaw_symbol_komputer(plansza, 3);
                            test_wygranej(plansza);
                            miejsce=wybor_miejsca(plansza);
                            if(miejsce==4)
                            {
                                wstaw_symbol_komputer(plansza, 6);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                            else if(miejsce==6)
                            {
                                wstaw_symbol_komputer(plansza, 4);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                            else
                            {
                                wstaw_symbol_komputer(plansza, 4);
                                test_wygranej(plansza);
                                test_remisu(plansza);
                            }
                        }

                }
            }
         break;





















    case 2:
        wstaw_symbol_komputer(plansza,1);
        miejsce=wybor_miejsca(plansza);
        if (miejsce==2)
        {
            algorytm2(5,9,4,6,7,plansza,miejsce);
        }

        else if(miejsce==4)
        {
            algorytm2(5,9,2,8,3,plansza, miejsce);
        }
        else if (miejsce==6)
        {
            algorytm2(5,9,3,2,7,plansza, miejsce);
        }
        else if (miejsce==8)
        {
            algorytm2(5,9,7,3,4,plansza, miejsce);
        }
        else if (miejsce==7)
        {
            wstaw_symbol_komputer(plansza,3);
            miejsce=wybor_miejsca(plansza);
            if(miejsce!=2)
            {
                 wstaw_symbol_komputer(plansza,2);
                 test_wygranej(plansza);
            }
            else
            {
                wstaw_symbol_komputer(plansza, 9);
                miejsce=wybor_miejsca(plansza);
                if (miejsce==5)
                {
                    wstaw_symbol_komputer(plansza,6);
                    test_wygranej(plansza);
                }
                else
                {
                    wstaw_symbol_komputer(plansza,5);
                    test_wygranej(plansza);
                }
            }
        }
        else if (miejsce==3)
        {
            wstaw_symbol_komputer(plansza,7);
            miejsce=wybor_miejsca(plansza);
            if(miejsce!=4)
            {
                 wstaw_symbol_komputer(plansza,4);
                 test_wygranej(plansza);
            }
            else
            {
                wstaw_symbol_komputer(plansza, 9);
                miejsce=wybor_miejsca(plansza);
                if (miejsce==5)
                {
                    wstaw_symbol_komputer(plansza,8);
                    test_wygranej(plansza);
                }
                else
                {
                    wstaw_symbol_komputer(plansza,5);
                    test_wygranej(plansza);
                }
            }
        }
        else if (miejsce==9)
        {
            wstaw_symbol_komputer(plansza, 7);
            miejsce=wybor_miejsca(plansza);
            if(miejsce!=4)
            {
                 wstaw_symbol_komputer(plansza,4);
                 test_wygranej(plansza);
            }
            else
            {
                wstaw_symbol_komputer(plansza, 3);
                miejsce=wybor_miejsca(plansza);
                if (miejsce==2)
                {
                    wstaw_symbol_komputer(plansza,5);
                    test_wygranej(plansza);
                }
                else
                {
                    wstaw_symbol_komputer(plansza,2);
                    test_wygranej(plansza);
                }
            }
        }

        else if(miejsce==5)
        {
         wstaw_symbol_komputer(plansza,9);
         miejsce=wybor_miejsca(plansza);
         if (miejsce==3)
         {
             wstaw_symbol_komputer(plansza,7);
             miejsce=wybor_miejsca(plansza);
             if (miejsce==4)
             {
                 wstaw_symbol_komputer(plansza,8);
                 test_wygranej(plansza);
             }
             else if (miejsce==8)
             {
                 wstaw_symbol_komputer(plansza,4);
                 test_wygranej(plansza);
             }
         }
         else if (miejsce==7)
         {
             wstaw_symbol_komputer(plansza,3);
             miejsce=wybor_miejsca(plansza);
             if (miejsce==2)
             {
                 wstaw_symbol_komputer(plansza,6);
                 test_wygranej(plansza);
             }
             else if (miejsce==6)
             {
                 wstaw_symbol_komputer(plansza,2);
                 test_wygranej(plansza);
             }
         }
         else if (miejsce==2)
         {
             algorytm(8,7,3,4,6,plansza, miejsce);
         }
         else if (miejsce==4)
         {
             algorytm(6,3,7,8,2,plansza, miejsce);
         }
         else if (miejsce==6)
         {
             algorytm(4,7,3,2,8,plansza, miejsce);
         }
         else if (miejsce==8)
         {
             algorytm(2,3,7,4,6,plansza, miejsce);
         }


        }
        break;
    }
    return 0;
    }


