#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<time.h>
int random_guess(int);
int main()
{
	int balance=1000,bet;
	while(1){
		printf("Your Balance is : %d $\n",balance);
		printf("Enter your bet : ");
		scanf("%d",&bet);
		/* Here we put the verification logic of the bet if the user puts invalid input */
		if(bet>1000 || bet<1) {
			printf("Invalid Bet. Please give between 1-1000 $\n");
			continue;
		}
		int guess;
		printf("Enter your Guess on the Dice : ");
		scanf("%d",&guess);
		if(guess<0 || guess>6){
			printf("Invalid Input !! , Please Try Again.\n");
			continue;
		}
		srand(time(NULL));
		int dice=random_guess(6);
		printf("%d\n",dice);
		sleep(2);
		if(guess==dice){
			printf("Bingo , You've won !!!!!1\n");
			balance+=20;
		}
		else
		{
			printf("Oops!!, Bad Luck try again \n");
			printf("But with an loss of -10 Bucks :( \n");
			balance-=10;
		}
		srand(getpid());
		while(1){
		char ch;
		printf("Do you wanna continue this game (y/n) : ");
		scanf("%c",&ch);
		if(ch=='y' || ch=='Y'){
		       	break;
		}
		else if(ch=='n' || ch=='N') return 0;
		else {
			printf("Invalid Input. \n");
			continue;
		}
	}
		if(balance<0) {
			printf("GAME OVER!!\n");
			return 0;
		}
}
}
	int random_guess(int max){
		return rand()%max +1;
	}
