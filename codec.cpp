#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
class Codec{
    public: 
        string compress(string data){
            string CompressedData="";
            int count=0;
            for(int i=0;i<data.length();i++){
                if(data.length() && data.back() == data[i]){
                     //when we get Aaaa then go back to the top of the loop
                    count++;
                    continue;
                }
               
                //At the end of the loop we get single letter A for aaaa plus count=3
                CompressedData=CompressedData+data[i]+(count);
                count=0;

            }
            return CompressedData;

        }

      string decompress(string data){
          string org="";
          for(int i=0;i<data.length();i++){
              if(isalpha(data[i]) && isdigit(data[i+1])){
                  for(int i=0;i<data[i+1];i++)
                    org=org+data[i];
                };
                org=org+data[i];
                };
                
                return org;
      }



};

int main(){
    string val="";
    string inp;
    Codec c;
    cin>>inp;
    val=c.compress(inp);
    cout<<c.decompress(val);
    return 0;   
}