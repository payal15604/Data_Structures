class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for(int i = 0; i < bills.size(); i++)
        {
            int num = bills[i];

            if(num == 5)
            {five++; continue;}

            else if(num == 10)
            {
                if(five){five--; ten++; continue;} 
                else {return false;}
            }

            else
            {    if (five && ten)
                {five--; ten--; continue;}

                else if(five >= 3)
                {five = five - 3; continue;}

                else
                {return false;}

            }
            
        }

        return true;
    }

  
};