#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
    using namespace std;

size_t CalcHash(string input)
{
  hash<string> hasher;
  return(hasher(input));

}

/ **password cracker function ***/
    string Crack(string password, vector<char> Chars)
    {
     cout<<"PASSWORD TO CRACK: "<<password<<endl;
     int n = Chars.size();
     int i = 0;
     while(true)
     {
     i++;
     int N = 1;
     for(int j=0;j<i;j++)N*=n;
     for(int j=0;j<N;j++)
     {
     int K = 1;
     string crack = "";
     for(int k=0;k<i;k++)
     {
     crack += Chars[j/K%n];
     K *= n;
     }
     cout<< "Testing PASS: "<<crack<<" "<<"against "<<password<<endl;
     if(password.compare(crack) == 0){
    // cout<<"Cracked password: "<<crack<<endl;
     return crack;
     }
     }
     }
    }



 int main(int argc, char **argv)
    {



       //int numberThreads = argv[3];
    // pthread_t threads[numberThreads];





     /**     **/
     vector<char> Chars;
     for(char c = '0';c<='z';c++){
     if(isalpha(c) || isdigit(c))Chars.push_back(c);
     }
     string p = argv[1];



     string input = Crack("nil01", Chars);  // to check for other password chnage parameters here
     size_t value = CalcHash(input);// sending values to calcHash function to calculate hash value and then compare
      cout<<"Cracked password:"<<input<<endl;
  //    cout<"output of calcHash fuction:"<< (char)value <<endl;
  /*   if(p ==((char *) value))
    {
     cout<<"password matched: "<<input<<endl;

    }*/
    //cout<"could not find password: "<<endl;
exit(0);
return 0;
}