int sum(int n){//宣告sum函式
	if(n==0){
		return 0;
	}
    
    if(n<0){
		return (-n%10+sum(-n/10));//即使輸入負值也會變成正值進入運算
	}
	
	else{
		return n%10+sum(n/10); //n除以10的餘數+sum函式中變數為n除以10的商數
	}
}
