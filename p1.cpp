#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    cout<<"        welcome to the number game         "<<endl;
    cout<<"-->   Below are the instructions given to play numer guess game "<<endl;
    cout<<" -->  u have to choose the numbers between 1 to 100"<<endl
        <<" -->  u' ll also have to select the difficult level for this game"<<endl;
            while (true) {
        cout << "\nDifficulty Levels\n";
        cout << "\n1 for easy level!\t";
        cout << "\n2 for medium-level!\t";
        cout << "\n3 for difficult level!\t";
        cout << "\n0 for ending the game!\n" << endl;

        // select the level of difficulty
        int level;
        cout << "Enter the difficulty level number: ";
        cin >> level;
        // generating the random number
        srand(time(0));
        int randomNumber = (rand() % (100-1))+1;
        int guess;
            //if the player chooses difficulty level as easy
    if (level == 1) {
        cout << "\nYou will get 7 choices for finding the random number between 1 and 100.";
        int leftChance = 7;
        for (int i = 1; i <= 7; i++) {
            
            // asking the player to guess the number
            cout << "\n\nEnter the number: ";
            cin >> guess;
            if(guess== randomNumber){
                cout<<"Voila! You guessed the right number";
                break;
            }
            else if(guess>randomNumber){
                cout<<guess<<" is greater than the random number";
                    }
            else{
               cout<<guess<<" is less than the random number";
            }
            leftChance--;
            if(leftChance==0){
                cout<<"\nBetter luck next time"<<endl;
                cout<<randomNumber<<" is the number";
            }
        }           
    }
    else if (level == 2) {
        cout << "\nYou have 5 choices for finding the random number between 1 and 100.";
        int leftChance = 5;
        for (int i = 1; i <= 5; i++) {
 
            // asking the player to guess the number
            cout << "\n\nEnter the number: ";
            cin >> guess;
            if(guess== randomNumber){
                cout<<"Voila! You guessed the right number";
                break;
            }
            else if(guess>randomNumber){
                cout<<guess<<" is greater than the random number";
            }
            else{
                cout<<guess<<" is less than the random number";
            }
            leftChance--;
            if(leftChance==0){
                cout<<"\nBetter luck next time"<<endl;
                cout<<randomNumber<<" is the number";
            }
        }
    }               
    else if (level == 3) {
        cout << "\nYou have 3 choices for finding the secret number between 1 and 100.";
        int leftChance = 3;
        for (int i = 1; i <= 3; i++) {
            cout << "\n\nEnter the number: ";
            cin >> guess;
            if(guess== randomNumber){
                cout<<"Voila! You guessed the right number";
                break;
            }
            else if(guess>randomNumber){
                cout<<guess<<" is greater than the random number";
            }
            else{
                cout<<guess<<" is less than the random number";
            }
            leftChance--;
            if(leftChance==0){
                cout<<"\nBetter luck next time"<<endl;
                cout<<randomNumber<<" is the number";
            }
        }
    }
        // To end the game
        else if (level == 0) {
            exit(0);
        }
        else {
            cout << "Kindly select between (0,1,2,3)"<< endl;
        }


            
        }
        return 0;
}

