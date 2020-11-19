/* USER: 33u9
LANG: C++
TASK: bankacc */
#include <cstdio>
#include <unordered_map>

using namespace std;

unordered_map<int,int> data; //using unordered maps for MEMORY and TIME efficiency

int main()
{
	freopen("bankacc.in","r",stdin);	//read from the bankacc.in file 
    freopen("bankacc.out","w",stdout);	//write to the bankacc.out file 
	int n = 0;
	char character;
	int acc_num;
	int amount;
	
	scanf("%d",&n); //scan N (how many actions the program must complete)
	
	for(int i = 0; i < n; i++) //run N times (once for every action)
	{
		
		scanf(" %c",&character); //read the type of action the program must execute ({q for querying},{d for depositing},{w for withdrawal})
		
		if(character == 'q') //query || For querying the system, the program just scans the bank account in question and prints its value
		{
			scanf("%d",&acc_num);
			printf("%d\n",data[acc_num]);
			continue;
		}
		
		
		else if(character == 'd') //deposit || To deposit an amount into an account the program scans the identification number of the account and the amount being added to the account value
		{						  //After the addition, the program prints "s"
			scanf("%d",&acc_num);
			scanf("%d",&amount);
			data[acc_num] += amount;
			printf("s\n");
			continue;
		}
		
		else  //withdrawal (w) || In the case of withdrawal, the program must scan the identification number of the account and the amount being subtracted from the account value
		{	  //If the withdrawal is possible (account_value - withdraw_amount > 0) then proceed and print "s", else print "f"
			scanf("%d",&acc_num);
			scanf("%d",&amount);
			if(data[acc_num] - amount > 0)
			{
				data[acc_num] -= amount;
				printf("s\n");
			}
			else printf("f\n");
		}
	}
	
	
	return 0; //terminate the program
}
