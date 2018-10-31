#include <iostream>
#include <math.h>
#include <random>
using namespace std;

int rollDice()
{
    int card[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    int randomNum, randomCard;
    randomNum = rand() % 13;
    // cout << randomNum << endl;
    randomCard = card[randomNum];

    return randomCard;
}

int calcMoney(int money, int wager)
{
    money = money - wager;
    return money;
}

int getWager(int money)
{

    int wager;
    do
    {
        cout << "Enter wager: ";
        cin >> wager;
    } while (wager <= 0 || wager > money);

    return wager;
}

int hit(int &total)
{
    int hitRoll;
    hitRoll = rollDice();
    total += hitRoll;
    return total;
}

bool bustOrNot(int &total)
{
    if (total > 21)
    {
        cout << "Your total is " << total << ". Busts!!" << endl;
        return true;
    }
    else
        cout << "player total: " << total << endl;
    return false;
}

int hitOrStand(int &playerTotal, int& houseTotal)
{

    string hitOrStand;
    cout << "hit or stand?" << endl;
    cin >> hitOrStand;
    if (hitOrStand == "hit")
    {
        playerTotal = hit(playerTotal);
        bustOrNot(playerTotal);
        return playerTotal;
    }
    else {
        houseTotal = hit(houseTotal);
        bustOrNot(houseTotal);
        return houseTotal;
    }
    
}

bool continueOrNot(int &total)
{
    if (total <= 21)
        return true;
    else
        return false;
}



void playerTurn(int money, int &wager, bool &bust, int &total, int &houseRoll)
{
}

int main()
{
    string answer;
    int pRoll1, pRoll2, pRoll3, pRoll4, pRoll5, hRoll1, hRoll2, hRoll3, hRoll4, hRoll5;
    int wager, firstMoney, remainMoney, playerTotal, houseTotal;
    bool playerBust, houseBust;

    firstMoney = 100;
    wager = getWager(firstMoney);

    do
    {
        pRoll1 = rollDice();
        pRoll2 = rollDice();
        pRoll3 = rollDice();
        pRoll4 = rollDice();
        pRoll5 = rollDice();

        hRoll1 = rollDice();
        hRoll2 = rollDice();
        hRoll3 = rollDice();
        hRoll4 = rollDice();
        hRoll5 = rollDice();
        remainMoney = calcMoney(firstMoney, wager);

        playerTotal = pRoll1 + pRoll2;
        houseTotal = hRoll1;
        bustOrNot(playerTotal);
        cout << ", house total: " << houseTotal << endl;
        bool gameContinue = continueOrNot(playerTotal);
        if (gameContinue)
        {
            playerTotal = hitOrStand(playerTotal, houseTotal);
            bustOrNot(playerTotal);
            gameContinue = continueOrNot(playerTotal);
            if (gameContinue)
            {
                playerTotal = hitOrStand(playerTotal, houseTotal);
                bustOrNot(playerTotal);
            }
        }

        cout << "again?";
        cin >> answer;
    } while (answer == "y" || answer == "Y");

    return 0;
}
