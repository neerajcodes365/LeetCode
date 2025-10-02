class Solution {
public:
    int maxBottlesDrunk(int bot, int ex) {
        int ans=bot;
        while(bot>=ex){
            bot=bot-ex;
            ex++;
            if(bot>=0){
                 bot++;
                 ans++;
            }
        }
        return ans;
    }
};