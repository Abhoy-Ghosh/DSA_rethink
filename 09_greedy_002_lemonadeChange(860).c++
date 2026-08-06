

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    
    int five =0;
    int ten = 0;

    for(auto bill : bills){
        if(bill ==5){
            five++;
        }

        else if(bill== 10){
            if(five < 1)
            return false;

            five--; 
            ten++;
        }
        else if(bill == 20){
            if(five > 0 && ten > 0){
                five--;
                ten--;
            }
            else if(five >= 3){
                five = five-3;
            }
            else return false;
        }
    }
return true;
    }
};


// Why it works

// You maintain two counters:

// five → number of $5 bills
// ten → number of $10 bills

// Then process each customer:

// Customer pays $5
// No change needed.
// Increase five.
// Customer pays $10
// Must give back one $5.
// If no $5 exists, return false.
// Otherwise, decrement five and increment ten.
// Customer pays $20
// Need to give $15 change.
// Prefer $10 + $5 if available.
// Otherwise, give three $5 bills.
// If neither is possible, return false.
