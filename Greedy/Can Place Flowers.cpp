class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        // base condition according to logic , logic is to trevarse from i == 1  
        if(flowerbed.size() == 1)
        {
            if(flowerbed[0] == 0 && n == 1)
            {
                return true;
            }
            else if((flowerbed[0] == 1 || flowerbed[0] == 0) && n == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // start from i == 1
        // make all i-1 == 0 && i == 0  then count++ and arr[i] == 1 and after 
        // if i-1 == 1 and i = 1 comes simply count--;  
        int count = 0;
        int prev = flowerbed[0];
        for(int i = 1 ; i < flowerbed.size();i++)
        {
          if(flowerbed[0] == 0 && flowerbed[1] == 0)
          {
              flowerbed[0] = 1;
              count++; 
          }
          else if(flowerbed[i] == 0 && prev == 0)
          {
            count++;
            flowerbed[i] = 1;
            
          }
          else if(prev == 1 && flowerbed[i] == 1)
          {
            count--;
          }
          prev = flowerbed[i];
        }
        return count > n-1 ;
    }
};