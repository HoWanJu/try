int sum(int n){//�ŧisum�禡
	if(n==0){
		return 0;
	}
    
    if(n<0){
		return (-n%10+sum(-n/10));//�Y�Ͽ�J�t�Ȥ]�|�ܦ����ȶi�J�B��
	}
	
	else{
		return n%10+sum(n/10); //n���H10���l��+sum�禡���ܼƬ�n���H10���Ӽ�
	}
}
