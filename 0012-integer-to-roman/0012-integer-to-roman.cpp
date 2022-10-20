class Solution {
public:
    string intToRoman(int num) {
        string s="";
        while(num){
            // cout<<num<<" ";
            if((num/1000)!=0){
                int cnt=num/1000;
                num=num%1000;      
                for(int i=0;i<cnt;i++){
                    s+="M";    
                }
            }else if(num/900!=0){
                 int cnt=num/900;
                num=num%900;
                for(int i=0;i<cnt;i++){
                    s+="CM";
                }
            }
            else if(num/500!=0){
                 int cnt=num/500;
                num=num%500;
                for(int i=0;i<cnt;i++){
                    s+="D";
                }
            }else if(num/400!=0){
                 int cnt=num/400;
                num=num%400;
                for(int i=0;i<cnt;i++){
                    s+="CD";
                }
            }else if(num/100!=0){
                 int cnt=num/100;
                num=num%100;
                for(int i=0;i<cnt;i++){
                    s+="C";
                }
            }else if(num/90!=0){
                 int cnt=num/90;
                num=num%90;
                for(int i=0;i<cnt;i++){
                    s+="XC";
                }
            }else if(num/50!=0){
                 int cnt=num/50;
                num=num%50;
                for(int i=0;i<cnt;i++){
                    s+="L";
                }
            }else if(num/40!=0){
                 int cnt=num/40;
                num=num%40;
                for(int i=0;i<cnt;i++){
                    s+="XL";
                }
            }
            else if(num/10!=0){
                 int cnt=num/10;
                num=num%10;
                for(int i=0;i<cnt;i++){
                    s+="X";
                }
            }else if(num/9!=0){   
                 int cnt=num/9;
                num=num%9;
                for(int i=0;i<cnt;i++){
                    s+="IX";
                }
            }else if(num/5!=0){
                 int cnt=num/5;
                num=num%5;
                for(int i=0;i<cnt;i++){
                    s+="V";
                }
            }else if(num/4!=0){
                 int cnt=num/4;
                num=num%4;
                for(int i=0;i<cnt;i++){
                    s+="IV";
                }
            }else if(num/1!=0){
                 int cnt=num/1;
                num=num%1;
                for(int i=0;i<cnt;i++){
                    s+="I";
                }
            }
        }
      return s;
    }
};