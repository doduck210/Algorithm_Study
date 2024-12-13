#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        
        int il=num%10;
        int sip=(num/10)%10;
        int baek=(num/100)%10;
        int chun=num/1000;
        
        // 10^3 solving
        for(int i=0;i<chun;i++){
            ans+="M";
        }

        // 10^2
        if(baek==9) ans+="CM";
        else if(baek==4) ans+="CD";
        else{
            while(baek){
                if(baek>=5){
                    ans+="D"; baek-=5;
                }
                else{
                    ans+="C";
                    baek-=1;
                }
            }
        }

        //10
        if(sip==9) ans+="XC";
        else if(sip==4) ans+="XL";
        else{
            while(sip){
                if(sip>=5){
                    ans+="L"; sip-=5;
                }
                else{
                    ans+="X";
                    sip-=1;
                }
            }
        }

        //1
        if(il==9) ans+="IX";
        else if(il==4) ans+="IV";
        else{
            while(il){
                if(il>=5){
                    ans+="V"; il-=5;
                }
                else{
                    ans+="I";
                    il-=1;
                }
            }
        }

        return ans;
    }
};