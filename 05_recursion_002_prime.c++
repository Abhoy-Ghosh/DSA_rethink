bool prime(int num,int divi){
    // for(int i = 2; i< num;i++ ){
    //     if(num % i == 0) return false;
    // }
    // return true;
    if(num < 0) return false;
    if(divi * divi > num) return true;
   
    if(num % divi == 0) return false;
    
    return prime(num,divi+1);
}

int main() {
   cout<< prime(7,0);

    return 0;
}
