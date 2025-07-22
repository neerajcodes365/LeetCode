class Solution {
public:
    string intToRoman(int num) {
    map<int, string> mp;
        mp[1] = "I";
        mp[4] = "IV";
        mp[5] = "V";
        mp[9] = "IX";
        mp[10] = "X";
        mp[40] = "XL";
        mp[50] = "L";
        mp[90] = "XC";
        mp[100] = "C";
        mp[400] = "CD";
        mp[500] = "D";
        mp[900] = "CM";
        mp[1000] = "M";

        int n = 13;
        vector<int> store(n, 0);
        store[0] = 1;
        store[1] = 4;
        store[2] = 5;
        store[3] = 9;
        store[4] = 10;
        store[5] = 40;
        store[6] = 50;
        store[7] = 90;
        store[8] = 100;
        store[9] = 400;
        store[10] = 500;
        store[11] = 900;
        store[12] = 1000;


        string ans="";
        int pt=12;
        // for(int i=0;i<n;i++){
        //     if(num>store[i]) pt=i;
        // }
        while(num>0 && pt>-1){
            if(num>=store[pt]){
            int digit=num/store[pt];
            for(int i=0;i<digit;i++){
                ans+=mp[store[pt]];
            }

            num=num%store[pt];
            }
            pt--;
        }
        return ans;
    }
};